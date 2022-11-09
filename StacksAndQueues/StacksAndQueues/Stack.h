#pragma once

#include "CircularDoublyLinkedList.h"

template <typename T>
class Stack {
private:
	CircularDoublyLinkedList<T> list;
public:
	Stack() {
		
	}

	void push(T item) {
		list.add_front(item);
	}

	T pop() {
		return list.remove_front();
	}

	T peek() {
		return list.at(0);
	}

	int size() {
		return list.size();
	}

	bool isEmpty() {
		return list.size() == 0;
	}

};