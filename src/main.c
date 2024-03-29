/**
 * Notein
 * The hacker's notes manager application.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fsutils.h"
#include "note.h"

/**
 * Program's main entry point.
 *
 * @param argc Number of command line arguments provided.
 * @param argv Command line arguments.
 *
 * @return Return code.
 */
int main(int argc, char **argv) {
	DIRHANDLE dir;
	char *fname;

	/* Open the note directory. */
	dir = fs_opendir(argv[1]);
	if (dir == NULL) {
		printf("An error occurred while opening the directory '%s': %s\n",
			   argv[1], strerror(errno));
		return errno;
	}

	/* Go through the files inside of the directory. */
	fname = NULL;
	printf("Go these files:\n");
	while ((fname = fs_readdir(dir, argv[1])) != NULL) {
		note_t *note;
		char *contents;

		printf("%s\n", fname);
		note = note_from_fname(fname);
		note_debug_print(note);

		contents = note_fh_slurp(note);
		if (contents == NULL) {
			printf("An error occurred while slurping the note: %s\n",
				strerror(errno));
		}
		printf("---\n%s\n---\n", contents);
		free(contents);
		printf("\n");

		free(fname);
		fname = NULL;
		free(note);
	}

	/* Close the directory handle. */
	if (fs_closedir(dir)) {
		printf("An error occurred while closing the notes directory: %s\n",
			   strerror(errno));
		return errno;
	}

	return 0;
}
