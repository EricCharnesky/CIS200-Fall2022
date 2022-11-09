#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>

using namespace std;

int main() {

	Stack<int> numbers;

	numbers.push(2);
	numbers.push(4);
	numbers.push(8);

	Queue<int> moreNumbers;
	moreNumbers.enqueue(2);
	moreNumbers.enqueue(4);
	moreNumbers.enqueue(8);

	cout << "Stack:" << endl;
	while (!numbers.isEmpty()) {
		cout << numbers.pop() << endl;
	}

	cout << "Queue:" << endl;
	while (!moreNumbers.isEmpty()) {
		cout << moreNumbers.dequeue() << endl;
	}

}