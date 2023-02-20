/**
 * fsutils.h
 * Some utilities for working with the filesystem.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _FSUTILS_H
#define _FSUTILS_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Platform-agnostic representation of a directory separator. */
#ifdef _WIN32
	#define PATH_SEP '\\'
#else
	#define PATH_SEP '/'
#endif /* _WIN32 */

/* Platform-agnostic directory handle. */
typedef DIR* DIRHANDLE;

/* Directory operations. */
DIRHANDLE fs_opendir(const char* path);
char* fs_readdir(DIRHANDLE hnd, const char* basepath);
int fs_closedir(DIRHANDLE hnd);

/* File path operations. */
bool fs_exists(const char *fname);
size_t fs_pathcat(char **path, const char *append);

#ifdef __cplusplus
}
#endif

#endif /* _FSUTILS_H */
