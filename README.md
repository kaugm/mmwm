# mmWM
#### Modern Minimalistic Window Manager (WIP, stripped down FrankenWM)

mmWM is a dynamic window manager that is heavily based off of FrankenWM. In fact, it is FrankenWM, but with many _unnecessary_ functions removed (and some unique features added). mmWM is designed to emulate a simple tiling workflow, but without the 10+ hotkeys to manage windows. 

mmWM is designed to prevent window overcrowding on the desktop. If a desktop is _full_, mmWM will open the window on the next desktop. Likewise, if a window is the only one on a desktop, mmWM will switch to the previous desktop when the window is closed (TODO).

#### Modern and Minimalist Approach
heavy gaps\
simplified, fewer, and more logical keyboard shortcuts\
3 modes: Tile (master/slave), Equal, (and floating on a per window basis)
Tiled windows are interacted with by the keyboard\
Floating windows are interacted with by the mouse (except using the keyboard to pop them out)\


#### Added features
#### --------------
Opens window in next desktop if current desktop is full
Switches to previous desktop if last window on desktop is killed
Disabled inverting stack in equal mode (no horizontally maximized windows because they're ugly)
Hotkey & function to swap between the 2 main tiling modes
Hotkey & function to pop a window in and out of floating mode

# _From FrankenWM_

Installation
------------

~~Note: If you are on Arch Linux, you can use the [AUR][aur].~~

You need xcb and xcb-utils then, copy `config.def.h` as `config.h` and edit to
suit your needs.  Build and install.

    $ cp config.def.h config.h
    $ $EDITOR config.h
    $ make
    # make clean install

The packages in Arch Linux needed for example would be
`libxcb` `xcb-util` `xcb-util-wm` `xcb-util-keysyms`

  ~~[aur]: https://aur.archlinux.org/packages/frankenwm-git/~~

Configuration
-------------

You can configure mmWM by editing `config.h` before compiling.

Usage
-----

man mmwm

Thanks
------

[FrankenWM by sulami](https://github.com/sulami/FrankenWM)


