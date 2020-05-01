typedef struct node
{
	void *data;
	struct node *next;
}Node;

Node* new_node(void *val);
void input_nodes(Node **head,void *b);
void push_beg(Node **head,void *val);
void push_end(Node **head,void *val);
void insertafter_specfic_node(Node *prev_node,void *val);
void insert_at_specfic_index(Node **head,int ind,void *val);
void* pop_beg(Node **head);
void* pop_end(Node **head);
void pop_specfic_val(Node **head,void *val);
void pop_by_index(Node **head,int ind);
void process(Node **head,void *a);
void print_list(Node *head);
void free_list(Node *head);