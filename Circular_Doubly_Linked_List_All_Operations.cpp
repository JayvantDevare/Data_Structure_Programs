//Program for Circular Doubly Linked List in CPP
#include<iostream>//Header files
#include<cstdlib>
using namespace std;
int counter = 0;
class Node//class Node for creating node
{
 public:
 int data;
 Node *next;
 Node *prev;
};//end Node class
class Circular_Doubly_Linked_list//class for Circular Doubly Linked List operations
{
    public:
    	Node* Head;
    	Node* Last;    	
    	Circular_Doubly_Linked_list()
        {
            Head = NULL;
            Last = NULL;			
        }        
        Node *create_node();//Circular Doubly Linked List all operations
        void insert_at_begin();
        void insert_at_last();
        void insert_at_position();
        void searchData();
        void updateData();
        void sortData();
        void reverseList();
        void delete_at_position();
        void displayData();
};//end Circular Doubly Linked List class 
//1. function for creating node for Circular Doubly Linked List
Node* Circular_Doubly_Linked_list::create_node()
{
    counter++;  
    Node* newnode = new Node();//creating node
    cout<<"Enter the data:";
    cin>>newnode->data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}//end of create_node() function
//2. function for inserting node at begining of the Circular Doubly Linked List
void Circular_Doubly_Linked_list::insert_at_begin()
{
    int value;
    Node* newnode;
    newnode = create_node();
    if (Head == Last && Head == NULL)//checking for first location
    {    
        Head = Last = newnode;
        Head->next = Last->next = NULL;
        Head->prev = Last->prev = NULL;
    }
    else
    {
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
        Head->prev = Last;
        Last->next = Head;
        cout<<newnode->data<<"inserted in to the list"<<endl;
    }
}//end of insert_at_begin() function

//3. function for inserting node at last in  Circular Doubly Linked List

