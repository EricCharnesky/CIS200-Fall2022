#pragma once

#include "CircularDoublyLinkedList.h"

template <typename T>
class Queue {
private:
	CircularDoublyLinkedList<T> list;
public:
	Queue() {

	}

	void enqueue(T item) {
		list.add_back(item);
	}

	T dequeue() {
		return list.remove_front();
	}

	T front() {
		return list.at(0);
	}

	int size() {
		return list.size();
	}

	bool isEmpty() {
		return list.size() == 0;
	}

};