#include "math.h"
// Leaky rectified linear unit (Leaky ReLU)
float activationFunction(const float input) 
{
    float result;
	if (input <= 0) { result = input * 0.01; }
    else { result = input; }
    return result;
}