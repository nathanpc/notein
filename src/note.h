/**
 * note.h
 * Helps us deal with the intricacies of notes in the application.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _NOTE_H
#define _NOTE_H

#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Note abstraction object.
 */
typedef struct {
	time_t date;
	char *title;
	char *format;
} note_t;

/* Construction and destruction. */
note_t* note_new(void);
note_t* note_from_fname(const char *path);
void note_free(note_t *note);

/* Getters and setters. */
time_t note_get_date(const note_t *note);
void note_set_date(note_t *note, time_t date);
const char* note_get_title(const note_t *note);
void note_set_title(note_t *note, const char *title);
const char* note_get_format(const note_t *note);
void note_set_format(note_t *note, const char *format);

/* Debugging */
void note_debug_print(const note_t *note);

#ifdef __cplusplus
}
#endif

#endif /* _NOTE_H */
