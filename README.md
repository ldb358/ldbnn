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
5. Repeat this process for each layer, the output of the last layer is the output

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

3. Repeat this process until all deltas are calculated.

4. for each weight update it using: w`<sub>i,n</sub> = w<sub>i,n</sub> + 
N*&Delta;<sub>n</sub>*(df(e)/de)*y<sub>Prev Layer<sub>i</sub></sub>
Note: N is the training speed coefficient

5. Repeat entire process until results are good

### Components

Note this is just the running part of the implementation testing will be addded later

```c++
class Node{
	vector<float> w;
	//performs the activation sumation and returns an output
	float activation(vector<float> inputs); //assert(w.size() == inputs.size());
	//perfroms the same operation as the activation function except with the derivative
	float activation_prime(vector<float> inputs);
	//populates the weights randomly. n is the number of inputs
	void populate_w(int n); 
}

class NeuralNetwork{
	vector< vector<Node> > layers;
	int N;	
	//sets up the nn by initallizing all of the hidden and output nodes, also sets
	//up the weights, either random or in the future from a file. There will be
	//layer_n + 1(the output layer) number of layers in the nn
	void NeuralNetwork(int input_s, int hidden_s, int layer_n);
	//gets a vector output for vector of inputs.
	vector<float> run(vector<float> inputs); 
	//run a single training iteration on the network. Input and output size must 
	//be correct
	void train_inter(vector<float> inputs, vector<float> expected_outputs);
}
```
