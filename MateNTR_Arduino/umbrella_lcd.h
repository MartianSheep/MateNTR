#pragma once

#include <LiquidCrystal_I2C.h>
#include "utility.h"
#include "configuration.h"

class Umbrella_lcd{
public:
	Umbrella_lcd() {
		lcd = new LiquidCrystal_I2C(LCD_Address, LCD_Row, LCD_Column);
	}
	~Umbrella_lcd() { delete lcd; }

	void init() {
		lcd->init();
		lcd->backlight();

		for(byte i = 0; i < 8; ++i)
			lcd->createChar(i, custom_chars[i]);

		lcd->clear();
		lcd->setCursor(0, 0);
	}

	void clear() { lcd->clear(); }

	void setCursor(int x, int y) { lcd->setCursor(x, y); }

	void print_custom_num(int num, int x = 0, int y = 0) {
		setCursor(x, y);
		for(byte i = 0; i < 2; ++i){
			for(byte j = 0; j < 3; ++j)
				lcd->write(byte(custom_nums[num][i][j]));
			setCursor(x, ++y);
		}
	}

	void print_custom_alpha(char a, int x = 0, int y = 0) {
		setCursor(x, y);
		for (byte i = 0; i < 2; ++i){
			for (byte j = 0; j < 3; ++j)
				lcd->write(byte(custom_alphabets[int(a - 'a')][i][j]));
			setCursor(x, ++y);
		}
	}

	void print(String s, int x = 0, int y = 0) {
		setCursor(x, y);
		lcd->print(s);
	}

	void await(){
		print("    Please swipe    ", 0, 0);
		print_custom_alpha('c', 2, 1);
		print_custom_alpha('a', 6, 1);
		print_custom_alpha('r', 10, 1);
		print_custom_alpha('d', 14, 1);
		print("--Umbrella Systems--", 0, 3);
	}

	void goodbye(){
		clear();
		print("   User Cancelled   ", 0, 0);
		print_custom_alpha('b', 0, 1);
		print_custom_alpha('y', 3, 1);
		print_custom_alpha('e', 6, 1);
		print_custom_alpha('b', 11, 1);
		print_custom_alpha('y', 14, 1);
		print_custom_alpha('e', 17, 1);
		print("--Umbrella Systems--", 0, 3);

		delay(3000);
		clear();
	}

	void six_words(String str){
		clear();
		print("Situation:", 0, 0);
		print(str, 7, 1);
		print("Umbrella", 6, 2);
	}

	void apology(){
		clear();
		print("We are", 7, 0);
		print_custom_alpha('s', 0, 1);
		print_custom_alpha('o', 4, 1);
		print_custom_alpha('r', 8, 1);
		print_custom_alpha('r', 12, 1);
		print_custom_alpha('y', 16, 1);
		print("<No Available Slots>", 0, 3);

		delay(3000);
		clear();
	}

	void thank(){
		clear();
		print_custom_alpha('t', 0, 0);
		print_custom_alpha('h', 4, 0);
		print_custom_alpha('a', 8, 0);
		print_custom_alpha('n', 12, 0);
		print_custom_alpha('k', 16, 0);
		print_custom_alpha('y', 3, 2);
		print_custom_alpha('o', 8, 2);
		print_custom_alpha('u', 13, 2);
		delay(3000);
		clear();
	}
private:
	LiquidCrystal_I2C* lcd;
};