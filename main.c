//Paul Bosonetto 2018.02.12

#include <stdio.h>
#include <dirent.h>
#include <string.h>


#include "linked_list.h"



int main(int argc, char* argv[]){
	
	linked_list* ll;
	ll = create_linked_list();
	
	char folderName[255];
	DIR *d;
	struct dirent *dir;
	
	
	if (argc == 1){
		d = opendir(".");
	} 
	else if (argc == 2){
		d = opendir(argv[1]);
	}
	
	else {
		printf("Error. Incorrect usage. There should be either 0 or 1 command line args.\n");
		return -1;
	}
	
	if (!d){
		printf("Error, directory '%s' does not exist\n.", argv[1]);
		return -2;
	}
	
	if (d){
		while ((dir = readdir(d)) != NULL){
			strncpy(folderName, dir->d_name, 254);
			folderName[254] = '\0';
			linked_list_add(ll,folderName); //dir->d_name
		}
		closedir(d);
			
	ll->head = sortList(ll->head);
	
	linked_list_print(ll);
	
	} return 0;

}


