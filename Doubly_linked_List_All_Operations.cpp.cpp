//Program for Doubly Linked List  in CPP 
 
#include<iostream>	//Header file
#include<cstdlib>
using namespace std;

class Node			//class Node for creating node
{
    public:
	int data;
    Node* next;
    Node* prev;
}; //end of Node class
 
class Doubly_Linked_List			//class for Doubly Linked List operations
{
    public:
    	Node*  Head;
    	double_llist()
        {
            Head = NULL;  
        }
        
        void create_list();			//operations on Doubly Linked List
        void insert_at_begin();
        void insert_after_node();
        void searchData();
        void updateData();
    	void deleteData();
    	void reverseList();
    	void sortData();
        void displayData();
        void count();       
};//end of Doubly_Linked_List class
 
 //1. function for creating Doubly Linked List
 
 void Doubly_Linked_List::create_list()
{
    Node* trav;
	Node* newnode = new Node(); 		//creating node
	cout<<"Enter the data	: ";
    cin>>newnode->data;
    newnode->next = NULL;
    if (Head == NULL)				// checking for first node
    {
        newnode->prev = NULL;
        Head = newnode;
    }
    else
    {
        trav= Head;
        while (trav->next != NULL)		//traversing list
            trav = trav->next;
        trav->next = newnode;
        newnode->prev = trav;
    }
}// end of create_list() function

 //2. function for inserting node at begining of the list
 
 void Doubly_Linked_List::insert_at_begin()
{
    if (Head == NULL)				//checking for list created or not
    {
        cout<<"List is not created "<<endl;
        return;
    }
    Node* newnode = new Node();		//creating node 
    cout<<"Enter the data	: ";
    cin>>newnode->data;
    newnode->prev = NULL;
    newnode->next = Head;
    Head->prev = newnode;
    Head = newnode;
    cout<<"Element Inserted"<<endl;
}// end of add_at_begin() function
 
 //3. function for inserting node after given node
 
 void Doubly_Linked_List::insert_after_node()
{
	int position;
	Node* newnode = new Node();				//creating node
    cout<<"Enter the data: ";
    cin>>newnode->data;
    cout<<"Insert postion after which you want to add node	: ";
    cin>>position;
    if (Head == NULL)			//checking for list created or not
    {
        cout<<"List is not created	"<<endl;
        return;
    }
    Node *trav;
    int i;
    trav = Head;
    for (i = 0;i < position - 1;i++)
    {
        trav = trav->next;
        if (trav == NULL)
        {
            cout<<"There are less than ";
            cout<<position<<" elements."<<endl;
            return;
        }
    }
    
    if (trav->next == NULL)
    {
        trav->next = newnode;
        newnode->next = NULL;
        newnode->prev = trav;      
    }
    else
    {
        newnode->next = trav->next;
        newnode->next->prev = newnode;
        trav->next = newnode;
        newnode->prev = trav;
    }
    cout<<"Element Inserted"<<endl;
}//end of insert_after_node() function
 
 //4. function for serching data into the list
void Doubly_Linked_List::searchData()
{ 	
    Node* trav = Head;
    int value;
    int flag=0;
    int position=0;
    cout<<"Enter the data to be search in the list	: ";
    cin>>value;
    while (trav != NULL)			//traversing list
    {
    	position++;
    	if(trav->data==value)
    	{
    		flag = 1;
            cout<<"Element "<<value<<" is found at position "<<position<<endl;
		}
        trav = trav->next;
    }
  if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}//end of searchData() function
 
 //5. function for updating data of given list
 
  void Doubly_Linked_List::updateData()
{ 	
    Node* trav = Head;
    int value;
    int flag = 0;
    int position = 0;
    cout<<"Enter the data to be update in the list	: ";
    cin>>value;
    while (trav != NULL)			//traversing list
    {
    	position++;
    	if(trav->data==value)
    	{
    		flag = 1;
            cout<<"Data "<<value<<" is found at position "<<position<<endl;
            cout<<"\n Enter new data	:	";
            cin>>trav->data;
		}
        trav = trav->next;
    }
  if (!flag)
        cout<<"Data "<<value<<" not found in the list"<<endl;  
}//end of searchData() function
 
 
 //6. function for
 
void Doubly_Linked_List::sortData()
{
    Node* trav;
	Node* temp;
    int value;
    if (Head == NULL)	//checking for list created or not
    {
        cout<<"Given List is empty!!!!!"<<endl;
        return;
    }
    trav = Head;
    while (trav != NULL)			//traversing list
    {
        for (temp = trav->next;temp !=NULL;temp = temp->next)
        {
            if (trav->data > temp->data)
            {
                value = trav->data;
                trav->data = temp->data;
                temp->data = value;
            }
        }
        trav = trav->next;
    }
}//end of sortList() function

 //7. function for reversing Doubly Linked List
 
