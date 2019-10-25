/*
Lab Assignment No 3: Implement C++/Java/Python program to create a base class called shape. Use this class to store two double type values that could be used to compute the area of figures. Derive two specific classes called function get_data() to initialize base class data members and another member function display_area() to compute and display the area of figures. Make classes to suit their requirements. Using these three classes, design a program that will accept dimension of a triangle or a rectangle interactively, and display the area. Remember the two values given as input will be treated as lengths of two sides in the case of rectangles, and as base and height in the case of triangles, and used as follows:
Area of rectangle= x*y Area of triangle =1/2*x*y

*/
#include<bits/stdc++.h>

using namespace std;

 class Shape		//base class
{

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

class Get: public virtual Shape		//Accepting Values
{

	public:
	
		void get_data(int i)
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

class Put:public virtual Shape		// calculating & Displaying area
{
	public:
		void display_area(int i)
		{	
			cout<<"----------------------------------------------"<<endl;
			double area=areaCal(i);
			cout<<"Area of Triangle is: "<<area<<endl;
			cout<<"----------------------------------------------"<<endl;
		}
		void display_area(char c)		//function overloading
		{
			cout<<"----------------------------------------------"<<endl;
			double area=areaCal(c);	
			cout<<"Area of Rectangle is:"<<area<<endl;
			cout<<"----------------------------------------------"<<endl;
		}
};

class ToUse:public Get,public Put		//Multiple Inheritance
{
	public:
		void passGet(int i)
		{
			get_data(i);
		}
		void passPut(int i)
		{
			display_area(i);
		}
		void passPut(char ch)		//function overloading
		{
			display_area(ch);
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


