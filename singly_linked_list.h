#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdbool.h>

struct node
{
	void *data;
	struct node *next;
};
typedef struct node Node;

struct iterator;

struct singlyLinkedList
{
	Node *head;
	Node *tail;
	size_t sizeOfDataType;
	struct iterator *i;//to avoid dangling pointer in iterator when i free the singly linked list
};
typedef struct singlyLinkedList SinglyLinkedList;

struct iterator
{
	Node *curr;
	struct singlyLinkedList *s;
};
typedef struct iterator Iterator;

Node* newNode(size_t, void *);
SinglyLinkedList* newSinglyLinkedList(size_t);//size_t for sizeOfDataType

void addHead(SinglyLinkedList *, void *);
void addTail(SinglyLinkedList *, void *);

void removeHead(SinglyLinkedList *);
void removeTail(SinglyLinkedList *);
void removeSpecificNode(SinglyLinkedList *, void *);

bool search(SinglyLinkedList *, void *);

SinglyLinkedList* freeSinglyLinkedList(SinglyLinkedList *);

Iterator* newIterator(SinglyLinkedList *);

extern void start(Iterator *);//extern coz i have used inline function
extern bool end(Iterator *);
extern void next(Iterator *);
extern void* data(Iterator *);

Iterator* freeIterator(Iterator *);

#endif