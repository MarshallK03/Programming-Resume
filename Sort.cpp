#include "Sort.h"
using namespace std;

Node::Node(int value) : data(value), next(nullptr) {}

linkedList::linkedList() : head(nullptr) {}

void linkedList::append(int value) {
	if (!head) {
		head = new Node(value);
		return;
	}
	Node* current = head;
	while (current->next) {
		current = current->next;
	}
	current->next = new Node(value);
}

void linkedList::display() {
	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void linkedList::insertion_sort() {
	if (!head || !head->next) {
		return; //list is empty or only has one element
	}

	Node* sorted = nullptr;
	Node* current = head;

	while (current) {
		Node* next = current->next;

		sorted = sorted_insert(sorted, current);
		current = next;
	}

	head = sorted;
}

Node* linkedList::sorted_insert(Node* sorted, Node* newNode) {
	if (!sorted || newNode->data < sorted->data) {
		newNode->next = sorted;
		return newNode;
	}
	else {
		Node* current = sorted;
		while (current->next && current->next->data < newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		return sorted;
	}
}
int main() {
	linkedList list;

	list.append(2);
	list.append(7);
	list.append(9);
	list.append(1);
	list.append(8);
	cout << "Original linked list: ";
	list.display();

	list.insertion_sort();

	cout << "Sorted linked list: ";
	list.display();

	return 0;
}