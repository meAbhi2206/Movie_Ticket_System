#include<bits/stdc++.h>
#include<unistd.h>
#include <windows.h>
#include <dos.h>
#include<fstream>
//DEVOLOPED BY Abhishek
//ADMIN CODE: **** IS REQUIED TO CREATE A NEW ADMIN ACCOUNT
using namespace std;
void qformatup();
void qformatdown();
void listofmovies();
void printline();
int movie_id;
int choice;
int ret;
int i=5;
char movie_name[10][50];
int timing[10];
int bill_id=1;
int bill_movie[10];
char bill_timing[10][6];
int seat_num[10][10];
char date[10][15];
char seat[10][6];

class enrtypoint
{
	public:
	enrtypoint()
	{
		strcpy(movie_name[1],"Ghosted");
		timing[1]=1;
		strcpy(movie_name[2],"Suzume no Tojimari");
		timing[2]=2;
		strcpy(movie_name[3],"Kisi Ka Bhai Kisi Ki Jaan");
		timing[3]=2;
		strcpy(movie_name[4],"John Wick: Chapter 4");
		timing[4]=3;
		
	}
		int admin_menu();
		int user_menu();
		int add_show();
		int delete_show();
		int booking();
		void showmovielist();
		int cancellation();
	string username, password, check;
	void usermenu();
	void mainmenu();
	void welcome();
    void login()
    {
    qformatup();
    cout<<"WELCOME TO LOGIN PAGE";
    qformatdown();
    sleep(1);
    cout<<"\n\t USERNAME: ";
    cin>>username;
    cout<<"\n\tPASSWORD:";
	cin>>password;
	system("CLS");
	cout<<"\tPLs WAIT while CHECKING";
	for(int i=0;i<5;i++)
	{
		cout<<".";
		sleep(1);
	}
	ifstream take("login.txt");
	while(!take.eof())
	{
	take>>check;
	cout<<"\nchecking: "<<check;
	if(check==username)
	{
		cout<<"\nfinded: "<<check;
		take>>check;
		if(check==password)
		{
			cout<<"\r\r\t------------------Login successfull-----------------------";
			sleep(2);
		take>>check;
			if(check=="admin")
			{
				cout<<"\n\t\tWelcome ADMIN";
				sleep(2);
			admin_menu();
			break;
			}
			else
			{
				cout<<"\n\t\tWELCOME USER";
				sleep(2);
				user_menu();
				
			}
		}
		else
		{
			cout<<"\n\tlogin Unsuccessful...pls try again: :)";
			sleep(2);
			system("CLS");
			mainmenu();
		}
	} 
	else
		{
			cout<<"\n\tlogin Unsuccessful...pls try again: :)";
			sleep(2);
			system("CLS");
			if(take.eof())
			mainmenu();
		}
	}
    }
	void regis()
	{
	string admin,temp;
	system("CLS");
	qformatup();
	cout<<"Registration from";
	qformatdown();
	cout<<"\n\nFUll NAME: ";
	cin>>temp;
	cout<<"\nCONTACT NUMBER: ";
	cin>>temp;
	cout<<"\nEMAIL ADDRESS: ";
	cin>>temp;
	cout<<"\nUSERNAME: ";
	cin>>username;
	cout<<"\nPASSWORD: ";
	cin>>password;
	xy:
	cout<<"\nCONFROM PASSWORD: ";
	cin>>temp;
	if(temp!=password)
	{
		cout<<"\tPASSWORD MISSMATCHED ";
		sleep(1);
		goto xy;
	}
	yz:
	cout<<"\nADMIN ACCOUNT? [Y/N]: ";
	char ch;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		cout<<"Admin code: ";
		cin>>admin;
		if(admin!="2206")
		{
			cout<<"!!!!!!!!!!!!!Wrong code!!!!!!!!!!!!!";
			goto yz;
		}
		}
	ofstream fill("login.txt",ios::app);
	if(admin=="2206")
	fill<<"\n"<<username<<' '<<password<<' '<<"admin";
	else
	fill<<"\n"<<username<<' '<<password<<' '<<"user";
	mainmenu();
	}
	
};

