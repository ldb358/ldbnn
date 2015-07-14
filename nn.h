#ifndef LDBNN_CORE

#include<vector>

class Node{
	private:
	std::vector<double> w;
	double y; //this allows for the reuse of the y value from the last run
	double sigmoid(double x);
	double sigmoid_prime(double x);
	
	public:
	Node();
	//performs the activation sumation and returns an output
	double activation(std::vector<double> &inputs); //assert(w.size() == inputs.size());
	//perfroms the same operation as the activation function except with the derivative
	double activation_prime(std::vector<double> &inputs);
	//populates the weights randomly. n is the number of inputs
	void populate_w(int n); 
	//adjust the weights using back propagation. Y will come from the input connected 
	//with the width we are adjusting 
	void adjust_w(double N, double delta_y, std::vector<double> &inputs);
	double get_w(int index);
};

class NeuralNetwork{
	std::vector< std::vector<Node> > layers;
	double N;	
	public:
	//sets up the nn by initallizing all of the hidden and output nodes, also sets
	//up the weights, either random or in the future from a file. There will be
	//layer_n + 1(the output layer) number of layers in the nn
	NeuralNetwork(std::vector<int> layer_s, int layer_n, int input_s, double learning_rate);
	//gets a vector output for vector of inputs.
	std::vector<double> run(std::vector<double> inputs); 
	//run a single training iteration on the network. Input and output size must 
	//be correct
	double train_iter(std::vector<double> inputs, std::vector<double> &expected_outputs);
};
#define LDBNN_CORE
#endif
