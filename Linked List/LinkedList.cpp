#include "LinkedList.h"
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
	this->head = NULL;
}

template <class T>
void LinkedList<T>::AddNode(T data)
{
	Node<T> *temp = new Node<T>();
	temp->data = data;
	temp->next = this->head;
	this->head = temp;
}

template <class T>
void LinkedList<T>::PrintList()
{
	Node<T> *currentNode = this->head;
	while(currentNode != NULL) {
		cout<<currentNode->data<<" ";
		currentNode = currentNode->next;
	}
}

template <class T>
void LinkedList<T>::DeleteNode(T data)
{
	Node<T> *currentNode = this->head, *prevNode = this->head;
	while (currentNode != NULL && currentNode->data != data)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	
	if (currentNode != NULL)
	{
		if (prevNode != currentNode)
		{
			prevNode->next = currentNode->next;
		}
		else
		{
			this->head = currentNode->next;
		}
		
		delete currentNode;
	}
}

template class LinkedList<int>;
