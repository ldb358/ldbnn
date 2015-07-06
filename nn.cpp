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

float Node::get_w(int index){
	return w[index];
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


std::vector<float> NeuralNetwork::run(std::vector<float> &inputs){	
	std::vector<float> outputs;
	for(int i=0; i < layers.size(); ++i){
		for(int n = 0; n < layers[i].size(); ++i){
			outputs.push_back(layers[i][n].activation(inputs));
		}
		inputs = outputs;
	}
	return outputs;
}


void NeuralNetwork::train_iter(std::vector<float> &inputs, 
		std::vector<float> &expected_outputs){
	//step one run the nn with the inputs
	std::vector<float> actual_output = run(inputs);
	std::vector< std::vector<float> > deltas;
	//initialize the vectors that will contain all of the deltas 
	for(int i=0; i < layers.size(); ++i){
		std::vector<float> row;
		deltas.push_back(row);
	}
	//calculate last row of deltas
	int n_rows = deltas.size()-1;
	for(int i=0; i < expected_outputs.size(); ++i){
		deltas[n_rows].push_back(expected_outputs[i]-actual_output[i]);	
	}
	//foreach row of deltas
	for(int i=n_rows-1; i > -1; i--){
		//foreach node in the layer
		for(int n=0; n < layers[n].size(); ++n){
			float sum = 0;
			//foreach weight coming out of this node	
			for(int z=0; z < layers[i+1].size(); ++z){
				sum += deltas[i+1][z]*layers[i+1][z].get_w(n);	
			}
			deltas[i].push_back(sum);
		}
	}
	
	std::vector<float> outputs;
	//use the deltas to adjust the weight
	//foreach layer
	for(int i=0; i < layers.size(); ++i){
		//foreach neuron in the layer
		for(int n=0; n < layers[i].size(); ++n){
			//adjust all of the weights for the neuron
			layers[i][n].adjust_w(N, deltas[i][n], inputs);
			//regenerate output
			outputs.push_back(layers[i][n].activation(inputs));	
		}
		//move this row of outputs to be the inputs for the next row
		inputs = outputs;
	}
}
