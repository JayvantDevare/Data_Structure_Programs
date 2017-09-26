//Program for Circular Linked List in CPP

#include<iostream>			//Header file
#include<cstdlib>
using namespace std;

class Node				//class Node for creating node
{
	public:
    int data;
    Node* next;
};//end of Node class
 
class circular_Linked_List		//class for Circular Linked List operations
{
    public:
    	Node* Last;
    	
        circular_Linked_List()
        {
            Last = NULL;           
        }
        void create_List();			//operations on Circular Linked List
        void insert_at_begin();
        void insert_after_node();
        void searchData();
        void updateData();
		void deleteData();
        void sortList();
        void display_list();
}; //end of circular_Linked_List class

 //1. function for creating Circular Linked List
 
 void circular_Linked_List::create_List()
{
    Node* newnode = new Node();		//creating node
    cout<<"Enter the data: ";
	cin>>newnode->data;
    if (Last == NULL)
    {
        Last = newnode;
        newnode->next = Last;   
    }
    else
    {
        newnode->next = Last->next; 
        Last->next = newnode;
        Last = newnode;
    }
}//end of create_List() function
 
 //2. function for inserting node at begining of the Circular Linked List

void circular_Linked_List::insert_at_begin()
{
	Node* newnode = new Node(); 	//creating node
    cout<<"Enter the data: ";
	cin>>newnode->data;
    if (Last == NULL)  	//checking for list is created or not
    {
        cout<<"Create the list"<<endl;
        return;
    }
    newnode->next = Last->next;
    Last->next = newnode;
}//end of insert_at_begin() function
  
 //3. function for inserting node after given node of the Circular Linked List
 
void circular_Linked_List::insert_after_node()
{
	int value;
	int position;
	cout<<"Insert element after position: ";
	cin>>position;
	cout<<"Enter the data: ";
	cin>>value;
	Node* newnode = new Node();			//creating node
	newnode->data = value;
    if (Last == NULL)					//checking for list is created or not
    {
        cout<<"Create the list "<<endl;
        return;
    }
    Node* trav;
    trav = Last->next;
    for (int i = 0; i < position-1 ; i++)
    {
        trav = trav->next;
        if (trav == Last->next)
        {
            cout<<"There are less than ";
            cout<<position<<" in the list"<<endl;
            return;
        }
    }
   
    newnode->next = trav->next;    
    trav->next = newnode;    
    if (trav == Last)  					//inserting node at last 
    { 
        Last=newnode;
    }
}//end of insert_after_node() function

 //4. function for searching data from the  circular_Linked_List
