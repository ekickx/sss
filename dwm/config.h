/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
	"mononoki Nerd Font:Regular:size=13:antialias=true:autohint=true"
};
static const char dmenufont[]       = "monospace:size=10";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gapscr    = 13;       /* gap between screen */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int round_radius       = 4;        // rounded corners radius
static const int round_all          = 0;        // whether or not to round everything up, reminder that fullscreen mode will also be included
static const int round_active       = 1;

#define NUMCOLORS 9
static const char colors[NUMCOLORS][MAXCOLORS][9] = {
	// border	 foreground	  background
	{ "#C8BAE9",	 "#18738C", 	  "#001E3B" },  // 0 = normal
	{ "#D2D28C", 	 "#a8c7c0", 	  "#001E3B" },  // 1 = selected
	{ "#b43030", 	 "#f5f5f5", 	  "#b23450" },  // 2 = red / urgent
	{ "#212121", 	 "#f5f5f5", 	  "#14161A" },  // 3 = green / occupied
	{ "#212121", 	 "#ab7438", 	  "#0b0606" },  // 4 = yellow
	{ "#212121", 	 "#475971", 	  "#0b0606" },  // 5 = blue
	{ "#212121", 	 "#694255", 	  "#0b0606" },  // 6 = cyan
	{ "#212121", 	 "#3e6868", 	  "#0b0606" },  // 7 = magenta
	{ "#212121",	 "#cfa696", 	  "#0b0606" },  // 8 = grey
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask    iscentered   isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,           1,           1,           -1 },
	{ "Iceweasel",  NULL,       NULL,       1 << 8,    1,           0,           -1 },
  { "Thunar",  NULL,        NULL,       0,           1,           0,           -1 },
  { "tabbed",  NULL,   NULL,       0,           1,           0,           -1 },
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
#include <X11/XF86keysym.h>
#include "moveresize.c"
#include "shiftview.c"
#include "maximize.c"

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "tabbed", "-c", "-r", "2", "st", "-w", "''", NULL };
static const char *filemngr[]  = { "thunar", NULL };
static const char *volup[]  = { "/home/ekickx/.commands/volume.sh", "up", NULL };
static const char *voldown[]  = { "/home/ekickx/.commands/volume.sh", "down", NULL };
static const char *voltogg[]  = { "/home/ekickx/.commands/volume.sh", "mute", NULL };
static const char *brightup[]  = { "/home/ekickx/.commands/brightness.sh", "up", NULL };
static const char *brightdown[]  = { "/home/ekickx/.commands/brightness.sh", "down", NULL };
static const char *skippy[]  = { "skippy-xd", "--toggle-window-picker", NULL };
static const char *menu[]  = { "jgmenu_run", NULL };
static const char *scrot[]  = { "/home/ekickx/.commands/screenshot.sh", NULL };
static const char *centered[]  = { "/home/ekickx/.commands/center.sh", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd} },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd} },
  { Mod1Mask,                     XK_slash,  spawn,          {.v = skippy} },
  { MODKEY|ControlMask,             XK_s,      spawn,          {.v = menu} },
  { MODKEY|ShiftMask,             XK_t,      spawn,          {.v = filemngr} },
	{ 0,                            XK_Print,  spawn,          {.v = scrot} },
  { MODKEY,                       XK_s,      spawn,          {.v = centered} },
  /* { MODKEY,                       XK_b,      togglebar,      {0} }, */
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },
	{ Mod1Mask|ShiftMask,           XK_Tab,    focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	/* { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { Mod1Mask,                     XK_F4,     killclient,     {0} },
/* Move */
  { MODKEY,                       XK_Down,        moveresize,         {.v = "0x 15y 0w 0h"}},
  { MODKEY,                       XK_Up,          moveresize,         {.v = "0x -15y 0w 0h"}},
  { MODKEY,                       XK_Right,       moveresize,         {.v = "15x 0y 0w 0h"}},
  { MODKEY,                       XK_Left,        moveresize,         {.v = "-15x 0y 0w 0h"}},

/* resize */
  { MODKEY|ShiftMask,             XK_Down,        moveresize,         {.v = "0x 0y 0w 25h"}},
  { MODKEY|ShiftMask,             XK_Up,          moveresize,         {.v = "0x 0y 0w -25h"}},
  { MODKEY|ShiftMask,             XK_Right,       moveresize,         {.v = "0x 0y 25w 0h"}},
  { MODKEY|ShiftMask,             XK_Left,        moveresize,         {.v = "0x 0y -25w 0h"}},

  { MODKEY|ShiftMask,           XK_s,     togglemaximize, {0} },
  { Mod1Mask|ControlMask,       XK_Right, shiftview,      {.i = +1} },
  { Mod1Mask|ControlMask,       XK_Left,  shiftview,      {.i = -1} },
  TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
  { 0,            XF86XK_AudioMute,         spawn,           {.v = voltogg } },
	{ 0,            XF86XK_AudioLowerVolume,  spawn,           {.v = voldown } },
  { 0,            XF86XK_AudioRaiseVolume,  spawn,           {.v = volup } },
  { 0,            XF86XK_MonBrightnessUp,   spawn,           {.v = brightup } },
	{ 0,            XF86XK_MonBrightnessDown, spawn,           {.v = brightdown } },
 { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
 { MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkRootWin,           0,              Button3,        spawn,          {.v = menu} },
	/* { ClkClientWin,         0,              Button1,        togglefloating, {0} }, */
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
