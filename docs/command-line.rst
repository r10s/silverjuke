==========
silverjuke
==========

Play and organize your music
----------------------------

:Date:            2016-02-09
:Version:         16.2
:Manual section:  1


SYNOPSIS
========

**silverjuke** [*options*] [*FILES*]


DESCRIPTION
===========

This manual page documents briefly the **silverjuke** command.
It can be used to play and organize your music collection.


OPTIONS
=======

This program follows the usual GNU command line syntax, with long options
starting with two dashes ('**-**'). **silverjuke** supports the following options:

--ini=FILE
  set the configuration file to use to FILE

--jukebox=FILE
  set the jukebox file to use to FILE

--temp=DIRECTORY
  set the temporary directory to use to DIRECTORY

--play
  start playing the current file

--pause
  pause the playback

--toggle
  toggle play/pause

--prev
  play previous file in list

--next
  play next file in list

--kiosk
  start Silverjuke in kiosk mode

--minimize
  start Silverjuke minimized

--open FILES
  open the given FILES, --open may be omitted

--enqueue FILES
  enqueue the given FILES

--help
  Show all available commands

--addcredit=NUM
  Adds the number of credits (tracks that may be enqueued) to the credit system.
  This option only works if the option "Credits may be added by external
  programs" is enabled in the kiosk mode settings.

--setcredit=NUM
  Sets the number of credits.  This option only works if the option "Credits may
  be added by external programs" is enabled in the kiosk mode settings.

--skiperrors
  With this option you can avoid showing errors about an erroneous termination
  on the last Silverjuke run. This is especially useful when turning off
  Silverjuke using the "Power off" button, as in this case the operating system
  may not give us the time we need to unload all modules completely.

--instance=INI-FILE
  If you give a different INI-file to each instance, you can use multiple
  instances of Silverjuke with this option. All settings for each instance are
  stored in the INI-file, so the instances are completely independent; however,
  make sure, there are no conflicts regarding the used hardware.
  You can give the INI-files as complete paths; if the files do not exist, they
  are created as needed.

  If you want to use different music libraries for each instance, you have to
  use the --jukebox=FILE option as described above.

--update
  This will automatically update the index as if you hit F5 just after starting
  Silverjuke. If you use this option in combination with --kiosk and the kiosk
  mode is running with limited functionality, the update process cannot be
  aborted.

--kioskrect=DISPLAY|X,Y,W,H[,clipmouse]
  With this option you can force the Silverjuke window to the given rectangle
  when using the kiosk mode. This is useful if you want to show sth. beside the
  Silverjuke window (by default, the whole screen is used).

  Moreover, if you add the "clipmouse" modifier, the mouse cannot be moved
  outside the given rectangle. Instead of X,Y,W,H you can also give a simple
  DISPLAY number, the first display has the number 1.

--visrect=DISPLAY|X,Y,W,H
  Assign a static portion of the screen to the visualization. Instead of X,Y,W,H
  you can also give a simple DISPLAY number, the first display has the number 1.

--blackrect=DISPLAY|X,Y,W,H[;DISPLAY|X,Y,W,H;...]
  Areas to cover by black rectangles. Instead of X,Y,W,H you can also give a 
  simple DISPLAY number, the first display has the number 1.

--volup
  increase the main volume

--voldown
  decrease the main volume

--togglevis
  toggle the selected visualizations on and off

--execute=SCRIPT_OR_FILE
  Execute the given script snippet or file. With this command line option you
  are able to execute any little script by the command line. For scripting
  details, please refer to the Silverjuke SDK. Instead of using the command line
  for this purpose, you can also use DDE, which, however, is a little bit more tricky.

Although there is always only one instance of Silverjuke running, you may call
Silverjuke with these commands which will then be forwarded to the running
instance if possible.

You can set the "db", "temp", "kiosk" and "minimize" options also manually to
the current configuration file (ini file) in the section "main".

Most commands are also available through TCP/IP communication.


AUTHOR
======

Björn Petersen <r10s@b44t.com>
