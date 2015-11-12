//============================================================================
// Name        : Q1.cpp
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Implementation of Question 1
//============================================================================

#include "Q1.h"

Q1::Q1() {

}

void Q1::itoo(int value, char* str) {
	str[8] = '\0';
	for(int i = 10; i > 0; i--) {
		str[i] = toChar(value&0x07);
		value >>= 3;
	}
	// Note that the implementation of >> is not wholly specified by the c++ standard
	// For that reason, on many compilers, >> is actually dependent on the type of number being shifted, instead of being consistent
	// This is why the next line must not be included in the previous loop
	str[0] = toChar(value&0x03);
}

char Q1::toChar(int value) {
	return (char) value+0x30;
}
