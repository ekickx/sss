/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gapscr    = 0;       /* gap between window and screen when maximized */
static const unsigned int snap      = 32;       /* snap pixel */
static const int round_radius       = 0;        // rounded corners radius

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
/* fonts */
/* static const char *fonts[]          = { "monospace:size=10" }; */
static const char *fonts[]          = { "mononoki Nerd Font:size=10" };
/* static const char *fonts[]          = { "Fira Code:size=11" }; */

/* themes */
#include "/home/ekickx/.cache/wal/colors-wal-dwm.h"

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask    iscentered   isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,           1,           1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,      1,           0,           -1 },
  { "Thunar",   NULL,       NULL,       0,           1,           0,           -1 },
  { "tabbed",   NULL,       NULL,       0,           1,           0,           -1 },
  { "Google Chrome",  NULL,   NULL,     0,           0,           0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      NULL },    /* no layout function means floating behavior */
  { "",      tile },    /* first entry is default */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#include "moveresize.c"
#include "shiftview.c"
#include "maximize.c"

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },
	{ Mod1Mask|ShiftMask,           XK_Tab,    focusstack,     {.i = -1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ Mod1Mask,                     XK_F4,     killclient,     {0} },
	/* { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
/* Move */
  { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 5y 0w 0h"}},
  { MODKEY,                       XK_Up,     moveresize,     {.v = "0x -5y 0w 0h"}},
  { MODKEY,                       XK_Right,  moveresize,     {.v = "5x 0y 0w 0h"}},
  { MODKEY,                       XK_Left,   moveresize,     {.v = "-5x 0y 0w 0h"}},

/* resize */
  { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x -4y 0w 8h"}},
  { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 4y 0w -8h"}},
  { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "-4x 0y 8w 0h"}},
  { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "4x 0y -8w 0h"}},

  { MODKEY|ShiftMask,             XK_s,      togglemaximize, {0} },
  { Mod1Mask|ControlMask,         XK_Right,  shiftview,      {.i = +1} },
  { Mod1Mask|ControlMask,         XK_Left,   shiftview,      {.i = -1} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

