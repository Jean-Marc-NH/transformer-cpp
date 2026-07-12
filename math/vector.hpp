#include <vector>
#include <cmath>

using namespace std;

class Vector 
{
    private:
        vector<double> data;
        int size;
    public:
        Vector(int size) : size(size) 
        {
            data.resize(size);
        }

        double& operator[](int index) 
        {
            return data[index];
        }

        int getSize() const 
        {
            return size;
        }

        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(double scalar) const;
        Vector dot(const Vector& other) const;
        int norm() const;
        Vector normalize() const;
        int mean() const;
        int variance() const;


};