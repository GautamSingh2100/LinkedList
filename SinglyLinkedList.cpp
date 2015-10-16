/**** Simple  Implementation of the Singly Linked list,
While Useing this code If found any issue ,Write to : gautamsingh2100@gmail.com
*****/

#include<iostream>
using namespace std;

class Node
{
	public:
	int value ;
	Node * next ;	
};

/*** class that contains all the list-implementation and function ****/
class SingleyLinkedList
{
  	Node *head ;
  	int size ; 
  	
  	private : /***** Private Methods to the List ****/
  		void traversal(Node *root ) ;  /*** For recursive terversal ****/
  		void reversePrint(Node *root) ; 
	public:
		SingleyLinkedList() ;
		void traversalItr() ;
		void traversalRec() ;
		void insertBeg(int val) ;
		void insertEnd(int val) ;	
		void isertOrdered(int val) ;
		void insertAt(int data , int Index) ;
        	void deleteBeg()  ;
		void deleteEnd()  ;
		void deleteAt(int index);
		void deleteKey(int Key)    ; 
		void deleteSingleLinkedList() ;	
		void printReverse() ;
		int  getSize() ;
 		int  search(int key) ;		
};



/**** Private Class method. print the list containtent in normal order ****/
void SingleyLinkedList::traversal(Node *root)
{
	if(root)	
	{
		cout<< root->value << "   " ;
		traversal(root->next) ;
	}
}

/*** print the list containtent in reverse order ****/
void SingleyLinkedList::reversePrint(Node *root)
{
	if(root)	
	{		
		traversal(root->next) ;
		cout<< root->value << "   " ;
	}
}


/**** Constructor  {T}****/
SingleyLinkedList::SingleyLinkedList()
{
	this->head = NULL ;
	this->size = 0 ;
}

/**** Displaying the data from beg to end ****/
void SingleyLinkedList::traversalItr()
{
	Node *ptr = this->head ;
	while(ptr)
	{
		cout << ptr->value << "    " ;
		ptr =  ptr->next  ;
	}
}

/**** Displaying the data from beg to end ****/
void SingleyLinkedList::traversalRec()
{
	traversal(head) ;
}

/**** insertBeging data beginning {T}****/
void SingleyLinkedList::insertBeg(int data)
{
      Node *newnode = new Node() ;
      newnode->value = data ;
      newnode->next = NULL ;
	
	if(this->head == NULL)
		{
			this->head = newnode ;
			this->size ++ ;
			return ;
		}
		
	newnode->next = this->head ;	
	this->head = newnode ;
	this->size ++ ;
}

/**** insert the data at end ****/
void SingleyLinkedList::insertEnd(int data)   
{
	/*** create New node ****/
	Node *newNode  = new Node() ;
        newNode->value = data ;
	newNode->next  = NULL ;
	
	Node *itr  = this->head ; 
	
	if(head == NULL)
	{
		this->head = newNode  ;
		return ; 
	}
	
	/**** traversal till last node ****/
	while(itr->next)
	{
		itr = itr->next ; 
	}
	
	itr->next = newNode ;
	
	this->size ++ ;
}

/**** Inserting data in ordered fasion ****/
void SingleyLinkedList::isertOrdered(int data) 
{
	/*** create New node ****/
	Node *newNode  = new Node() ;
        newNode->value = data ;
	newNode->next  = NULL ;
	
	Node *itr  = this->head ; 
	Node *itrSave = NULL ;
	if(head == NULL)
	{
		this->head = newNode  ;
		return ; 
	}
	
	/*** traversaing to the right position ****/
	while( itr && itr->value < data)
	{
		itrSave = itr ;
		itr = itr -> next  ;
	}
	
	if(itrSave == NULL)
	{
		newNode->next = this->head ; 
		this->head = newNode ;
	}
	else
	{
		newNode->next = itrSave->next ; 
		itrSave->next = newNode ; 
	}
	
	this->size ++ ;
}

