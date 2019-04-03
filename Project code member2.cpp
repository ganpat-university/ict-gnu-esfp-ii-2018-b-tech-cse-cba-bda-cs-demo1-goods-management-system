//GOODS MANAGEMENT SYSTEM
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
using namespace std;
// Creation of class in this project
class goods
{
	long int good_id;
	char good_name[50];
	char good_cond;
	char good_cat;
	char good_company[100];
	char good_shipment;
	char good_ship_status;
	char good_ship_date;
	public:
	void create_goods()
	{
		cout<<"\n\n====NEW GOOD ENTRY FORM====\n\n";
		cout<<"\nEnter The good id : ";
		cin>>good_id;
		cout<<"\nEnter The Name of The good : ";
		cin>>good_name;
		cout<<"\nEnter the good condition(D for damaged/P for perfect) : ";
		cin>>good_cond;
		cout<<"\nEnter the good catagory(C for cloth/F for food/M for medicine) : ";
		cin>>good_cat;
		cout<<"\nEnter the good's company : ";
		cin>>good_company;
		cout<<"\nEnter good transportation vehicle(M for mini truck/V for van) : ";
		cin>>good_shipment;
		cout<<"\nEnter the good shipment status(P for pending/D for dispatched/A for arrived) : ";
		cin>>good_ship_status;
		cout<<"\nEnter the shipment date(T fo today/Y for yesterday) : ";
		cin>>good_ship_date;
		cout<<"\n\n\nYour goods Created Successfully ..";
	}
	void show_goods()
	{
		cout<<"\n\n----GOOD STATUS----\n";
		cout<<"\nThe good id : "<<good_id;
		cout<<"\nThe good Name : "<<good_name;
		cout<<"\nThe good condition(D for damaged/P for perfect) : "<<good_cond;
		cout<<"\nThe good catagory(C for cloth/F for food/M for medicine) : "<<good_cat;
		cout<<"\nthe good's company : "<<good_company;
		cout<<"\nThe good transportation vehicle(M for mini truck/V for van) : "<<good_shipment;
		cout<<"\nThe good shipment status(P for pending/D for dispatched/A for arrived) : "<<good_ship_status;
		cout<<"\nEnter the shipment date(t for today/Y for yesterday) : "<<good_ship_date;
	}
	void modify_goods()
	{
		cout<<"\nGood id : "<<good_id;
		cout<<"\nmodify The good Name : ";
		cin>>good_name;
		cout<<"\nmodify The good condition(D for damaged/P for perfect) : ";
		cin>>good_cond;
		cout<<"\nmodify The good catagory(C for cloth/F for food/M for medicine) : ";
		cin>>good_cat;
		cout<<"\nmodify the good's company : ";
		cin>>good_company;
		cout<<"\nmodify The good transportation vehicle(M for mini truck/V for van) : ";
		cin>>good_shipment;
		cout<<"\nmodify The good shipment status(P for pending/D for dispatched/A for arrived) : ";
		cin>>good_ship_status;
		cout<<"\nEnter the shipment date(T for today/Y for yesterday) : ";
		cin>>good_ship_date;
		
	}
	void report()
	{
		cout<<good_id<<"\t"<<good_name<<"\t\t"<<good_cond<<"\t"<<good_cat<<"\t\t"<<good_company<<"\t\t"<<good_shipment<<"\t\t"<<good_ship_status<<"\t\t"<<good_ship_date<<endl;
	}
	int retgood_id()
	{
		return good_id;
	}
	char retgood_cat()
	{
		return good_cat;
	}
	char retgood_ship_status()
	{
		return good_ship_status;
	}
	char retgood_ship_date()
	{
		return good_ship_date;
	}
};	 	//class ends here


// 	global declaration for stream object, object



 fstream fp;
 goods ac;


// 	function to write in file


int write_goods()
{
	fp.open("accounttt.dat",ios::out|ios::app);
	ac.create_goods();
	fp.write((char*)&ac,sizeof(goods));
	fp.close();
}


// 	function to read specific record from file



