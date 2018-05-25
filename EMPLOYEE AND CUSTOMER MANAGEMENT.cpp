//LIBRARIES
#include<iostream>
#include<iomanip>
#include <conio.h>
using namespace std;

struct node
   {
      //POINTER FOR BOTH
	  node *next;
	  node *prev;
	  //CUSTOMER MANAGEMENT SYSTEM VARIABLES
	  //VARIABLES DECLARATION
	   int acno;
	   string name;
	   string address;
	   double phone_no;
	   string city;
	   double deposite;
	   double withdraw; 
	   //EMPLOYEE MANAGEMENT SYSTEM VARIABLES
	   //VARIABLES DECLARATION
	   int id; 			
	   string nam; 		
	   string qua;
	   string addrs; 
	   string v_city;
	   string jobtitle;
	   int salary;
	   string date;
	};
	
	node *head;	//GLOBALLY INITIALIZE POINTER OF HEAD

//FUNCTION DECLARATIONS
void login();
void connection_ways();
void customer_menu_selection();
void employee_menu_selection();

//BEGINNING NODE OF EMPLOYEE
void add_first()		
	{    
		system("cls");		
		system(" color 2e");
		node *newer=new node;
		cout<<"ENTER THE NEW EMPLOYEE ID"<<endl;
		cin>>newer->id;
		cout<<"ENTER THE FULL NAME OF NEW EMPLOYEE"<<endl;
		cin>>newer->nam;
		cout<<"ENTER THE QUALIFICATION OF NEW EMPLOYEE"<<endl;
		cin>>newer->qua;
		cout<<"ENTER THE ADDRESS OF NEW EMPLOYEE"<<endl;
		cin>>newer->addrs;
		cout<<"ENTER THE CITY OF NEW EMPLOYEE"<<endl;
		cin>>newer->v_city;
		cout<<"ENTER THE JOB TITLE OF NEW EMPLOYEE"<<endl;
		cin>>newer->jobtitle;
		cout<<"ENTER THE SALARY OF NEW EMPLOYEE"<<endl;
		cin>>newer->salary;
		cout<<"ENTER THE START DATE OF HIS SELECTION"<<endl;
		cin>>newer->date;
		
		cout<<"BEGINNING RECORD SUCCESFULLY INSERTED PRESS Y TO CONTINUE"<<endl;
			 			
		newer->prev=NULL;           
		newer->next=NULL;
					   
		if(head==NULL)
		{
			head=newer;
			return;				
		}
		head->prev=newer; 		 
		newer->next=head;
		head=newer;

 	}
//LAST NODE OF EMPLOYEE 	
 	void add_last()		
	{
		system("cls");		
		system(" color 3e");
		char ch;
		if (head==NULL)
		{
			cout<<"OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'||ch=='y')
			{
				add_first();
				return;
			}
			else 
			{
				employee_menu_selection();
			}		
		}
		else 
		{
			node *p=head;
			
			while (p->next!=NULL)
			{
				p=p->next;
			}	
			node *newer=new node;
			
			cout<<"ENTER THE NEW EMPLOYEE ID"<<endl;
			cin>>newer->id; 
			cout<<"ENTER THE FULL NAME OF NEW EMPLOYEE"<<endl;
			cin>>p->nam;
			cout<<"ENTER THE QUALIFICATION OF NEW EMPLOYEE"<<endl;
			cin>>newer->qua;
			cout<<"ENTER THE ADDRESS OF NEW EMPLOYEE"<<endl;
			cin>>newer->addrs;
			cout<<"ENTER THE CITY OF NEW EMPLOYEE"<<endl;
			cin>>newer->v_city;
			cout<<"ENTER THE JOB TITLE OF NEW EMPLOYEE"<<endl;
			cin>>newer->jobtitle;
			cout<<"ENTER THE SALARY OF NEW EMPLOYEE"<<endl;
			cin>>newer->salary;
			cout<<"ENTER THE START DATE OF HIS SELECTION"<<endl;
			cin>>newer->date;
			
			newer->next=NULL;
			p->next=newer;
			newer->prev=p; 
		}
		cout<<"RECORD SUCCESSFULLY INSERTED"<<endl;
	}
