// Program for Writing/Reading objects to/from  a file in CPP
#include <iostream>
#include <fstream>		//header file declaration
using namespace std;
 
class Customer		//Customer class having name and salary data members
{
    private:
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
 
        void showCustomerInfo())			//Display customer data on console
        {
        cout<<"Customer Name	:	"<<c_name;
		cout<<"Customer Salary	:"<<c_salary<<endl;
        }
};		//end of Customer class
 
int main()			//main() function
{
  	 Customer c1;		//Creation of Customer class
     
    ofstream file;	//creating object of fstream class
 	//File Writing Operation 
    file.open("Customerdata.txt",ios::out); //opening file "Customerdata.txt" in write mode  (ios::out opens/create file in write mode)
    
    if(!file)		//checking for file
    {
      cout<<"Error in file Creation!!!!!!!"<<endl;
      return 0;
    }
    cout<<"\nFile created successfully!!!!!"<<endl;
        
    c1.getCustomerInfo();    //reading customer details from console
    
    file.write((char*) &c1, sizeof(c1));    //writing customer details into file
 
    file.close();   //closing  file
    
    cout<<"\nFile saved and closed succesfully!!!!!!!"<<endl;
 
   //File Reading Operation
    ifstream fileread;
   
    fileread.open("Customerdata.txt",ios::in); //opening file "Customerdata.txt" in read mode  (ios::in opens file in read mode)
   
    if(!file1)			//checking for file
	{
        cout<<"Error in file Opening!!!!!!!";
        return 0;
    }
    
    fileread.read((char*)&c1,sizeof(c1));	//reading customer details from file
 
    c1.showCustomerInfo();	//writing customer details on console

    fileread.close();  //closing file
     
    return 0;
}//end of main() function
