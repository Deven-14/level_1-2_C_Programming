#ifndef LIST_H
#define LIST_H

typedef struct node
{
	void *data;
	struct node *next;
}Node;
typedef struct list
{
	Node *head;
	Node *tail;
	unsigned int count;
}List;

Node* create_node(void *val);
List* create_list();
void input_list(List *l,int a,int b[]);//should change typecast for different datatypes
void add_head(List *l,void *val);
void add_tail(List *l,void *val);
void insert_after_specfic_node(List *l,Node *n,void *val);
void insert_at_specfic_index(List *l,int ind,void *val);
void* pop_head(List *l);
void* pop_tail(List *l);
void pop_specfic_val(List *l,void *val);//should change typecast for different datatypes
void pop_by_index(List *l,int ind);
void print_list(List *l);//should change typecast for different datatypes
void output_count(int c);
void list_empty(List *l);
void list_delete(List *l);

void input_fuctions_trial(List *l,int *b,int d);
void deleting_fuctions_trial(List *l,int *c);

#endif