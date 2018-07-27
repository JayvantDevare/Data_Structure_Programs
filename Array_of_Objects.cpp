//Array of Objects

#include<iostream>					//Header file Declaration
using namespace std;

class Customer{						//class declaration
 public:
 	int cid;
 	string cname; 	
 	void getdata(){					//Reading data from console 		
 		cout<<"\n Enter Customer Id	:	";
 		cin>>cid;
 		cout<<"\n Enter Customer Name	:	";
 		cin>>cname;	
 		cout<<endl;
 	}								//end of getdata() function
	void display(){		
		cout<<"\n Customer Id     :	"<<cid;
		cout<<"\n Customer Name   :	"<<cname<<endl;
	}							//end of display() function
};								//end of Custmoer class
int main()
{	
	int choice;
	Customer c[10];					//Array of Objects
	int count=0;					//variables declaration and Initialization
	int id;
	int flag=0;
	int cnt=0;
	do{								//Menu
		cout<<"\n ******* MENU *********";
		cout<<"\n Custmoer Record";
		cout<<"\n 1. Insert Custmoer Record";
		cout<<"\n 2. Display Custmoer Record";
		cout<<"\n 3. Search Custmoer Record";
		cout<<"\n 4. Exit";
		cout<<"\n Enter u r Choice";
		cin>>choice;	
	switch(choice){ 							//Switch case		
		case 1: 
			c[count].getdata();				//calling of function
			count++;
			cout<<count <<" Customer Added "<<endl;
			break;		
		case 2: 	
			cout<<" Total Customers added	"<<count<<endl;
			for(int i=0;i<count;i++){
				c[i].display();
			}
			break;			
		case 3:
			cout<<"\n enter id to be serach"<<endl;
			cin>>id;
			for(int i=0;i<count;i++){
				if(c[i].cid==id)
				{
				flag=1;
				cnt=i;
		    		}
			}				
			if(flag==1){
				cout<<"\n found";
				c[cnt].display();
				flag=0;
			}
			else{
				cout<<"\n  Not found";
			}
			break;			
		case 4:
			cout<<"\n Thank you......";
			break;
	}
	
}while(choice!=4);		//Menu ends	
return 0;	//returns 0 value
}	//end of main() function