void printline()
{
	cout<<"\n________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n";
	
}
main()
{
	enrtypoint e;
	e.welcome();
	
}
//welcome page:
void enrtypoint::welcome()
{

	cout<<"\n________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n\n\n   ----    ---     ---  ----------  ---       	-------       -----        ------     ------   ---------";	  
	cout<<"\n    ---   -----   ---   ---         ---         ---   ---    ---   ---     --- ---   -------   ---";
 	cout<<"\n     --- ------- ---    -------|    ---        ---          ---     ---    ---   -----   ---   ------|";  
  	cout<<"\n      -------------     ---         ---------  ---   ---    ---   ---      ---           ---   ---";
  	cout<<"\n       -----------      ----------  ---------  -------       -----         ---           ---   ---------\n\n\n";
  	qformatup();
  	cout<<"\t Movie ticket Management System";
  	qformatdown();
  	cout<<"\n\n---------------------------DEVELOPED BY Abhishek----------------------------------------------";
  	sleep(2);
	cout<<"\n\n\t\t\t\t\t     Please wait while loading\n\n";
	char a=177, b=219;
	cout<<"\t\t\t\t\t\t";
 	for (int i=0;i<=15;i++)
 		cout<<a;
 	cout<<"\r";
 	cout<<"\t\t\t\t\t\t";
 	for (int i=0;i<=15;i++)
 	{
  		cout<<b;
  	for (int j=0;j<=1e8;j++);
 	}
 	
 	mainmenu();
}
void qformatup()
{
	cout<<"\n\t                  ::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	cout<<"\n\t::::::::::::::::::                                                      :::::::::::::::::::::::::::::::";
	cout<<"\n\t  			";
	
}
void qformatdown()
{
	cout<<"\n\t::::::::::::::::::                                                      :::::::::::::::::::::::::::::::";
	cout<<"\n\t                 ::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	
}
void enrtypoint::mainmenu()
{
	system("CLS");
 	qformatup();
 	cout<<"\tLogin/Signup to proceed\t";
 	qformatdown();
	int chi;
	cout<<"\n[1]. Login";
	cout<<"\n[2]. SIGN UP";
	cout<<"\n[3]. Continue as guest";
	cout<<"\n Enter ur choice: ";
	cin>>chi;
	switch (chi)
	{
		case 1:
			login();
			break;
		case 2:
			regis();
		case 3:
			user_menu();
			break;
		default:
			mainmenu();
			break;
    }
}
int enrtypoint::add_show()
				{
				string ans;
				char yes;
				abc:
				system("CLS");
				qformatup();
				cout<<"ADMIN MENU";
				qformatdown();
				cout<<"\n\t\t Enter movie name:  ";
				cin>>movie_name[i];				
				cout<<"\t\t\t TIMINGS ";
				cout<<"\n1.9:00      13:00       17:00 \n2.  10:00     14:00       18:00\n3.   11:00     15:00       19:00\n\t CHOOSE TIMING ID:[1/2/3]";
				string timings;
				int x;
				cin>>x;
				timing[i]=x;
				switch (x)
				{
					case 1:
						timings="9:00      13:00       17:00";
						break;
					case 2:
						timings="10:00     14:00       18:00";
						break;
					default:
						timings="11:00     15:00       19:00";
						break;
			}
							cout<<"Movie id:  "<< i;
							sleep(1);
							cout<<"\rMovie name: "<<movie_name[i];
							sleep(1);
							cout<<"\r Show timings="<<timings;
							i++;
				cout<<"\nDO you want to add more movie[y/n]: ";
				cin>>ans;
				if( ans=="y"|| ans== "Y")
				{
				goto abc;
				}
				else
				admin_menu();	
				}
int enrtypoint::delete_show()
				{
					system("CLS");
					qformatup();
					cout<<"ADMIN MENU";
					qformatdown();
					cout<<"Enter the movie id to delete:";
					cin>>i;
					cout<<"NAME OF THE MOVIE IS:"<<movie_name[i];
					sleep(1);
					cout<<"\n\n\t ARE U SURE[y/n]: ";
					char c;
					cin>>c;
					if(c=='y'|| c=='Y')
					{
						strcpy(movie_name[i]," ");
					}
					admin_menu();
				}
