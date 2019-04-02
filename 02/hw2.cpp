#pragma once 
#include <iostream> 

using namespace std;
class Vector {
private:
	size_t columns;
	int *vector;
public:
	Vector(int *row, size_t cols) : vector(row), columns(cols){}
	
	int &operator[](size_t j) 
	{
		if (j >= columns)
			throw std::out_of_range("");
		return vector[j];
	}
	const int &operator[](size_t j) const 
	{
		if (j >= columns)
			throw std::out_of_range("");
		return vector[j];
	}
};
class Matrix
{
private:
	int **matrix;
	const size_t rows, cols;
public:
	Matrix(size_t n, size_t m) : rows(n), cols(m)
	{
		matrix = new int*[rows];
		for (size_t i = 0; i < rows; i++)
			matrix[i] = new int(cols);			
	}
	Matrix &operator*= (int c)
	{
		for (size_t i = 0; i < rows; i++)
			for (size_t j = 0; j < cols; j++)
				matrix[i][j] *= c;
		return *this;
	}
	bool operator==(const Matrix& B) const
	{
		if (this == &B)
			return true;
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				if (matrix[i][j] != B.matrix[i][j])
					return false;
		return true;
	}
	bool operator!=(const Matrix& B) const
	{
		if (this == &B)
			return false;
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				if (matrix[i][j] != B.matrix[i][j])
					return true;
		return false;
	}
	Vector operator[](size_t i) 
	{
		if (i >= rows)
			throw std::out_of_range("");
		return Vector(matrix[i], cols);
	}

	const Vector operator[](size_t i) const 
	{
		if (i >= rows)
			throw std::out_of_range("");
		return Vector(matrix[i], cols);
	}
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return cols;
	}
	~Matrix()
	{
		for (size_t i = 0; i < rows; i++)
			delete[]matrix[i];
		delete[] matrix;
	}
};