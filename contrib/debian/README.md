
Debian
====================
This directory contains files used to package snowpuppycoind/snowpuppycoin-qt
for Debian-based Linux systems. If you compile snowpuppycoind/snowpuppycoin-qt yourself, there are some useful files here.

## snowpuppycoin: URI support ##


snowpuppycoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install snowpuppycoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your snowpuppycoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/snowpuppycoin128.png` to `/usr/share/pixmaps`

snowpuppycoin-qt.protocol (KDE)