//MID NODE OF EMPLOYEE
void add_after()
	{
		system(" color 3e");
		system("cls");		
		char ch;
		if (head == NULL)
		{
			cout<<"OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD A NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{
				employee_menu_selection();
			}
		}
		else 
		{
			int val;
			cout<<"ENTER THE ID OF THAT EMPLOYEE AFTER WHICH YOU WANT TO ADD THIS NEW EMPLOYEE"<<endl;
			cin>>val;
			bool flag = false;
			node *p=head;
			while(p!=NULL)
			{
				if(p->id==val)
				{
					node* newer=new node;
					
					cout<<"ENTER THE NEW EMPLOYEE ID"<<endl;
					cin>>newer->id; 
					cout<<"ENTER THE FULL NAME OF NEW EMPLOYEE"<<endl;
					cin>>newer->nam;	
					cout<<"ENTER THE QUALIFICATION OF NEW EMPLOYEE"<<endl;
					cin>>newer->qua;
					cout<<"ENTER THE ADDRESS OF NEW EMPLOYEE"<<endl;
					cin>>newer->addrs;
					cout<<"ENTER THE CITY OF NEW EMPLOYEE"<<endl;
					cin>>newer->v_city;
					cout<<"ENTER THE JOB TITLE OF NEW EMPLOYEE"<<endl;
					cin>>newer->jobtitle;
					cout<<"ENTER THE SALARY OF NEW EMPLOYEE"<<endl;
					cin>>newer->salary;
					cout<<"ENTER THE START DATE OF HIS SELECTION"<<endl;
					cin>>newer->date;
					
					if (p->next!=NULL )
					{
						newer->next=p->next;
						newer->prev=p;
						p->prev=newer;
						p->next=newer;
					}
					else 
					{
						newer->next=p->next;
						newer->prev=p;
						p->next=newer;
					}
					flag = true;
				}
				p=p->next;
			}
			if(flag==false)
			{
				cout<<"ID IS NOT FOUND"<<endl;
			}
		} 
	}
	
//SEARCH NODE OF EMPLOYEE	
	void search()		
	{
	system(" color 4e");
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<<"OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD A NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{
				employee_menu_selection();
			}
		}
		else 
		{
			int val;
			cout<<"ENTER THE EMPLOYEE ID YOU WANT TO SEARCH"<<endl;
			cin>>val;
			node *p=head; 
			while(p!=NULL)
			{
				if(p->id==val)
				{
					cout<<"INFORMATION OF ALL EMPLOYEES"<<endl;
					cout<<"ID"<<"NAME"<<"QUALIFICATION"<<"ADDRESS"<<"CITY"<<"JOB TITLE"<<"SALARY"<<"STARTING DATA"<<endl;
					cout<<p->id<<p->nam<<p->qua<<p->addrs<<p->v_city<<p->jobtitle<<p->salary<<p->date<<endl;
					return;	
				}
				else
				{
					p=p->next;	
				}
			}
		}
	}

//UPDATE NODE OF EMPLOYEE		
	void update()		
	{
	system(" color 5e");
		system("cls");		
		char ch;
		if (head==NULL)		
		{
			cout<<"OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD A NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{
				employee_menu_selection();
			}
		}
		else			
		{
			int val;
			cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO UPDATE"<<endl;
			cin>>val;		
			node *p=head;
			while (p!=NULL)		
			{
				if(p->id==val)		
				{
					cout<<"ENTER THE FULL NAME OF NEW EMPLOYEE"<<endl;
					cin>>p->nam;	
				}
				p=p->next;		
			}
			cout<<"RECORD HAS BEEN SUCCESSFULLY UPDATED"<<endl;
		}
	}
//DELETE FIRST NODE OF EMPLOYEE
void del()		
	{ system(" color 6e");
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<< "OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{	
				employee_menu_selection();
			}	
		}
		else
		{
			node *tmp=head;
			
			head=tmp->next;
			head->prev=NULL;
			delete tmp;
			cout<<"RECORD HAS BEEN DELETED SUCCESSFULLY"<<endl;
		}		
	}