int display_sp()
{
	int n;
	cout<<"\n\n====CUSTOMER DETAILS====";
	cout<<"\n\nEnter the good id : ";
	cin>>n;
	int flag=0;
	fp.open("accounttt.dat",ios::in);					
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		if(ac.retgood_id()==n)
		{
			ac.show_goods();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\ngood id Number does not exist";
	return 0;
}
char harsh_1()
{
	cout<<"The goods which are food or medicine:-";
	fp.open("accounttt.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		if(ac.retgood_cat()=='F'||ac.retgood_cat()=='M')
		{
			ac.show_goods();
		}
	}

	fp.close();
	return 0;
}
char harsh_2()
{
	cout<<"goods which are yet to be dispatched:-";
	fp.open("accounttt.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		if(ac.retgood_ship_status()=='P')
		{
			ac.show_goods();
		}
	}

	fp.close();
	return 0;
}
char harsh_3()
{
	cout<<"goods which are arrived today:-";
	fp.open("accounttt.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		if(ac.retgood_ship_date()=='T')
		{
			ac.show_goods();
		}
	}

	fp.close();
	return 0;
}

// 	function to modify record of file


int modify_goods()
{
	int no,found=0;
	cout<<"\n\n====MODIFY RECORD====";
	cout<<"\n\nEnter the good id : ";
	cin>>no;
	fp.open("accounttt.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(goods)) && found==0)
	{
		if(ac.retgood_id()==no)
		{
			ac.show_goods();
			cout<<"\n\n\n----Enter the New Details----\n";
			ac.modify_goods();
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(goods));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	return 0;
}


// 	function to delete record of file

int delete_goods()
{
	int no;
	cout<<"\n\n====Delete Record====";
	cout<<"\n\nEnter The good. : ";
	cin>>no;
	fp.open("accounttt.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temppp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		if(ac.retgood_id()!=no)
		{
			fp2.write((char*)&ac,sizeof(goods));
		}
	}
	fp2.close();
	fp.close();
	remove("accounttt.dat");
	rename("Temppp.dat","accounttt.dat");
	cout<<"\n\n\tRecord Deleted ..";
	return 0;
}


// 	function to display all accounts deposit list


int display_all()
{
	fp.open("accounttt.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		return 0;
	}
	cout<<"\n\n\t\t\tGOOD HOLDER LIST\n\n";
	cout<<"=======================================================================================\n";
	cout<<"A/c no.\tNAME\t\tCONDITION\tCATAGORY\tCOMPANY\t\tSHIPMENT\tSHIP_STATUS\tSHIP_DATE\n";
	cout<<"=======================================================================================\n";
	while(fp.read((char*)&ac,sizeof(goods)))
	{
		ac.report();
	}
	fp.close();
	return 0;
}   
//***************************************************************
// 	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	int ch;
	char con;
	//intro();
	cout<<"\n\t\t\t";					//gotoxy(5,7);
	cout<<"\t\t\t\t==============================";
	cout<<"\n\t\t   \t\t";			//gotoxy(18,11);
	cout<<"\t\t\t\t     GOODS";
	cout<<"\n\t\t\t\t";			//gotoxy(15,14);
	cout<<"\t\t\t\t  MANAGEMENT";
	cout<<"\n\t\t  \t\t";		//gotoxy(17,17);
	cout<<"\t\t\t\t    SYSTEM";
	cout<<"\n\t\t\t";		//gotoxy(5,21);
	cout<<"\t\t\t\t==============================";
	cout<<"\n\n\n\t\t\t";	//gotoxy(5,24);
	cout<<"\t\t\t\tMADE BY : HARSH WANI";
	//do
	//{
		cout<<"\n\n\n\t\t\t\t\t\t\tMAIN MENU";
		cout<<"\n\n\t\t\t\t\t\t\t01. NEW GOOD";
		cout<<"\n\n\t\t\t\t\t\t\t02. GOOD ENQUIRY";
		cout<<"\n\n\t\t\t\t\t\t\t03. ALL GOOD LIST";
		cout<<"\n\n\t\t\t\t\t\t\t04. CLOSE AN GOOD";
		cout<<"\n\n\t\t\t\t\t\t\t05. MODIFY AN GOOD";
		cout<<"\n\n\t\t\t\t\t\t\t    ****SPECIFIC TASK GROUP MEMBER 2****";
		cout<<"\n\n\t\t\t\t\t\t\t06. Display all the goods which fall in the category of either food or medicine";
		cout<<"\n\n\t\t\t\t\t\t\t07. Display all the goods whose shipment status is yet to be dispatched.";
		cout<<"\n\n\t\t\t\t\t\t\t08. Display all the goods which have arrived today:";
		cout<<"\n\n\t\t\t\t\t\t\t09. EXIT";
		cout<<"\n\n\t\t\t\t\t\t\tSelect Your Option (1-9) ";
		again:
		cin>>ch;
		switch(ch)
		{
			case 1: write_goods();
				break;
			case 2: display_sp();
				break;
			case 3: display_all();
				break;
			case 4: delete_goods();
				break;
			case 5: modify_goods();
				break;
			case 6: harsh_1();
				break;
			case 7: harsh_2();
				break;
			case 8: harsh_3();
				break;
			case 9: goto exit;
				break;
			default : cout<<"invaild input.Try again\n";
			goto again;
		}
		cout<<"\nWant to continue[y/n]\n";
		cin>>con;
		if(con=='y'||con=='Y')
		{
			cout<<"Enter your choice from 1-15\n";
			goto again;
		}
		else if(con=='n'||con=='N')
		{
			cout<<"->VISIT AGAIN<-";
			goto exit;
		}
		else
		{
			cout<<"Invaild input \n";
		}
		
	//}while(ch!='9');
		exit:
		cout<<"\t\t\tEnd of program";
		return 0;
}
