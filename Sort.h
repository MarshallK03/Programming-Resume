#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;

	Node(int value);
};

class linkedList {
public: 
	Node* head;
	//Default constructor for the linked list
	linkedList(); 
	//Function to append a value to the linked list
	void append(int value);
	//Function to display the order of the current linked list
	void display();
	//Insertion sort performed on the linked list	
	void insertion_sort();

private:
	//Inserts node in sorted order
	Node* sorted_insert(Node* sorted, Node* newNode);
};