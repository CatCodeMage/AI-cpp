#include "class/neuron.h"

// based in https://github.com/AndoideXDD/AIC- // Now will work 

int main()
{
	Neuron neuronNew(1);
	float input[4] = {1,2,3,4};
	float expectedOut[4] = {1,1,1,1};
	//std::cout << neuronNew.neuronOutPut(input,4);
	neuronNew.oneNeuronTrainingTest(input, expectedOut, 4, 1, 10000);
	return 0;
}