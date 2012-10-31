#!/bin/bash

# by Ivan Smirnov

CXX="g++ -static -fno-optimize-sibling-calls -fno-strict-aliasing \
     -DONLINE_JUDGE -D_LINUX -lm -s -O2"
name="MyStrategy"

if [ ! -f $name.cpp ]
then
    echo Unable to find $name.cpp > compilation.log
    exit 1
fi

rm -f $name

libs=""

# compile static sources in parent directory
for file in `ls *.cpp | grep -v $name`
do
    bfile=`basename $file .cpp`
    if [ ! -e $bfile.o ]
    then
        echo Compiling file $bfile.cpp...
        $CXX -c $bfile.cpp || exit 1
    fi

    libs="$libs $bfile.o"
done

# compile static libraries
for dir in csimplesocket model
do
    cd $dir
    lib=lib$dir.a
    if [ ! -e $lib ]
    then
        echo Compiling library $lib...
        $CXX -c *.cpp || exit 1
        ar -cvq $lib *.o || exit 1
        ar -t $lib || exit 1
        rm -f *.o || exit 1
    fi
    cd ..

    libs="$libs $dir/$lib"
done

$CXX $name.cpp $libs -o $name || exit 1

