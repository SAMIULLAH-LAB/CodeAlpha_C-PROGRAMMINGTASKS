#include<iostream>
#include<fstream>
using namespace std;
class LoginSystem
{
	public:		
		string username;
		string password;
		void registerUser()
		{	
			string user, pass;
			bool found = false;	
			cout<<"Enter Username: ";
			cin>>username;
			cout<<"Enter Password: ";
			cin>>password;
			ifstream file("data.txt");
			
			while(file>>user>>pass)
			{
				if(username == user)
				{
					found = true;
				}
			}
			
			file.close();
			
			if(found){
				cout<<"Username Already Exists"<<endl;
			}
			else{
				ofstream file("data.txt",ios::app);
				
				file<<username<<"  "<<password<<endl;
				file.close();
				
				cout<<"Registration Successful"<<endl;
			}
		}
		
		void loginUser()
{
			
			string user, pass;
			bool login = false;
			
			cout<<"Enter Username: ";
			cin>>username;
			cout<<"Enter Password: ";
			cin>>password;
			ifstream file("data.txt");
			while(file>>user>>pass)
			{	
				if(username == user && password == pass){
					login = true;
			}
			}
			
			file.close();
			
			if(login){
				cout<<"Login Successful"<<endl;
			}
			else{
				cout<<"Wrong Username or Password"<<endl;
			}
		}
};

int main(){	
	LoginSystem l;
	int choice;

do
	{
	cout<<endl;
	cout<<"1. Register"<<endl;
	cout<<"2. Login"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Enter Choice: ";
	cin>>choice;
		
	if(choice == 1)
	{
		l.registerUser();
		}
		else if(choice == 2)
		{
			l.loginUser();
		}
		else if(choice == 3){
			cout<<"Program Ended"<<endl;
		}
		else
		{
			cout<<" Invalid choice"<<endl;
	}
		
}
		while(choice != 3);
	
	return 0;
}
