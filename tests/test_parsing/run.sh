#!/bin/bash


cp ../../src/parsing/parsing.c .

gcc -o test_parsing parsing.c tests.c -I../../include

./test_parsing

rm -rf parsing.c test_parsing tmp.cor
