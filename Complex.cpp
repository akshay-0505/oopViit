#include<bits/stdc++.h>

using namespace std;

class Complex{

	int real,imag;
	public:
		Complex()
		{
			real=0;
			imag=0;
		}
		friend ostream & operator <<(ostream &os,Complex &c);
		friend istream & operator >>(istream &in,Complex &c);

		Complex operator +(Complex b)
		{
			Complex c;
			c.real=real+b.real;
			c.imag=imag+b.imag;
			return c;
		}
		Complex operator -(Complex b)
		{
			Complex c;
			c.real=real-b.real;
			c.imag=imag-b.imag;
			return c;
		}
		Complex operator *(Complex b)
		{
			Complex c;
			c.real=(real*b.real)-(imag*b.imag);
			c.imag=(real*b.imag)+(b.real*imag);
			return c;
		}
};
//friend functions
		ostream & operator <<(ostream &os,Complex &c)
		{
			if(c.imag>=0)
			{
				cout<<"Complex number is:"<<c.real<<" + "<<c.imag<<" i "<<endl<<endl;
			}
			else
			{
				cout<<"Complex number is:"<<c.real<<" "<<c.imag<<" i "<<endl;
			}
			return os;
				
		}
		istream & operator >>(istream &in,Complex &c)
		{
			cout<<"Enter Complex number( Format >>Real>>imaginary)";
			cin>>c.real>>c.imag;
			return in;

		}
int main()
{
	Complex a[10],c;
	int i,n,ch;
	cout<<"Enter how many complex numbers are there:"<<endl;
	cin>>n;
	for( i=0;i<n;i++)
	{
	cout<<"Enter "<<i+1<<"th complex number"<<endl;
		cin>>a[i];
	}

	//b.display();
	do
	{
	cout<<"Enter Your Choice:"<<endl<<"1.Addition"<<endl<<"2.Subtraction"<<endl<<"3.Multiplicatio"<<endl<<"4.Display Answer"<<endl;
	
	cin>>ch;
	switch(ch)
	{
	
	case 1:
	for( i=0;i<n;i++)
		c=c+a[i];
		cout<<c;
	break;

	case 2:
	c=a[0];
	for( i=1;i<n;i++)
	{
		c=c-a[i];
	}
	cout<<c;
	
	break;

	case 3:
	c=a[0];
		for( i=1;i<n;i++)
		c=c*a[i];	
		cout<<c;
	break;

	case 4:
		cout<<c;
	break;

	default:
			cout<<"Invalid Choice...."<<endl;

	}
		cout<<"Enter 1 to continue..."<<endl;
		cin>>ch;
	}while(ch==1);

	
	
	//c.display();
	return 0;
}
