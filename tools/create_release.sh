#!/bin/bash -e

VERSION=`grep version= platform.txt | sed 's/version=//g'`

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`

mkdir -p build
rm -f build/$FOLDERNAME-$VERSION.tar.bz2

cd ..
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    tar -s "/$FOLDERNAME/$VERSION/g" \
        --exclude=.trunk/** --exclude=build/** --exclude=extras/** --exclude=.git* --exclude=.idea \
        -cjf $FOLDERNAME-$VERSION.tar.bz2 \
        $FOLDERNAME
else
    # Linux
    tar --transform "s|$FOLDERNAME|$VERSION|g" \
        --exclude=.trunk/** --exclude=build/** --exclude=extras/** --exclude=.git* --exclude=.idea \
        -cjf $FOLDERNAME-$VERSION.tar.bz2 \
        $FOLDERNAME
fi
cd -


mv ../$FOLDERNAME-$VERSION.tar.bz2 ./build/

cd ..
zip -r framework-arduinoadafruitnrf52@$VERSION.zip $FOLDERNAME -x "$FOLDERNAME/.trunk/*" -x "$FOLDERNAME/build/*" -x "$FOLDERNAME/extras/*" "$FOLDERNAME/.git*" "$FOLDERNAME/.idea/*"
cd -
mv ../framework-arduinoadafruitnrf52@$VERSION.zip ./build/

echo ""
echo "Package for Arduino BSP"
echo "Path: `pwd`/build/$FOLDERNAME-$VERSION.tar.bz2"
echo checksum: SHA-256:`sha256sum ./build/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'`
echo size: `wc -c ./build/$FOLDERNAME-$VERSION.tar.bz2 | awk '{print $1}'` bytes
echo ""
echo "Package for PlatformIO"
echo "Path: `pwd`/build/framework-arduinoadafruitnrf52@$VERSION.zip"
echo checksum: SHA-256:`sha256sum ./build/framework-arduinoadafruitnrf52@$VERSION.zip | awk '{print $1}'`
echo size: `wc -c ./build/framework-arduinoadafruitnrf52@$VERSION.zip | awk '{print $1}'` bytes

# Generate package_fobe_nrf52_index.json based on template
echo ""
echo "Generating package_fobe_nrf52_index.json..."

ARCHIVE_FILE="$FOLDERNAME-$VERSION.tar.bz2"
ARCHIVE_CHECKSUM=`sha256sum ./build/$ARCHIVE_FILE | awk '{print $1}'`
ARCHIVE_SIZE=`wc -c ./build/$ARCHIVE_FILE | awk '{print $1}'`

# Use sed to replace placeholders in template
sed -e "s|\"version\": \"\"|\"version\": \"$VERSION\"|g" \
    -e "s|\"url\": \"\"|\"url\": \"https://github.com/fobe-projects/fobe-nrf52-arduino/releases/download/$VERSION/$ARCHIVE_FILE\"|g" \
    -e "s|\"archiveFileName\": \"\"|\"archiveFileName\": \"$ARCHIVE_FILE\"|g" \
    -e "s|\"checksum\": \"\"|\"checksum\": \"SHA-256:$ARCHIVE_CHECKSUM\"|g" \
    -e "s|\"size\": \"\"|\"size\": \"$ARCHIVE_SIZE\"|g" \
    package/package_nrf52_index.template.json > build/package_fobe_nrf52_index.json

echo "Generated: `pwd`/build/package_fobe_nrf52_index.json"
echo "Version: $VERSION"
echo "Archive: $ARCHIVE_FILE"
echo "Checksum: SHA-256:$ARCHIVE_CHECKSUM"
echo "Size: $ARCHIVE_SIZE bytes"