int enrtypoint::admin_menu()
{
			system("CLS");
			qformatdown();
			cout<<"ADMIN MENU";
			qformatup();
			cout<<"\n\n\t\t\t 1.ADD show & SELECT Timing"<<endl;
			cout<<"\t\t\t 2.Delete show "<<endl;
			cout<<"\t\t\t 3.Book show "<<endl;
			cout<<"\t\t\t 4.Back to main "<<endl;
			cout<<"\n\n\tEnter your choice:   ";
			cin>>choice;
			switch(choice)
			{
				case 1: 
				add_show();
				break;
				case 2:
				delete_show();
				break;
				case 3:
				booking();
				break;
				default:
				mainmenu();
				break;
			}
			return 0;
}
int enrtypoint::user_menu()
		{
			system("CLS");
			qformatup();
			cout<<"USER MENU";
			qformatdown();
			cout<<"\n\n\t\t\t 1.Booking"<<endl;
			cout<<"\t\t\t 2.Cancellation"<<endl;
			cout<<"\t\t\t 3.Return to main menu"<<endl;
			cout<<"\t\t\t Enter your choice ";
			cin>>choice;
			switch(choice)
			{
				case 1: 
				booking();
				break;
				case 2: 
				cancellation();
				break;
				default:
				mainmenu();
				break;
					
			}
			return 0;
	}
		int enrtypoint::booking()
		{
			system("CLS");
			qformatup();
			cout<<"BOOK UR TICKET";
			qformatdown();
			showmovielist();
			cout<<"\nMOVIE SERIAL NO[1/2/3..]: ";
			cin>>bill_movie[bill_id];
			cout<<"\nMOVIE TIMING ID[1/2/3..]: ";
			cin>>timing[bill_id];
			cout<<"ENTER DATE:[DD/MM/YYYY]: ";
			cin>>date[bill_id];
			for(int j=1;j<=5;j++)
			{
				cout<<endl;
				for(int k=1;k<=6;k++)
				{ 
					cout<<"\t|["<<j<<","<<k<<"]";
					
				}
			}
			cout<<"\nSELECT UR SEAT: ";
			cin>>seat[bill_id];
			cout<<"\n\n\t\t\tPLEASE WAIT..";
			for(i=0;i<3;i++)
			{	
			cout<<".. ";
			sleep(1);
			}
			cout<<"\n\n\nYOUR TICKET IS BOOKED;";
            //writeBookingToFile(*bill_movie, *timing, seat, *date);
			sleep(1);
			user_menu();
		}

        void writeBookingToFile(int movie_id, int timing, int seat_num, char* date) {
        // Open the file in append mode
        ofstream bookingsFile("bookings.txt", std::ios_base::app);
        if (bookingsFile.is_open()) {
        // Write the details to the file
        bookingsFile << bill_movie << "," << timing << "," << seat << "," << date << "\n";
        // Close the file
        bookingsFile.close();
    }
}
		void enrtypoint::showmovielist()
			{
				cout<<"\n------------------------------------------------------------------------------------";
				cout<<"\n|SR NO|   \t[1.]\t[2.]\t[3.]\t\t\t|MOVIE NAME|";
				cout<<"\n------------------------------------------------------------------------------------";
				for(int j=1;j<i;j++)
				{
					int z;
					string timings;
					z=timing[j];
				switch (z)
				{
					case 1:
						timings="9:00      13:00       17:00";
						break;
					case 2:
						timings="10:00     14:00       18:00";
						break;
					default:
						timings="11:00     15:00       19:00";
						break;
				}
				cout<<"\n"<<j<<".\t"<<timings<<"\t\t\t"<<movie_name[j]<<endl;	
					
				}
			}
			int enrtypoint::cancellation()
			{
			system("CLS");
			qformatup();
			cout<<"CANCEL MENU";
			qformatdown();
			cout<<"Enter your bill id = : ";
			int k;
			cin>>k;		
			cout<<"\nMOVIE: "<<movie_name[bill_movie[bill_id]];
			cout<<"\n\n\t\t\tPLEASE WAIT..";
			for(i=0;i<3;i++)
			{	
			cout<<".. ";
			sleep(1);
			}
			cout<<"\n\n\t\tTICKET CANCELLED";
			sleep(1);
			user_menu();
					
				}