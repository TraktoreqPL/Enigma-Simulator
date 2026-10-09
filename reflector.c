#include "reflector.h"

#define ALPHABET_SIZE 26
#define ALL_REFLECTORS_COUNT 3

Reflectors mounted_reflector;

char pass_through_reflector(const char letter)
{
	static const char reflectors[ALL_REFLECTORS_COUNT][ALPHABET_SIZE + 1] = { /* Adding one to aplhabet size beacuse null terminator */
		"EJMZALYXVBWFCRQUONTSPIKHGD",
		"YRUHQSLDPXNGOKMIEBFZCWVJAT",
		"FVPJIAOYEDRZXWGCTKUQSBNMHL"
	};

	return reflectors[mounted_reflector][letter - 'A']; /* Subtracting one beacuse indexes start at 0 not 1 */
}