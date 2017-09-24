//Program for Constructor (Default/parameterized) in CPP

#include<iostream>	//Header file declaration
using namespace std;

class Student   //class student
{
	
 public:	
		int studid;		//data members
		string studname;	
	
	void getData();		//member functions declaration

	void displayData();						
	
};// class ends

//function outside the class syntax   return_type class_name :: function_name()
void Student :: getData()		//function outside the class
{ 
cout<<"\n Enter Student Id	:	";
cin>>studid;
cout<<"\n Enter Student Name	:	";
cin>>studname;
}
//function outside the class syntax   return_type class_name :: function_name()
void Student::displayData()			//function outside the class				
{
		cout<<"\n Student id is		:	"<<studid;
		cout<<"\n Student Name is	:	"<<studname<<endl;
}

int main()
{
 	int choice;
	int i;
	
	Student s1;  		//creation of object
	cout<<"\n Accept Student Record "<<endl;
	s1.getData();
	cout<<"\n Display Student Record "<<endl;
	s1.displayData();

	
	return 0;
}  //end of main()
