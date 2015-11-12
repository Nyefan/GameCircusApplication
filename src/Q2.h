//============================================================================
// Name        : Q2.h
// Author      : Anthony St. Aubin
// Version     : 1.0
// Description : Header for Question 2
//============================================================================

#pragma once

class Q2 {

public:
	int is_anagram(const char* first, const char* second);
private:
	void populateCounter(const char* str, int* counter);
};

