/*Lab Assignment No 6: Create a class template to represent a generic vector. Include following member functions:
i.To create the vector.
ii.To modify the value of a given element
iii.To multiply by a scalar value
iv.To display the vector in the form(10, 20, 30, …)*/

#include<iostream>
#include<vector>

using namespace std;

template <class T>		//template class
class Gen
{
	int n;
	T v;
public:
	Gen();
	~Gen();
	void createVector();
	void addElement();
	void mulElements();
	void displayVector();
	void modifyElement();


private:

};

template<class T>
Gen<T>::Gen()
{
}

template<class T>
Gen<T>::~Gen()
{
}

template<class T>
void Gen<T>::createVector()			//creating vector
{
	int n,ele;
	cout << "Enter no of elements you want in vector: ";
	cin >> n;
	cout << "Enter elements in vector: " ;
	for (int  i = 0; i < n; i++)
	{
		cin >> ele;
		v.push_back(ele);
	}
}

template<class T>
void Gen<T>::addElement()		//adding element at the end
{
	int ele;
	cout << "Enter the elements to add : ";
	cin >> ele;
	v.push_back(ele);
}

template<class T>
void Gen<T>::mulElements()		//multiplying by scaklar value
{
	int value;
	cout << "Enter scalar value to multiply vector elements by it : " ;
	cin >> value;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * value;
	}
}

template<class T>
void Gen<T>::displayVector()		//displayiing elemtnts of vector
{
	cout << "Vector elements are : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	/*for (auto i = v.begin(); i !=v.end(); ++i)
	{
		cout << *i << " ";
	}*/
}

template<class T>
void Gen<T>::modifyElement()			//modifying vector elements
{
	int ind,replacement;
	cout << "Enter index element to be modified : " ;
	cin >> ind;
	cout << "Enter new value of element : " ;
	cin >> replacement;
	v[ind-1] = replacement;

}

int main()
{
	Gen<vector<int>> g;
	int ch;
	do
	{
		cout << "1. Create vectror" << endl;
		cout << "2. Modify the value of given element" << endl;
		cout << "3. Multiply elements by scalar value" << endl;
		cout << "4. Add elemnt in vector" << endl;
		cout << "5. Display the Vector" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			g.createVector();
			break;

		case 2:
			g.modifyElement();
			break;

		case 3:
			g.mulElements();
			break;

		case 4:
			g.addElement();
			break;

		case 5:
			g.displayVector();
			break;

		default:
			cout << "Invalid choice" << endl;
			break;
		}

		cout <<endl<< "Press 1 to continue: ";
		cin >> ch;
		cout << endl;
	} while (ch==1);
	return 0;
}