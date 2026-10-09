#include "rotors.h"

#define ALL_ROTORS_COUNT 5

int rotor_order[INSIDE_ROTORS_COUNT];
int rotors_shift[INSIDE_ROTORS_COUNT];

char pass_through_rotor(const int pos, const int dir, const char letter)
{
	static const char rotors[ALL_ROTORS_COUNT][ALPHABET_SIZE + 1] = { /* Adding one to aplhabet size beacuse null terminator */
		"EKMFLGDQVZNTOWYHXUSPAIBRCJ",
		"AJDKSIRUXBLHWTMCQGZNPYFVOE",
		"BDFHJLCPRTXVZNYEIWGAKMUSQO",
		"ESOVPZJAYQUIRHXLNFTGKDCMWB",
		"VZBRGITYUPSDNHLXAWMJQOFECK"
	};
	static const char rotors_inv[ALL_ROTORS_COUNT][ALPHABET_SIZE + 1] = {
		"UWYGADFPVZBECKMTHXSLRINQOJ",
		"AJPCZWRLFBDKOTYUQGENHXMIVS",
		"TAGBPCSDQEUFVNZHYIXJWLRKOM",
		"HZWVARTNLGUPXQCEJMBSKDYOIF",
		"QCYLXWENFTZOSMVJUDKGIARPHB"
	};
	int rotor_id = rotor_order[pos];
	int shift = rotors_shift[pos];
	int in_pin = (letter - 'A' + shift) % ALPHABET_SIZE;
	char out_char = (dir == 0) ? rotors[rotor_id][in_pin] : rotors_inv[rotor_id][in_pin];
	int out_pin = (out_char - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;

	return 'A' + out_pin;
}

void rotate_rotors(void)
{
	int i;
	static const int notches[ALL_ROTORS_COUNT] = {16, 4, 21, 9, 25};
	int middle_rotor_id = rotor_order[1];

	if (rotors_shift[1] == notches[middle_rotor_id]) {
		rotors_shift[1] = (rotors_shift[1] + 1) % ALPHABET_SIZE;
		rotors_shift[2] = (rotors_shift[2] + 1) % ALPHABET_SIZE;
	}

	for (i = 0; i < INSIDE_ROTORS_COUNT; i++) {
		rotors_shift[i] = (rotors_shift[i] + 1) % ALPHABET_SIZE;
		if (rotors_shift[i] != 0) {
			break;
		}
	}
}