/**
 * strutils.c
 * Some utilities for working with the dreaded C strings.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include <stdio.h>
#include <string.h>

#include "strutils.h"

/**
 * Similar to strcpy except we allocate (reallocate if needed) the destination
 * string automatically.
 *
 * @warning This function will allocate memory for dest. Make sure you free this
 *          string later.
 *
 * @param dest Destination string. (Will be [re]allocated by this function.)
 * @param src  Source string to be copied.
 *
 * @return Number of bytes copied.
 */
size_t string_copy(char **dest, const char *src) {
	size_t len;
	char *dest_buf;
	const char *src_buf;

	/* Check if we have a valid destination pointer. */
	if (dest == NULL)
		return 0;

	/* Allocate space for the new string. */
	len = strlen(src);
	*dest = (char *)realloc(*dest, (len + 1) * sizeof(char));

	/* Copy the new string over. */
	dest_buf = *dest;
	src_buf = src;
	while (*src_buf != '\0') {
		*dest_buf = *src_buf;

		src_buf++;
		dest_buf++;
	}

	/* Ensure the NULL termination of the string. */
	*dest_buf = '\0';

	return len;
}
