#pragma once
#include <stdexcept>
template <typename T>
class vector {
public:
	vector(size_t n = 8);
	vector(size_t n, const T& elem);

	vector(const vector<T>& other);
	vector<T>& operator=(const vector<T>& other);

	vector(vector<T>&& other);
	vector<T>& operator=(vector<T>&& other);

	void push_back(const T& elem);
	void push_back(T&& elem);
	void pop_back();
	void remove(size_t pos);//this method 
	//is wriiten by chatGPT

	const T& operator[](size_t at) const;
	T& operator[](size_t at);

	const T& at(size_t at) const;
	T& at(size_t at);

	bool isEmpty() const;
	size_t size() const;
	size_t capacity() const;
	bool contains(const T& elem) const;
	void clear();
	void resize(size_t newCapacity);
	~vector();
private:
	T* m_data;
	size_t m_size;
	size_t m_capacity;
	void copyFrom(const vector<T>& other);
	void moveFrom(vector<T>&& other);
	void free();

};

template <typename T>
vector<T>::vector(size_t n) {
	this->m_capacity = n;
	this->m_size = 0;
	this->m_data = new T[m_capacity];
}

template <typename T>
vector<T>::vector(size_t n, const T& elem)
{
	if (n == 0)
		throw std::invalid_argument("v count of elems <= 0!!!");
	this->m_size = n;
	this->m_capacity = n;
	this->m_data = new T[n];
	for (size_t i = 0; i < m_size; i++) {	// std::fill
		this->m_data[i] = elem;
	}
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
	copyFrom(other);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
vector<T>::vector(vector<T>&& other) {
	moveFrom(std::move(other));
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
vector<T>::~vector() {
	free();
}

template <typename T>
void vector<T>::copyFrom(const vector<T>& other) {
	this->m_data = new T[other.m_capacity];
	for (int i = 0; i < other.m_capacity; i++) {
		this->m_data[i] = other.m_data[i];
	}
	this->m_capacity = other.m_capacity;
	this->m_size = other.m_size;
}

template <typename T>
void vector<T>::moveFrom(vector<T>&& other) {
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_data = other.m_data;
	other.m_data = nullptr;
	other.m_size = other.m_capacity = 0;
}

template <typename T>
void vector<T>::free() {
	delete[] m_data;
	m_data = nullptr;
}

template <typename T>
void vector<T>::resize(size_t newCapacity) {
	T* resizedData = new T[newCapacity];
	for (size_t i = 0; i < m_size; i++) {	// std::copy
		resizedData[i] = m_data[i];
	}
	m_capacity = newCapacity;
	free();
	m_data = resizedData;
}

template <typename T>
void vector<T>::push_back(const T& elem) {
	if (m_size == m_capacity)
		resize(m_capacity * 2);
	m_data[m_size] = elem;
	m_size++;
}

template <typename T>
void vector<T>::push_back(T&& elem) {
	if (m_size == m_capacity)
		resize(m_capacity * 2);
	m_data[m_size] = std::move(elem);// move op=
	m_size++;
}

template <typename T>
void vector<T>::pop_back() {
	if (isEmpty())
		throw std::logic_error("Empty vector!");
	m_size--;
}
template <typename T>
void vector<T>::remove(size_t pos) {
	if (pos >= m_size) {
		throw std::out_of_range("you try to access memory that is not allocated!!!");
	}
	for (size_t i = pos; i < m_size - 1; i++) {
		m_data[i] = m_data[i + 1];
	}
	m_size--;
}
template <typename T>
bool vector<T>::contains(const T& elem) const {
	for (size_t i = 0; i < this->m_size; i++) {
		if (this->m_data[i] == elem) {
			return true;
		}
	}
	return false;
}
template <typename T>
const T& vector<T>::at(size_t at) const {
	if (at >= m_size) {
		throw std::out_of_range("you try to access memory that is not allocated!!!");
	}
	return m_data[at];
}

template <typename T>
const T& vector<T>::operator[](size_t at) const {
	return m_data[at];
}

template <typename T>
T& vector<T>::at(size_t at) {
	if (at >= m_size) {
		throw std::out_of_range("you try to access memory that is not allocated!!!");
	}
	return m_data[at];
}

template<typename T>
T& vector<T>::operator[](size_t at) {
	return m_data[at];
}

template <typename T>
bool vector<T>::isEmpty() const {
	return m_size == 0;
}

template <typename T>
size_t vector<T>::size() const {
	return m_size;
}

template <typename T>
size_t vector<T>::capacity() const {
	return m_capacity;
}

template <typename T>
void vector<T>::clear() {
	free();
	m_size = 0;
}


