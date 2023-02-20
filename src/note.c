/**
 * note.c
 * Helps us deal with the intricacies of notes in the application.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "note.h"

#include <stdio.h>
#include <string.h>

#include "fsutils.h"
#include "strutils.h"

/**
 * Allocates a brand new note object.
 * @warning The object allocated by this function must be free'd after use.
 *
 * @return Brand new note object.
 *
 * @see note_free
 */
note_t* note_new(void) {
	note_t* note;

	/* Allocate enough memory for our object. */
	note = (note_t *)malloc(sizeof(note_t));

	/* Populate the note with some defaults. */
	note->date = time(NULL);
	note->title = NULL;
	note->format = NULL;

	return note;
}

/**
 * Frees up any resources allocated by a note object.
 *
 * @param note Note object to be free'd.
 */
void note_free(note_t *note) {
	/* Do we even have anything to do? */
	if (note == NULL)
		return;

	/* Free the fields. */
	if (note->title)
		free(note->title);
	if (note->format)
		free(note->format);

	/* Free the object itself. */
	free(note);
	note = NULL;
}

/**
 * Allocates a brand new note object from a note's file name.
 * @warning The object allocated by this function must be free'd after use.
 *
 * @param path Path to a note.
 *
 * @return Brand new note object or NULL if we couldn't parse the necessary
 *         information from the file name.
 *
 * @see note_free
 */
note_t* note_from_fname(const char *path) {
	const char *fname;
	note_t *note;
	struct tm _tm;
	time_t _time;
	const char *buf;
	int n;

	/* Set things up. */
	fname = fs_basename(path);
	note = note_new();
	_time = time(NULL);
	memcpy(&_tm, localtime(&_time), sizeof(struct tm));

	/* Try to parse the data out of the filename. */
	n = sscanf(fname, "%u-%u-%u_", &_tm.tm_year, &_tm.tm_mon, &_tm.tm_mday);
	if (n != 3) {
		fprintf(stderr, "Couldn't properly parse date from filename. Parsed %d "
				"items.\n", n);

		free(note);
		return NULL;
	}

	/* Fix the year field and assign the date. */
	_tm.tm_year -= 1900;
	note_set_date(note, mktime(&_tm));

	/* Get note title. */
	buf = strrchr(fname, '_');
	string_copy_until(&note->title, buf + 1, '.');
	/* TODO: Change this to accommodate titles with dots in them. */

	/* Get the note format. */
	note_set_format(note, fs_extname(fname));

	return note;
}

/**
 * Gets the date of the note object.
 *
 * @param note Note object.
 *
 * @return Date of the note.
 */
time_t note_get_date(const note_t *note) {
	return note->date;
}

/**
 * Sets the date of the note object.
 *
 * @param note Note object.
 * @param date New date of the note.
 */
void note_set_date(note_t *note, time_t date) {
	note->date = date;
}

/**
 * Gets the title of the note object.
 *
 * @param note Note object.
 *
 * @return Title of the note.
 */
const char* note_get_title(const note_t *note) {
	return note->title;
}

/**
 * Sets the title of the note object.
 *
 * @param note  Note object.
 * @param title New title of the note.
 */
void note_set_title(note_t *note, const char *title) {
	string_copy(&note->title, title);
}

/**
 * Gets the format of the note object.
 *
 * @param note Note object.
 *
 * @return Format of the note.
 */
const char* note_get_format(const note_t *note) {
	return note->format;
}

/**
 * Sets the format of the note object.
 *
 * @param note   Note object.
 * @param format New format of the note.
 */
void note_set_format(note_t *note, const char *format) {
	string_copy(&note->format, format);
}

/**
 * Gets the canonical filename for a note.
 *
 * @warning This function will allocate memory for its return value. Make sure
 *          you free this string later.
 *
 * @param note Note object.
 *
 * @return Allocated string with the canonical filename for this note.
 */
char* note_get_fname(note_t *note) {
	char *fname;
	const struct tm *time;
	char dates[11];

	/* Get date-related stuff. */
	time = localtime(&note->date);
	strftime(dates, sizeof(dates), "%Y-%m-%d", time);

	/* Allocate enough space for our filename. */
	fname = (char *)malloc(
		(strlen(note->title) + strlen(note->format) + 13) * sizeof(char));

	/* Copy the string over. */
	sprintf(fname, "%s_%s.%s", dates, note->title, note->format);

	return fname;
}

/**
 * Prints out everything about the note for debugging purposes.
 *
 * @param note Note object.
 */
void note_debug_print(const note_t *note) {
	const struct tm *time;
	char dates[11];

	/* Get date-related stuff. */
	time = localtime(&note->date);
	strftime(dates, sizeof(dates), "%Y-%m-%d", time);


	printf("\"note\": {\n");
	printf("    \"date\": \"%s\"\n", dates);
	printf("    \"title\": \"%s\"\n", note->title);
	printf("    \"format\": \"%s\"\n", note->format);
	printf("}\n");
}
