#ifndef LDBNN_CORE

#include<vector>

class Node{
	private:
	std::vector<float> w;
	float y; //this allows for the reuse of the y value from the last run
	float sigmoid(float x);
	float sigmoid_prime(float x);
	
	public:
	Node();
	//performs the activation sumation and returns an output
	float activation(std::vector<float> &inputs); //assert(w.size() == inputs.size());
	//perfroms the same operation as the activation function except with the derivative
	float activation_prime(std::vector<float> &inputs);
	//populates the weights randomly. n is the number of inputs
	void populate_w(int n); 
	//adjust the weights using back propagation. Y will come from the input connected 
	//with the width we are adjusting 
	void adjust_w(float N, float delta_y, std::vector<float> &inputs);

};

class NeuralNetwork{
	std::vector< std::vector<Node> > layers;
	float N;	
	//sets up the nn by initallizing all of the hidden and output nodes, also sets
	//up the weights, either random or in the future from a file. There will be
	//layer_n + 1(the output layer) number of layers in the nn
	NeuralNetwork(std::vector<int> layer_s, int layer_n, int input_s, int learning_rate);
	//gets a vector output for vector of inputs.
	std::vector<float> run(std::vector<float> inputs); 
	//run a single training iteration on the network. Input and output size must 
	//be correct
	void train_inter(std::vector<float> inputs, std::vector<float> expected_outputs);
};
#define LDBNN_CORE
#endif
