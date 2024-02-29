#!/bin/bash


cp ../../src/parsing/parsing.c .

gcc -o test_parsing parsing.c tests.c

./test_parsing

rm -rf parsing.c test_parsing
