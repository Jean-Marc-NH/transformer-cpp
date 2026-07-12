#include <random>

using namespace std;

class Random
{

public:
    static double Uniform(double min, double max) 
    {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_real_distribution<double> dis(min, max);
        return dis(gen);
    }

    static double Normal(double mean, double stddev) 
    {
        static random_device rd;
        static mt19937 gen(rd());
        normal_distribution<double> dis(mean, stddev);
        return dis(gen);
    }

    static double xavier(int fan_in, int fan_out) 
    {
        double limit = sqrt(6.0 / (fan_in + fan_out));
        return Uniform(-limit, limit);
    }

    static double he(int fan_in) 
    {
        double limit = sqrt(2.0 / fan_in);
        return Normal(0, limit);
    }

};