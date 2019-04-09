#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;

	class goods_mgmt
	{
                public : 

			int good_id;
			string good_name, good_category, good_company, good_shipment_status; 
	        	char *good_shipment_date, *good_condition, *good_shipment;
		  	
			
			void set_id(int a)
			{ 
				good_id = a; 
			}
			int get_id()
			{ 
				return good_id; 
			}
			void set_name(string b)
			{ 
				good_name = b; 
			}
			string get_name()
			{ 
				return good_name; 
			}
			void set_condition(char *c)
			{ 
				good_condition = c; 
			}
			char *get_condition()
			{ 
				return good_condition; 
			r}
			void set_category(string d)
			{ 
				good_category = d; 
			}
			string get_category()
			{ 
				return good_category; 
			}
			void set_company(string e)
			{ 
				good_company = e; 
			}
			string get_company()
			{ 
				return good_company; 
			}
			void set_shipment(char *f)
			{ 
				good_shipment = f; 
			}
			char *get_shipment()
			{ 
				return good_shipment; 
			}
			void set_shipment_status(string g)
			{ 
				good_shipment_status = g; 
			}
			string get_shipment_status()
			{ 
				return good_shipment_status; 
			}
			void set_shipment_date(char *h)
			{ 
				good_shipment_date = h; 
			}
			char *get_shipment_date()
			{ 
				return good_shipment_date; 
			}
	};
int main()
{  
	int i;
	float p;
	string q, s, t, v,dat,cat,stat;
	char w[10],r[10],u[10],da[10];
	char *m,*n,*o,*l;
	goods_mgmt obj[25];
	
	for(i=0;i<=0;i++)
	{
		cout<<"Enter good id :";
		cin>>p;
		obj[i].set_id(p);
		cout<<"Enter good name: ";
		cin>>q;
		obj[i].set_name(q);
		cout<<"Enter good condition (damaged/perfect): ";
		cin>>r;
		obj[i].set_condition(r);
		cout<<"Enter good category (cloth/food/medicine): ";
		cin>>s;
		obj[i].set_category(s);
		cout<<"Enter good company: ";
		cin>>t;
		obj[i].set_company(t);
		cout<<"Enter good shipment (truck/van): ";
		cin>>u;
		obj[i].set_shipment(u);
		cout<<"Enter good shipment status (pending/dispatched/arriving): ";
		cin>>v;
		obj[i].set_shipment_status(v);
		cout<<"Enter good shipment date (in format DD/MM/YYYY): ";
		cin>>w;
		obj[i].set_shipment_date(w);
	}
	
	
	
		for(i=0;i<=0;i++)
		{
			cout<<"Good ID is "<<obj[i].get_id();
			cout<<endl<<"Good Name is "<<obj[i].get_name();
			cout<<endl<<"Good Condition is "<<obj[i].get_condition();
			cout<<endl<<"Good Category is "<<obj[i].get_category();
			cout<<endl<<"Good Company is "<<obj[i].get_company();
			cout<<endl<<"Good Shipment is through "<<obj[i].get_shipment();
			cout<<endl<<"Good Shipment status is "<<obj[i].get_shipment_status();
			cout<<endl<<"Good Shipment date is "<<obj[i].get_shipment_date();
		}
		cout<<endl<<"Enter tomorrow's date to search ";
		cin>>da;
		for(i=0;i<1;i++)
		{
		stat=obj[i].get_shipment_status();
		cat=obj[i].get_category();
		dat=obj[i].get_shipment_date();
		if(stat=="pending" && cat=="cloth" && dat==da)
		{
			cout<<"Good ID is "<<obj[i].get_id();
			cout<<endl<<"Good Name is "<<obj[i].get_name();
			cout<<endl<<"Good Condition is "<<obj[i].get_condition();
			cout<<endl<<"Good Category is "<<obj[i].get_category();
			cout<<endl<<"Good Company is "<<obj[i].get_company();
			cout<<endl<<"Good Shipment is through "<<obj[i].get_shipment();
			cout<<endl<<"Good Shipment status is "<<obj[i].get_shipment_status();
			cout<<endl<<"Good Shipment date is "<<obj[i].get_shipment_date();
		}
		else
		{
			cout<<endl<<"No goods matched for category cloth, tomorrow's date and pending status";
		}
		}
		struct date
		{
			int day;
			int month;
			int year;
		};


	struct date input[2];
	for(int i=0; i<2; i++)
	{
		cin>>input[i].day;
		cin>>input[i].month;
		cin>>input[i].year;

	}
	for (int i=0; i<24; i++)
	{
		for (int j=i+1; j<2; j++)
		{
			if (input[i].year > input[j].year)
			{
				struct date temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			else if (input[i].year == input[j].year && input[i].month > input[j].month)
			{
				struct date temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			else if (input[i].year == input[j].year && input[i].month == input[j].month && input[i].day > input[j].day)
			{
				struct date temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}

		}
	}


	for(int i=0; i<2; i++)
	{
		cout<<input[i].day<<" "<<input[i].month<<" "<<input[i].year;
		cout<<endl;
	}
}
