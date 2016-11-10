// Assignment #5 My-Pod
// Michael Cohen

#include "stdafx.h"
#include <iostream>
using namespace std;

//list node Class
class node
{
	char data;
	node *next;
public:
	node(int x);
	friend class linkedList;
};

node::node(int x)
{
	data = x;
	next = NULL;
}

//Linked List Class
class linkedList
{
	node *head;
	node *tail;
public: 
	linkedList();
	void addNodeToEnd(node *nptr);
	void addNodeToHead(node *nptr);
	int insertAfter(node *ptr, int i);
	int removeNode(int i);
	void showList();
	node * findItem(int i);

};

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

void linkedList::showList()
{
	node *ptr;
	ptr = head;
	cout << "****  List Contents *****" << endl;
	if (ptr == NULL)
	{
		cout << "list is empty " << endl;
		return;
	}
	cout << "(head is " << head->data << " tail is " << tail->data << ")" << endl;
	while (ptr != NULL)
	{
		cout << "data is " << ptr->data << endl;
		ptr = ptr->next;
	}
}

void linkedList::addNodeToEnd(node *ptr)
{
	// if lists is empty
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

void linkedList::addNodeToHead(node *ptr)
{
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

int linkedList::insertAfter(node *newnode, int i)
{
	node *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == i) // we found the node to insert after
		{
			newnode->next = ptr->next;
			ptr->next = newnode;
			if (tail == ptr) // repoint tail if we added to end
			{
				tail = newnode;
			}
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

node * linkedList::findItem(int i)
{
	node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == i)
		{
			cout << "found it!" << endl;
			return ptr;
		}
		ptr = ptr->next;
	}
	cout << "Not Found" << endl;
	return NULL;
}

int linkedList::removeNode(int i)
{
	node *ptr = head;
	if (ptr == NULL) // empty list
	{
		return -1;
	}
	//if node is at the head
	if (head->data == i)
	{
		//if only 1 node in the list
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete ptr;
		return 0;
	}

	while (ptr != NULL)
	{
		if (ptr->next && (ptr->next)->data == i)
		{
			if (tail == ptr->next)
			{
				tail = ptr;
			}
			node *tbd = ptr->next;
			ptr->next = (ptr->next)->next;
			delete tbd;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

int main()
{
	linkedList *mylist = new linkedList();

	//
	
	
	return 0;
}

