//Paul Bosonetto 2018.02.12

#ifndef linked_list_h
#define linked_list_h

//create data structure for a node of the list

struct node_t { //syntax for structure
	char * data;
	struct node_t * next;
};

typedef struct node_t node; //alias

//Data structure for the linked list type

typedef struct{
	node*head;
	int count;
} linked_list;

// functions to manipulate the linked list

// constructor
linked_list * create_linked_list(); // return linked_list * (pointer)

// destructor
void destroy_linked_list( linked_list* ll);

//add new node to end of linked list
void linked_list_add( linked_list * ll, char * data_in);

//Delete a node from the linked list
void linked_list_delete( linked_list * ll, node * to_delete);

// search for a node by it's data field
node * linked_list_search( linked_list* ll,  char* search_string );

// get node by index
node* linked_list_get ( linked_list* ll, int index);

//print out the linked list
void linked_list_print( linked_list* ll);

//swap two nodes for sorting purposes, helper method
node* nodeSwap( node* x, node* y);

//sort the linked list
node* sortList( node* front );








#endif /* linked_list_h*/


