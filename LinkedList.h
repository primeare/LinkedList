/*
* Author: Vladyslav Dukhin
* Version: 0.3.0 (01.07.2016)
* Copyright (c) Flexare Inc.
*/

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <initializer_list>

template <typename T>
class LinkedList;

template <typename T>
class ListNode {
private:
	T _value;
	ListNode<T> *_next, *_prev;
	friend LinkedList<T>;
public:
	ListNode(const T&);
	ListNode<T>& operator =(const T&);
	ListNode<T>& operator =(const ListNode<T>&);
	ListNode<T>& operator =(const ListNode<T>*);
	template <typename T>
	friend std::ostream& operator <<(std::ostream&, const ListNode<T>&);
	template <typename T>
	friend std::ostream& operator <<(std::ostream&, const LinkedList<T>&);
};

template <typename T>
class LinkedList {
private:
	ListNode<T> *_head, *_tail;
	size_t _size;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const std::initializer_list<T>&);
	size_t size() const;
	bool isEmpty() const;
	bool contains(const T&) const;
	void add(const T&);
	void add(size_t, const T&);
	void addAll(const std::initializer_list<T>&);
	bool remove(const T&);
	T remove(size_t);
	bool removeAll(const std::initializer_list<T>&);
	void clear();
	T get(size_t) const;
	T set(size_t, const T&);
	size_t indexOf(const T&) const;
	size_t lastIndexOf(const T&) const;
	LinkedList<T>& subList(size_t, size_t) const;
	bool swap(size_t, size_t);
	void sort();
	ListNode<T>& operator [](size_t) const;
	template <typename T>
	friend std::ostream& operator <<(std::ostream&, const LinkedList<T>&);
};

/*
================================= Realization of class ListNode =================================
*/

template <typename T>
ListNode<T>::ListNode(const T &value) : _value(value), _next(nullptr), _prev(nullptr) {}

template <typename T>
std::ostream& operator <<(std::ostream &out, const ListNode<T> &element) {
	out << element._value;
	return out;
}

template <typename T>
ListNode<T>& ListNode<T>::operator =(const T &value) { _value = value; return *this; }

template <typename T>
ListNode<T>& ListNode<T>::operator =(const ListNode<T> &element) { _value = element._value; return *this }

template <typename T>
ListNode<T>& ListNode<T>::operator =(const ListNode<T> *element) { _value = element->_value; return *this }

/*
================================= Realization of class LinkedList =================================
*/

template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
	clear();
	delete _head;
	delete _tail;
	_head = _tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &elements) {
	for (T element : elements)
		add(element);
}

template <typename T>
size_t LinkedList<T>::size() const { return _size; }

template <typename T>
bool LinkedList<T>::isEmpty() const { return _size == 0; }

template <typename T>
bool LinkedList<T>::contains(const T &value) const {
	ListNode<T> *node = _head;
	while (node != nullptr) {
		if (node->_value != value)
			node = node->_next;
		else
			return true;
	}
	return false;
}

template <typename T>
void LinkedList<T>::add(const T &value) {
	ListNode<T> *newElement = new ListNode<T>(value);
	if (_size != 0) {
		newElement->_prev = _tail;
		_tail->_next = newElement;
		_tail = newElement;
	}
	else {
		_head = _tail = newElement;
	}
	++_size;
}

template <typename T>
void LinkedList<T>::add(size_t index, const T &value) {
	if (_size == 0) {
		add(value);
		return;
	}
	if (index >= 0 && index < _size) {
		ListNode<T> *node = _head;
		for (size_t i = 0; i < index; ++i)
			node = node->_next;
		ListNode<T> *newElement = new ListNode<T>(value);
		newElement->_next = node;
		newElement->_prev = node->_prev;
		if (node->_prev != nullptr) node->_prev->_next = newElement;
		node->_prev = newElement;
		if (index == 0) _head = newElement;
		if (index == _size - 1) _tail = newElement->_next;
		++_size;
	}
	else
		throw std::out_of_range("LinkedList :: add(index, value)");
}

template <typename T>
void LinkedList<T>::addAll(const std::initializer_list<T> &elements) {
	for (T element : elements)
		add(element);
}

