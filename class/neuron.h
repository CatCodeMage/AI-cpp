#include "../constants/constants.h"
#include "../functions/math.h"
class Neuron
{
public:
	Neuron(const int numInputs);
	float neuronOutPut(const float* input, const int numInputs);
	void oneNeuronTrainingTest(const float* input,const float* expectedOut, const int numInputs, const int lenghInput, const int iterations);
	~Neuron();

private:
	float* wheights;
	float variableNumber;
	int numWeights;
	std::queue<float> oldOutput;
};

