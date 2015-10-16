/***** Simple implementation of the linked list, While going through the code if found isses 
please write to : gautamsingh2100@gmail.com 
*****/

#include<iostream>
using namespace std;

/***** Node of the List *****/
class listnode
{
	public:
	int value ;
	listnode * next ;	
};


/**** List class ADT *****/
class mylist
{
  	listnode *head ;
	public:
	mylist() ;
	void insert(int i) ;
	void traversal() ;
	int search(int key) ;
	void deletelist() ;
};

/**** list constructor *****/
mylist::mylist()
{
	this->head = NULL ;
}

/***** Inserting data in the list *****/
void mylist::insert(int data)
{
	/**** creating the new Node ****/
      listnode *newnode = new listnode() ;
      newnode->value = data ;
      newnode->next = NULL ;
	
	/***** List has no element , Node will be first node *****/
	if(this->head == NULL)
	{
			this->head = newnode ;
			return ;
	}
		
	/**** Inserting the Node at beg...****/
	newnode->next = this->head ;	
	this->head = newnode ;
}

/***** traversal of the from the beginning to end ****/
/***** Display the value of the each node         ****/
void mylist::traversal()
{
	listnode *ptr = this->head ;
	while(ptr)
	{
		cout << ptr->value << "    " ;
		ptr =  ptr->next  ;
	}
}

/**** Searching the key in the list, Going through each node and comparing weather key is there *****/
/**** 1 : element in the List  , 0: element is not in the list ***/
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
	list.insert(123) ;
	list.deletelist() ;
	
	return 0  ;
}
