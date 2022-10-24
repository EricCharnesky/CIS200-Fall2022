using namespace std;

#include <vector>
#include <iostream>
#include "DoublyLinkedList.h"

int main() {

	DoublyLinkedList<int> list;

	list.add_front(12);

	list.add_back(16);

	list.add_at(15, 1);

	list.print();

	list.remove_at(2);

	list.print();

	list.remove_front();

	list.print();

	list.remove_at(0);

	list.print();

	return 0;
}