//DELETE LAST NODE OF EMPLOYEE	
void del_last()
	{system(" color 7e");
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<< "OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{	
				employee_menu_selection();
			}	
		}
		else
		{
			node *p=head;
			node *tmp;			
			while (p->next->next!=NULL)
			{
				p=p->next;
			}
			tmp=p->next;
			p->next=NULL;
			delete tmp;
		}
	}
//DELETE MID NODE OF EMPLOYEE
void del_position()
	{ system(" color 8e");
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<< "OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{	
				employee_menu_selection();
			}	
		}
		else
		{
			int val;
			cout<<"MAKE SURE THAT THE GIVEN ID IS NOT THE FIRST ONE OR THE LAST ONE"<<endl;
			cout<<"ENTER THE ID OF THE RECORD YOU WANT TO DELETE"<<endl;
			cin>>val;
			node *p=head;
			node *temp;
			while(p->next!=NULL)
			{
				if(p->next->id==val)
				{
					temp=p->next;
					p->next=temp->next;
					temp->next->prev=temp->prev;
					delete temp;
				}
				p=p->next;
			}
		}
	}
//DELETE IF ONLY ONE NODE OF EMPLOYEE IS REMAINING	
void del_only()
	{ system(" color 9e");
		system("cls");		
		node *temp=head;
		head=NULL;
		delete temp;
	}
	
//DISPLAY NODE OF EMPLOYEE
void show()			
	{   system(" color 5e");
		system("cls");		
		char ch;
		if(head==NULL)
		{
			cout<<"OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD A NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				add_first();
				return;
			}
			else 
			{
				employee_menu_selection();
			}
		}
		else
		{
			node *temp=head;		
			while(temp!=NULL)	
			{
				cout<<"INFORMATION OF ALL EMPLOYEES"<<endl;
				cout<<"ID \t"<<temp->id<<endl;
				cout<<"NAME \t"<<temp->nam<<endl;
				cout<<"QUALIFICATION \t"<<temp->qua<<endl;
				cout<<"ADDRESS \t"<<temp->addrs<<endl;
				cout<<"CITY \t"<<temp->v_city<<endl;
				cout<<"JOB TITLE \t"<<temp->jobtitle<<endl;
				cout<<"SALARY \t"<<temp->salary<<endl;
				cout<<"STARTING DATE \t"<<temp->date<<endl;
				temp=temp->next;
			}
		}
	}
//MENU OF EMPLOYEE MANAGEMENT	
void employee_menu()				
	{   system(" color 6e");
		system("cls");		
		cout<<setw(50)<<"******************* \n"<<endl;
		cout<<setw(50)<<"EMPLOYEE MANAGEMENT \n"<<endl;
		cout<<setw(50)<<"******************* \n"<<endl;
		cout<<setw(51)<<"1. TO ADD A RECORD AT BEGINNING \n"<<endl;
		cout<<setw(46)<<"2. TO ADD A RECORD AT LAST \n"<<endl;
		cout<<setw(55)<<"3. TO ADD A RECORD AFTER ANY RECORD \n"<<endl;
		cout<<setw(40)<<"4. TO SEARCH A REORD \n"<<endl;
		cout<<setw(41)<<"5  TO UPDATE A RECORD \n"<<endl;
		cout<<setw(54)<<"6. TO DELETE A RECORD AT BEGINNING \n"<<endl;
		cout<<setw(49)<<"7. TO DELETE A RECORD AT LAST \n"<<endl;
		cout<<setw(57)<<"8. TO DELETE A RECORD AT ANY POSITION \n"<<endl;
		cout<<setw(58)<<"9. TO DELETE THE ONLY RECORD REMAINING \n"<<endl;
		cout<<setw(42)<<"10 TO DISPLAY A RECORD \n"<<endl;
		cout<<setw(30)<<"11 TO EXIT \n"<<endl;
		cout<<setw(42)<<"12 GOTO SELECTION MENU \n"<<endl;
	}
	
