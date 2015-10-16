/***** sorting the linked list using merge sort over the linked lis  ******/
/**** To nderstand the flow can write to me at : gautamsingh2100gmail.com
#include<stdio.h>
#include<stdlib.h>

/***** linked list Node ****/
struct Node
{
	int data ;
	struct Node  * next ;
};
typedef struct Node Node ;

/***** algorithm to get the middle node ******/
Node *middle(Node *head)
{
	Node *temp ;
	if(head->next == NULL)
		return head ;
	else if(head->next->next == NULL)
		return head ;
// clearly there must be at least  three nodes in the list
	temp = head ;
	head = head->next ;
	while(head && head->next)
		{
			temp = temp->next ;
			head = head->next->next ;
		}
	return temp ;
}
	

/***** DIvide and conqure method to sort linked liset *****/
Node *merge_sort(Node *head)
{

	Node *list1 ,*list2 ;
	Node *temp , *newhead  = NULL ,*rear;
	if(!head ||head->next == NULL)	
		return head ;
	
	temp = middle(head) ;
	list2 = temp->next ;
	temp->next = NULL ;
	list1 = merge_sort(head) ;
	list2  = merge_sort(list2) ;

	/***** Merging of two list---> sorted list *****/
	while(list1 && list2 )
	{
		if(list1->data > list2->data)
			{
				if(newhead == NULL)
				{
					newhead = list2 ;
					rear = newhead ;
					list2 = list2->next ;
				}
				else
				{
					rear->next = list2 ;
					list2 = list2->next ;
					rear = rear->next ;
				}
			}
		else
						{
				if(newhead == NULL)
				{
					newhead = list1 ;
					rear = newhead ;
					list1 = list1->next ;
				}
				else
				{
					rear->next = list1 ;
					list1 = list1->next ;
					rear = rear->next ;
				}
			}
	}

	if(list1)
		rear->next = list1 ;
	else
		rear->next = list2 ;

	return newhead ;
}

Node *insert(Node *head , int val)
{
	Node *temp = malloc(sizeof(Node)) ;
	temp->data = val ;
	temp->next = NULL ;
	if(!head)
		return temp ;
	
	temp->next = head ;
	return temp ;
}

void deleteList(Node *head)
{
	if(!head)
		return ;

	deleteList(head->next) ;
	free(head) ;
}

void DeleteIter(Node *head)
{
	Node *temp ;
	while(head)
	{
		temp = head->next ;
		free(head) ;
		head = temp;
	}
}

void display(Node *head)
{
	while(head)
	{
		printf("  %d  ",head->data) ;
		head = head->next ;
	}		
}

int main()
{
  int data[100] = {33, 19, 17, 62, 39, 35, 26, 49, 36, 50, 21, 49, 55, 47, 20, 64, 25, 34, 22, 21, 57, 12, 44, 20, 34, 18, 47, 66, 58, 47, 52, 7, 8, 66, 35, 21, 55, 17, 15, 35, 61, 63, 59, 26, 1, 62, 52, 31, 11, 24, 21, 49, 64, 64, 16, 26, 38, 34, 25, 32, 24, 46, 38, 54, 47, 6, 47, 15, 14, 59, 64, 31, 39, 38, 24, 32, 5, 64, 50, 64, 50, 32, 21, 17, 32, 18, 46, 32, 20, 31, 38, 47, 55, 60, 40, 6, 47, 38, 20, 41} ;
	Node *head = NULL ;
	int i  ;
	for(i = 0 ; i < 100 ; i++)
		head = insert(head , data[i]) ;
	
	display(head) ;
	head = merge_sort(head) ;
	printf("\n\n\n\n") ;
	display(head) ;
	DeleteIter(head) ;
return 0 ;
}
