all: compile
compile: type_r type_i type_j main
    g++ -o Converter Type_R.o Type_I.o Type_J.o Main.o
type_r: Type_R.cpp Type_R.h
    g++ -c Type_R.cpp
type_i: Type_I.cpp Type_I.h
    g++ -c Type_I.cpp
type_j: Type_J.cpp Type_J.h
    g++ -c Type_J.cpp
main: Main.cpp Type_R.h Type_I.h Type_J.h
    g++ -c Main.cpp

