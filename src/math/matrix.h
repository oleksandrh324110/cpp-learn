#pragma once

#include <iostream>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iterator>
#include <initializer_list>

template <typename T, size_t _rows, size_t _cols>
class matrix {
public:
	matrix(std::initializer_list<std::initializer_list<T>> initList) {
		size_t row = 0;
		for (const auto& rowList : initList) {
			if (row >= _rows)
				throw std::out_of_range("Too many rows in initializer list");
			if (rowList.size() != _cols)
				throw std::invalid_argument("Invalid number of columns in initializer list");
			std::copy(rowList.begin(), rowList.end(), _data[row]);
			row++;
		}
		if (row < _rows)
			throw std::out_of_range("Too few rows in initializer list");
	};
	matrix(const matrix& other) {
		std::copy(other.begin(), other.end(), begin());
	};
	matrix(T(&arr)[_rows][_cols]) {
		for (size_t i = 0; i < _rows; i++)
			std::copy(std::begin(arr[i]), std::end(arr[i]), std::begin(_data[i]));
	}
	matrix() {};
	matrix(double value) {
		std::fill(begin(), end(), value);
	}
	matrix& operator=(const matrix& other) {
		if (this != &other)
			std::copy(other.begin(), other.end(), begin());
		return *this;
	}
	~matrix() {};

	bool operator==(const matrix<T, _rows, _cols>& other) const {
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				if (_data[i][j] != other[i][j])
					return false;
		return true;
	}

	inline size_t rows() const { return _rows; }
	inline size_t cols() const { return _cols; }

	T* operator[](size_t index) { return _data[index]; }
	const T* operator[](size_t index) const { return _data[index]; }

	T* begin() { return &_data[0][0]; }
	const T* begin() const { return &_data[0][0]; }
	T* end() { return &_data[_rows - 1][_cols]; }
	const T* end() const { return &_data[_rows - 1][_cols]; }

	matrix sum(const matrix& other) const {
		matrix<T, _rows, _cols> res;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				res[i][j] = _data[i][j] + other[i][j];
		return res;
	}
	matrix operator+(const matrix& other) const { return sum(other); }

	matrix sub(const matrix& other) const {
		matrix<T, _rows, _cols> res;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				res[i][j] = _data[i][j] - other[i][j];
		return res;
	}
	matrix operator-(const matrix& other) const { return sub(other); }

	template <size_t other_cols>
	matrix<T, _rows, other_cols> mult(const matrix<T, _cols, other_cols>& other) const {
		matrix<T, _rows, other_cols> res(0);
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < other_cols; j++)
				for (size_t k = 0; k < _cols; k++)
					res[i][j] += _data[i][k] * other[k][j];
		return res;
	}
	template <size_t other_cols>
	matrix<T, _rows, other_cols> operator*(const matrix<T, _cols, other_cols>& other) const { return mult(other); }

	matrix scale(double value) {
		matrix result = *this;
		std::transform(begin(), end(), result.begin(), [value](T item) { return item * value; });
		return result;
	}
	matrix operator*(double value) { return scale(value); }
	matrix operator/(double value) { return scale(1.0 / value); }

	double det() const {
		static_assert(_rows == _cols, "Determinant can only be calculated for square matrices");

		if constexpr (_rows == 1)
			return _data[0][0];
		else if constexpr (_rows == 2)
			return _data[0][0] * _data[1][1] - _data[0][1] * _data[1][0];
		else {
			double determinant = 0;
			for (size_t j = 0; j < _cols; j++) {
				matrix<T, _rows - 1, _cols - 1> subMatrix;
				for (size_t i = 1; i < _rows; i++)
					for (size_t k = 0; k < _cols; k++)
						if (k < j)
							subMatrix[i - 1][k] = _data[i][k];
						else if (k > j)
							subMatrix[i - 1][k - 1] = _data[i][k];

				double subMatrixDeterminant = subMatrix.det();
				determinant += (_data[0][j] * subMatrixDeterminant * ((j % 2 == 0) ? 1 : -1));
			}
			return determinant;
		}
	}

	matrix<T, _cols, _rows> transpose() const {
		matrix<T, _cols, _rows> res;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				res[j][i] = _data[i][j];
		return res;
	}

	matrix<T, _rows, _cols> inverse() const {
		static_assert(_rows == _cols, "Inverse can only be calculated for square matrices");

		double det = this->det();
		if (det == 0)
			throw std::invalid_argument("Matrix is not invertible");

		matrix<T, _rows, _cols> minors;
		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < _cols; j++) {
				matrix<T, _rows - 1, _cols - 1> subMatrix;
				for (size_t x = 0; x < _rows; x++)
					for (size_t y = 0; y < _cols; y++)
						if (x != i && y != j)
							subMatrix[x < i ? x : x - 1][y < j ? y : y - 1] = _data[x][y];
				minors[i][j] = subMatrix.det();
			}
		}

		matrix<T, _rows, _cols> cofactors;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				cofactors[i][j] = minors[i][j] * ((i + j) % 2 == 0 ? 1 : -1);

		matrix<T, _rows, _cols> adjugate = cofactors.transpose();

		matrix<T, _rows, _cols> inverse;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < _cols; j++)
				inverse[i][j] = adjugate[i][j] / det;

		return inverse;
	}

	void print() const {
		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < _cols; j++)
				if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value)
					std::cout << (int)_data[i][j] << ' ';
				else
					std::cout << _data[i][j] << ' ';
			std::cout << '\n';
		}
	}

private:
	T _data[_rows][_cols];
};
