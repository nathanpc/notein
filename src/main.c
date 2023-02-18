/**
 * Notein
 * The hacker's notes manager application.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * Program's main entry point.
 *
 * @param argc Number of command line arguments provided.
 * @param argv Command line arguments.
 *
 * @return Return code.
 */
int main(int argc, char **argv) {
	int i;
	printf("notein\n\n");

	printf("Arguments:\n");
	for (i = 0; i < argc; i++) {
		printf("   - \"%s\"\n", argv[i]);
	}

	return 0;
}
