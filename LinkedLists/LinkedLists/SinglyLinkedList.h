#pragma once

using namespace std;

#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* next;

		Node(T data, Node<T>* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	Node<T>* first;
	Node<T>* last;
	int numberOfItems;

public:

	SinglyLinkedList() {
		first = nullptr;
		numberOfItems = 0;
	}

	// TODO - destructor

	// TODO - copy assignment operator

	// TODO - copy constructor

	void add_front(T data) {
		Node<T>* newNode = new Node<T>(data, first);
		first = newNode;
		// must be the first item if it was empty before
		if (numberOfItems == 0) {
			last = newNode;
		}
		numberOfItems++;
	}

	void add_back(T data) {
		// don't do more work than we need to
		if (last == nullptr) {
			add_front(data);
		}
		else {
			Node<T>* newNode = new Node<T>(data);
			last->next = newNode;
			last = newNode;
			numberOfItems++;
		}
		
	}

	T at(int index) {
		if (index >= numberOfItems) {
			throw logic_error("invalid index");
		}

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
		Node<T>* currentNode = first;

		while (currentNode != nullptr && currentNode->data != data) {
			currentIndex++;
			currentNode = currentNode->next;
		}

		if (currentIndex == numberOfItems) {
			throw logic_error("item not found");
		}

		return currentIndex;
	}

};