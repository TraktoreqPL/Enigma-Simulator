#ifndef ROTORS_H
#define ROTORS_H

#define ALPHABET_SIZE 26
#define INSIDE_ROTORS_COUNT 3

extern int rotor_order[INSIDE_ROTORS_COUNT];
extern int rotors_shift[INSIDE_ROTORS_COUNT];

char pass_through_rotor(const int pos, const int dir, const char letter);

void rotate_rotors(void);

#endif