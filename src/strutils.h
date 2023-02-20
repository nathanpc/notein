/**
 * strutils.h
 * Some utilities for working with the dreaded C strings.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _STRUTILS_H
#define _STRUTILS_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* String copying. */
size_t string_copy(char **dest, const char *src);
size_t string_copy_until(char **dest, const char *src, char c);
size_t string_copy_untilp(char **dest, const char *src, const char *p);

#ifdef __cplusplus
}
#endif

#endif /* _STRUTILS_H */
