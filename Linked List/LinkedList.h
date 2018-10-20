#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node {
	public:
		Node *next;
		T data;
};

template <class T>
class LinkedList {
	private:
		Node<T> *head;
		
	public:
		LinkedList();
		void AddNode(T data);
		void DeleteNode(T data);
		void PrintList();
};

#endif
