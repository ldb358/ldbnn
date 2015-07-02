#include "nn.h"

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include <stdlib.h>/* srand, rand */
#include <time.h> /* time */

float Node::sigmoid(float x){
	return 1 / (1 + abs(x));
}

float Node::sigmoid_prime(float x){
	return sigmoid(x)*(1-sigmoid(x));
}

float Node::activation(std::vector<float> &inputs){
	assert(inputs.size() == w.size());
	float sum = 0;
	for(unsigned int i=0; i < inputs.size(); ++i){
		sum += inputs[i]*w[i];
	}
	y = sigmoid(sum);
	return y;
}

float Node::activation_prime(std::vector<float> &inputs){
	assert(inputs.size() == w.size());
	//if we have the previous value from the activation function we can use that to
	//get the sigmoid with less calculations
	if(y >= 0){
		return sigmoid_prime(y);
	}

	float sum = 0;
	for(unsigned int i=0; i < inputs.size(); ++i){
		sum += inputs[i]*w[i];
	}
	return sigmoid_prime(sum);

}

void Node::populate_w(int n){
	for(int i=0; n < w.size(); ++i){
		//generate a random value between 0-1
		w.push_back((rand()%101)/100.0);
	}
}

void Node::adjust_w(float N, float delta_y, std::vector<float> &inputs){
	for(int i=0; i < w.size(); ++i){
		w[i] = w[i] + N*delta_y*activation_prime(inputs)*inputs[i];
	}
}

Node::Node(){
	y = 0;
}

NeuralNetwork::NeuralNetwork(std::vector<int> layer_s, int layer_n, int input_s, int learning_rate){
	N = learning_rate;
	for(int i=0; i < layer_s.size(); ++i){
		std::vector<Node> layer;
		for(int n=0; n < layer_s[i]; ++n){
			Node neuron;
			neuron.populate_w(i==0? input_s : layer_s[i-1]);
			layer.push_back(neuron);
		}
		layers.push_back(layer);
	}
}

NeuralNetwork::run(std::vector<float> inputs){
	
}

int main(){
	return 0;
}
