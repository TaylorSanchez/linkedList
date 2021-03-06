/**
 * Implementation of the linkedList.cpp
 *
 * @author Taylor Sanchez
 * @version 1.0
 * @date Jan 25, 2014
 * @file linkedList.cpp
 */

 /**
  * Summary:
  *		This will create a singly linked list data type.
  * Being singly linked, it must be traversed from the head node downward.
  * this is similar to a stack, but can have data rearranged and entered
  * at mutliple points.
  * Since it lacks an index, the nodes and their pointers must be traversed
  * each time data needs to be accessed.
  * Nodes are the memory allocations for data and pointer storage.
  * Multiple nodes make up a linked list, but I forwent this formality and
  * simply named my struct linkedList as it seemed more fitting to me.
  */

#include <iostream>
#include <fstream>
using namespace std;

struct linkedList{
	int data;
	linkedList *next;
};


/**
 * Creates the first node (or memory space) of the linkedList
 * This Should be called before attemping any other fuctions
 */
linkedList* createLinkedList(){
	//first pointer to start/header of linked list,
	//this will be used to add to the beginning of the linkedList
	linkedList *head = NULL;
	return head;
}


/**
 * Inserts walks through the linkedList and outputs both the data and pointer
 * of each node.
 */
void outputLinkedList(linkedList* head){
	//This will output each node in the linkedList
	linkedList *end;
  	end=head;
  	int i = 0;
	while( end!=NULL ){
		printf("%i ",end->data );
		printf("%p\n",end->next );
		end = end->next;   // tranfer the address of 'end->next' to 'end'
		if (i > 9){break;}
		i++;
	}
	printf("\n");
}


/**
 * Inserts a new node to the top/beginning of the linkedList.
 * This will replace the head node with the new data, and move the data down
 * the 'stack'.
 */
linkedList* insertToHead(int newData, linkedList *head){
	//temporary pointer for 'juggling' nodes, also first data holder
	linkedList *newHead = NULL;
	newHead = (linkedList*)malloc(sizeof(linkedList));

	newHead->data = newData;
	newHead->next = head;
	return head = newHead;
}


/**
 * Inserts a new node to the end/bottom of the linkedList.
 * The head node stays constant, so there is no need for a return value.
 */
void insertToEnd(int newData, linkedList *head){
	//This adds a node to the END of the linkedList
	linkedList *temp = NULL;
	linkedList *end = NULL;
	end = (linkedList*)malloc(sizeof(linkedList));

	temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
  	}
	end->data = newData;
	end->next = NULL;
	temp->next = end;
}


/**
 * Inserts a new node to the middle of the linkedList.
 * The head node stays constant, so there is no need for a return value.
 * nodeLocation requires a minimum of 2 be input, as it will not insert
 * to the top location. Instead use insertToTop, as it requires the head node
 * to change, and must return a value.
 */
void insertToMid(int newData, int nodeLocation, linkedList *head){
	//inserting after 'x' number of nodes
	linkedList *temp = NULL;
	linkedList *mid = NULL;
	mid = (linkedList*)malloc(sizeof(linkedList));
	temp = head;
	for( int i = 1; i <= nodeLocation ; i++ ){
		if( temp->next == NULL ){
	    	printf("Node %i does not exist,"
	    	       " added to end Node.\n", nodeLocation);
	    	mid->data = newData;
	    	mid->next = NULL;
	    	temp->next = mid;
	    	break;
	    }

	    else if ( i == nodeLocation ){
	      	mid->data = newData;
	      	mid->next = temp->next;
	      	temp->next = mid;
	      	break;
	    }
	   temp = temp->next;
	}
}


/**
 * Inserts a new node to any part of the linkedList.
 * This function has logic to automatically chose insertToTop/End/Mid
 * based on the imput it is given.
 */
linkedList* insertNode(int newData, int nodeLocation, linkedList *head){
	if ( nodeLocation == 0 ){
		head = insertToHead(newData, head);
	}
	else if ( nodeLocation == -1 )
	{
		insertToEnd(newData, head);
	}
	else{
		insertToMid(newData, nodeLocation, head);
	}
	return head;
}


/**
 * Moves the a node to the last position of the linkedList
 * tempPrt: points to the node being moved
 * stepPtr: pointer used to traverse through linkedList
 * This is is called as needed by moveNode()
 */
void moveToEnd( linkedList *tempPtr, linkedList *stepPtr){
	tempPtr->next = NULL;
	stepPtr->next = tempPtr;
}


/**
 * Moves the head node to the the new position specified
 * newLocation: new position specified
 * tempPrt: points to the node being moved
 * stepPtr: pointer used to traverse through linkedList
 * head: the head node used to traverse down
 * This is is called as needed by moveNode()
 */