//EMPLOYEE MANAGEMENT MENU SELETION	
void employee_menu_selection()
	{
		int n;
		char ch;
		x2:employee_menu(); 
		cout<<"ENTER YOUR CHOICE"<<endl;
		cin>>n;		
		if(n==1)		
		{
			add_first();		
			cout<"DO YOU WANT TO GO MAIN MENU (Y/N)";
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x2; 	
			}
			else
			{
				exit(1);	
			}		
		}
		else if(n==2)
		{
			add_last();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==3)
		{
			add_after();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if (n==4)		
		{
			search();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;			
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if (n==5)			
		{
			update();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;		
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==6)		
		{
			del();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}	
		}
		else if(n==7)
		{
			del_last();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
				if(ch=='Y'||ch=='y')
				{
					goto x2;
				}
				else 
				{
					exit(1);
				}
			}
		else if(n==8)
		{
			del_position();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==9)
		{
			del_only();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==10)		
		{
			show();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;		
			if(ch=='Y'||ch=='y')
			{
				goto x2;
			}
			else 
			{
				exit(1);
			}		
		}
		else if (n==11)		
		{
			exit(1);
		}
		else if(n==12)
		{
			connection_ways();
		}
		else		
		{
			cout<<"CHOOSE CORRECT ANSWER"<<endl;
			goto x2;
		}
	}
	
//BEGINNING NODE OF CUSTOMER
void insertAtbeg ()
	{   system(" color 9e");
		system("cls");		
		node *newer = new node;
		cout<<"ENTER THE ACCOUNT NUMBER "<<endl;
		cin>>newer->acno;
		cout<<"ENTER THE NAME "<<endl;
		cin>>newer->name;
		cout<<"ENTER THE ADDRESS "<<endl;
		cin>>newer->address;
		cout<<"ENTER THE PHONE_NO "<<endl;
		cin>>newer->phone_no;
		cout<<"ENTER THE CITY NAME "<<endl;
		cin>>newer->city;
		cout<<"ENTER THE INITIAL AMMOUNT  "<<endl;
		cin>>newer->deposite;
		
		cout<< "RECORD INSERTED AT BEGINNING PRESS Y TO CONTINUE"<<endl; 
		newer->next = NULL;
		newer->prev = NULL;
		
		if (head== NULL) 
		{
			head = newer;
			return;
		}
		head->prev= newer;
		newer->next = head;
		head = newer; 
	}

//LAST NODE OF CUSTOMER	
void insertAtlast ()
	{system(" color 8e");
		system("cls");		
	    char ch;
    	if (head == NULL)
    	{
    		cout<<"RECORD IS EMPTY"<<endl;
    		cout<<"DO YOU WANT TO ADD RECORD ??"<<endl;
            cin>>ch;
			if (ch=='Y'||ch=='y')     
			{
				insertAtbeg();
				return;
			}		
			else 
			{
				customer_menu_selection();
			}
		}
		else 
		{		   	
			node *p = head;
			while (p->next!=NULL)
			{
				p= p->next;
			}
		
			node *newer = new node;
			
			cout<<"ENTER THE ACCOUNT NUMBER "<<endl;
			cin>>newer->acno;
			cout<<"ENTER THE NAME "<<endl;
			cin>>newer->name;
			cout<<"ENTER THE ADDRESS "<<endl;
			cin>>newer->address;
			cout<<"ENTER THE PHONE_NO "<<endl;
			cin>>newer->phone_no;
			cout<<"ENTER THE CITY NAME "<<endl;
			cin>>newer->city;
			cout<<"ENTER THE INITIAL AMMOUNT  "<<endl;
			cin>>newer->deposite;
			newer->next = NULL;
			p->next =newer;
			newer->prev= p;
		}
	}

