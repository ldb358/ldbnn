GTEST_INCLUDES=~/code/lib/gtest/includes/

nn.o: nn.cpp nn.h
	g++ -g -c -o nn.o nn.cpp

test:
	g++ -g tests/*	-lpthread

xor: nn.o
	g++ -g -std=c++0x examples/xor/xor.cpp nn.o -o examples/xor/xor
