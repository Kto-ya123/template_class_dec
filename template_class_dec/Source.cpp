#include<conio.h>
#include<iostream>
#include<string>
#include<vector>
#include"dec.h"
#include<algorithm>
#define function_3_step(x) (x)*(x)*(x)

using namespace std;

class A 
{
public:
	virtual void func(int i = 7) { cout << ++i << endl; }
};
class B : public A
{
public:
	virtual void func(int i = 3) { cout << --i << endl; }
};

void func(int a) { cout << "1" << endl; }
void func(bool a) { cout << "2" << endl; }
void func(string a) { cout << "3" << endl; }


int main()
{
	my::dec<int> a1;
	for (int i(0); i < 10; i++)
	{
		a1.push_back(i);
	}
	decltype(a1) a2 = a1;
	cout << a2[9] << endl;
	system("pause");
	return 0;

}