//SEARCH NODE OF CUSTOMER	  
void searcher()
	{   system(" color 4e");
		system("cls");		
		char ch;
	  if (head==NULL)
		{
			cout<<"RECORD IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO SEARCH THE RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}  
			else 
			{
				customer_menu_selection();
			}
		}
		else 
		{
			int val;
			cout<<"ENTER THE ACCOUNT NUMBER YOU WANT TO SEARCH :"<<endl;
			cin>>val;
			node *p = head;
			while (p->next!=NULL)
			{
				if(p->acno==val)
				{
					cout<<"RECORD IS FOUND "<<endl;
					cout<<"THE ACCOUNT NUMBER "<<p->acno<<endl;
					cout<<"THE NAME "<<p->name<<endl;
			        cout<<"THE ADDRESS"<<p->address<<endl;
		            cout<<"THE PHONE_NO"<<p->phone_no<<endl;
			    	cout<<"THE CITY NAME"<<p->city<<endl;
		        	cout<<"THE BALANCE AMOUNT"<<p->deposite<<endl;					
				}	
				p=p->next;
			}
		}
	}

//DISPLAY NODE OF CUSTOMER
void display()
	{	
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<<"RECORD IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}
			else 
			{
				customer_menu_selection();
			} 	
		}	
		else 
		{
			node *p = head;
			while (p!= NULL)
			{
				cout<<"LIST OF ALL ACCOUNT HOLDER"<<endl;	
				cout<<" ACCOUNT NUMBER="<<p->acno<<endl;
			    cout<<" THE NAME="<<p->name<<endl;
		        cout<<" THE ADDRESS="<<p->address<<endl;
			    cout<<" THE PHONE_NO="<<p->phone_no<<endl;
		        cout<<" THE CITY NAME="<<p->city<<endl;
			    cout<<" THE BALANCE  IS ="<<p->deposite<<endl;
			    
			    p=p->next;
			}
		}
	}
void modify_balance()
	{	
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<<"RECORD IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}  
			else 
			{
				customer_menu_selection();
			} 	
		}
		else 
		{ 
			int val;   
			cout<<"ENTER THE ACCOUNT NUMBER:"<<endl;
			cin>>val;
			node *p = head;
			while (p!=NULL)
			{
		    	if(p->acno==val)
		    	{ 
			    	cout<<"LIST OF ALL ACCOUNT HOLDER"<<endl;
					cout<<" THE NAME "<<p->name<<endl;
		        	cout<<" THE ADDRESS"<<p->address<<endl;
			    	cout<<" THE PHONE_NO "<<p->phone_no<<endl;
		        	cout<<" THE CITY NAME "<<p->city<<endl;
			    	cout<<" THE BALANCE  IS  "<<p->deposite<<endl;			    
					cout<<" ENTER THE NEW BALANCE AMOUNT"<<endl;
					cin>>p->deposite;
				}
				p=p->next;
			}	
		}
		cout<<"RECORD SUCCESSFULLY HAS BEEN UPDATED!!!!"; 
	}	
//UPDATE NODE OF CUSTOMER	
void modify()
	{
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<<"RECORD IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}  
			else 
			{
				customer_menu_selection();
			} 	
		}
		else 
		{ 
			int val;   
			cout<<"ENTER THE ACCOUNT NUMBER:"<<endl;
			cin>>val;
			node *p = head;
			while (p!=NULL)
			{
		    	if(p->acno==val)
		    	{ 
			    	cout<<"LIST OF ALL ACCOUNT HOLDER"<<endl;
					cout<<" ENTER THE NAME "<<endl;
					cin>>p->name;
		    	    cout<<"  ENTER THE ADDRESS "<<endl;
					cin>>p->address;
				    cout<<"  ENTER THE PHONE_NO"<<endl;
					cin>>p->phone_no;
		    	    cout<<"  ENTER THE CITY NAME "<<endl;
					cin>>p->city;
			    	cout<<" ENTER THE BALANCE IS"<<endl;
					cin>>p->deposite;
				}
				p=p->next;
			}	
		}
		cout<<"RECORD SUCCESSFULLY HAS BEEN UPDATED!!!!"; 
	}

//DELETE FIRST NODE OF CUSTOMER	
void delAtFirst()
	{  system(" color 5e");
		system("cls");		
		char ch;
		if(head==NULL)
		{
			cout<<"RECORD IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}  
			else 
			{
				customer_menu_selection();
			} 	
		}
		else
		{
			node *temp = head;
			head = temp->next; 
			head->prev = NULL;
			delete temp;
			cout<<"RECORD SUCCESSFULLY HAS BEEN DELETE ";
 		}
 	}

