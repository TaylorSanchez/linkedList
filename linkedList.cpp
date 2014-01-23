#include <iostream>
#include <fstream>
using namespace std;

struct linkedList
{
	int data;
	linkedList *next;
};

int main(){

	int nums=2;
	int array[nums];
	int divs=nums/2;
	int endarr;

	//first pointer to start/header of linked list,
	//this will be used to add to the beginning of the linkedList
	linkedList *head = NULL;

	//temporary pointer for 'juggling' nodes, also first data holder
	linkedList *temp = NULL;

	//declare this will be used to add to either end of the linkedList,
	//as well as mid breaks created for mid inserts
	linkedList *end;

	//allocate the memory for my 1st link in the list, added to the beginning.
	end = (linkedList*)malloc(sizeof(linkedList));
	end->data = 345;
	end->next = head;
	head = end;

	//allocate the memory for my 2nd link in the list added to the beginning.
	end = (linkedList*)malloc(sizeof(linkedList));
	end->data = 346;
	end->next = head;
	head = end;

	//allocate the memory for my 3rd link in the list, added to the beginning.
	end = (linkedList*)malloc(sizeof(linkedList));
	end->data = 347;
	end->next = head;
	head = end;


	//This adds a node to the END of the linkedList
	end=(linkedList*)malloc(sizeof(linkedList));   // allocate space for node
	temp = head;              // transfer the address of 'head' to 'end'
	while(temp->next!=NULL){ // go to the last node
		temp = temp->next;//tranfer the address of 'end1->next' to 'end'
  	}
	end->data = 344;                   // store data(first field)
	end->next = NULL;                   // second field will be null(last node)
	temp->next = end;
	printf("\n\nadded to end\n\n");


	//This adds a node to the END of the linkedList
	end=(linkedList*)malloc(sizeof(linkedList));   // allocate space for node
	temp = head;              // transfer the address of 'head' to 'end'
	while(temp->next!=NULL){ // go to the last node
		temp = temp->next;//tranfer the address of 'end1->next' to 'end'
  	}
	end->data = 343;                   // store data(first field)
	end->next = NULL;                   // second field will be null(last node)
	temp->next = end;
	printf("\n\nadded to end\n\n");

	//This will output each node in the linkedList
	end=(linkedList*)malloc(sizeof(linkedList));
  	end=head;
	while( end!=NULL ){
		printf("\n");
		cout<< end->data<<" ";// show the data in the linked list
		cout<< end->next<<" ";
		end = end->next;   // tranfer the address of 'end->next' to 'end'
	}
	printf("\n");

	//inserting after 'x' number of nodes
	int node_number;
	cout<<"ENTER THE NODE NUMBER:";
	cin>>node_number;                   // take the node number from user

	temp = (linkedList*)malloc(sizeof(linkedList)); // allocate space for node
	temp = head;

	for( int i = 1 ; i < node_number ; i++ ){
	    temp = temp->next;           // go to the next node
	    if( temp == NULL ){
	    	printf("Node %i does not exist.\n", node_number);
	    	break;
	    }
	    else{
	      	end=(linkedList*)malloc(sizeof(linkedList));
	      	end->data=500;
	      	end->next=temp->next;
	      	temp->next=end;
	    }

	}


	//This will output each node in the linkedList
	end=(linkedList*)malloc(sizeof(linkedList));
  	end=head;
	while( end!=NULL ){
		printf("\n");
		cout<< end->data<<" ";// show the data in the linked list
		cout<< end->next<<" ";
		end = end->next;   // tranfer the address of 'end->next' to 'end'
	}
	printf("\n");


	linkedList *temp;                                      // create a temporary node
	temp = (linkedList*)malloc(sizeof(linkedList));  // allocate space for node
	temp = head;                   // transfer the address of 'head' to 'temp'
	head = temp->next;      // transfer the address of 'temp->next' to 'head'
	free(temp);



	// for (int i=0;i<nums;i++){
	// 	printf("%i. Please enter your number\n", i);
	// 	cin >> array[i];
	// }
	// printf("=========================\n\n");

	// for(int i=0;i<nums;i++){
	// 	if (array[i]>array[i+1]){
	// 		endarr=array[i];
	// 		array[i]=array[i+1];
	// 		array[i+1]=endarr;
	// 	}
	// 	printf("%i is >= %i\n\n",array[i+1],array[i]);
	// 	i++;
	// }
return 0;
}
