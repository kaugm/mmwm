/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/* Button definitions, nothing to edit for you */
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/* EDIT THIS: general settings */
#define MASTER_SIZE     0.5       /* master-stack ratio */
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    30        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    EQUAL     /* TILE MONOCLE BSTACK GRID FIBONACCI EQUAL */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_MOUSE    False     /* Focus the window the mouse just entered */
#define FOLLOW_WINDOW   False     /* Follow the window when moved to a different desktop */
#define CLICK_TO_FOCUS  True      /* Focus an unfocused window when clicked */
#define WIN_LIMIT		3		  /* Maximum number of windows allowed per desktop */
#define BORDER_WIDTH    8         /* window border width */
#define SCRATCH_WIDTH   0         /* scratch window border width, 0 to disable */
#define FOCUS           "#eeeeee" /* focused window border color   */
#define UNFOCUS         "#1d383e" /* unfocused window border color */
#define SCRATCH         "#cc0000" /* scratchpad border color */
#define DESKTOPS        10        /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define DEFAULT_DESKTOP 0         /* the desktop to focus on exec */
#define MINWSZ          50        /* minimum window size in pixels */
#define USELESSGAP      128         /* the size of the useless gap in pixels */
#define GLOBALGAPS      True      /* use the same gap size on all desktops */
#define MONOCLE_BORDERS False     /* display borders in monocle mode */
#define INVERT          False     /* use alternative modes by default */
#define AUTOCENTER      True      /* automatically center windows floating by default */
#define OUTPUT_TITLE    False     /* output the title of the currently active window */
#define USE_SCRATCHPAD  False     /* enable the scratchpad functionality */
#define CLOSE_SCRATCHPAD True     /* close scratchpad on quit */
#define SCRPDNAME       "scratchpad" /* the name of the scratchpad window */
/*#define EWMH_TASKBAR    True       False if text (or no) panel/taskbar */

/*
 * EDIT THIS: applicaton specific rules
 * Open applications to specified desktop with specified mode.
 * If desktop is negative, then current is assumed. Desktops are 0-indexed.
 * The matching is done via POSIX-regexes on the window title, see
 * https://en.wikipedia.org/wiki/Regular_expression#POSIX_extended for syntax
 * Sadly, this can not be empty (for now), so enter something non-existent if
 * you do not wish to use this functionality.
 */
static const AppRule rules[] = { \
    /* title regex  desktop  follow  float border_with */
    { "GNU Image",  -1,      False,  True, 0 },
    { "Firefox",    -1,      False,  False, 0 },
};

/* helper for spawning shell commands, usually you don't edit this */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/*
 * EDIT THIS: commands
 * Adjust and add these to the shortcuts below to launch anything you want by
 * pressing a key (combination). The last argument should ALWAYS be a null
 * pointer. scrpcmd needs to be defined and different from all other commands!
 */
static const char *termcmd[] = { "xterm",     NULL };
static const char *menucmd[] = { "rofi","-show","run", NULL };
static const char *scrpcmd[] = { "xterm", "-T", "scratchpad", NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,              change_desktop, {.i = N}}, \
    {  MOD4|ShiftMask,   K,              client_to_desktop, {.i = N}},

/*
 * EDIT THIS: shortcuts
 * By default, all shortcuts use only Mod4 (+ Shift/Control), but you can use
 * Mod1 as well if you like to, I just prefer not to. (Update: handling
 * floating windows makes more sense when using Mod1 as well, so there's that)
 */
static key keys[] = {
    /* modifier          key            function           argument */

    /* cycle between windows on desktop */
    {  MOD1,             XK_Tab,        next_win,          {NULL}},
    {  MOD1|SHIFT,       XK_Tab,        prev_win,          {NULL}},
    /* move tiled windows to different positions*/
    {  MOD4,             XK_Down,       move_down,         {NULL}},
    {  MOD4,             XK_Up,         move_up,           {NULL}},
    /* swap the current window with the master */
    {  MOD4,             XK_w,          swap_master,       {NULL}},
    /* maximize the current window */
    {  MOD4,             XK_f,          maximize,          {NULL}},
    /* float focused window and center it */
    {  MOD4,             XK_j,          popout,            {NULL}},
    /* toggles inverted stacking mode for TILE layout. Slaves on left/right of master */
    {  MOD4,             XK_i,          invertstack,       {NULL}},
    /* change tiling mode: TILE or EQUAL */
    {  MOD4|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    /*{  MOD4|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  MOD4|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}}, */
    {  MOD4|SHIFT,       XK_e,          switch_mode,       {.i = EQUAL}},
    {  MOD4,			 XK_m,			swap_modes,	   	   {NULL}},
    /* spawn terminal, dmenu, w/e you want to */
    {  MOD4,             XK_Return,     spawn,             {.com = termcmd}},
    {  MOD4,             XK_d,          spawn,             {.com = menucmd}},
    /* quit current window */
    {  MOD4,             XK_q,          killclient,        {NULL}},
    /* desktop selection */
       DESKTOPCHANGE(    XK_1,                             0)
       DESKTOPCHANGE(    XK_2,                             1)
       DESKTOPCHANGE(    XK_3,                             2)
       DESKTOPCHANGE(    XK_4,                             3)
       DESKTOPCHANGE(    XK_5,                             4)
       DESKTOPCHANGE(    XK_6,                             5)
       DESKTOPCHANGE(    XK_7,                             6)
       DESKTOPCHANGE(    XK_8,                             7)
       DESKTOPCHANGE(    XK_9,                             8)
       DESKTOPCHANGE(    XK_0,                             9)
    /* exit */
    {  MOD4|CONTROL,     XK_q,          quit,              {.i = 0}},
};

/* EDIT THIS: mouse-based shortcuts */
static Button buttons[] = {
    /* move/resize using the mouse */
    {  MOD4,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD4,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif

