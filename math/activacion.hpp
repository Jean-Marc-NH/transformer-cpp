#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double ReLu(double x) 
{
    return x > 0 ? x : 0;
}

double GeLU(double x)
{
    constexpr double sqrt_2_over_pi = 0.7978845608028654;

    return 0.5 * x *
           (1.0 + std::tanh(
               sqrt_2_over_pi *
               (x + 0.044715 * x * x * x)
           ));
}

double Sigmoid(double x) 
{
    return 1.0 / (1.0 + exp(-x));
}

double softmax(const vector<double>& x, int index) 
{
    double max_val = * max_element(x.begin(), x.end());
    double sum_exp = 0.0;
    for (double val : x) 
    {
        sum_exp += exp(val - max_val);
    }
    return exp(x[index] - max_val) / sum_exp;
}