/**** note that index will be the index of the new node *****/
/**** for the index 0 / 1 insert beg , if index is greater than size insert end ****/
void SingleyLinkedList::insertAt(int data , int index)
{
	/*** create New node ****/
	Node *newNode  = new Node() ;
        newNode->value = index ;
	newNode->next  = NULL ;
	
	if(index == 0 || index == 1)
	{
		newNode->next  = this->head ; 
		this->head = newNode  ;
	}
	
	/**** go and search the perfect index ****/
	Node *itr  = this->head ; 
	Node *itrSave = NULL ;
	int itrIndex = 0 ;
	while( itr && itrIndex < (index -1) ) 
	{
		itrSave = itr ;
		itr = itr->next ;
		itrIndex ++ ;
	}
	
	newNode->next = itrSave->next ;
	itrSave->next = newNode ;
}

/**** Delete from begin ****/
void SingleyLinkedList::deleteBeg()
{
	if(this->head == NULL )
	{
		return ;
	}
	
	Node *temp = this->head->next ;
	delete head ;
	this->head = temp ;
	size -- ;
}

/**** Deleting the node from the end ****/
void SingleyLinkedList::deleteEnd()
{
	if(this->head == NULL )
	{
		return ;
	}
	
	Node *itr = this->head ;
	Node *itrSave = NULL ;
	while(itr->next != NULL)
	{
		itrSave = itr->next  ;
		itr     = itr->next  ;
	}
	
	if(itrSave)
	{
		delete itr ;
		itrSave->next = NULL ;
	}
	else
	{
		delete itrSave ;
	}
	size -- ;
}

/**** Delete at spacific position ****/
/**** if the index is 0 or 1 delete beg , do not delete ****/
void SingleyLinkedList::deleteAt(int index)
{
	if(this->head == NULL || index > size )
	{
		return ;
	}
	
	if(index == 0 || index == 1)
	{
		deleteBeg() ;
		size ++ ;
		return ;		
	}
	
	Node *itr     = this->head ;
	Node *itrSave = NULL   ;
	int   itrIndex = 0 ;
	while(itr && itrIndex < index - 1 )
	{
		itrSave = itr->next  ;
		itr     = itr->next  ;
		itrIndex++ ;
	}
	
	if(itrSave)
	{
		if(itrSave->next )
		{
			Node *temp = itrSave->next ;
			itrSave->next = itrSave->next->next ;
		}
	}
	
	size -- ;
}

/**** deleting the whole List ****/
void SingleyLinkedList::deleteKey(int key)
{
	if(!search(key))
	{
		return ;
	}
	
	Node *itr     = this->head ;
	Node *itrSave = NULL   ;
	
	while(itr->value != key)
	{
		itrSave = itr  ;
		itr = itr->next ;
	}
	
	if(itrSave)
	{
		Node *temp = itrSave->next ;
		itrSave->next = itrSave->next->next ; 
		delete temp ;
	}
	else
	{
		Node *temp = this->head ; 
		this->head = this->head->next ;
		delete temp ;
	}
	size -- ;
}

/**** deleting the whole List ****/
void SingleyLinkedList::deleteSingleLinkedList()
{
	Node *ptr = this->head ,*temp;
	while(ptr)
	{
		temp = ptr->next ;
		delete ptr ;
		ptr = temp ;		
	}
	size = 0 ;
}

/*** print the list in reverse ****/
void SingleyLinkedList::printReverse()
{
	reversePrint(head)	 ;
}

/**** returnig the number of node in the list ****/
int SingleyLinkedList::getSize()
{
	return size ; 
}


/**** Searching the data in thelist ****/
int SingleyLinkedList::search(int key)
{
	Node *ptr = this->head ;
	while(ptr&& ptr->value != key)
		ptr =  ptr->next  ;
		
   return ptr ? 1 : 0 ;
}

int main()
{
	SingleyLinkedList listObj ; 
	int data [] = { 16, 2, 77, 40, 12071 , 123,232,43,5645,75,234,2342,214,242,342 };
	int size = sizeof(data) / sizeof(int) ;
	
	/*** insertBeging data into the list ****/
	for(int i = 0 ; i < size ; i++)
	{
		listObj.insertBeg(data[i]) ;
	}
	cout << listObj.getSize() << endl ; 
	
	/*** Deleting the whole list *****/
	listObj.deleteSingleLinkedList() ;
	
}
