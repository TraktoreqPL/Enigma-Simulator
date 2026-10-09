#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#define CABLE_COUNT 10

typedef struct {
	char in_pins[CABLE_COUNT];
	char out_pins[CABLE_COUNT];
} plugboard_configuration;

extern plugboard_configuration config;

char pass_through_plugboard(const char letter);

#endif