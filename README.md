# mmWM
#### Modern Minimalistic Window Manager

mmWM is a dynamic window manager that is heavily based off of FrankenWM but 25% smaller. In fact, it is FrankenWM, but with many _unnecessary_ features stripped out, and others added. Its goal is to simplify your tiling workflow, with less, more logical hotkeys, and more automated window management.

mmWM is designed to provide an aesthetic and minimalistic desktop that prevents window overcrowding. If a desktop is _full_, mmWM will open the window on the next desktop. Likewise, if a window is the only one on a desktop, mmWM will switch to the previous desktop when the window is killed to speed up your workflow.

![mmwm thumbnail](mmwm1.jpg)
![mmwm thumbnail](mmwm2.jpg)

mmWM is lightweight. `smem` outputs USS and PSS at 368k and 409k respectively.

#### Modern and Minimalist Approach
No per-app rules. All windows start tiled and focused on current desktop (unless desktop is _full_)\
Simplified, fewer, and more logical keyboard shortcuts. All are {MOD4 + Single Key}\
Single Tiling mode: Main window + secondary & tertiary on the side
Tiled windows are interacted with by the keyboard\
Floating windows are interacted with by the mouse (except using the keyboard to pop them out and changing master window size)

Standard WM features (Can be toggled On/Off): Borders, Gaps, Panel, Follow Mouse, Multiple Desktops\


#### Added features
Automated desktop switching when opening a new window in a _full_ desktop\
Automated focusing on previous _populated_ desktop if last window on desktop is killed\
User can define the maximum number of allowed windows per desktop\
Hotkey & function to pop a window in and out of floating mode\
Hotkey to reset master window size\
Command executed when clicking on root window (the desktop)\

#### Other features
Brightness and volume XF86Keysym support for laptop keys (see Vendorkeys branch for code addition)\
Pywal Support (Must add this in manually. Follow add_pywal_support.txt\


#### TODO
BUG FIX: If a desktkop is _full_, transient windows are mapped in next available desktop, not the current one

Installation
------------

You need xcb and xcb-utils then, copy `config.def.h` as `config.h` and edit to
suit your needs.  Build and install.

    $ cp config.def.h config.h
    $ $EDITOR config.h
    $ make
    # make clean install

Dependencies:
`libxcb` `xcb-util` `xcb-util-wm` `xcb-util-keysyms`


Configuration
-------------

You can configure mmWM by editing `config.h` before compiling.\

Usage
-----

Without panel: Add the following to your `.xinitrc`

    $ exec mmwm

With Panel:\
Download a panel script from [FrankenWM's Github page](https://gist.github.com/sulami/d6a53179d6d7479e0709), make it executable, and save it somewhere (basic panel, contains function for getting desktop number and tiling mode only)

Add the following to your `.xinitrc`

    $ exec [PATH TO BAR SCRIPT]


Thanks
------

[FrankenWM by sulami](https://github.com/sulami/FrankenWM)\
[Customized Panel Scripts by shmalebx9](https://github.com/shmalebx9)\
[2bwm by venam](https://github.com/venam/2bwm)
