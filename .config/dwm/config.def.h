// spDE dwm configuration
// https://spdgmr.github.io/spde

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } } // Change if you're going to use a different shell.

static unsigned int borderpx                  = 1;
static unsigned int snap                      = 32;
static const unsigned int gappx               = 5;
static int showbar                            = 1;
static int topbar                             = 1;
static char font[]                            = "Terminus:size=8";
static const char *fonts[]                    = { font };
static char col_background[]                  = "#222222"; // dwm dark bg & slstatus bg
static char col_backgroundmid[]               = "#222222"; // dwm middle background
static char col_textnorm[]                    = "#bbbbbb"; // application title bar/font for norm
static char col_textsel[]                     = "#eeeeee"; // dwm text/font for selected
static char col_windowbordernorm[]            = "#5757ff"; // dwm norm window border
static char col_windowbordersel[]             = "#5757ff"; // dwm sel window border
static const unsigned int baralpha            = 0xd0;
static const unsigned int borderalpha         = OPAQUE;
static float mfact                            = 0.50;
static int nmaster                            = 1;
static int resizehints                        = 0;
static char dmenumon[2]                       = "0";
static const char *dmenucmd[]                 = { NULL };
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *alttags[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]" };
static char *colors[][3]      = {
	[SchemeNorm] = { col_textnorm, col_background, col_windowbordernorm },
	[SchemeSel]  = { col_textsel, col_backgroundmid, col_windowbordersel }, 
//                       text         background         window border
};

static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const Rule rules[] = {
    	/* class       instance    title       tags mask     CenterFirst   isfloating   monitor */
        { "st",        NULL,       NULL,       3 << 9,       0,            0,           -1 },
	    { "Firefox",   NULL,       NULL,       2 << 9,       0,            0,           -1 },
		{ "Librewolf", NULL,       NULL,       2 << 9,       0,            0,           -1 },
		{ "urxvt",     NULL,       NULL,       3 << 9,       0,            0,           -1 },
};

#include "layouts.c"
static const Layout layouts[] = {
    { "",          tile },
	{ "",          NULL },
	{ "",       monocle },
	{ "",          grid },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ShiftMask,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

ResourcePref resources[] = {
       { "font",                 STRING,  &font },
       { "col_background",       STRING,  &col_background },
       { "col_backgroundmid",    STRING,  &col_backgroundmid },
       { "col_textnorm",         STRING,  &col_textnorm },
       { "col_windowbordersel",  STRING,  &col_windowbordersel },
       { "col_windowbordernorm", STRING,  &col_windowbordernorm },
       { "col_textsel",          STRING,  &col_textsel },
       { "borderpx",             INTEGER, &borderpx }, 
	   { "snap",                 INTEGER, &snap },
       { "showbar",              INTEGER, &showbar },
       { "topbar",               INTEGER, &topbar },
       { "nmaster",              INTEGER, &nmaster },
       { "resizehints",          INTEGER, &resizehints },
       { "mfact",                FLOAT,   &mfact },
};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD("/usr/bin/dmenu_run || dmenu_run") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("/usr/local/bin/.spDE/st/st") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("maim -sB | xclip -selection clipboard -t image/png") },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("$TERMINAL fff || $TERMINAL ranger") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,             XK_t,	   spawn,          SHCMD("$TERMINAL $EDITOR") },
        { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("killall $BROWSER || pkill $BROWSER") },
        { MODKEY|ControlMask,           XK_m,      spawn,          SHCMD("killall mocp || pkill mocp") },
	{ ControlMask|ShiftMask,        XK_y,      spawn,          SHCMD("$TERMINAL yt || $TERMINAL ytfzf") },
	{ ControlMask|MODKEY,           XK_y,      spawn,          SHCMD("$TERMINAL rss || $TERMINAL newsboat") },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("$TERMINAL htop") },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("$TERMINAL /usr/bin/setwallpaper") },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("$TERMINAL cat /usr/local/bin/.spDE/dwm/keybinds | less") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("$TERMINAL alsamixer || $TERMINAL pulsemixer") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("$TERMINAL mocp -T transparent-background $MUSICDIR") }, 
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, 
	{ MODKEY,                       XK_a,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_d,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ControlMask,           XK_e,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_r,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_d,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("$TERMINAL") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

