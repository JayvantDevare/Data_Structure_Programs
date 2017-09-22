// Program for Writing and Reading data to/from  a file in CPP
#include <iostream>
#include <fstream>		//header file declaration
 
using namespace std;
 
int main()				//main() function
{
   fstream file; //creating object of fstream class
    
  //File Writing Operation
  
   file.open("myfile.txt",ios::out); //opening file "myfile.txt" in write mode  (ios::out opens/create file in write mode)
	
	if(!file)			//checking for file
   {
       cout<<"Error in file Creation!!!!!!!"<<endl;
       return 0;
   }
   cout<<"File created successfully."<<endl;

   file<<"Welecome to Data Structure World ";    //writing string into file
  
   file.close();	//closing of file
  
  //File Reading Operation
  
   file.open("myfile.txt",ios::in);  //opening file "myfile.txt" in read mode  (ios::in opens file in read mode)
    
	if(!file)					//checking for file
   {
       cout<<"Error in file Opening!!!!!!!"<<endl;
       return 0;
   }   
    
   
   char ch; 					//to read single character
   cout<<"File content are: ";
    
   while(!file.eof())
   {
       file>>ch;      //reads single character at a time from file
       cout<<ch;	//printing character on console
   }
    
   file.close(); //closing of file
    
   return 0;
}  //end of main() function
