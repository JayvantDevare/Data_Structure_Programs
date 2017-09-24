//Program for writing function with parameters in CPP
//each program containse only one main function
//you can write any number of functions 

#include <iostream>	//header file 
using namespace std;

int addition(int* num1, int* num2) //adition function with two parameters
{
	int result;
	result= *num1+*num2;			// performing operation
	return result;				// returning result 
	
}//end additiion function

int main()  //main function
{
	int num1;	//local variable declaration
	int num2;
	int result;
	cout<<"\n Enter number 1:";  //accepting input from user
	cin>>num1;
	cout<<"\n Enter number 2:";
	cin>>num2;
	
	result= addition(&num1, &num2);	//calling addition function by passing two arguments

	cout<<"\n Addition is	:	"<<result;

	return 0;  // return int value
}//end of main function
