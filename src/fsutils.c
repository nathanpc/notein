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
#include <unistd.h>

#include "strutils.h"

/**
 * Appends a path to an existing path.
 * @warning This function will 'realloc' the path. You are responsible for
 *          freeing this allocated memory.
 *
 * @param path   Path that will be resized and have another part appended to.
 * @param append Path to be appended. May or may not start with a separator.
 *
 * @return Number of characters appended to the original path.
 */
size_t fs_pathcat(char **path, const char *append) {
	size_t len;
	size_t len_buf;
	char *cur;
	const char *buf;

	/* Get the sizes. */
	len = strlen(*path);
	len_buf = strlen(append);

	/* Do we need to make space for the path separator? */
	if ((append[0] != PATH_SEP) &&
			((*path == NULL) || ((*path)[len - 1] != PATH_SEP))) {
		len_buf++;
	}

	/* Allocate enough space for us append the path and set our cursor. */
	*path = (char *)realloc(*path, (len + len_buf + 1) * sizeof(char));
	cur = *path + len;
	len_buf = 0;

	/* Append the path separator if needed. */
	if ((*(cur - 1) != PATH_SEP) && (append[0] != PATH_SEP)) {
		*cur = PATH_SEP;
		cur++;
		len++;
	}

	/* Append the rest of the path. */
	buf = append;
	while (*buf != '\0') {
		*cur = *buf;

		cur++;
		buf++;
		len++;
	}

	/* Ensure the NULL termination of the string. */
	*cur = '\0';

	return len_buf;
}

/**
 * Checks if a file exists in the file system.
 *
 * @param fname File path to be checked.
 *
 * @return Does this file exist?
 */
bool fs_exists(const char *fname) {
	return access(fname, F_OK) == 0;
}

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
 * @param hnd      Directory handle.
 * @param basepath Path to the directory.
 *
 * @return Path to a regular file name in the directory or NULL if no more items
 *         are available. (This is allocated internally and must be free'd)
 */
char* fs_readdir(DIRHANDLE hnd, const char *basepath) {
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
		string_copy(&fname, basepath);
		fs_pathcat(&fname, de->d_name);

		/* Get some data on the item. */
		stat(fname, &st);

		/* Check if we are dealing with a regular file. */
		if (S_ISREG(st.st_mode))
			return fname;
	}

	/* Looks like we've reached the end of the file listing. */
	if (fname)
		free(fname);
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
