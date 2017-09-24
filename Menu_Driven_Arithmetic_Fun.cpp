//menu driven program for arithmatic operations in CPP
//each program containse only one main function
//you can write any number of functions 

#include <iostream>	//header file 
using namespace std;

int addition(int num1, int num2) //adition function with two parameters
{
	return 	num1+num2;;				// returning result 
	
}//end additiion function

int substraction(int num1, int num2) //substraction function with two parameters
{
	return 	num1-num2;;				// returning result 
	
}//end substraction function

int division(int num1, int num2) //division function with two parameters
{
	return 	num1/num2;;				// returning result 
	
}//end division function 

int multiplication(int num1, int num2) //multiplication function with two parameters
{
	return 	num1*num2;;				// returning result 
	
}//end multiplication function

int main()  //main function
{
	int num1;	//local variable declaration
	int num2;
	int result;
	int choice;	// accepting choice from user

	do
	{
			cout<<"\n\n ********* Menu ********";
			cout<<"\n 1. Addition";
			cout<<"\n 2. Substraction";
			cout<<"\n 3. Division";
			cout<<"\n 4. Multiplication";
			cout<<"\n Enter number 1:";  //accepting input from user
			cin>>num1;
			cout<<"\n Enter number 2:";
			cin>>num2;
			cout<<"\n Enter your choice:";	//accept choice from user
			cin>>choice;
		switch(choice)			//switch case
		{
			case 1: result = addition(num1, num2);	//calling addition function by passing two arguments
					cout<<"\n Addition is	:	"<<result<<endl;
					break;
			case 2: result = substraction(num1, num2);	//calling substraction function by passing two arguments
					cout<<"\n Substraction is	:	"<<result<<endl;
					break;
			case 3: result = division(num1, num2);	//calling division function by passing two arguments
					cout<<"\n Division is	:	"<<result<<endl;
					break;
			case 4: result =  multiplication(num1, num2);	//calling multiplication function by passing two arguments
					cout<<"\n Multiplication is	:	"<<result<<endl;
					break;
			default:
				cout<<"Invalid choice............"<<endl;
		}
		
	}while(choice<=5);
	
	return 0;  // return int value
}//end of main function