//DELETE LAST NODE OF CUSTOMER
 void delAtlast()
	{system(" color 2e");
		system("cls");		
		string val;
		cout<<"ENTER THE ID :";	
		cin>>val;
		char ch;
		if (head==NULL)
		{
			cout<< "RECORD  IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD  RECORD ??"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}
			else 
			{	
				customer_menu_selection();
			}	
		}
		else
		{
		
			node *p = head;
			node *temp ;
			while (p->next->next!=NULL)
			{
				p=p->next;	
			}
			temp=p->next;
			p->next=NULL;
			delete temp;
		}		
	}

//DELETE MID NODE OF CUSTOMER	
void del_mid_one()
	{system(" color 2e");
		system("cls");		
		char ch;
		if (head==NULL)
		{
			cout<< "OOPS! LIST IS EMPTY"<<endl;
			cout<<"DO YOU WANT TO ADD NEW RECORD (Y/N)"<<endl;
			cin>>ch;
			if (ch=='Y'|| ch=='y')
			{
				insertAtbeg();
				return;
			}
			else 
			{	
				customer_menu_selection();
			}	
		}
		else
		{
			int val;
			cout<<"MAKE SURE THAT THE GIVEN ACCOUNT NO IS NOT THE FIRST ONE OR THE LAST ONE"<<endl;
			cout<<"ENTER THE ACCOUNT NO OF THE RECORD YOU WANT TO DELETE"<<endl;
			cin>>val;
			node *p=head;
			node *temp;
			while(p->next!=NULL)
			{
				if(p->next->acno==val)
				{
					temp=p->next;
					p->next=temp->next;
					temp->next->prev=temp->prev;
					delete temp;
				}
				p=p->next;
			}
		}
	}	

//DELETE IF ONLY NODE OF CUSTOMER IS REMAINING	
void del_only_remain()
	{system(" color 4e");
		system("cls");		
		node *temp= head;
		head = NULL;
		delete temp;	
	}

//MENU OF CUSTOMER MANAGEMENT
void customer_menu()
	{ system(" color 6e");
		system("cls");		
		cout<<setw(50)<<"****************** \n"<<endl;
		cout<<setw(50)<<"CUSTOMER MANAGEMENT \n"<<endl;
		cout<<setw(50)<<"******************* \n"<<endl;
        cout<<setw(50)<<"1. CREATE ANY  ACCOUNT AT BEGNINNING \n"<<endl;
    	cout<<setw(44)<<"2. CREATE ANY  ACCOUNT AT LAST \n"<<endl;
    	cout<<setw(35)<<"3. SEARCH ANY ACCOUNT \n"<<endl;
    	cout<<setw(40)<<"4. ALL ACCOUNT HOLDER LIST \n"<<endl;
    	cout<<setw(34)<<"5. MODIFY AN ACCOUNT \n"<<endl;
    	cout<<setw(46)<<"6. CLOSE AN ACCOUNT AT BEGINNING \n"<<endl;
    	cout<<setw(41)<<"7. CLOSE AN ACCOUNT AT LAST \n"<<endl;
    	cout<<setw(34)<<"8. CLOSE ANY ACCOUNT \n"<<endl;
    	cout<<setw(50)<<"9. CLOSE THE ONLY ACCOUNT REMAINNING \n"<<endl;
    	cout<<setw(22)<<"10. EXIT \n"<<endl;
    	cout<<setw(37)<<"11. GOTO SELECTION MENU \n"<<endl;
    	cout<<setw(32)<<"12. MODIFY BALANCE \n"<<endl;
	}

