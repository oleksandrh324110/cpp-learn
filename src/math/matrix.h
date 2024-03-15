#pragma once

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
		for (size_t i = 0; i < _rows; ++i)
			std::copy(std::begin(arr[i]), std::end(arr[i]), std::begin(_data[i]));
	}
	matrix() {
		std::fill(begin(), end(), 0);
	};
	~matrix() {};

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
	matrix operator+(const matrix& other) const { return add(other); }

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
		matrix<T, _rows, other_cols> res;
		for (size_t i = 0; i < _rows; i++)
			for (size_t j = 0; j < other_cols; j++)
				for (size_t k = 0; k < _cols; k++)
					res[i][j] += _data[i][k] * other[k][j];
		return res;
	}
	template <size_t other_cols>
	matrix<T, _rows, other_cols> operator*(const matrix<T, _cols, other_cols>& other) const { return mult(other); }

	double det() const {
		static_assert(_rows == _cols, "Determinant can only be calculated for square matrices");

		if (_rows == 1)
			return _data[0][0];
		else if (_rows == 2)
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
