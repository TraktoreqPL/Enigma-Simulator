#include "plugboard.h"

plugboard_configuration config;

int search(const char letter, const char table[CABLE_COUNT])
{
	int i;

	for (i = 0; i < CABLE_COUNT; i++) {
		if (table[i] == letter) {
			return i;
		}
	}

	return -1;
}

char pass_through_plugboard(const char letter)
{
	int index;

	index = search(letter, config.in_pins);

	if (index != -1)
		return config.out_pins[index];

	index = search(letter, config.out_pins);

	if (index != -1)
		return config.in_pins[index];

	return letter;
}