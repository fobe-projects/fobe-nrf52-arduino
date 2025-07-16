#!/bin/bash -e

VERSION=`grep version= platform.txt | sed 's/version=//g'`

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`

mkdir -p release
rm -f release/$FOLDERNAME-$VERSION.tar.bz2

cd ..
gtar --transform "s|$FOLDERNAME|$VERSION|g" --exclude=.trunk/** --exclude=release/** --exclude=extras/** --exclude=.git* --exclude=.idea -cjf $FOLDERNAME-$VERSION.tar.bz2 $FOLDERNAME
cd -


mv ../$FOLDERNAME-$VERSION.tar.bz2 ./release/

cd ..
zip -r framework-arduinoadafruitnrf52.zip $FOLDERNAME -x "$FOLDERNAME/.trunk/*" -x "$FOLDERNAME/release/*" -x "$FOLDERNAME/extras/*" "$FOLDERNAME/.git*" "$FOLDERNAME/.idea/*"
cd -
mv ../framework-arduinoadafruitnrf52.zip ./release/

echo ""
echo "Package for Arduino BSP"
echo "Path: `pwd`/release/$FOLDERNAME-$VERSION.tar.bz2"
echo checksum: SHA-256:`sha256sum ./release/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'`
echo size: `wc -c ./release/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'` bytes
echo ""
echo "Package for PlatformIO"
echo "Path: `pwd`/release/framework-arduinoadafruitnrf52.zip"
echo checksum: SHA-256:`sha256sum ./release/framework-arduinoadafruitnrf52.zip | awk '{print $1}'`
echo size: `wc -c ./release/framework-arduinoadafruitnrf52.zip | awk '{print $1}'` bytes