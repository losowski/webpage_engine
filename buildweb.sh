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
