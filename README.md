#ldbnn

##This is a simple feed forward artificial neural network implemented in C++.

##The goal of this is completely educational


### Process of using a neural neural:
1. Create a neural network with I inputs, H hidden and O output nodes
2. Initialize the weights, for an untrained set these should be random for a 
trained set these should be loaded. There should be a weight from non-output 
node to every node in the next layer in the nn. for example input->hidden and
hidden->output.
3. add the inputs for the sample
4. for each node in the hidden layer use the summation &Sigma;
w<sub>i->h</sub>*y<sub>i</sub>. This value is then run through a sigmoid 
activation function
5. Repeat this process from the hidden to output layer. You now have the 
output.

### Training the nn:

The training algorithm that I will use by default is the back propagation 
algorithm. To use this we start with output.

1. For each output calculate &delta; using the expected value Z and the 
output of the output nodes Y<sub>O<sub>i</sub></sub> where &delta;
<sub>O<sub>i</sub></sub> = Z <sub>expected O<sub>i</sub></sub> - 
Y<sub>O<sub>i</sub></sub>

2. For each node in the hidden layer calculate the &delta;<sub>H<sub>i</sub></sub>
using the summation of all outputs such that &delta;<sub>H<sub>i</sub></sub> = 
&Sigma; &delta;<sub>O<sub>n</sub></sub>*w<sub>i,n</sub>

### Components

Note this is just the running part of the implementation testing will be addded later

```c++
class Node{
	vector<float> w;
	//performs the activation sumation and returns an output
	float activation(vector<float> inputs); //assert(w.size() == inputs.size());
	//populates the weights randomly. n is the number of inputs
	void populate_w(int n); 
}

class NeuralNetwork{
	vector<Node> outputs;
	vector<Node> hidden;
	
	//sets up the nn by initallizing all of the hidden and output nodes, also sets
	//up the weights, either random or in the future from a file
	void NeuralNetwork(int input_s, int hidden_s, int output_s);
	//gets a vector output for vector of inputs.
	vector<float> run(vector<float> inputs); 
}


```
