// Program for Writing/Reading objects to/from  a file in CPP
#include <iostream>
#include <fstream>		//header file declaration
#include <cstring>
using namespace std;
 
class Customer		//Customer class having name and salary data members
{
    public:
        char c_name[30];
        int c_salary;
    public:
        void getCustomerInfo()				//Read customer details from console
        { 
			cout<<"Enter Customer Name	:	"; 
			cin>>c_name;
            cout<<"Enter Customer Salary	:	"; 
			cin>>c_salary;
        }
 
        void showCustomerInfo()			//Display customer data on console
        {
        cout<<"\nCustomer Name	:	"<<c_name;
		cout<<"\nCustomer Salary	:"<<c_salary<<endl;
        }
};		//end of Customer class
 
class filedata
{
	public:
		ofstream filewrite;
		ifstream fileread;
		Customer c1;
		Customer c2;
		
	void writetofile()	// function for writing objects into text file
	{
		/*
			opening file "Customerdata.txt" in write mode  
			(ios::out opens/create file in write mode)
			(ios::app opens  file in append mode)
		*/
		filewrite.open("Customerdata.txt",ios::out|ios::app); 
	    
	    if(!filewrite)		//checking for file
	    {
	      cout<<"Error in file Creation!!!!!!!"<<endl;
	      
	    }
	    cout<<"\nFile created successfully!!!!!"<<endl;
	        
	    c1.getCustomerInfo();    //reading customer details from console
	    
	    filewrite.write((char*) &c1, sizeof(c1));    //writing customer details into file
	 
	    filewrite.close();   //closing  file
	    
	    cout<<"\nFile saved and closed succesfully!!!!!!!"<<endl;
	}
	
	void readfromfile() // function for reading objects from text file
	{
	
		fileread.open("Customerdata.txt",ios::in); //opening file "Customerdata.txt" in read mode  (ios::in opens file in read mode)
	   
	    if(!fileread)			//checking for file
		{
	        cout<<"Error in file Opening!!!!!!!";
	       
	    }
	    
	    while(fileread.read((char*)& c1,sizeof(c1)))		//reading customer data from file
		{
		 
		 		c1.showCustomerInfo();
				cout<<endl<<"--------------------------------------------\n"<<endl;
		}
	    fileread.close();  //closing  file
	}
	
	
	
	void searchRecordFromFile()  // function for searching record in to file
	{
		
		char name[10];
		int flag=0;
		
		fileread.open("Customerdata.txt",ios::in); //opening file "Customerdata.txt" in read mode  (ios::in opens file in read mode)
   
	    if(!fileread)			//checking for file
		{
	        cout<<"Error in file Opening!!!!!!!";
	        
	    }
    	
		cout<<"Enter which customer u want to search";
    	cin>>name;
    
        while(fileread.read((char*)& c1,sizeof(c1)))	//seraching customer into file
		{
			if(strcmp(c1.c_name,name)==0)
			{
				c2=c1;
				flag=1;
				cout<<endl<<"--------------------------------------------\n"<<endl;
				break;
			}
		}
		
		if(flag)
		{
		    cout<<"found";
			c2.showCustomerInfo();
		    flag=0;
		}
		else
		{
			cout<<"not found";
		}
		fileread.close(); //closing file
    }
};
 
 
int main()			//main() function
{
	int choice;
	filedata f;
	do
	{
		cout<<"\n ***********File Operations***************";
		cout<<"\n 1. Writing Object into File";
		cout<<"\n 2. Reading Objects from File";
		cout<<"\n 3. Searching Customer Records from File";
		cout<<"\n Enter choice	:	";
		cin>>choice;
		switch(choice)
		{
			case 1: 
					f.writetofile();		//calling function for writing objects to file
					break;
			case 2:
					f.readfromfile();	//calling function for reading objects from file
					break;
			case 3:
					f.searchRecordFromFile();  //calling function for searching record from file
					break;
		}
	}while(choice!=9);
    return 0;
}//end of main() function
