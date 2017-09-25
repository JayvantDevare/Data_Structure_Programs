//Program for Singly Linked List in CPP
/*
 	1.Insert Node at beginning of the List
    2.Insert node at given position in the List
    3.Insert node at last of the List
    4.Sort Link List
    5.Update Node Value in the List
    6.Delete a Particular Node from List
    7.Search Element in the List
    8.Reverse List
    9.Display List Data
*/
#include<iostream>	//Header file
#include<cstdio>
#include<cstdlib>
using namespace std;

class Node		//class Node for creating node		
{
    public:
			int data;
    		Node *next;				//next pointer which will point to the next node into the list
};
 
class Singly_Linked_List	//class for singly linked list operations
{
    public:
    	Node* Head;			//pointer to point first node of the list 
    	
    	Singly_Linked_List() 
        {
            Head = NULL;
        }
        
        Node* create_node(int Value);			//operations on SLL
        void insert_at_begin();
        void insert_at_position();
        void insert_at_last(); 
        void delete_at_position();
        void sortList();
        void searchData();
        void updateData();
        void reverseList();
        void displayList();
        
};
 
 // 1. Function for Creating Node

Node* Singly_Linked_List::create_node(int value)
{
    Node* newnode;
    newnode = new Node(); 		//creating node
    if (newnode == NULL)
    {
        cout<<"Memory not allocated for the New Node"<<endl;
        return 0;
    }
    else
    {
        newnode->data = value;
        newnode->next = NULL;     
        return newnode;
    }
}	//end of create_node(int) function
 

// 2. Function for Inserting Node into the List at Begining

void Singly_Linked_List::insert_at_begin()
{
    int value;
    cout<<"Enter the data to be inserted into the list	: ";
    cin>>value;
    Node* newnode;
	Node* temp;
    newnode = create_node(value);			//calling create_node(int) function
    if (Head == NULL)				     	// if list is empty 
    {
        Head = newnode;
        Head->next = NULL;          
    } 
    else							       //if list containse one or more nodes
    {
        temp = Head;
        Head = newnode;
        Head->next = temp;
    }
    cout<<"Element Inserted at beginning of the List"<<endl;
}// end of insert_at_begin() function

// 3. Function for Inserting Node into the List at Given Possition
void Singly_Linked_List::insert_at_position()
{
    int value;
	int position;
	int counter = 0; 
    cout<<"Enter the Data to be inserted at given position	: ";
    cin>>value;
    Node* newnode;
	Node* trav;
	Node* temp;
    newnode = create_node(value);
    cout<<"Enter the postion at which node is to be inserted	:	 ";
    cin>>position;
    int i;
    trav = Head;
    while (trav != NULL)
    {
        trav = trav->next;
        counter++;
    }
    if (position == 1)
    {
        if (Head == NULL)
        {
            Head = newnode;
            Head->next = NULL;
        }
        else
        {
            temp = Head;
            Head = newnode;
            Head->next = temp;
        }
    }
    else if (position > 1  && position <= counter)
    {
        trav = Head;
        for (i = 1; i < position; i++)
        {
            temp = trav;
            trav = trav->next;
        }
        temp->next = newnode;
        newnode->next = trav;
    }
    else
    {
        cout<<"Invalid Positon!!!! "<<endl;
    }
}//end of insert_at_postion() function

 //4. fucntion for inserting node at last
void Singly_Linked_List::insert_at_last()
{
    int value;
    cout<<"Enter the data to be inserted at last in the List: ";
    cin>>value;
    Node* newnode;
	Node* trav;
    newnode = create_node(value);
    trav = Head;
    while (trav->next != NULL)
    {         
        trav = trav->next;        
    }
    newnode->next = NULL;
    trav->next = newnode;
    cout<<"Element Inserted at last"<<endl;  
}//end of insert_at_last() function

 //5.function for sorting given list
