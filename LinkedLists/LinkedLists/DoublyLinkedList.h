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

	Node<T>* first;
	Node<T>* last;
	int numberOfItems;

	void checkForEmpty() {
		if (numberOfItems == 0) {
			throw logic_error("List is empty!");
		}
	}

public:

	DoublyLinkedList() {
		first = nullptr;
		last = nullptr;
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
			Node<T>* newNode = new Node<T>(data, nullptr, last);
			last->next = newNode;
			last = newNode;
			numberOfItems++;
		}

	}



	T remove_back() {
		checkForEmpty();

		T data = last->data;

		if (numberOfItems == 1) {
			return remove_front();
		}
		else {
			// skip over the old last
			last->previous->next = nullptr;

			// save the node to delete it
			Node<T>* current = last;

			// move first
			last = last->previous;

			delete current;
		}

		numberOfItems--;

		return data;
	}

	T remove_front() {
		checkForEmpty();

		T data = first->data;

		if (numberOfItems == 1) {
			Node<T>* current = first;
			first = nullptr;
			last = nullptr;
			delete current;

		}
		else {
			// skip over the old first
			first->next->previous = nullptr;

			// save the node to delete it
			Node<T>* current = first;

			// move first
			first = first->next;

			delete current;
		}

		numberOfItems--;

		return data;
	}

	// pop back in vector?
	T remove_at(int index) {
		checkForEmpty();

		if (index >= numberOfItems || index < 0) {
			throw logic_error("Invalid index!");
		}

		if (index == 0) {
			return remove_front();
		}
		else if (index == numberOfItems - 1) {
			return remove_back();
		}

		int currentIndex = 0;
		Node<T>* currentNode = first;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		T data = currentNode->data;

		// make the previous node 'jump over' the current node
		currentNode->previous->next = currentNode->next;

		// make the next node 'jump over' the current node
		currentNode->next->previous = currentNode->previous;

		delete currentNode;

		numberOfItems--;

		return data;

	}

	void add_at(T data, int index) {
		int currentIndex = 0;
		Node<T>* currentNode = first;

		while (currentIndex != index) {
			currentNode = currentNode->next;
			currentIndex++;
		}

		Node<T>* newNode = new Node<T>(data, currentNode, currentNode->previous);
		
		// go to the node before the new node, set it's next to the new node
		newNode->previous->next = newNode;

		// go to the node after the new node, set it's previous to the new node
		newNode->next->previous = newNode;

		numberOfItems++;
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

	void print() {
		Node<T>* currentNode = first;

		while (currentNode != nullptr) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

};