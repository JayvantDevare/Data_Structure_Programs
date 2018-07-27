//Program for command line arguments in CPP
//Command-line argument program in CPP
#include<iostream>//Header file decleration 
#include<stdlib.h>
using namespace std;
int main(int argc, char* argv[])//main function with command line arguments
{
	cout<<"\n Argc	:"<<argc;// argc - count of arguments	
	int num1, num2, result;
	num1 = atoi(argv[1]);//argv[] array of arguments in char format
	num2 = atoi(argv[2]);//atoi - conversion of char to int
	result = num1 + num2;
	cout<<"\n result	:"<<result;
	return 0;
}//end of main()
//while runnig program on command prompt  
//save file in  TURBOC3\BIN
//compile program 
//then run
//C:\TURBOC3\BIN>filename 200 300
