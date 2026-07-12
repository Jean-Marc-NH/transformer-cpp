#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class Matrix 
{
    private:
        vector<double> data;
        int rows;
        int cols;
    public:
        Matrix(int rows, int cols) : rows(rows), cols(cols) 
        {
            data.resize(rows * cols);

        }

        double& operator()(int row, int col) 
        {
            return data[row * cols + col];
        }

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double scalar) const;

        Matrix transpose() const;

        // Multiplicacion elemento a elemento (Hadamard)
        Matrix hadamard(const Matrix& other) const;

        vector<double> row(int row) const;
        vector<double> col(int col) const;

        void reshape(int new_rows, int new_cols);

        // Concatenar matrices a lo largo de un eje (0 para filas, 1 para columnas)
        Matrix concatenate(const Matrix& other, bool axis) const;

        vector<double> Argmax() const;
        int sum() const;
        int mean() const;
        int max() const;
        void fill(double value);
        void identity();




};