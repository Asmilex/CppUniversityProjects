#include <iostream>
#include <random> //Random Number Generator
#include "Personaje.h"

using namespace std;

float RNG(double min, double max){
    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_real_distribution<double> uni(min,max); // guaranteed unbiased

    auto random_double = uni(rng);
    return random_double;
}

int main(int argc, char const *argv[]){
    cout <<RNG(1,5)<<endl;
    cout <<RNG(5,8)<<endl;

    return 0;
}
