/****** Simple implementation of the cyclic linked list based on the singly linked list
For any issues write to : gautamsingh2100@gmail.com   :)
****/


#include<iostream>
using namespace std;


/****** List Node ****/
class listnode
{
	public:
	int value ;
	listnode * next ;	
};

/***** My list Class *****/
class mylist
{
  	listnode *head ;
	public:
	mylist() ;
	void insert(int i) ;
	void traversal() ;
	int search(int key) ;
	void deletelist() ;
	int getSize() ;
};

/***** Constructor of the Class *****/
mylist::mylist()
{
	this->head = NULL ;
}

/***** Inserting the data in begining *****/
void mylist::insert(int data)
{
	listnode *newnode = new listnode() ;
	newnode->value = data ;
	newnode->next = NULL ;
	
	listnode *temp1 , *temp2 ;
	/***** when list is empty *****/
	if(this->head == NULL)
	{
		this->head = newnode ;
		newnode->next = this->head ;
		return ;
	}
		
	/**** If there is only one node *****/
	if(this->head == this->head->next)
	{
		newnode->next = this->head ;
		this->head->next = newnode ;
		return ;
	}

	/**** finding the last node of the list *****/
	temp1 = this->head->next ;

	while(this->head != temp1)
	{
		temp2 = temp1 ; /***** temp2 will the last node ****/
		temp1 = temp1->next ;
	}
	
	/***** inserting the node at beg *****/
	newnode->next = this->head ;	
	temp2->next   = newnode ;
	this->head    = newnode ;
}

/***** traversal of node in the circular list *****/
void mylist::traversal()
{
	listnode *ptr = this->head ;
	listnode *ptr1 ;
	/***** displaying the first node ****/
	if(ptr != NULL)
	{
		cout << ptr->value << "    " ;
		 ptr1 = ptr->next   ;
	}
	else
	{
		return ;
	}

	/***** Logic will display rest of the node *****/
	while(ptr != ptr1)
	{
		cout << ptr1->value << "    " ;
		ptr1 =  ptr1->next  ;
	}
}

/****** searching the key in the circular list *****/
int mylist::search(int key)
{
	listnode *ptr = this->head ;
	listnode *ptr1 ;

	if(ptr == NULL)
		return 0 ;

	ptr1 = ptr->next ; 
	if(ptr->value == key)
		return 1 ;

	while(ptr != ptr1 && ptr1->value != key)
		ptr1 =  ptr1->next  ;
	if( ptr1 == ptr)
		return 0 ;
	return 1 ;
}

/**** Clearing the heap memory , bcz dynamically allocated in c an c ++ ,, shaf karo .. ***/
void mylist::deletelist()
{
	listnode *ptr = this->head ;
	listnode *ptr1 = ptr ;
	listnode *temp ;
	if(ptr == NULL) return ;

	if(ptr->next == ptr)
		delete ptr ;
	ptr1 = ptr->next ;


	while(ptr != ptr1)
	{
		temp = ptr1->next ;
		delete ptr1       ;
		ptr1 = temp ;		
	}
	
	delete ptr ;
}

/***** method returning getting the size of the CLL *****/
int mylist::getSize()
{
	listnode *ptr = this->head ;
	listnode *ptr1 ;
	int count = 0 ;
	if(ptr == NULL) return 0 ;

	if(this->head == this->head->next)
		return 1 ;
	ptr1 = this ->head->next ;

	while(ptr1 != ptr)
	{
		count++ ;
		ptr1 = ptr1->next ;

	}
	return count + 1 ;
}
int main()
{
	int data [] = { 16, 2, 77, 40, 12071 , 123,232,43,5645,75,234,2342,214,242,342 };
	int size = sizeof(data) / sizeof(int) ;
	mylist listObj ;
	for(int i = 0 ; i < size ; i++)
	{
		listObj.insert(data[i]) ;
	}

	cout <<" TIll there its end " ;
	cout << listObj.getSize() << endl ; 
	
	/*** Deleting the whole list *****/
	listObj.deletelist() ;
	




}
