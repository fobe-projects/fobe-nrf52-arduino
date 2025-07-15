#!/bin/bash -e

VERSION=`grep version= platform.txt | sed 's/version=//g'`

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`

mkdir -p build
rm -f build/$FOLDERNAME-$VERSION.tar.bz2

cd ..
gtar --transform "s|$FOLDERNAME|$VERSION|g"  --exclude=extras/** --exclude=.git* --exclude=.idea -cjf $FOLDERNAME-$VERSION.tar.bz2 $FOLDERNAME
cd -


mv ../$FOLDERNAME-$VERSION.tar.bz2 ./build/

echo checksum: SHA-256:`sha256sum ./build/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'`
echo size: `wc -c ./build/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'` bytes