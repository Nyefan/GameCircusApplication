//============================================================================
// Name        : TestBench.cpp
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Test code for Game Circus Application
//============================================================================

#include <iostream>
#include <climits>
#include "Q1.h"
#include "Q2.h"
#include "PacketManager.h"
#include "ElevatorManager.h"

void testQ1() {
	Q1 testQ1 = Q1();
	char str [11];

	// These could both be handled in one loop by starting with i = -100,
	// but this is clearer when examining the results.

	std::cout << std::endl << "Testing Positive Octal Conversions" << std::endl;

	for (int i = 0; i < 101; i++) {
		int value = i*(INT_MAX/100);
		testQ1.itoo(value, str);
		std::cout << str << " " << std::oct << value << std::endl;
	}

	std::cout << std::endl << "Testing Negative Octal Conversions" << std::endl;

	for (int i = 0; i < 101; i++) {
		int value = i*(INT_MIN/100);
		testQ1.itoo(value, str);
		std::cout << str << " " << std::oct << value << std::endl;
	}
}

void testQ2() {
	Q2 testQ2 = Q2();
	char* str [5];
	str[0] = "pRa gmA tic"; 	//should anagram itself, 0, and 4
	str[1] = "ta mga rc ip"; 	//should anagram itself, 0, and 4
	str[2] = "Gra Mat ic";  	//should only anagram itself
	str[3] = " Pragmatic p "; 	//should only anagram itself
	str[4] = "pragmatic"; 		//should anagram iself, 0, and 1;

	char* answer [2];
	answer[0] = "no";
	answer[1] = "yes";

	std::cout << std::endl << "Testing Anagram Checker" << std::endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << str[i] << ",\t" << str[j] << ":\t" << answer[testQ2.is_anagram(str[i], str[j])] << std::endl;
		}
	}
}

int main() {
	//testQ1();
	//testQ2();
}