void Singly_Linked_List::sortList()
{
    Node* trav;
	Node* temp;
    int value;
    if (Head == NULL)
    {
        cout<<"Given List is empty!!!!!"<<endl;
        return;
    }
    trav = Head;
    while (trav != NULL)
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

//6. function for searching data into the List

void Singly_Linked_List::searchData()
{
    int value;
	int position = 0;
    int flag = 0;
    if (Head == NULL)
    {
        cout<<"Sorry List is empty!!!!!"<<endl;
        return;
    }
    cout<<"Enter the data to be searched into the List	: ";
    cin>>value;
    Node* trav;
    trav = Head;
    while (trav != NULL)
    {
        position++;
        if (trav->data == value)
        {
            flag = 1;
            cout<<"Element "<<value<<" is found at position "<<position<<endl;
        }
        trav = trav->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}// end of searchData() function

 //7. function for Updating data of the node from the List
void Singly_Linked_List::updateData()
{
    int value;
	int position;
	int i;
    if (Head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion whose value is to be updated in to the List	: ";
    cin>>position;
    cout<<"Enter the new value: ";
    cin>>value;
    Node* trav;
    trav = Head;
    if (position == 1)
    {
        Head->data = value; 
    }
    else
    {
        for (i = 0; i < position - 1 ; i++)
        {
            if (trav == NULL)
            {
                cout<<"There are less than "<<position<<" elements available in to the List";
                return;
            }
            trav = trav->next;
        }
        trav->data = value;  
    }
    cout<<"Node Data Updated into the List"<<endl;
} //end of updataData() function

//8. function for Deleting node from the List at any position
void Singly_Linked_List::delete_at_position()
{
    int position;
	int i;
	int counter = 0;
    if (Head == NULL)
    {
        cout<<"Sorry List is empty!!!"<<endl;
        return;
    }
    cout<<"Enter the position of data to be deleted from the List: ";
    cin>>position;
    Node* trav;
	Node* temp;
    trav = Head;
    if (position == 1)
    {
        Head = trav->next;
    }
    else
    {
        while (trav != NULL)
        {
            trav = trav->next;
            counter++;  
        }
        if (position > 0 && position <= counter)
        {
            trav = Head;
            for (i = 1 ; i < position ; i++)
            {
                temp = trav;
                trav = trav->next;
            }
            temp->next = trav->next;
        }
        else
        {
            cout<<"Invalid Position!!!!!"<<endl;
        }
        free(trav);
        cout<<"Given Element is Deleted from the List"<<endl;
    }
}//end of delete_at_position() function

// 9. function for reversing the data of List
 void Singly_Linked_List::reverseList()
{
    Node* temp1;
	Node* temp2;
	Node* trav;
    if (Head == NULL)
    {
        cout<<"Sorry List is empty!!!"<<endl;
        return;
    }
    if (Head->next == NULL)
    {
        return;
    }  
    temp1 = Head;
    temp2 = temp1->next;
    trav = temp2->next;
    temp1->next = NULL;
    temp2->next = temp1;
    while (trav != NULL)
    {
        temp1 = temp2;
        temp2 = trav;
        trav = trav->next;
        temp2->next = temp1;         
    }
    Head = temp2;
}

//10. function for displaying List data

void Singly_Linked_List::displayList()
{
    Node* trav;
    if (Head == NULL)
    {
        cout<<"Sorry List is Empty!!!"<<endl;
        return;
    }
    trav = Head;
    cout<<"Elements in the list are: "<<endl;
    while (trav != NULL)
    {
        cout<<trav->data<<"->";
        trav = trav->next;
    }
    cout<<"NULL"<<endl;
}//end of displayList() function


int main()
{
    int choice;
	int i;
    Singly_Linked_List sl;  //creating object of list class
    do 
    {
        cout<<endl<<"********************************"<<endl;
        cout<<endl<<" Singly Linked List Operations"<<endl;
        cout<<endl<<"********************************"<<endl;
        cout<<"1.Insert Node at beginning of the List"<<endl;
        cout<<"2.Insert node at given position in the List"<<endl;
        cout<<"3.Insert node at last of the List"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Search Element in the List"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Delete a Particular Node"<<endl;
        cout<<"8.Reverse Linked List"<<endl;
        cout<<"9.Display Linked List"<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
	            cout<<"Inserting Node at Beginning of the List: "<<endl;
	            sl.insert_at_begin();
	            cout<<endl;
	            break;
        case 2:
	            cout<<"Inserting Node at a given position in the List:"<<endl;
	            sl.insert_at_position();
	            cout<<endl;
	            break;
        case 3:
                cout<<"Inserting Node at Last of the List: "<<endl;
	            sl.insert_at_last();
	            cout<<endl;
	            break;
        case 4:
        		cout<<"Before Sorting : "<<endl;
	            sl.displayList();
	            sl.sortList();
	            cout<<endl;
	            cout<<"After Sorting : "<<endl;
	            sl.displayList();
            	break;
        case 5:
	        	cout<<"Search any element in Link List: "<<endl;
	            sl.searchData();
	            cout<<endl;
            	break;
        case 6:
	            cout<<"Update Node Value into the List:"<<endl;  
	            sl.updateData();
	            cout<<endl;
	            break;
        case 7:
            	cout<<"Delete a particular node: "<<endl;
           		sl.delete_at_position();
           		cout<<"After Deleting node : "<<endl;
	            sl.displayList();
	            cout<<endl;
            	break;
        case 8:
        		cout<<"Reverse elements of Link List"<<endl;
        		cout<<"\n Before Reverse"<<endl;
        		sl.displayList();
	            sl.reverseList();
	            cout<<endl;
	            cout<<"\n After Reverse"<<endl;
	            sl.displayList();
	            cout<<endl;
	            break;
        case 9:
	            cout<<"Display elements of link list"<<endl;
	            sl.displayList();
	            cout<<endl;
	            break;
        case 10:
	            cout<<"Thank you keep visiting..."<<endl;
	            exit(1);
	            break;  
        default:
            	cout<<"Sorry Wrong choice"<<endl;
        }
    }while(choice!=10);
}//end of main() function
 


 