linkedList* moveHeadNode(int newLocation, linkedList* tempPtr,
                          linkedList* stepPtr, linkedList* head)
{
	tempPtr = stepPtr;
	head = stepPtr->next;
	//update pionter to point past the one we are moving
	stepPtr->next = tempPtr->next;
	//start back at the top:
	stepPtr = head;
	if ( newLocation == -1 ){
		while( stepPtr->next != NULL ){ stepPtr = stepPtr->next; }
		moveToEnd( tempPtr, stepPtr );
	}
	for( int j=0; j <=  newLocation; j++){
		if( stepPtr->next == NULL ){
			moveToEnd( tempPtr, stepPtr);
			break;
		}
		else if ( j == newLocation - 2 ){
			tempPtr->next = stepPtr->next;
			stepPtr->next = tempPtr;
			break;
		}
		stepPtr = stepPtr->next;
	}
	return head;
}


/**
 * Moves the a node specified to the the new position specified
 * currentLocation: node specified
 * newLocation: new position specified
 * tempPrt: points to the node being moved
 * stepPtr: pointer used to traverse through linkedList
 * head: the head node used to traverse down
 * This is is called as needed by moveNode()
 */
linkedList* moveMidNode(int currentLocation, int newLocation,
                        linkedList* tempPtr,linkedList* stepPtr,
                        linkedList* head )
{
	for( int i = 0; i <= currentLocation ; i++ ){
	    if( stepPtr->next == NULL ){
	    	printf("Node %i for currentLocation does not exist. "
	    	       "Exiting moveNode early.\n", currentLocation );
	    	break;
	    }
	    else if ( i == currentLocation-2 ){
	    	tempPtr = stepPtr->next;
	    	stepPtr->next = tempPtr->next;
	    	stepPtr = head;
	    	if ( newLocation == -1 ){
	    		while( stepPtr->next != NULL ){ stepPtr = stepPtr->next; }
			    moveToEnd( tempPtr, stepPtr);
			    break;
	    	}
	    	for( int j=0; j <=  newLocation; j++){
	    		if ( newLocation == 1 || newLocation == 0){
	    			tempPtr->next = head;
	    			head = tempPtr;
	    			break;
	    		}
				else if( stepPtr->next == NULL ){
			    	moveToEnd( tempPtr, stepPtr );
	    			break;
	    		}
	    		else if ( j == newLocation - 2 ){
	    			tempPtr->next = stepPtr->next;
	    			stepPtr->next = tempPtr;
	    			break;
	    		}
	    		stepPtr = stepPtr->next;
	    	}
	    	break;
	    }
		stepPtr = stepPtr->next;
	}
	return head;
}


/**
 * Moves the last node to the the new position specified
 * newLocation: new position specified
 * tempPrt: points to the node being moved
 * stepPtr: pointer used to traverse through linkedList
 * head: the head node used to traverse down
 * This is is called as needed by moveNode()
 */
linkedList* moveEndNode(int newLocation, linkedList* tempPtr,
                         linkedList* stepPtr, linkedList* head)
{
	while( stepPtr->next->next != NULL ){ stepPtr = stepPtr->next; }
	tempPtr = stepPtr->next;
	stepPtr->next = NULL;
	stepPtr = head;
	if ( newLocation == -1 ){
		while( stepPtr->next != NULL ) { stepPtr = stepPtr->next; }
		moveToEnd( tempPtr, stepPtr );
	}
	for ( int j=0; j <=  newLocation; j++){
		if ( newLocation == 1 || newLocation == 0){
			tempPtr->next = head;
			head = tempPtr;
			break;
		}
		else if ( stepPtr->next == NULL ){
	    	moveToEnd( tempPtr, stepPtr );
			break;
		}
		else if ( j == newLocation - 2 ){
			tempPtr->next = stepPtr->next;
			stepPtr->next = tempPtr;
			break;
		}
		stepPtr = stepPtr->next;
	}
	return head;
}


/**
 * Moves a node specified to the the new position specified
 * currentLocation: node specified
 * newLocation: new position specified
 * tempPtr: points to the node being moved
 * stepPtr: pointer used to traverse through linkedList
 * head: the head node used to traverse down
 * This calls the necessary functions needed based on the input
 * shorthand:
 * 		0  for newLocation/Location refers to the head node or 1st position
 * 		-1 for newLocation/Location refers to the last node or last position
 */
