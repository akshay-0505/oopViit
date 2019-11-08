/*Lab Assignment No 4 :Write a function template and class template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array. */

#include<bits/stdc++.h>
#define MAX 20
using namespace std;

template <class T>	//temlate class
class Sort
{
	T *ptr;
	int n;
	
	public:
		void selectionSort(T arr[],int n);
		void print();
};

template <class T>	//template function
void Sort<T>::selectionSort(T arr[],int size)		//selection sort
{
	int min;
	ptr=new T[size];
	n=size;
  	for(int i = 0; i < n; i++) 
     	   ptr[i] = arr[i]; 

 	T tmp;
        for(int i=0;i<n;i++)
        {
  	      min=i;
  	      for(int j=i;j<n;j++)
              {
   	         if(ptr[min]>ptr[j])
   	             min=j;
              }
              tmp=ptr[min];
              ptr[min]=ptr[i];
              ptr[i]=tmp;
        
        	/*cout<<"pass"<<i+1<<" is:"<<endl;     
      		  for(int k=0;k<n;k++)
            		cout<<ptr[k]<<"  ";*/
         }
}

template <class T> 	//template function
void Sort<T>::print() { 
    cout<<"Soted array is: ";
    for (int i = 0; i < n; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 

int main()
{

	int ch,n;
	Sort<int> sa;
	Sort<float> sf;
	do
	{
	cout<<"Enter How many numbers do you want to insert in array?:";
	cin>>n;
	int arr[n];
	float arr1[n];
	cout<<"Selection Sort:\n1.Integer array\n2.Float array\n";
	cout<<"Enter Your Chioce"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter integers in array:"<<endl;
			for(int i=0;i<n;i++)
				cin>>arr[i];
			sa.selectionSort(arr,n);
			sa.print();
		break;

		case 2:
			cout<<"Enter Floating point values in array:"<<endl;
			for(int i=0;i<n;i++)
				cin>>arr1[i];
			sf.selectionSort(arr1,n);
			sf.print();
		break;

		default:
		cout<<"Inavlid Choice"<<endl;

	}
	cout<<"Press 1 to continue :";
	cin>>ch;
	}while(ch==1);
	
	return 0;
}

















