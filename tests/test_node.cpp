#include "catch.hpp"
#include <vector>
#include "L_NN/nn.h"
TEST_CASE ( "Test weight set constant", "[node]") {
	Node n;
	int weight_n = 10;
	n.populate_w(weight_n, .1);
	for(int i=0; i < weight_n; ++i){
		REQUIRE(n.get_w(i) == .1);
	}
}
TEST_CASE ( "Test weight set constant", "[node]") {
	Node n;
	int weight_n = 10;
	n.populate_w(weight_n, .1);
	for(int i=0; i < weight_n; ++i){
		REQUIRE(n.get_w(i) == .1);
	}
}

TEST_CASE ( "Activation", "[node]"){
	Node n;
	REQUIRE(1 == 1);
}
