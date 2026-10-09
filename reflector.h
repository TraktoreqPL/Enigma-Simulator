#ifndef REFLECTOR_H
#define REFLECTOR_H

typedef enum {
	UKW_A,
	UKW_B,
	UKW_C
} Reflectors;

extern Reflectors mounted_reflector;

char pass_through_reflector(const char letter);

#endif