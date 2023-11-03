#include <iostream>
#include <fstream>
#include <cstddef>
#include "List.h"

List::List() {
	head = NULL;
	length = 0;
}

List::List(const List& aList) {
	length = aList.length;
	if (aList.head == NULL)
		head = NULL;
	else
	{
		head = new Node;
		head->field = aList.head->field;

		Node* newPtr = head; // new list pointer 

		for (Node* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->field = origPtr->field;
		}
		newPtr->next = NULL;
	}
}

List::List(const char* fileName) {
	try
	{
		ifstream file;
		file.open(fileName);
		head = NULL;
		length = 0;
		if (!file) {
			throw - 1;
		}
		int ch;

		if (!file.eof()) {
			head = new Node;
			file >> ch;
			head->field = ch;
			head->next = NULL;
			length++;
		}
		Node* current = head;
		while (!file.eof()) {
			file >> ch;
			length++;
			current->next = new Node;
			current = current->next;
			current->field = ch;
			current->next = NULL;
		}
	}
	catch (const int n)
	{
		cerr << "Ошибка! Файл не открылся\n";
	}
}

bool List::isEmpty() const {
	return bool(length == 0);
}

int List::getLength() const {
	return length;
}

Node* List::find(int index) const {
	if ((index < 1) || (index > getLength())) {
		return NULL;
	}
	else
	{
		Node* cur = head;
		for (int skip = 1; skip < index; ++skip)
			cur = cur->next;
		return cur;
	}
}

int List::getValue(Node* p) {
	return p->field;
}

void List::setValue(Node* p, int value) {
	p->field = value;
}

Node* List::getFirst() {
	return head;
}

Node* List::getLast() {
	Node* current = head;
	Node* next = current->next;
	while (next != NULL) {
		current = next;
		next = current->next;
	}
	return current;
}

void List::insert(int index, int value) {
	Node* newPtr = new Node();
	newPtr->field = value;
	length++;
	if (index == 1 || index == 0) { 
		newPtr->next = head; 
		head = newPtr;
	}
	else {
		Node* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next = newPtr;
	}
}

List::List(int num) {
	head = NULL;
	length = num;
	if (num == 0)
		return;
	cout << "Введите значения для списка:\n";
	int n, i = 1;

	head = new Node;
	cout << i++ << ": ";
	cin >> n;
	head->field = n;
	head->next = NULL;
	Node* current = head;
	for (i = 2; i <= length; i++) {
		cout << i << ": ";
		cin >> n;
		current->next = new Node;
		current = current->next;
		current->field = n;
		current->next = NULL;
	}
}

void List::remove(int index) {
	Node* cur;
	length--;
	if (index == 1) {
		cur = head;
		head = head->next;
	}
	else {
		Node* prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
	}
	cur->next = NULL;
	delete cur;
	cur = NULL;
}

Node* List::next(Node* node) {
	if (head != NULL) {
		return node->next;
	}
	return NULL;
}

void List::show() {
	if (head == NULL) {
		cout << "Список пуст!\n";
		return;
	}
	Node* current = head;
	while (current != NULL) {
		cout << getValue(current) << " ";
		current = current->next;
	}
	cout << endl;
}

List::List(int arr[], int size) {
	head = NULL;
	length = 0;
	int i = 0;
	head = new Node;
	head->field = arr[i++];
	head->next = NULL;
	length++;
	Node* current = head;
	for (i; i < size; i++) {
		current->next = new Node;
		current = current->next;
		current->field = arr[i];
		length++;
		current->next = NULL;
	}
}

List::~List() {
	while (!isEmpty())
		remove(1);
}

List List::operator=(const List& list2) {
	List list1(list2);
	return list1;
}

std::ofstream& operator<<(std::ofstream& f, List& obj)
{
	if (obj.getFirst() == NULL) {
		f << "Список пуст!\n";
		return f;
	}
	Node* current = obj.getFirst();
	while (current != NULL) {
		f << obj.getValue(current) << "  ";
		current = current->next;
	}
	f << endl;
	return f;
}
