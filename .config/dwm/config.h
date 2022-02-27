// spDE dwm configuration
static const unsigned int borderpx            = 1;
static const unsigned int snap                = 32;
static const unsigned int gappx               = 4;
static const int showbar                      = 1;
static const int topbar                       = 1;
static const char *fonts[]                    = { "Terminus:size=8", "fontawesome:size=8" };
static const char col_background[]            = "#222222"; // dwm dark bg & slstatus bg
static const char col_backgroundmid[]         = "#222222"; // dwm middle background
static const char col_textnorm[]              = "#bbbbbb"; // application title bar/font for norm
static const char col_textsel[]               = "#eeeeee"; // dwm text/font for selected
static const char col_windowbordernorm[]      = "#5757ff"; // dwm norm window border
static const char col_windowbordersel[]       = "#5757ff"; // dwm sel window border
static const unsigned int baralpha            = 0xd0;
static const unsigned int borderalpha         = OPAQUE;
static const float mfact                      = 0.50;
static const int nmaster                      = 1;
static const int resizehints                  = 1;
static char dmenumon[2]                       = "0";
static const char *dmenucmd[]                 = { NULL };
static const char *termcmd[]                  = { NULL };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const char *alttags[] = { "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]" };
static const char *colors[][3]      = {
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
	{ "Chromium",  NULL,       NULL,       2 << 9,       0,            0,           -1 },
	{ "urxvt",     NULL,       NULL,       3 << 9,       0,            0,           -1 },
	{ "mocp",      NULL,       NULL,       5 << 9,       1,            0,           -1 },
        { "alsamixer", NULL,       NULL,       0,            1,            0,           -1 },
};

#include "layouts.c"
static const Layout layouts[] = {
        { "",          tile },
	{ "",          NULL },
	{ "",       monocle },
	{ "",          grid },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ShiftMask,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD("dmenu_run") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("/usr/local/bin/.spDE/st/st") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("mkdir -pv ~/Screenshots") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("cd ~/Screenshots && touch .TempScreenshot.png") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("cd ~/Screenshots && rm -rf ~/Screenshots/.TempScreenshot.png && scrot '.TempScreenshot.png' -s -b -p -q 100 && xclip -in -selection clipboard -target image/png ~/Screenshots/.TempScreenshot.png && killall scrot") },
        { MODKEY|ControlMask,           XK_s,      spawn,          SHCMD("cd ~/Screenshots && rm -rf ~/Screenshots/.TempScreenshot.png && scrot '.TempScreenshot.png' -b -p -q 100 && xclip -in -selection clipboard -target image/png ~/Screenshots/.TempScreenshot.png && killall scrot") },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st fff") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("librewolf || firefox || chromium || chrome") },
	{ ControlMask|ShiftMask,        XK_d,      spawn,          SHCMD("librewolf https://discord.com/channels/@me || firefox https://discord.com/channels/@me") },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st htop") },
	{ ControlMask|MODKEY,           XK_x,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st btop --utf-force") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD("obs") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st alsamixer") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st mocp -T transparent-background") }, 
	{ MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st /usr/bin/setwallpaper") }, 
	{ MODKEY|ControlMask,           XK_h,      spawn,          SHCMD("/usr/local/bin/.spDE/st/st nvim /usr/local/bin/.spDE/dwm/keybinds") },
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
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("/usr/local/bin/.spDE/st/st") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

