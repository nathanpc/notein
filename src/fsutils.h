/**
 * fsutils.h
 * Some utilities for working with the filesystem.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _FSUTILS_H
#define _FSUTILS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Platform-agnostic directory handle. */
typedef DIR* DIRHANDLE;

/* Directory operations. */
DIRHANDLE fs_opendir(const char* path);
char* fs_readdir(DIRHANDLE hnd, const char* path);
int fs_closedir(DIRHANDLE hnd);

#ifdef __cplusplus
}
#endif

#endif /* _FSUTILS_H */