//CUSTOMER MANAGEMNT MENU SELECTION
void customer_menu_selection()
	{
		int n;
		char ch;
		x3:customer_menu(); 	
		cout<<"ENTER YOUR CHOICE"<<endl;
		cin>>n;		
		if(n==1)		
		{
			insertAtbeg();		
			cout<"DO YOU WANT TO GO MAIN MENU (Y/N)";
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x3; 	
			}
			else
			{
				exit(1);	
			}		
		}
		else if(n==2)
		{
			insertAtlast();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==3)
		{
			searcher();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if (n==4)		
		{
			display();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;			
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if (n==5)			
		{
			modify();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;		
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==6)		
		{
			delAtFirst();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}	
		}
		else if(n==7)
		{
			delAtlast();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==8)
		{
			del_mid_one();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if(n==9)
		{
			del_only_remain();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		else if (n==10)		
		{
			exit(1);
		}
		else if(n==11)
		{
			connection_ways();
		}
		else if(n==12)
		{
			modify_balance();
			cout<<"DO YOU WANT TO GO MAIN MENU (Y/N)"<<endl;
			cin>>ch;	
			if(ch=='Y'||ch=='y')
			{
				goto x3;
			}
			else 
			{
				exit(1);
			}
		}
		
		else	
		{
			cout<<"CHOOSE CORRECT ANSWER"<<endl;
			goto x3;
		}	
	}

//SELECTION MENU OF WHICH SYSTEM YOU WANT TO WORK	
void connection_ways()
	{system(" color 9e");
		system("cls");			
		char ch;
		cout<<setw(50)<<"******************* \n"<<endl;
		cout<<setw(44)<<"WELCOME \n"<<endl;
		cout<<setw(50)<<"******************* \n"<<endl;

		cout<<setw(50)<<"PRESS 'E' IF YOU WANT TO WORK ON EMPLOYEE"<<endl;
		cout<<setw(50)<<"PRESS 'C' IF YOU WANT TO WORK ON CUSTOMER"<<endl;
		cin>>ch;
		if(ch== 'E'||ch =='e'){
			employee_menu_selection();
		}
		else if(ch== 'C'||ch =='c')
		{
			customer_menu_selection();
		}
	}

//LOGIN FORM
void login()
{ 
    system("title **********************BANK MANAGEMENT SYSTEM**********************");
	system("color 5e");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	for (int i=0;i<6;i++)
	{
		cout << ".";
	}
	
	system("color 4e");
	system("CLS");
	cout <<endl;
	cout << "\t             ^^^^^^^^^^^^^^^^^^^^^^^^^^              " <<endl;
	cout << "\t************^  WELCOME TO LOGIN PAGE  ^*************" <<endl;
	cout << "\t************^^^^^^^^^^^^^^^^^^^^^^^^^^^*************" <<endl;
	string username;
	string password;
	char a;
	cout << "\t\t\t USERNAME = " ;
	cin >>username;
	cout <<endl;
	cout << "\t\t\t PASSWORD = " ;
    do{	
        a = getch();//Reads a keystoke and saves it to the ch, but doesn't display it in the console.
        switch(a)
		{
        case 13://enter (ASCII code 13)
            cout<<endl;
            break;
        case 8://backspace (ASCII code 8)
            if(password.length()>0)
			{
                password.erase(password.end()-1); //remove last character from string
                cout<<a<<' '<<a;//go back, write space over the character and back again.
            }
            break;
        default://regular ascii
            password.push_back(a);
            cout << '*';
            break;
        }
    }while(a!=13);//As long as the user doesn't press Enter (enter is ASCII code 13) continue reading keystrokes from the screen.

	if (username=="admin" && password=="database")
	{
		system("CLS");
		cout<<"welcome"<<endl;
		connection_ways();
	}
	else if (username!="admin" && password!="database")
	{
		cout <<endl;
		cout <<"*********************\n";
		cout << "Error! Login Failed " <<endl;
		system("pause");
		system("CLS");
		login();
	}
	else if (username!="admin")
	{
		cout <<endl;
		cout <<"*********************\n";
		cout << "wrong username !" <<endl;
		system("pause");
		system("CLS");
		login();
	}
	else if (password!="database")
	{
		cout <<endl;
		cout <<"*********************\n";
		cout << "wrong password !" <<endl;
		system("pause");
		system("CLS");
		login();
	}
}

//MAIN
int main(){
	login();
}
