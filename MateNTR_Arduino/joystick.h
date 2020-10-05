#pragma once

#include "configuration.h"

class Joystick{
public:
	Joystick() {};
	~Joystick() {};

	void init() {
		pinMode(INPUT, Joystick_X);
		pinMode(INPUT, Joystick_Y);
		pinMode(INPUT, Joystick_Btn);
	}

	char wait_key() {
		int x = CenterThreshold;
		int y = CenterThreshold;
		int btn = CenterThreshold;
		while (true){
			x = analogRead(Joystick_X);
			y = analogRead(Joystick_Y);
			btn = analogRead(Joystick_Btn);

			if(btn == 0)			return 'c'; // confirm
			if(x > UpperThreshold)	return 'u'; // right -> up
			if(x < LowerThreshold)	return 'd'; // left -> down
			if(y > UpperThreshold)	return 'r'; // down -> right
			if(y < LowerThreshold)	return 'l'; // up -> left
		}
	}
};