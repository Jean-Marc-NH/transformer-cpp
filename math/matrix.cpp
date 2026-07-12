#include "matrix.hpp"

Matrix Matrix::operator+(const Matrix& other) const 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result(i, j) = data[i * cols + j] + other.data[i * cols + j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result(i, j) = data[i * cols + j] - other.data[i * cols + j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const 
{
    if (cols != other.rows) 
    {
        throw std::invalid_argument("No se puede hacer la multiplicacion de matrices: las dimensiones no coinciden.");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < other.cols; ++j) 
        {
            result(i, j) = 0;
            for (int k = 0; k < cols; ++k) 
            {
                result(i, j) += data[i * cols + k] * other.data[k * other.cols + j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const 
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result(i, j) = data[i * cols + j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::transpose() const 
{
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result(j, i) = data[i * cols + j];
        }
    }
    return result;
}

// Multiplicacion elemento a elemento (Hadamard)
Matrix Matrix::hadamard(const Matrix& other) const 
{
    if (rows != other.rows || cols != other.cols) 
    {
        throw std::invalid_argument("No se puede hacer la multiplicacion de Hadamard: las dimensiones no coinciden.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result(i, j) = data[i * cols + j] * other.data[i * cols + j];
        }
    }
    return result;
}

vector<double> Matrix::row(int row) const 
{
    vector<double> result(cols);
    for (int j = 0; j < cols; ++j) 
    {
        result[j] = data[row * cols + j];
    }
    return result;
}

vector<double> Matrix::col(int col) const 
{
    vector<double> result(rows);
    for (int i = 0; i < rows; ++i) 
    {
        result[i] = data[i * cols + col];
    }
    return result;
}

void Matrix::reshape(int new_rows, int new_cols) 
{
    if (new_rows * new_cols != rows * cols) 
    {
        throw std::invalid_argument("No se puede hacer reshape: el numero de elementos no coincide.");
    }
    rows = new_rows;
    cols = new_cols;
}


Matrix Matrix::concatenate(const Matrix& other, bool axis) const 
{
    if (axis == 0) // Concatenar filas
    {
        if (cols != other.cols) 
        {
            throw std::invalid_argument("No se puede concatenar: el numero de columnas no coincide.");
        }
        Matrix result(rows + other.rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result(i, j) = data[i * cols + j];
            }
        }
        for (int i = 0; i < other.rows; ++i) 
        {
            for (int j = 0; j < other.cols; ++j) 
            {
                result(i + rows, j) = other.data[i * other.cols + j];
            }
        }
        return result;
    } 
    else // Concatenar columnas
    {
        if (rows != other.rows) 
        {
            throw std::invalid_argument("No se puede concatenar: el numero de filas no coincide.");
        }
        Matrix result(rows, cols + other.cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result(i, j) = data[i * cols + j];
            }
            for (int j = 0; j < other.cols; ++j) 
            {
                result(i, j + cols) = other.data[i * other.cols + j];
            }
        }
        return result;
    }
}


vector<double> Matrix::Argmax() const 
{
    vector<double> result(rows);
    for (int i = 0; i < rows; ++i) 
    {
        double max_value = data[i * cols];
        int max_index = 0;
        for (int j = 1; j < cols; ++j) 
        {
            if (data[i * cols + j] > max_value) 
            {
                max_value = data[i * cols + j];
                max_index = j;
            }
        }
        result[i] = max_index;
    }
    return result;
}

int Matrix::sum() const 
{
    double total = 0;
    for (double val : data) 
    {
        total += val;
    }
    return total;
}

int Matrix::mean() const 
{
    return sum() / (rows * cols);
}

int Matrix::max() const 
{
    double max_value = data[0];
    for (double val : data) 
    {
        if (val > max_value) 
        {
            max_value = val;
        }
    }
    return max_value;
}

void Matrix::fill(double value) 
{
    std::fill(data.begin(), data.end(), value);
}

void Matrix::identity() 
{
    if (rows != cols) 
    {
        throw std::invalid_argument("No se puede crear una matriz identidad: la matriz no es cuadrada.");
    }
    fill(0);
    for (int i = 0; i < rows; ++i) 
    {
        data[i * cols + i] = 1;
    }
}
