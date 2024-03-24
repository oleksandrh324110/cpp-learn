#pragma once

#include <iostream>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iterator>
#include <initializer_list>

template <typename T, size_t _size>
class vector {
public:
	vector(std::initializer_list<T> initList) {
		if (initList.size() > _size)
			throw std::out_of_range("Initializer list size exceeds vector size");
		std::copy(initList.begin(), initList.end(), _data);
	}
	vector(const vector& other) {
		std::copy(other.begin(), other.end(), begin());
	}
	vector(T(&arr)[_size]) {
		std::copy(std::begin(arr), std::end(arr), begin());
	}
	vector() {};
	vector(double value) {
		std::fill(begin(), end(), value);
	}
	vector& operator=(const vector& other) {
		if (this != &other)
			std::copy(other.begin(), other.end(), begin());
		return *this;
	}
	~vector() {};

	bool operator==(const vector<T, _size>& other) const {
		for (size_t i = 0; i < _size; i++)
			if (_data[i] != other[i])
				return false;
		return true;
	}

	T& operator[](size_t index) { return _data[index]; }
	T operator[](size_t index) const { return _data[index]; }

	T* begin() { return _data; }
	const T* begin() const { return _data; }
	T* end() { return _data + _size; }
	const T* end() const { return _data + _size; }

	size_t size() const { return _size; }

	vector scale(double value) const {
		vector<T, _size> res = *this;
		std::transform(
			begin(), end(), res.begin(),
			[value](T item) { return item * value; });
		return res;
	}
	vector operator*(double value) const { return scale(value); }
	vector operator/(double value) const { return scale(1.0 / value); }

	vector sum(const vector& other) const {
		vector<T, _size> res;
		for (size_t i = 0; i < _size; i++) {
			res[i] = _data[i] + other[i];
		} return res;
	}
	vector operator+(const vector& other) const { return sum(other); }

	vector sub(const vector& other) const {
		vector<T, _size> res;
		for (size_t i = 0; i < _size; i++) {
			res[i] = _data[i] - other[i];
		} return res;
	}
	vector operator-(const vector& other) const { return sub(other); }

	double dot(const vector& other) const {
		double product = 0;
		for (size_t i = 0; i < _size; i++) {
			product += _data[i] * other[i];
		} return product;
	}
	double operator*(const vector& other) const { return dot(other); }

	vector<T, 3> cross(const vector<T, 3>& other) const {
		static_assert(_size == 3);
		return {
			_data[1] * other[2] - _data[2] * other[1],
			_data[2] * other[0] - _data[0] * other[2],
			_data[0] * other[1] - _data[1] * other[0]
		};
	}

	double length() const {
		return
			std::sqrt(
				std::accumulate(
					begin(),
					end(), (double)0,
					[](double prev, double curr) { return prev + curr * curr; }));
	}

	vector normalize() const { return scale((double)1 / length()); }

	void print() const {
		for (size_t i = 0; i < _size; i++) {
			if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value)
				std::cout << (int)_data[i] << ' ';
			else
				std::cout << _data[i] << ' ';
		} std::cout << '\n';
	}

private:
	T _data[_size];
};

template <typename T, size_t _size>
vector<T, _size> operator*(double value, const vector<T, _size>& vec) {
	return vec.scale(value);
}

template <typename T, size_t _size>
vector<T, _size> operator/(double value, const vector<T, _size>& vec) {
	return vec.scale(1.0 / value);
}
