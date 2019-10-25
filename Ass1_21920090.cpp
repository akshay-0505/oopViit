/*
	Lab Assignment 1 : Develop an object oriented program in C++ to create a database of student information system containing the following information: Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the database with suitable member functions viz, static member functions, friend class/ friend function, this pointer, inline code and dynamic memory allocation operators-new and delete. Implement all the keywords as mentioned in the problem statement. 
*/
#include<bits/stdc++.h>
using namespace std;

class Student{
	static int cnt;
	int roll;
	string name,clas,div,Dob,blgr,addr,phone,drlNo;
	
	public:
	
	Student()//default Constructor
	{
		
		//roll=00;
	}
	Student(int roll,string name)//Parameterized Constructor
	{
		this->roll=roll;
		this->name=name;
	}
	Student(Student *st)//Copy Constructor
	{
		this->roll=st->roll;
		this->name=st->name;
		this->clas=st->clas;
		this->div=st->div;
		//this->Dob=st->Dob;
		this->blgr=st->blgr;
		this->addr=st->addr;
		this->phone=st->phone;
		this->drlNo=st->drlNo;
		cout<<"Done...!";
		
	}
	friend inline void copyRoll(Student *&,Student *&);//friend function declaration
	void addRecord()
	{
		cout<<"Enter Roll no:"<<endl;
		cin>>roll;
		cout<<"Enter Name:"<<endl;
		cin>>name;
		cout<<"Enter class:"<<endl;
		cin>>clas;
		cout<<"Enter Division:"<<endl;
		cin>>div;
		cout<<"Enter blood group:"<<endl;
		cin>>blgr;
		cout<<"Enter address:"<<endl;
		cin>>addr;
		cout<<"Enter phone no:"<<endl;
		cin>>phone;
		cout<<"Enter driving licscene no:"<<endl;
		cin>>drlNo;
		Student::cnt++;

	}
	void displayRecord()
	{
		cout<<"--------------------------------------------------------"<<endl;
		cout<<"Roll no:"<<roll<<endl<<"Name:"<<name<<endl<<"Class:"<<clas<<endl<<"Division:"<<div<<endl<<"Blood Group"<<blgr<<endl<<"Adress"<<addr<<endl<<"Phone No:"<<phone<<endl<<"Driviing Liscene No:"<<drlNo<<endl;
	}
	static void recordCount()
	{
		cout<<"Number Of Records is:"<<Student::cnt<<endl;
	}

};
int Student::cnt=0;

inline void copyRoll(Student *&p1,Student *&p2)		//Inline Function
{
	cout<<"Friend Function Called..!"<<p2->roll<<" "<<p2->roll<<endl;
	p1->roll=p2->roll;
	cout<<"Friend Function Called..!"<<p2->roll<<" "<<p2->roll<<endl;
}

int main()
{
	int n,pos,ch;
	cout<<"Enter No of students"<<endl;
	cin>>n;
	Student *std[n],*tmp;
	do{

	cout<<"1.Add Students\n2.Delete Student\n3.display"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
	cout<<"Enter Student details"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<" th record"<<endl;
		std[i]=new Student;				//Dynamic Allocation
		std[i]->addRecord();
	}
	break;

	case 2:
	cout<<"Enter position to delete record from:"<<endl;
	cin>>pos;
	for(int i=pos-1;i<n-1;i++)
	{
		std[i]=std[i+1];
	}
	//std[n-2]->roll=std[n-1]->roll;
	copyRoll(std[n-2],std[n-1]);
	tmp=std[n-1];
	delete(tmp);						//Freeing up memory space
	
	n--;
	break;
	
	case 3:
	cout<<"------------------------Student Records--------------------------"<<endl;
	Student::recordCount();
	for(int i=0;i<n;i++)
	{
		std[i]->displayRecord();
	}
	break;
	
	default:
	cout<<"Invalid Choice";
	}
	
	cout<<"Enter 1 to continue>>"<<endl;
	cin>>ch;
	}while(ch==1);

	return 0;
}
