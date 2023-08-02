#! /bin/sh

#mkdir -m 777 Build

gcc -c main.cpp -o main.o
gcc -c C_Test.c -o C_Test.o
gcc -c Cpp_Test.cpp -o Cpp_Test.o
gcc -c Fpt_Test.c -o Fpt_Test.o

gcc main.o C_Test.o Cpp_Test.o Fpt_Test.o -lstdc++ -o TestProj -Xlinker -Map TestProj.map

# to clean trash
# rm -rf Buiild
# rm *.o

