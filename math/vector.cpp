#include "vector.hpp"

Vector Vector::operator+(const Vector &other) const
{
    Vector result(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = data[i] + other.data[i];
    }
    return result;
}

Vector Vector::operator-(const Vector &other) const
{
    Vector result(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = data[i] - other.data[i];
    }
    return result;
}

Vector Vector::operator*(double scalar) const
{
    Vector result(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = data[i] * scalar;
    }
    return result;
}

Vector Vector::dot(const Vector &other) const
{
    Vector result(1);
    result[0] = 0;
    for (int i = 0; i < size; ++i)
    {
        result[0] += data[i] * other.data[i];
    }
    return result;
}

int Vector::norm() const
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += data[i] * data[i];
    }
    return sqrt(sum);
}

Vector Vector::normalize() const
{
    int n = norm();
    Vector result(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = data[i] / n;
    }
    return result;
}

int Vector::mean() const
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += data[i];
    }
    return sum / size;
}

int Vector::variance() const
{
    int m = mean();
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sum / size;
}

