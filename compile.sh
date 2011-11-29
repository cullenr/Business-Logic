#!/bin/bash

bison -d -o parser.cpp parser.y --debug --verbose &&

lex -o tokens.cpp tokens.l &&

g++ -o parser `llvm-config --libs core jit native --cxxflags --ldflags` impl.cpp parser.cpp tokens.cpp
#g++ -o parser parser.cpp tokens.cpp