void circular_Linked_List::searchData()
{
   	Node* trav;
    int counter = 0;
    int value;
    cout<<"Enter the data to be searched: ";
	cin>>value;
	if (Last == NULL)					//checking for list is created or not
	{
		cout<<"Sorry List is Empty!!!!!!"<<endl;
	   // break;
	}
	            
    trav = Last->next;
    while (trav != Last)
    {
        counter++;
        if (trav->data == value)    
        {
            cout<<"Element "<<value; 
            cout<<" found at position "<<counter<<endl;
            return;
        }
        trav = trav->next;
    }
    if (trav->data == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}// end of searchData() function

 //5. function for updating data into the Circular Linked List
 
void circular_Linked_List::updateData()
{
    int value;
	int position;
	int i;
    if (Last == NULL)			//checking for list is created or not
    {
        cout<<"Sorry List is Empty!!!!!"<<endl;
        return;
    }
    cout<<"Enter the node position whose value is to be updated : ";
    cin>>position;
    cout<<"Enter the new data: ";
    cin>>value;
    Node* trav;
    trav = Last->next;
    for (i = 0; i < position - 1 ; i++)		//traversing till the position
    {
        if (trav == Last)
        {
            cout<<"There are less than "<<position<<" elements.";
            cout<<endl;
            return;
        }
        trav= trav->next;
    }
    trav->data = value;  
    cout<<"Node value Updated"<<endl;
} //end of updateData() function

//6. function for deleting data from the Circular Linked List

void circular_Linked_List::deleteData()
{
    Node* temp;
	Node* trav;
	int value;
	if (Last == NULL)
	{
		cout<<"Sorry List is Empty!!!!!"<<endl;
	    //break;
	}
	cout<<"Enter the data for deletion: ";
	cin>>value;
    trav = Last->next;
      /* If List has only one element*/
    if (Last->next == Last && Last->data == value)  
    {
        temp = Last;
        Last = NULL;
        free(temp);
        return;
    }
    if (trav->data == value)  //deleting first node - if data found at first node
    {
        temp = trav;
        Last->next = trav->next;
        free(temp);
        return;
    }
    while (trav->next != Last)   	//traversing till the data
    {
      
        if (trav->next->data == value)    //deleting node - if it found in between  the list  
        {
            temp = trav->next;
            trav->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        trav = trav->next;
    }
    
    if (trav->next->data == value)   //deleting last node - if found at last in list 
    {
        temp = trav->next;
        trav->next = Last->next;
        free(temp);		
        Last = trav;
        return;
    }
    cout<<"Given data "<<value<<" not found in the list"<<endl;
}//end of delete_element() function

 //7. function for sorting Circular Linked List

void circular_Linked_List::sortList()
{
    Node* trav;
	Node* ptr;
    int temp;
    if (Last == NULL) 
    {
        cout<<"Sorry List is empty!!!!!!"<<endl;
        return;
    }
    trav = Last->next;
    while (trav != Last)			//traversing list
    {
        ptr = trav->next;
        while (ptr != Last->next)
        {
            if (ptr != Last->next)
            {
                if (trav->data > ptr->data)
                {
                    temp = trav->data;		//sorting data
                    trav->data = ptr->data;
                    ptr->data = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;    
        }
        trav = trav->next;         
    }
}//end of sortList() function

 //8. function for displaying data from Circular Linked List

void circular_Linked_List::display_list()
{
   Node* trav;
    if (Last == NULL)
    {
        cout<<"Sorry List is empty!!!!!!"<<endl;
        return;
    }
    trav = Last->next;
    cout<<"Circular Link List: "<<endl;
    while (trav != Last)
    {
        cout<<trav->data<<"->";
        trav = trav->next;
    }
    cout<<trav->data<<endl;
}// end of display_list() function


int main()
{
    int choice;
    circular_Linked_List cl;
    do
    {
        cout<<endl<<"**************************************"<<endl;
        cout<<endl<<"Circular Linked List Operations"<<endl;
        cout<<endl<<"**************************************"<<endl;     
        cout<<"1.Create Circular Linked List"<<endl;
        cout<<"2.Insert Node at beginning of the Circular Linked List"<<endl;
        cout<<"3.Insert Node at given position in the Circular Linked List"<<endl;
        cout<<"4.Search Element in the Circular Linked List"<<endl;
        cout<<"5.Update Node Value of Circular Linked List"<<endl;
        cout<<"6.Delete a Particular Node from Circular Linked List "<<endl;
        cout<<"7.Sort Circular Linked List"<<endl;
        cout<<"8.Display data of Circular Linked List"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        
    switch(choice)
    {
        	
        case 1:
	            cout<<"\n Creating Circular Linked List	"<<endl;
				cl.create_List();
	            cout<<endl;
	            break;
        case 2:
	            cout<<"Inserting Node at Beginning of the List: "<<endl;
				cl.insert_at_begin();
	            cout<<endl;
	            break;
        case 3:
	        	cout<<"Inserting Node after given position in the List:"<<endl;
	            cl.insert_after_node();
	            cout<<endl;
	            break;
        case 4:
	        	cout<<"Search any element in Link List: "<<endl;
	            cl.searchData();
	            cout<<endl;
		        break;
        case 5: 
        		cout<<"Update Node Value into the List:"<<endl;  
	            cl.updateData();
	            break;
	    case 6:
        		cout<<"Delete a particular node: "<<endl;
	            cl.deleteData();
	            cout<<endl;
	            break;
	    case 7:
        		cout<<"Before Sorting : "<<endl;
	        	cl.display_list();
	            cl.sortList();
	            cout<<"After Sorting : "<<endl;
	            cl.display_list();
	            break;
	    case 8:
        		cout<<"Display Data of Circular link list"<<endl;
	            cl.display_list();
	            break;
		case 9:
               cout<<"Thank you keep visiting..."<<endl;
	           exit(1);
	           break; 
        default:
            	cout<<"Sorry Wrong choice!!!!!!"<<endl;
    }
        
    }while(choice!=9); //end of menu
    
    return 0;
}//end of main() function
 




