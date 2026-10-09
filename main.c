#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plugboard.h"
#include "reflector.h"
#include "rotors.h"

#define BUFFER_SIZE 265

char buffer[BUFFER_SIZE];

int check_if_valid(const char letter)
{
	int i;

	static char valid_letters[ALPHABET_SIZE + 1] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ',}; /* Space is valid but is ignored that's why there is ALPHABET_SIZE + 1 */

	for (i = 0; i < ALPHABET_SIZE + 1; i++) {
		if (letter == valid_letters[i]) {
			return -1;
		}
	}

	return 0;
}

char encrypt(const char letter)
{
	rotate_rotors();

	/* Read it from down to top, beacuse function arguments are after the function call */
	return pass_through_plugboard(
	pass_through_rotor(0, 1,
	pass_through_rotor(1, 1,
	pass_through_rotor(2, 1, 
	pass_through_reflector(
	pass_through_rotor(2, 0,
	pass_through_rotor(1, 0,
	pass_through_rotor(0, 0,
	pass_through_plugboard(letter)
	))))))));
}

int main(int argc, char* const argv[])
{
	int i;

	rotor_order[0] = atoi(argv[1]);
	rotor_order[1] = atoi(argv[2]);
	rotor_order[2] = atoi(argv[3]);

	rotors_shift[0] = atoi(argv[4]);
	rotors_shift[1] = atoi(argv[5]);
	rotors_shift[2] = atoi(argv[6]);

	mounted_reflector = (Reflectors)atoi(argv[7]);

	config.in_pins[0] = argv[8][0];
	config.in_pins[1] = argv[9][0];
	config.in_pins[2] = argv[10][0];
	config.in_pins[3] = argv[11][0];
	config.in_pins[4] = argv[12][0];
	config.in_pins[5] = argv[13][0];
	config.in_pins[6] = argv[14][0];
	config.in_pins[7] = argv[15][0];
	config.in_pins[8] = argv[16][0];
	config.in_pins[9] = argv[17][0];

	config.out_pins[0] = argv[18][0];
	config.out_pins[1] = argv[19][0];
	config.out_pins[2] = argv[20][0];
	config.out_pins[3] = argv[21][0];
	config.out_pins[4] = argv[22][0];
	config.out_pins[5] = argv[23][0];
	config.out_pins[6] = argv[24][0];
	config.out_pins[7] = argv[25][0];
	config.out_pins[8] = argv[26][0];
	config.out_pins[9] = argv[27][0];

	fgets(buffer, BUFFER_SIZE, stdin);

	int len = strlen(buffer);
	
	if (len > 0 && buffer[len - 1] == '\n') {
		buffer[len - 1] = ' '; 
	}

	for (i = 0; i < len - 1; i++)
		if (!check_if_valid(buffer[i])) {
			puts("Wrong text. Use only uppercase letters and spaces");
			return 1;
		}

	for (i = 0; i < len; i++)
		if (buffer[i] != ' ')
			buffer[i] = encrypt(buffer[i]);

	puts(buffer);
}