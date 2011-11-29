#!/bin/bash

bison -d -o parser.cpp parser.y --debug --verbose &&

lex -o tokens.cpp tokens.l &&

g++ -o parser parser.cpp tokens.cpp