template <typename T>
bool LinkedList<T>::remove(const T &value) {
	ListNode<T> *node = _head;
	bool isDeleted = false;
	while (node != nullptr) {
		if (node->_value != value)
			node = node->_next;
		else {
			if (node->_prev != nullptr) node->_prev->_next = node->_next;
			if (node->_next != nullptr) node->_next->_prev = node->_prev;
			if (_tail == node && node->_prev != nullptr) _tail = node->_prev;
			if (_head == node && node->_next != nullptr) _head = node->_next;
			if (_head == _tail && _tail == node) _head = _tail = nullptr;
			ListNode<T> *tmp = node->_next;
			node->_next = nullptr;
			node->_prev = nullptr;
			node = tmp;
			tmp = nullptr;
			--_size;
			isDeleted = true;
		}
	}
	return isDeleted;
}

template <typename T>
T LinkedList<T>::remove(size_t index) {
	if (index >= 0 && index < _size) {
		ListNode<T> *node = _head;
		for (size_t i = 0; i < index; ++i)
			node = node->_next;
		if (node->_prev != nullptr) node->_prev->_next = node->_next;
		if (node->_next != nullptr) node->_next->_prev = node->_prev;
		if (_tail == node && node->_prev != nullptr) _tail = node->_prev;
		if (_head == node && node->_next != nullptr) _head = node->_next;
		if (_head == _tail && _tail == node) _head = _tail = nullptr;
		node->_next = nullptr;
		node->_prev = nullptr;
		--_size;
		return node->_value;
	}
	else
		throw std::out_of_range("LinkedList :: remove(index)");
}

template <typename T>
bool LinkedList<T>::removeAll(const std::initializer_list<T> &elements) {
	// TODO : removeAll()
}

template <typename T>
void LinkedList<T>::clear() {
	if (_size != 0) {
		ListNode<T> *node = _tail;
		while (node != nullptr) {
			if (node->_next != nullptr) {
				delete node->_next;
				node->_next = nullptr;
			}
			if (node->_prev != nullptr)
				node = node->_prev;
			else {
				delete node;
				node = nullptr;
			}
		}
		_head = _tail = nullptr;
		_size = 0;
	}
}

template <typename T>
T LinkedList<T>::get(size_t index) const {
	if (index >= 0 && index < _size) {
		ListNode<T> *node = _head;
		for (size_t i = 0; i < index; ++i)
			node = node->_next;
		return node->_value;
	}
	else
		throw std::out_of_range("LinkedList :: get(index)");
}

template <typename T>
T LinkedList<T>::set(size_t index, const T &value) {
	if (index >= 0 && index < _size) {
		ListNode<T> *node = _head;
		for (size_t i = 0; i < index; ++i)
			node = node->_next;
		T tmp = node->_value;
		node->_value = value;
		return tmp;
	}
	else
		throw std::out_of_range("LinkedList :: set(index, value)");
}

template <typename T>
size_t LinkedList<T>::indexOf(const T &element) const {
	// TODO : indexOf()
	return 0;
}

template <typename T>
size_t LinkedList<T>::lastIndexOf(const T &element) const {
	// TODO : lastIndexOf()
	return 0;
}

template <typename T>
LinkedList<T>& LinkedList<T>::subList(size_t fromIndex, size_t toIndex) const {
	// TODO : subList()
	return *(new LinkedList);
}

template <typename T>
bool LinkedList<T>::swap(size_t index1, size_t index2) {
	if (index1 >= 0 && index1 < _size && index2 >= 0 && index2 < _size) {
		ListNode<T> tmp = (*this)[index1];
		(*this)[index1] = (*this)[index2];
		(*this)[index2] = tmp;
		return true;
	}
	else
		return false;
}

template <typename T>
void LinkedList<T>::sort() {
	// TODO : sort()
}

template <typename T>
ListNode<T>& LinkedList<T>::operator [](size_t index) const {
	if (index >= 0 && index < _size) {
		ListNode<T> *node = _head;
		for (size_t i = 0; i < index; ++i)
			node = node->_next;
		return *node;
	}
	else
		throw std::out_of_range("LinkedList :: operator [index]");
}

template <typename T>
std::ostream& operator <<(std::ostream &out, const LinkedList<T> &list) {
	ListNode<T> *node = list._head;
	out << '[';
	while (node != nullptr) {
		if (node->_next != nullptr)
			out << node->_value << ", ";
		else
			out << node->_value;
		node = node->_next;
	}
	out << ']';
	node = nullptr;
	return out;
}

#endif