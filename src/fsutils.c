/**
 * fsutils.c
 * Some utilities for working with the filesystem.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "fsutils.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * Opens a directory handle for us to operate on.
 *
 * @param path Path to the directory.
 *
 * @return Directory handle or NULL in case of an error.
 */
DIRHANDLE fs_opendir(const char* path) {
	return opendir(path);
}

/**
 * Gets an item from a directory.
 * @warning This function allocates its return value. You are responsible for
 * freeing it.
 *
 * @param hnd  Directory handle.
 * @param path Path to the directory.
 *
 * @return Path to a regular file name in the directory or NULL if no more items
 *         are available. (This is allocated internally and must be free'd)
 */
char* fs_readdir(DIRHANDLE hnd, const char *path) {
	const struct dirent* de;
	struct stat st;
	char *fname;

	/* Try to get the first regular file in the directory. */
	fname = NULL;
	while ((de = readdir(hnd)) != NULL) {
		/* Ignore dotfiles. */
		if (de->d_name[0] == '.')
			continue;

		/* Construct a proper path to the file. */
		fname = (char*)realloc(fname,
			(strlen(de->d_name) + strlen(path) + 2) * sizeof(char));
		strcpy(fname, path);
		strcat(fname, "/");
		strcat(fname, de->d_name);
		/* TODO: Improve this and make it platform-independent. */

		/* Get some data on the item. */
		stat(fname, &st);

		/* Check if we are dealing with a regular file. */
		if (S_ISREG(st.st_mode))
			return fname;
	}

	/* Looks like we've reached the end of the file listing. */
	return NULL;
}

/**
 * Closes an open directory handle.
 *
 * @param hnd Directory handle.
 *
 * @return 0 on success.
 *         -1 on error.
 */
int fs_closedir(DIRHANDLE hnd) {
	return closedir(hnd);
}
