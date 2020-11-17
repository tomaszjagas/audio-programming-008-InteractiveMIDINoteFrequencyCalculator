/******************************************************
Description: Interactive MIDI Note frequency calculator
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double c5, c0, semitoneRatio, frequency;
	int midinote;
	char message[256];
	char* result;

	// necessary initial calculations
	semitoneRatio = pow(2, 1.0 / 12);
	c5 = 220.0 * pow(semitoneRatio, 3);
	c0 = c5 * pow(0.5, 5);

	printf("Enter MIDI note (0 - 127): ");
	result = gets(message);

	if (result == NULL) {
		printf("There was an error reading the input.\n");
		return 1;
	}
	if (message[0] == '\0') {
		printf("Have a nice day!\n");
		return 1;
	}
	
	midinote = atoi(message);
	if (midinote < 0) {
		printf("Sorry - %s is a bad MIDI note number\n", message);
		return 1;
	}
	if (midinote > 127) {
		printf("Sorry - %s is beyond the MIDI range!\n", message);
		return 1;
	}

	frequency = c0 * pow(semitoneRatio, midinote);
	printf("Frequency of MIDI note %d = %.2f Hz\n", midinote, frequency);

	return 0;
}