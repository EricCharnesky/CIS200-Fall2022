#pragma once

#pragma once

using namespace std;

#include <stdexcept>
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* next;
		Node<T>* previous;

		Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr) {
			this->data = data;
			this->next = next;
			this->previous = previous;
		}
	};

	Node<T>* start;
	int numberOfItems;

	void checkForEmpty() {
		if (numberOfItems == 0) {
			throw logic_error("List is empty!");
		}
	}

	T remove_node(Node<T>* current) {
		T data = current->data;

		current->next->previous = current->previous;
		current->previous->next = current->next;

		delete current;

		numberOfItems--;

		return data;
	}

	void add_between(T data, Node<T>* next, Node<T>* previous) {
		Node<T>* newNode = new Node<T>(data, next, previous);
		numberOfItems++;
	}

public:

	CircularDoublyLinkedList() {
		start = new Node<T>(NULL);
		start->next = start;
		start->previous = start;
		numberOfItems = 0;
	}

	// TODO - destructor

	// TODO - copy assignment operator

	// TODO - copy constructor

	void add_front(T data) {
		add_between(data, start->next, start);
	}

	void add_back(T data) {
		add_between(data, start, start->previous);
	}



	T remove_back() {
		checkForEmpty();

		return remove_node(start->previous);
	}

	T remove_front() {
		checkForEmpty();

		return remove_node(start->next);
	}

	// pop back in vector?
	T remove_at(int index) {
		checkForEmpty();

		if (index >= numberOfItems || index < 0) {
			throw logic_error("Invalid index!");
		}

		int currentIndex = 0;
		Node<T>* currentNode = first;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		return remove_node(currentNode);

	}

	void add_at(T data, int index) {
		int currentIndex = 0;
		Node<T>* currentNode = first;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		add_between(data, currentNode, currentNode->previous);
	}

	T at(int index) {
		if (index >= numberOfItems) {
			throw logic_error("invalid index");
		}

		// TODO
		// could check if index is closer to the back half 
		//  and start at last working backwards

		int currentIndex = 0;
		Node<T>* currentNode = first;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		return currentNode->data;
	}

	int indexOf(T data) {
		int currentIndex = 0;
		Node<T>* currentNode = start->next;

		while (currentNode != start && currentNode->data != data) {
			currentIndex++;
			currentNode = currentNode->next;
		}

		if (currentIndex == numberOfItems) {
			throw logic_error("item not found");
		}

		return currentIndex;
	}

	void print() {
		Node<T>* currentNode = start->next;

		while (currentNode != start) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

};