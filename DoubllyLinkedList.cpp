/****** Simple implementation of the doully linked list based on the singly linked list
For any issues write to : gautamsingh2100@gmail.com   :)
****/

#include<iostream>
using namespace std;

/**** Class for the DLL Node ****/
class listnode
{
	public:
	int value ;
	listnode * next ;	
	listnode * prev ;
	listnode(int val) ;
};

/*** Constructor to create the new node ****/
listnode::listnode(int data)
{
		value = data ;
		next = NULL ;
		prev = NULL ;
}

/***** Doublly Linked Listt Class ****/
class mylist
{
  	listnode *head ;
	public:
	mylist() ;
	void insertB(int i) ;
	void insertL(int data) ;
	void traversal() ;
	int  search(int key) ;
	void deletelist() ;
	void reverse() ;
};

/***** Constructor of the DLL ****/
mylist::mylist()
{
	this->head = NULL ;
}

/**** Inserting the data at beg ****/
void mylist::insertB(int data)
{
	/* Creating New node ****/
        listnode *newnode = new listnode(data) ;
	
	/**** Incase empty list ****/
	if(this->head == NULL)
	{
		this->head = newnode ;
		return ;
	}
		
	/***** Inserting the Node at beg ****/
	this->head->prev = newnode ;
	newnode->next = this->head ;	
	this->head = newnode ;
}

/***** Inserting the node at the end, ******/
void mylist::insertL(int data)
{
        listnode *newnode = new listnode(data) ;
	listnode *temp ;
	if(this->head == NULL)
	{
		this->head = newnode ;
		return ;
	}
	/*****  Traversing last node ****/
	temp = this->head ;	
	while(temp->next != NULL)
		temp = temp->next ; 
		
	temp->next = newnode;	
	newnode ->prev = temp ;
}

/***** Traversall of the doublly linked list same as the singly *****/
void mylist::traversal()
{
	listnode *ptr = this->head ;
	while(ptr)
	{
		cout << ptr->value << "    " ;
		ptr =  ptr->next  ;
	}
}

/***** searshing the key in the DLL ****/
int mylist::search(int key)
{
	listnode *ptr = this->head ;
	while(ptr&& ptr->value != key)
		ptr =  ptr->next  ;
   return ptr ? 1 : 0 ;
}

/**** Clearing the heap memory , bcz dynamically allocated in c an c ++ ,, shaf karo .. ***/
void mylist::deletelist()
{
	listnode *ptr = this->head ,*temp;
	while(ptr)
	{
		temp = ptr->next ;
		delete ptr ;
		ptr = temp ;		
	}
}


int  main()
{
	mylist list ;
	list.insertB(123) ;
	list.deletelist() ;
	
	return 0  ;
}
