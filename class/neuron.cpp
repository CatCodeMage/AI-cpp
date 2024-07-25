#include "neuron.h"

Neuron::Neuron(const int numInputs)
{
	wheights = new float[numInputs];
	numWeights = numInputs;
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10);
	for (int i = 0; i < numWeights; i++)
		wheights[i] = dist(gen);
	variableNumber = dist(gen);
}

float Neuron::neuronOutPut(const float* input,const int numInputs)
{
	float out = 0;
	if (numInputs == numWeights)
	{
		for (int i = 0; i < numWeights; i++)
			out += wheights[i] * input[i];
		out = activationFunction(out + variableNumber);
		oldOutput.push(out);// para luego hacer pops al hacer la derivada y sacar los datos 
	}
	else
		std::cout << "Num of inputs not match num outputs";
	return out;
}

void Neuron::oneNeuronTrainingTest(const float* input,const float* expectedOut, const int numInputs, const int lenghInput,const int iterations)
{
	
	if (lenghInput == numWeights)
	{
		int lenghData = numInputs * lenghInput;
		float* dataOut = new float[numInputs];
		int posOut;
		float* loss = new float[numWeights + 1];
		float auxiliar;
		float* steap = new float[numWeights + 1];
		for (int iteration = 0; iteration < iterations; iteration++)
		{
			posOut = 0;
			for (int i = 0; i <= numWeights; i++) // +1 iteration
				loss[i] = 0;

			for (int numInputBegin = 0; numInputBegin < lenghData; numInputBegin += lenghInput)
			{
				float* dataInput = new float[lenghInput];
				for (int i = 0; i < lenghInput; i++)
					dataInput[i] = input[i + numInputBegin];
				dataOut[posOut] = neuronOutPut(dataInput, lenghInput);
				auxiliar = expectedOut[posOut] - dataOut[posOut];
				// quadratic cost function 
				for (int i = 0; i < lenghInput; i++)
				{
					if (dataOut[i] <= 0)
						loss[i] += -0.02 * dataInput[i] * auxiliar;
					else
						loss[i] += -2 * dataInput[i] * auxiliar;
				}
				loss[numWeights] += -2 * auxiliar;
				posOut++;
				delete[] dataInput;
			}
			for (int i = 0; i < numWeights; i++)
				wheights[i] -= loss[i] * PRECISION;
			variableNumber -= loss[numWeights] * PRECISION;
		}
		
		// show results 
		std::cout << "Printing results at % of correct:\n";
		float percentagePrecision;
		for (int i = 0; i < numInputs; i++)
		{
			percentagePrecision = dataOut[i]; //- expectedOut[i];
			//percentagePrecision = (percentagePrecision * 100) / expectedOut[i];
			std::cout << "\n" << percentagePrecision;
		}
		delete[] dataOut;
	}
	else
		std::cout << "Num of inputs not match num outputs";
}

Neuron::~Neuron()
{
	if (wheights != nullptr)
		delete wheights; 
}