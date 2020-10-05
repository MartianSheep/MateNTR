#pragma once

/**************** Slots_Num Related ****************/
	#define Slots_Num	3
	byte limit_switches[Slots_Num]	=	{2, 3, 4};
	byte servo_pin[Slots_Num]		=	{5, 6, 7};
/**************** Slots_Num Related ****************/

/**************** Motors ****************/
	#define Motor_Right		10
	#define Motor_Right_IN1	9
	#define Motor_Right_IN2	8
	#define Motor_Left		11
	#define Motor_Left_IN3	12
	#define Motor_Left_IN4	13
/**************** Motors ****************/

/**************** Servos ****************/
	#define Servo_Close		0
	#define Servo_Open		90

	#define Process_Time	30
	#define Slot_Delay_Time	10
/**************** Servos ****************/

/**************** Monitors ****************/
	#define Joystick_X		14
	#define Joystick_Y		15
	#define Joystick_Btn	16

	#define CenterThreshold 512
	#define ThresholdRatio	0.5
	#define UpperThreshold	(CenterThreshold + CenterThreshold * ThresholdRatio)
	#define LowerThreshold	(CenterThreshold - CenterThreshold * ThresholdRatio)

	#define LCD_Address		0x27
	#define LCD_Row			20
	#define LCD_Column		4
/**************** Monitors ****************/