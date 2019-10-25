#include<bits/stdc++.h>

using namespace std;

 class Shape{

	double base,height;
	public:
		void get()
		{	
			cin>>base>>height;
		}
		inline double areaCal(int i)
		{
			return 1.5*base*height;
		}
		inline double areaCal(char i)
		{
			return base*height;
		}
};

class Get: public virtual Shape
{

	public:
	
		void getData(int i)
		{
			if(i==1)
			{
				cout<<"Enter Base and Height of Triangle:"<<endl;
				get();
			}
			else
			{
				cout<<"Enter Breadth and Length of Rectangle"<<endl;
				get();
			}
		}
		/*void calcArea(int i)
		{
			area=base*height;
		}
		void calcArea(char c)
		{
			area=1.5*base*height;
		}*/
};

class Put:public virtual Shape
{
	public:
		void displayArea(int i)
		{	
			cout<<"----------------------------------------------"<<endl;
			double area=areaCal(i);
			cout<<"Area of Triangle is: "<<area<<endl;
			cout<<"----------------------------------------------"<<endl;
		}
		void displayArea(char c)
		{
			cout<<"----------------------------------------------"<<endl;
			double area=areaCal(c);	
			cout<<"Area of Rectangle is:"<<area<<endl;
			cout<<"----------------------------------------------"<<endl;
		}
};

class ToUse:public Get,public Put
{
	public:
		void passGet(int i)
		{
			getData(i);
		}
		void passPut(int i)
		{
			displayArea(i);
		}
		void passPut(char ch)
		{
			displayArea(ch);
		}

};

int main()
{

	int ch;
	ToUse t;
	do
	{
		cout<<"1.Area of Rectangle "<<endl<<"2.Area of Triangle"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			t.passGet(2);
			t.passPut('r');
		break;

		case 2:
			t.passGet(1);
			t.passPut(1);
		break;

		default:
			cout<<"Inavlid Choice"<<endl;
		}
		cout<<"Enter 1 to continue..."<<endl;
		cin>>ch;
	}while(ch==1);
	return 0;
}


