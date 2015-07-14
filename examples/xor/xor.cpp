#include "../../nn.h"
#include<iostream>


void dec2bin_vector(std::vector<double> &bin_v, int dec){
	if(dec <= 1){
		bin_v.push_back(dec);
		for(int i=bin_v.size(); i < 5; ++i){
			bin_v.push_back(0);
		}	
		return;
	}
	if(dec%2==1){
		bin_v.push_back(1);
		dec2bin_vector(bin_v, (dec-1)/2);
	}else{
		dec2bin_vector(bin_v, dec/2);
	}
}



int main(int argc, char** argv){
	std::vector<int> sizes = {5, 1};
	NeuralNetwork nn(sizes, 2, 5, .25);
	std::vector<double> inputs;
	std::vector<double> outputs = {0};

	int power = 1;
	std::cout << "starting training" << std::endl;
	for(int i=0; i < 31; ++i){
		inputs.clear();
		dec2bin_vector(inputs, i);
		if(i==power){	
			outputs[0] = 1;
			power *= 2;
		}else{
			outputs[0] = 0;
		}
		int iter = 0;
		double error = 0;
		//this loops for ever or if iter is not used it doesnt loop at all
		do{
			error = nn.train_iter(inputs, outputs);
			std::cout << error << ":" << (iter < 200 && error > .25) << std::endl;
			iter++;
		} while( error > .25);
	}
	std::cout <<"Start Tests" << std::endl; 
	for(int i=0; i < 31; ++i){
		inputs.clear();
		dec2bin_vector(inputs, i);
		outputs = nn.run(inputs);
		std::cout << "for:" << i << " return:";
		for(int i=0; i < outputs.size(); ++i){
			std::cout << outputs[i];
		}
		std::cout << std::endl;
	}

	return 0;
}

