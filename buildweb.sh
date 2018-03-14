#!/bin/sh
# Build a complete repo
BUILDDIR=/tmp
GITBRANCH=master
if [ $# -ge 1 ]; then
	GITBRANCH=$1
else
	echo "WARN:	Checking out master by default"
fi
if [ $# -ge 2 ]; then
	BUILDDIR=$2
	echo
else
	echo "WARN: Setting default BUILDDIR"
fi
echo "Building web_engine in "$BUILDDIR
mkdir $BUILDDIR
cd $BUILDDIR
git clone ssh://eugene@Gears/home/eugene/git/web_engine_repo webengine
cd webengine
git checkout $GITBRANCH
git submodule init
git submodule update --init
git submodule foreach checkout $GITBRANCH
(
	cd python
	./buildCMS.py
)
if [ $# -ge 3 ]; then
	echo $PWD
	MAKEPARAM=$3
	if [ $MAKEPARAM = "local_install" ] ; then
		(
			cd cpp/libhtml
			make $MAKEPARAM
		)
		(
			cd cpp/libwebpage
			make $MAKEPARAM
		)
		(
			cd cpp/libwebcms
			make $MAKEPARAM
		)
		(
			cd cpp/binwebcms
			make $MAKEPARAM
		)
	fi
	cd $BUILDDIR/webengine/cpp
fi
