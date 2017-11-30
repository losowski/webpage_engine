#!/bin/sh
#
# Build the CDN (or local file)
#
echo $PWD
PROJHOME= echo $PWD | sed 's/sh//'
echo $PROJHOME
PROJHOME_CSS= echo $PWD | sed 's/sh/css\/\*\.css/'
echo $PROJHOME_CSS
(
	cd $HOME/www
	## CSS
	for file in $(ls $(echo $PROJHOME_CSS)); do echo $file; ln -s $file; done
)
PROJHOME_JAVASCRIPT= echo $PWD | sed 's/sh/javascript\/\*\.js/'
echo $PROJHOME_JAVASCRIPT
(
	cd $HOME/www
	## Javascript#
	for file in $(ls $(echo $PROJHOME_JAVASCRIPT)); do echo $file; ln -s $file; done
	## Images
)
