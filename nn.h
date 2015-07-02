#include<iostream>
#include<vector>
class Node{
	private:
	std::vector<float> w;
	
	public:
	//performs the activation sumation and returns an output
	float activation(std::vector<float> inputs); //assert(w.size() == inputs.size());
	//perfroms the same operation as the activation function except with the derivative
	float activation_prime(std::vector<float> inputs);
	//populates the weights randomly. n is the number of inputs
	void populate_w(int n); 
};

class NeuralNetwork{
	std::vector< std::vector<Node> > layers;
	int N;	
	//sets up the nn by initallizing all of the hidden and output nodes, also sets
	//up the weights, either random or in the future from a file. There will be
	//layer_n + 1(the output layer) number of layers in the nn
	NeuralNetwork(int input_s, int hidden_s, int layer_n);
	//gets a vector output for vector of inputs.
	std::vector<float> run(std::vector<float> inputs); 
	//run a single training iteration on the network. Input and output size must 
	//be correct
	void train_inter(std::vector<float> inputs, std::vector<float> expected_outputs);
};
