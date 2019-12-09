#!/bin/bash

OUT_DIR='Bin.Debug'
BUILD_DIR='Build.Debug'

if [ ! -d $BUILD_DIR ]; then
	mkdir $BUILD_DIR
fi

if [ ! -d $OUT_DIR ]; then
	mkdir $OUT_DIR
fi

cd $BUILD_DIR
cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_RUNTIME_OUTPUT_DIRECTORY=../../$OUT_DIR ..
make
cd ..