void Circular_Doubly_Linked_list::insert_at_last()
{
    Node* newnode;
    newnode = create_node();
    if (Head == Last && Head == NULL)
    {
        Head = Last = newnode;
        Head->next = Last->next = NULL;    
        Head->prev = Last->prev = NULL;
    }
    else
    {
        Last->next = newnode;
        newnode->prev = Last;
        Last = newnode;
        Head->prev = Last;
        Last->next = Head;
    }
}//end of insert_at_Last() function
//4. function for inserting node at given position of the Circular Doubly Linked List
void Circular_Doubly_Linked_list::insert_at_position()
{    
    int position=0;
    int i;
    cout<<endl<<"Enter the postion where data to be inserted in to the list :";
    cin>>position;
    Node* newnode;
    Node* trav;
    Node* temp;
    newnode = create_node();
    if (Head == Last && Head == NULL)
    {
        if (position == 1)
        {
            Head = Last = newnode;
            Head->next = Last->next = NULL;    
            Head->prev = Last->prev = NULL;
        }
        else
        {
            cout<<"Sorry invalid position!!!!"<<endl;
            counter--;
            return;
        }
    }  
    else
    {
        if (counter < position)
        {
             cout<<"Sorry invalid position!!!!"<<endl;
             counter--;
             return;   		
        }
        trav = Head;		
        for (i = 1;i <= counter;i++)
        {
            temp = trav;
            trav = trav->next;
            if (i == position - 1)
            {
                temp->next = newnode;
                newnode->prev = temp;
                newnode->next = trav;
                trav->prev = newnode;
                cout<<newnode->data<<"Element inserted at given position"<<position<<endl;
                break;
            }
        }
    }
}//end of insert_at_position() function
//5. function for searching data from the  Circular Doubly Linked list
void Circular_Doubly_Linked_list::searchData()
{
    int position = 0;
    int value;
    int i;
    int flag = 0;
    Node* trav;
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry List is empty!!!!!"<<endl;
        return;
    }
    cout<<endl<<"Enter the data to be searched	:";
    cin>>value;
    trav = Head;
    for (i = 0;i < counter;i++)
    {
        position++;
        if (trav->data == value)
        {
            cout<<"Data "<<value<<" found in the list at position	:"<<position<<endl;
            flag = 1;
        }    
        trav = trav->next;
    }
    if (!flag)
      cout<<"Data not found in the list"<<endl;   
}//end of searchData() function
//6. function for updating data into the Circular Doubly Linked list
void Circular_Doubly_Linked_list::updateData()
{
    int value;
    int position;
    int i;	
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry List is empty"<<endl;
        return; 
    }
    cout<<endl<<"Enter the postion of node to be updated	:";
    cin>>position;
    cout<<"Enter the new value for updation :";
    cin>>value;
    Node* trav;
    if (counter < position)
    {
        cout<<"Sorry Invalid Position!!!!!"<<endl;
        return;
    }
    trav = Head;  
    if (position == 1)
    {
       trav->data = value;
       cout<<"data Updated at :"<<position<<endl;
       return;   
    }
    for (i=0;i < position - 1;i++)
    {
        trav = trav->next; 		 
    }
    trav->data = value;
    cout<<"Data Updated at :"<<position<<endl;
}//end of updateData() function
//7. function for sorting data of the Circular Doubly Linked list
void Circular_Doubly_Linked_list::sortData()
{
    Node* temp;
    Node* trav;
    int i;
    int value;
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry List is empty"<<endl;
        return;
    }
    trav = Head;
    for (i = 0;i < counter;i++)
    {
        temp = trav->next;
        while (temp != Head)
        {
            if (trav->data > temp->data)
            {
                value = trav->data;
                trav->data = temp->data;
                temp->data = value;
            }
            temp = temp->next;
        }
        trav = trav->next;
    }
}//end of sortDdata() function
//8. function for Reversing data of the Circular Doubly Linked list
void Circular_Doubly_Linked_list::reverseList()
{
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry List is empty"<<endl;
        return;
    }
    Node* trav;
    Node* temp = Head;
    trav = temp->next;
    temp->next = NULL;
    temp->prev = trav;    
    while (trav != Head)
    {
        trav->prev = trav->next;
        trav->next = temp;
        temp = trav;
        trav = trav->prev;
    }
    Last = Head;
    Head = temp;
}//end of reverseList() function
//9. function for deleting data by position from the Circular Doubly Linked list
void Circular_Doubly_Linked_list::delete_at_position()
{    
    int position;
    int i;
    Node* temp;
    Node* trav;
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry list is empty"<<endl;
        return;
    }
    cout<<endl<<"Enter the postion of node to be deleted:";
    cin>>position;
    if (counter < position)
    {
        cout<<"Sorry Invalid Position!!!!"<<endl;
        return;
    }
    trav = Head;
    if(position == 1)
    {
        counter--;
        Last->next = trav->next;
        trav->next->prev = Last;
        Head = trav->next;
        cout<<trav->data<<"Element Deleted at :"<<position<<endl;
        free(trav);       
        return;	   
    }
    for (i = 0;i < position - 1;i++ )
    {  
        trav = trav->next;
        temp = trav->prev;    	  
    }    
    temp->next = trav->next;
    trav->next->prev = temp;
    if (position == counter)
    {
        Last = temp; 	   
    }
    counter--;
    cout<<trav->data<<"Element Deleted at :"<<position<<endl;
    free(trav);
}// end of delete_at_position() function
//10. function for displaying data  from the Circular Doubly Linked list
void Circular_Doubly_Linked_list::displayData()
{
    int i;
    Node* trav;
    if (Head == Last && Head == NULL)
    {
        cout<<"Sorry List is empty"<<endl;
        return;
    }
    trav = Head;
    for (i = 0;i < counter-1;i++)
    {	
        cout<<trav->data<<"<->";
        trav = trav->next; 
    }
    cout<<trav->data<<endl;
}//end of displayData() function
int main()//main() function
{
    int choice;    
    Circular_Doubly_Linked_list cdl;//creating object of Circular_Doubly_Linked_list class    
    do
    {
        cout<<"\n-------------------------------"<<endl;
        cout<<"Operations on Doubly Circular Linked List"<<endl;
        cout<<"\n-------------------------------"<<endl;         
        cout<<"1.Insert data at Beginning of the List"<<endl;
        cout<<"2.Insert data at Last of the List"<<endl;
        cout<<"3.Insert data at given Position"<<endl;
        cout<<"4.Search data in the List"<<endl;
        cout<<"5.Update data in the List"<<endl;
        cout<<"6.Sort Doubly Circular Linked List"<<endl;
        cout<<"7.Reverse Doubly Circular Linked List"<<endl;
        cout<<"8.Delete data  from given Position"<<endl;
        cout<<"9.Display Doubly Circular Linked List"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your choice :";
	cin>>choice;        
        switch(choice)
        {
        case 1:
	       cout<<"\nInserting data at begining of the List"<<endl;
	       cdl.insert_at_begin();
	       break;
        case 2:
	       cout<<"\nInserting data at Last of the List"<<endl;
	       cdl.insert_at_last();
	       break;   
        case 3:
	       cout<<"\nInserting data at given position in the List"<<endl;
	       cdl.insert_at_position();
	       break; 
        case 4:
	       cout<<"\nSearching data in the List"<<endl;
	       cdl.searchData();
	       break;
        case 5:
	        	cout<<"\n Updating data in the List"<<endl;
	            cdl.updateData();
	            cout<<"\n after data updation "<<endl;
	            cdl.displayData();
	            break;
        case 6:
        	cout<<"\nBefore sorting List"<<endl;
		cdl.displayData();
	        cout<<"\nSorting data of the List"<<endl;
	        cdl.sortData();
	        cout<<"\nAfter sorting List"<<endl;
	        cdl.displayData();
	        break;
        case 7:
	       cout<<"\nReversing List"<<endl;
	       cdl.reverseList();
	       cout<<"\nAfter Reversing the List"<<endl;
	       cdl.displayData();
	       break;
        case 8:
	       cout<<"\nDeleting data from given position"<<endl;
	       cdl.delete_at_position();
	       cout<<"\nAfter node deletion "<<endl;
	       cdl.displayData();
	       break;
        case 9:
	       cout<<"\nDisplaying data from the List"<<endl;
	       cdl.displayData();
	       break;
        case 10:
               exit(1); 
        default:
            	cout<<"Wrong choice"<<endl;	
        }        
    }while(choice!=10);    
    return 0;
}//end of main() function
