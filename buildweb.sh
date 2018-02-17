#!/bin/sh
# Build a complete repo
BUILDDIR=/tmp
if [ $# -ge 1 ]; then
	BUILDDIR=$1
else
	echo "Setting default BUILDDIR"
fi
echo "Building web_engine in "$BUILDDIR
mkdir $BUILDDIR
cd $BUILDDIR
git clone ssh://eugene@Gears/home/eugene/git/web_engine_repo webengine
cd webengine
git checkout B_DEV_MENU_BIN_V2
(
	cd python
	./buildCMS.py
)
echo $PWD
(
	cd cpp/libhtml
	echo $PWD
	make local_install
)
(
	cd cpp/libwebpage
	make local_install
)
(
	cd cpp/libwebcms
	make local_install
)
(
	cd cpp/binwebcms
	make local_install
)
