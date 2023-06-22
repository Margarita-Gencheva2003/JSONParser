#pragma once
#include "vector.hpp"
template <typename T>
//from Angel55 repo, but i use my vector instead of fixed capacity stack
//i don't want to write the big five
class stack {
public:
	void push(const T& obj);
	void push(T&& obj);
	const T& peek() const;
	void pop();
	size_t size() const;
	bool empty() const;
private:
	vector<T> arr;
};
template <typename T>
void stack<T>::push(const T& obj) {
	arr.push_back(obj);
}

template <typename T>
void stack<T>::push(T&& obj) {
	arr.push_back(std::move(obj));
}

template <typename T>
const T& stack<T>::peek() const {
	if (empty())
		throw std::out_of_range("stack is empty! Do not peek elems!");
	return arr[arr.size() - 1];
}
template <typename T>
void stack<T>::pop() {
	if (empty()) 
		throw std::out_of_range("stack is empty! Do not pop elems!");
	arr.pop_back();
}

template<typename T>
inline size_t stack<T>::size() const
{
	return arr.size();
}

template<typename T>
inline bool stack<T>::empty() const
{
	return arr.isEmpty();
}
