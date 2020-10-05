#include <Servo.h>
#include "umbrella_lcd.h"
#include "joystick.h"
#include "utility.h"
#include "configuration.h"

Umbrella_lcd lcd_console;
Joystick joystick;
bool slots_state[Slots_Num];
Servo servos[Slots_Num];

void borrow_or_return(bool cmd);
bool situation_available(bool wanted);
int decide(bool wanted);
bool confirm();
void slot_chosed(int num, bool cmd);

void setup(){
	Serial.begin(9600);
	lcd_console.init();
	joystick.init();

	for(int i = 0; i < Slots_Num; ++i){
		pinMode(limit_switches[i], INPUT_PULLUP);
		servos[i].attach(servo_pin[i]);
		servos[i].write(Servo_Close);
		slots_state[i] = true;
	}
}

void loop(){
	lcd_console.await();
	if(Serial.available()){
		char cmd = Serial.read();
		if(cmd == 'b')
			borrow_or_return(true);
		else if(cmd == 'r')
			borrow_or_return(false);
	}
}

bool confirm(){
	bool result = true;
	while(true){
		lcd_console.print((result? " >Confirm<  Cancel  " : "  Confirm  >Cancel< "),
			0, 3);
		
		delay(200);

		char action = joystick.wait_key();
		switch(action){
			case 'l': result = true;	break;
			case 'r': result = false;	break;
			case 'c': return result;
		}
	}
}

bool situation_available(bool wanted){
	for(int i = 0; i < Slots_Num; ++i)
		slots_state[i] = !digitalRead(limit_switches[i]);
	for(int i = 0; i < Slots_Num; ++i){
		if(slots_state[i] == wanted)
			return true;
	}
	return false;
}

void borrow_or_return(bool cmd){
	lcd_console.six_words(cmd ? "BORROW" : "RETURN");
	if(confirm()){
		// start process
		if(situation_available(cmd)){
			int num = decide(cmd);
			if(num) slot_chosed(num, cmd);
			else lcd_console.goodbye();
		}
		else lcd_console.apology();
	}
	else lcd_console.goodbye();
}

int decide(bool wanted){ // choose slot number
	lcd_console.clear();
	lcd_console.print("Choose your slot:", 0, 0);

	int decision = 1;
	while(slots_state[decision - 1] != wanted)
		++decision;
	bool state_num = true;
	String str = "";

	while(true){
		str = "";
		for(int i = 1; i <= Slots_Num; ++i){
			if(slots_state[i-1] != wanted)
				str += " X ";
			else if(i == decision && state_num)
				str += (">" + String(i) + "<");
			else
				str += (" " + String(i) + " ");
		}
		lcd_console.print(str, 5, 2);
		lcd_console.print(state_num ? " Cancel " : ">Cancel<", 6, 3);
		
		delay(200);

		char action = joystick.wait_key();
		switch (action){
			case 'l':
				do{decision = (decision == 1 ? Slots_Num : (decision - 1));
				}while(slots_state[decision - 1] != wanted);
				break;
			case 'r':
				do{decision = (decision == Slots_Num ? 1 : (decision + 1));
				}while(slots_state[decision - 1] != wanted);
				break;
			case 'u':	state_num = true;	break;
			case 'd':	state_num = false;	break;
			case 'c':	return (state_num ? decision : 0);
		}
	}
}

void slot_chosed(int num, bool cmd){
	lcd_console.clear();

	servos[num - 1].write(Servo_Open);
	// countdown
	lcd_console.print("Pls take action in:", 0, 0);
	lcd_console.print("seconds.", 12, 3);
	int seconds_left = Process_Time;
	unsigned long then = millis();
	unsigned long now = millis();
	while(digitalRead(limit_switches[num - 1]) != cmd && seconds_left){
		lcd_console.print_custom_num(seconds_left / 10, 6, 1);
		lcd_console.print_custom_num(seconds_left % 10, 10, 1);

		now = millis();
		if(now - then >= 1000){
			seconds_left--;
			then = now;
		}
	}
	lcd_console.clear();

	if(digitalRead(limit_switches[num - 1]) == cmd){
		Serial.print(cmd);
		Serial.print(num);
		Serial.print("\n");
		slots_state[num - 1] = !cmd;
		// delay((cmd ? 10000 : 1000));
		if(cmd){
			lcd_console.print("Umbrella taken,", 0, 0);
			lcd_console.print("Slot closed in:", 0, 1);
			lcd_console.print("seconds.", 12, 3);
			seconds_left = Slot_Delay_Time;
			then = millis();
			now = millis();
			while(seconds_left){
				lcd_console.print_custom_num(seconds_left / 10, 4, 2);
				lcd_console.print_custom_num(seconds_left % 10, 8, 2);

				now = millis();
				if(now - then >= 1000){
					seconds_left--;
					then = now;
				}
			}
		}
		lcd_console.thank();
		servos[num - 1].write(Servo_Close);
	}
	else{
		lcd_console.print("Umbrella unprocessed", 0, 0);
		lcd_console.print("Slot is Closing...", 1, 2);
		servos[num - 1].write(Servo_Close);
		delay(3000);
	}

	lcd_console.clear();
}