linkedList* moveNode(int currentLocation,int newLocation,linkedList* head){
	linkedList *stepPtr;
	linkedList *tempPtr;
	stepPtr = head;
	if ( currentLocation == -1 )
	{
		head = moveEndNode(newLocation, tempPtr, stepPtr, head);
	}
	else if ( currentLocation == 0 || currentLocation == 1 ){
		head = moveHeadNode(newLocation, tempPtr, stepPtr, head);
	}
	else {
		head = moveMidNode(currentLocation, newLocation, tempPtr, stepPtr,
		                   head);
	}
	return head;
}



/**
 * Deletes the head node
 * tempPtr: pointer used to hold head location for deletion
 * head: updated to new head node location.
 * This is is called as needed by deleteNode()
 */
linkedList* deleteHeadNode(linkedList* head){
	linkedList* tempPtr;
	tempPtr = head;			// xfer the address of 'head' to 'tempPtr'
	head = head->next;		// set head equal to next Node in list
	free(tempPtr);
	return head;
}


/**
 * Deletes the end node
 * stepPtr: pointer used to traverse through linkedList,
 *			and is eventually deleted
 * head: the head node used to start traverse downward
 * This is is called as needed by deleteNode()
 */
void deleteEndNode(linkedList* head){
	//This deletes a node to the END of the linkedList
	linkedList* stepPtr;
	linkedList* end;
	stepPtr = head;              // transfer the address of 'head' to 'end'
	while(stepPtr->next!=NULL){ // go to the last node
		end = stepPtr;
			stepPtr = stepPtr->next;//tranfer the address of
			//'end1->next' to 'end'
	}
	end->next = NULL;
	free(stepPtr);
}


/**
 * Deletes the a node to the the node position specified
 * nodeLocation: node position specified
 * stepPtr: pointer used to traverse through linkedList,
 *			and is eventually deleted
 * head: the head node used to start traverse downward
 * This is is called as needed by deleteNode()
 */
void deleteMidNode(int nodeLocation, linkedList* head){
	linkedList* stepPtr;
	linkedList* end;
	stepPtr = head;
	for( int i = 1; i <= nodeLocation ; i++ ){
		if( stepPtr->next == NULL ){
		    if ( i++ == nodeLocation ) { deleteEndNode(head); }
		    else { printf("Node %i does not exist.\n", nodeLocation); }
		    break;
		  }
		else if ( i == nodeLocation ){
		    end->next = stepPtr ->next;
		    free(stepPtr);
		    break;
		}
		end = stepPtr;
		stepPtr = stepPtr->next;           // go to the next node
	}
}


/**
 * Deletes the node specified to the the
 * nodeLocation: node specified
 * head: the head node used to traverse down and update for return
 * This calls the necessary functions needed based on the input
 * shorthand:
 * 		0  for nodeLocation refers to the head node or 1st position
 * 		-1 for nodeLocation refers to the last node or last position
 */
linkedList* deleteNode(int nodeLocation, linkedList* head){
	if (nodeLocation == -1 ){ deleteEndNode(head); }
	else if ( nodeLocation == 1 | nodeLocation == 0 ){
		head = deleteHeadNode(head);
	}
	else { deleteMidNode(nodeLocation, head); }
	return head;
}

void changeData(int nodeLocation, int nodeData, linkedList* head){
	linkedList* stepPtr;
	stepPtr = head;
	if ( nodeLocation == 0 ) { head->data = nodeData; }
	else if ( nodeLocation == -1 ) {
		while( stepPtr->next!=NULL ){ stepPtr = stepPtr->next; }
		stepPtr->data = nodeData;
	}
	else for( int i = 1; i <= nodeLocation ; i++ ){
		if( stepPtr->next == NULL ){
		    if ( i++ == nodeLocation ) { stepPtr->data = nodeData; }
		    else { printf("Node %i does not exist.\n", nodeLocation); }
		    break;
		  }
		else if ( i == nodeLocation ){
	    	stepPtr->data = nodeData;
			break;
		}
		stepPtr = stepPtr->next;           // go to the next node
	}
}

/**
 *Change functions here to make use of linkedList
 */
int main(){
	int node_number;
	//first pointer to start/header of linked list,
	//this will be used to add to the beginning of the linkedList
	linkedList *head = createLinkedList();
	head = insertToHead(345, head);
	head = insertToHead(346, head);
	head = insertToHead(347, head);
	insertToEnd(344, head);
	insertToEnd(343, head);
	insertToEnd(342, head);
	insertToEnd(341, head);

	insertToMid(5000, 2, head);

	head = insertNode(80085, 7, head);

	outputLinkedList(head);

	//head = moveNode(0,-1,head); //add -1 to choose last one

	//head = deleteNode(9, head);

	changeData(-1, 348, head);

	outputLinkedList(head);

return 0;
}
