// Program for creating a file in CPP
#include <iostream>		//header file declaration
#include <fstream>
using namespace std; 
int main()					//main() function
{
   fstream file; 			//creating object of fstream class  
   file.open("myfile.txt",ios::out);  //opening file "mitaoe.txt" in write mode  (ios::out opens/create file in write mode)    
   if(!file)				//checking for files
   {
       cout<<"Error in file Creation!!!!!!!";
       return 0;
   }    
   cout<<"Congratulations File created successfully on your Computer";      
   file.close(); //closing the file    
   return 0;
}//end of main() function
