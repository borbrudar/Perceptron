#pragma once
#include <vector>
#include <random>


class Perceptron {
public:
	Perceptron() {
		//Assign random values to weights
		std::default_random_engine generator;
		std::uniform_real_distribution<float> distribution(-1, 1);
		for (std::size_t i = 0; i < weights.size(); ++i) {
			weights[i] = distribution(generator);
		}

	}
	int activate(float n) {
		if (n >= 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	int guess(std::vector<float> inputs) {
		float sum = 0;
		for (std::size_t i = 0; i < inputs.size(); ++i) {
			sum += inputs[i] * weights[i];
		}
		return activate(sum);
	}
	void train(std::vector<float> inputs, int target) {
		int error = target - guess(inputs);
		for (std::size_t i = 0; i < inputs.size(); ++i) {
			weights[i] += error * inputs[i] * lr;
		}
	}
	std::vector<float> weights= {0.f,0.f};
	float lr = 0.1f;
};