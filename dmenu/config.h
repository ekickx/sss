/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int fuzzy = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

/* ------------- Font -------------- */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
  "mononoki Nerd Font:size=10"
  /* "monospace:size=10" */
};
/* -------------------------------- */

/* ------------- Theme ------------ */
#include "/home/ekickx/.cache/wal/colors-wal-dmenu.h"
/* -------------------------------- */

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
static unsigned int lineheight = 0;         /* -h option; minimum height of a menu line     */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
