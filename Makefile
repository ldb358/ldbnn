GTEST_INCLUDES=~/code/lib/gtest/includes/

nn.o: nn.cpp nn.h
	g++ -c -o nn.o nn.cpp

test:
	g++ tests/*	-lpthread
