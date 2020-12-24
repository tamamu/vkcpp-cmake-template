#pragma once

#include <iostream>

#define STRINGIFY(n) #n
#define TOSTRING(n) STRINGIFY(n)
#define panic(...) \
	do {\
		fprintf(stderr, "[e] " __FILE__ " panic at line " TOSTRING(__LINE__) ": " __VA_ARGS__);\
		fprintf(stderr, "\n");\
		std::exit(EXIT_FAILURE);\
	} while (0)