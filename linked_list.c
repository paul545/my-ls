//Paul Bosonetto 2018.02.12

#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// constructor
linked_list * create_linked_list(){ // return linked_list * (pointer)
		
	linked_list* ll = (linked_list*) malloc(sizeof(linked_list)); //malloc returns void pointer
	ll->count = 0;
	ll->head = NULL;
	return ll;
}


// destructor
void destroy_linked_list( linked_list* ll){
	
	//empty the linked list
	while ( ll->count > 0){
		linked_list_delete( ll, ll->head );
	}
	//unallocate the memory
	free(ll);
	
}


//add new node to end of linked list
void linked_list_add( linked_list * ll, char * data_in){

	
	node* n = (node *) malloc( sizeof(node));
	n->data = (char *) malloc( sizeof(char)* (strlen(data_in) +1));
	strcpy(n->data, data_in);
	n->next = NULL;
	
	
	//traverse the list
	node * t = ll->head;
	if (t == NULL){
		ll->head = n;
	} else{
		while ( t->next != NULL){
			t = t->next;
		}
		t->next = n;
	}
	
	
	
	//increase the size
	ll->count++;

}

//Delete a node from the linked list
void linked_list_delete( linked_list * ll, node * to_delete){
	
	node* prev_node;
	if (ll->head == NULL){
		printf("Error, linked_list_delete() empty list\n");
		return;
	}
	else if(to_delete == ll->head){
		ll->head = ll->head->next;
	}
	else {
		for(prev_node = ll->head; prev_node->next != NULL; prev_node = prev_node->next){
			if (prev_node->next == to_delete){
				break;
			}
		}
		if (prev_node->next == NULL){
			printf("Error, linked_list_delete(), could not find item in list\n");
			return;
		}
		prev_node->next = to_delete->next; //connect the list
	}
	
	//free and reduce size
	ll->count--;
	free(to_delete->data);
	free(to_delete);
	
	
	

}

// search for a node by it's data field
node * linked_list_search( linked_list* ll,  char* search_string ){

	node* n;
	for (n=ll->head; n != NULL; n = n->next){
		if (strcmp(n->data, search_string) == 0){
			break;
		}
	}
	if (n == NULL){
		printf("Error, linked_list_search(), could not find element in list\n");
		return NULL;
	}
	// success, found the element
	return n;

}

// get node by index
node* linked_list_get ( linked_list* ll, int index){

	int count = 0;
	node* n = ll->head;
	
	if (ll->head == NULL){
		printf("Error, linked_list_get(), list is empty");
		return NULL;
	}
	
	while (count < index){
		if (n->next == NULL){
			printf("Error, linked_list_get(), list shorter than %i \n", index);
			return NULL;
		}
		n = n->next;
		count++;
	}
	return n;
}

void linked_list_print( linked_list* ll){
	
	node* n = ll->head;
	if (ll->head == NULL){
		printf("Error, linked_list_print(), list is empty");
		return;
	}
	
	while (n->next != NULL){
		printf("%s\n", n->data);
		n = n->next;
	}
	printf("%s\n", n->data);
	
	
	return;
}


node* sortList( node* front ){
	
	node *a, *b, *top;
	int changed = 1;
	
	if ((top = (node *)malloc(sizeof(node))) == NULL){
		printf("Malloc error.\n");
		exit(1);
	}
	
	top->next = front;
	if( front != NULL && front->next != NULL){	
		while (changed){
			changed = 0;
			b = top;
			a = top->next;
			
			while (a->next){
				if (strcmp (a->data, a->next->data) > 0){
					b->next = nodeSwap(a, a->next);
					changed = 1;
				}
				b = a;
				if (a->next){
					a = a->next;
				}
			}
		}
	}
	a = top->next;
	free(top);
	return a;
}

node* nodeSwap( node* x, node* y){
	
	x->next = y ->next;
	y->next = x;
	return y;

}
































