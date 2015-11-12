//============================================================================
// Name        : Q2.cpp
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Implementation of Question 2
//============================================================================

#include "Q2.h"

int Q2::is_anagram(const char* first, const char* second) {

	int numCharsFirst [26] = {};
	int numCharsSecond [26] = {};

	populateCounter(first, numCharsFirst);
	populateCounter(second, numCharsSecond);

	for (int i = 0; i < 26; i++) {
		if (numCharsFirst[i] != numCharsSecond[i]) {
			return 0;
		}
	} return 1;

}

void Q2::populateCounter(const char* str, int* counter) {

	int charAt = 0;
	char testChar = str[charAt];
	while (testChar!='\0') {
		if (testChar > 0x40 && testChar < 0x5B) {
			counter[testChar-0x41]++;
		} else if (testChar > 0x60 && testChar < 0x7B) {
			counter[testChar-0x61]++;
		}

		charAt++;
		testChar = str[charAt];
	}

}