void Doubly_Linked_List::reverseList()
{
    Node* temp;
	Node* trav;
    temp = Head;
    trav = temp->next;
    temp->next = NULL;
    temp->prev = trav;
    if (Head == NULL)		//checking for list created or not
    {
                cout<<"Sorry List is empty."<<endl;
    }
    while (trav != NULL)		//traversing list
    {
        trav->prev = trav->next;
        trav->next = temp;
        temp = trav;
        trav = trav->prev; 
    }
    Head = temp;
    cout<<"List Reversed"<<endl; 
}//end of reveerseList() function
 
  //8. function for deleting node from the list
  
void Doubly_Linked_List::deleteData()
{
    Node *temp; 
	Node* trav;
    int value; 
    if (Head == NULL)			//checking for list created or not
    {                      
        cout<<"Sorry List is empty."<<endl;   
	}
    cout<<"Enter the element for deletion: ";
    cin>>value;
    if (Head->data == value)	//deletion of first node
    {
        temp = Head;
        Head = Head->next;  
        Head->prev = NULL;
        cout<<"Node Deleted"<<endl;
        free(temp);
        return;
    }
    trav = Head;
    while (trav->next->next != NULL)
    {   
       
        if (trav->next->data == value)    //deletion of in between node
        {
            temp = trav->next;
            trav->next = temp->next;
            temp->next->prev = trav;
            cout<<"Node Deleted"<<endl;
            free(temp);
            return;
        }
        trav = trav->next;
    }
     
    if (trav->next->data == value) 	//deletion of last node   
    { 	
        temp = trav->next;
        free(temp);
        trav->next = NULL;
        cout<<"Node Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}//end of reverseList() function

 //9. function for displaing data from Doubly Linked List 
void Doubly_Linked_List::displayData()
{
    Node* trav;
    if (Head == NULL)			//checking for list created or not
    {
        cout<<"Sorry List is empty."<<endl;
        return;
    }
    trav = Head;
    cout<<"The Doubly Link List is :"<<endl;
    while (trav != NULL)				//traversing list
    {
        cout<<trav->data<<" <-> ";
        trav = trav->next;
    }
    cout<<"NULL"<<endl;
} //end of displayData() function

int main()		//main function
{
    int choice;
    Doubly_Linked_List dl;	//creating object
    do
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Create Doubly Linked List"<<endl;
        cout<<"2.Insert Node at begining of the List"<<endl;
        cout<<"3.Insert Node after given position in the List"<<endl;
        cout<<"4.Search Node in the List"<<endl;
        cout<<"5.Update Node Data in the List"<<endl;
        cout<<"6.Sort the Doubly Linked List"<<endl;
        cout<<"7.Reverse the Doubly Linked List"<<endl;
        cout<<"8.Delete Node from the List"<<endl;
        cout<<"9.Display data of the List"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
        		cout<<"Creating List"<<endl;
                dl.create_list();
	            cout<<endl;
	            break;
        case 2:
        		cout<<"Inserting node at beginig of the List"<<endl;
                dl.insert_at_begin();
	            cout<<endl;
	            break;
        case 3:
        	 	cout<<"Inserting node after given node of the List"<<endl;
                dl.insert_after_node();
	            cout<<endl;
	            break;
        case 4:
        		cout<<"Seraching data from the List"<<endl;
        		dl.searchData();
	            cout<<endl;
	            break;
	    case 5: 
				cout<<"Updating data from the List"<<endl; 
				dl.updateData();
	            cout<<endl;
	            break;  
        case 6:
        		cout<<"Before Sorting : "<<endl;
	        	dl.displayData();
        		dl.sortData();
        		cout<<"After Sorting : "<<endl;
	            dl.displayData();
        		break;
        case 7:
        		cout<<"Reversing data of the List"<<endl;
	            dl.reverseList();
	            cout<<"After Reversing the List : "<<endl;
	            dl.displayData();
	            cout<<endl;
	            break;
        case 8:    
				cout<<"Deleting data from the List"<<endl;      
	            dl.deleteData();
	            cout<<endl;
	            break;    
        case 9:
        		cout<<"Displaying data from the List"<<endl;
                dl.displayData();
	            break;
        case 10:
	        	cout<<"Thank you visit Again!!!!"<<endl;
	            exit(1);
        default:
            	cout<<"Sorry Invalid choice!!!!"<<endl;
        }
    }while(choice!=10);
    return 0;
}//end of main()
 

