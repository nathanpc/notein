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
	return string_copy_until(dest, src, '\0');
}

/**
 * Copies a string until a character (non-inclusive). Will allocate (reallocate
 * if needed) the destination string automatically and NULL terminate always.
 *
 * @warning This function will allocate memory for dest. Make sure you free this
 *          string later.
 *
 * @param dest Destination string. (Will be [re]allocated by this function.)
 * @param src  Source string to be copied.
 * @param c    Character to stop copying at. (Won't be included)
 *
 * @return Number of bytes copied.
 */
size_t string_copy_until(char **dest, const char *src, char c) {
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
	len = 0;
	dest_buf = *dest;
	src_buf = src;
	while (*src_buf != c) {
		*dest_buf = *src_buf;

		src_buf++;
		dest_buf++;
		len++;
	}

	/* Ensure the NULL termination of the string. */
	*dest_buf = '\0';
	len++;

	return len;
}

/**
 * Copies a string until a point inside of it (non-inclusive). Will allocate
 * (reallocate if needed) the destination string automatically and NULL
 * terminate always.
 *
 * @warning This function will allocate memory for dest. Make sure you free this
 *          string later.
 *
 * @param dest Destination string. (Will be [re]allocated by this function.)
 * @param src  Source string to be copied.
 * @param p    Point inside of source to stop copying at. (Won't be included)
 *
 * @return Number of bytes copied.
 */
size_t string_copy_untilp(char **dest, const char *src, const char *p) {
	size_t len;
	char *dest_buf;
	const char *src_buf;

	/* Check if we have a valid destination pointer. */
	if (dest == NULL)
		return 0;

	/* Allocate space for the new string. */
	len = p - src;
	*dest = (char *)realloc(*dest, (len + 1) * sizeof(char));

	/* Copy the new string over. */
	len = 0;
	dest_buf = *dest;
	src_buf = src;
	while (src_buf != p) {
		*dest_buf = *src_buf;

		src_buf++;
		dest_buf++;
		len++;
	}

	/* Ensure the NULL termination of the string. */
	*dest_buf = '\0';
	len++;

	return len;
}
