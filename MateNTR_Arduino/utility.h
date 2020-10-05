#pragma once

/**************** Custom Chars ****************/
	byte custom_chars[10][8] = {
		{ // 0, upper left, UPL
			0b00111,
			0b01111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111
		},
		{ // 1, upper middle bar, UMB
			0b11111,
			0b11111,
			0b11111,
			0b00000,
			0b00000,
			0b00000,
			0b11111,
			0b11111
		},
		{ // 2, upper right, UPR
			0b11100,
			0b11110,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111
		},
		{ // 3, upper bar, UPB
			0b11111,
			0b11111,
			0b11111,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000
		},
		{ // 4, lower left, LWL
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b01111,
			0b00111
		},
		{ // 5, lower slice, LWS
			0b00000,
			0b00000,
			0b00000,
			0b10000,
			0b11000,
			0b11100,
			0b11110,
			0b11111
		},
		{ // 6, lower right, LWR
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11111,
			0b11110,
			0b11100
		},
		{ // 7, lower bar, LWB
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b11111,
			0b11111,
			0b11111
		}
	};

	#define UPL	0
	#define UMB 1
	#define UPR 2
	#define UPB 3
	#define LWL 4
	#define LWS 5
	#define LWR 6
	#define LWB 7

	#define MPT 0b10000000
	#define FUL 0b11111111

	#define RIGHT_ARROW		0b01111110
	#define LEFT_ARROW		0b01111111
/**************** Custom Chars ****************/

/**************** Custom Nums ***************/
	byte custom_nums[10][2][3] = {
		{{UPL, UPB, UPR}, {LWL, LWB, LWR}}, // 0
		{{UPB, UPR, MPT}, {LWB, FUL, LWB}}, // 1
		{{UMB, UMB, UPR}, {LWL, LWB, LWB}}, // 2
		{{UPB, UMB, UPR}, {LWB, LWB, LWR}}, // 3
		{{LWL, LWB, FUL}, {MPT, MPT, FUL}}, // 4
		{{LWL, UMB, UMB}, {LWB, LWB, LWR}}, // 5
		{{UPL, UMB, UMB}, {LWL, LWB, LWR}}, // 6
		{{UPB, UPB, UPR}, {MPT, MPT, FUL}}, // 7
		{{UPL, UMB, UPR}, {LWL, LWB, LWR}}, // 8
		{{UPL, UMB, UPR}, {LWB, LWB, FUL}}, // 9
	};
/**************** Custom Nums ***************/

/**************** Custom Alphabet ***************/
	byte custom_alphabets[26][2][3] = {
		{{UPL, UMB, UPR}, {LWL, MPT, LWR}}, // a
		{{FUL, UMB, LWR}, {FUL, LWB, UPR}}, // b
		{{UPL, UPB, UPB}, {LWL, LWB, LWB}}, // c
		{{FUL, UPB, UPR}, {FUL, LWB, LWR}}, // d
		{{UPL, UMB, UMB}, {LWL, LWB, LWB}}, // e
		{{UPL, UMB, UMB}, {LWL, MPT, MPT}}, // f
		{{UPL, UPB, UPB}, {LWL, LWB, UPR}}, // g
		{{UPL, LWB, UPR}, {LWL, MPT, LWR}}, // h
		{{UPB, FUL, UPB}, {LWB, FUL, LWB}}, // i
		{{UPB, FUL, UPB}, {LWB, LWR, MPT}}, // j
		{{FUL, LWB, LWR}, {FUL, MPT, UPR}}, // k
		{{FUL, MPT, MPT}, {LWL, LWB, LWB}}, // l
		{{FUL, FUL, FUL}, {FUL, MPT, FUL}}, // m-
		{{FUL, LWS, FUL}, {FUL, MPT, FUL}}, // n-
		{{UPL, UPB, UPR}, {LWL, LWB, LWR}}, // o
		{{UPL, UMB, UPR}, {LWL, MPT, MPT}}, // p
		{{LWR, LWL, MPT}, {UPR, UPL, LWS}}, // q--
		// {{UPL, UMB, UPR}, {MPT, MPT, LWR}}, // q
		{{FUL, UMB, UPR}, {FUL, MPT, LWR}}, // r
		{{FUL, UMB, UPB}, {LWB, LWB, FUL}}, // s
		{{UPB, FUL, UPB}, {MPT, FUL, MPT}}, // t
		{{FUL, MPT, FUL}, {LWL, LWB, LWR}}, // u
		{{LWL, MPT, LWR}, {MPT, UPB, MPT}}, // v--
		{{FUL, MPT, FUL}, {FUL, FUL, FUL}}, // w-
		{{LWL, LWB, LWR}, {UPL, MPT, UPR}}, // x
		{{LWL, LWB, LWR}, {MPT, FUL, MPT}}, // y
		{{UPB, UMB, LWR}, {UPL, LWB, LWB}}  // z
	};
/**************** Custom Alphabet ***************/