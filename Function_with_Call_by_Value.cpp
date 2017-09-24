//Program for writing function with parameters (pass by value) in CPP
//each program containse only one main function
//you can write any number of functions 

#include <iostream>	//header file 
using namespace std;

int addition(int num1, int num2) //adition function with two parameters
{
	int result;
	result= num1+num2;			// performing operation
	return result;				// returning result 
	
}//end additiion function

int main()  //main function
{
	
	int result;
		
	result= addition(100, 200);	//calling addition function by passing two arguments(call by value)

	cout<<"\n Addition is	:	"<<result;

	return 0;  // return int value
}//end of main function
