// Program for Reading data from  a file in CPP
#include<iostream>
#include<fstream>	//header file declaration
using namespace std;
int main()	//main() function
{
	char data;
	const char *fileName="myfile.txt";
	ifstream file;		//creating object of ifstream class
	file.open(fileName,ios::in); //opening file "myfile.txt" in write mode  (ios::in opens file in read mode)	
	if(!file)
	{
	 cout<<"Error in file Reading!!!!!!!"<<endl;  //if file doesnot exists it will show Error
	 return -1; 
	}	
	while (!file.eof())    	//Reading contents from file
	{
		file  >> data;	//read from file
		cout << data;	//Printing on console from file
	}
	file.close();    //closing the file	
	return 0;
}      //end of main() function
