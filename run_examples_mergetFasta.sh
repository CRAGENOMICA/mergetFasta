#mergetFasta v0.1 (20170908) Jordi Leno-Colorado

#Usage: ./merge_tfastas -i list_tFastas.txt -o outputname
#
#Flags:
#      -i [List with the name of all tFasta to merge (with the path to each file if they were not in the same directory of program)]
#      -o [Output compressed tFasta filename (without extension)]
#   OPTIONAL PARAMETERS:
#      -h [help and exit]

# To compile:
make -f nbproject/Makefile-Release.mk build/Release/GNU-Linux/main.o
mkdir -p build/Release/GNU-Linux
rm -f "build/Release/GNU-Linux/main.o.d"
g++ -std=c++0x -lz   -c -O2 -MMD -MP -MF "build/Release/GNU-Linux/main.o.d" -o build/Release/GNU-Linux/main.o main.cpp
/usr/bin/make -f Makefile CONF=Release

# Run examples

cd Examples

echo ----------------------------------------------
echo Example. Merging two crompressed tFasta files
echo ----------------------------------------------
echo
echo ../bin/mergetFasta -i list_tfastas.txt -o merged
../bin/mergetFasta -i list_tfastas.txt -o merged
echo
