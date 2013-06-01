#include <iostream>

using namespace std;

class base
{
public:
	int b;
	virtual void func()	
	{
		cout << "I am in base";	
	}
	void func1()	
	{
		cout << "I am in base";	
	}
};

class derived:public base
{
public:
	int d;
	void func()	
	{
		cout << "I am in derived";
	}
};

int main()
{
	int ia = 10;
	float fb = ia;

	cout << "Implicit conversion " << fb ;

	base objB;
	derived objD;
	base* b;
	b = &objB;
	base* bd;
	bd = &objD;
	derived* d;
	d= &objD;

	cout << "base " << endl;
	b->func();
	cout << endl;

	cout << "derived " << endl; 
	bd->func();
	cout << endl;

	//objD = dynamic_cast<derived>(objB);
	//objB = dynamic_cast<base>(objD);
	/*
	bd = dynamic_cast<derived*>(b);
	cout << "b" << endl; 
	bd->func();
	cout << endl;
	*/
	b = dynamic_cast<base*>(bd);
	cout << "b" << endl; 
	b->func1();
	cout << endl;

	b = static_cast<derived*>(d);
	cout << "b" << endl; 
	b->func();
	cout << endl;

	//reintterpret cast
	base* rb = new base;
	derived* rd = new derived;

	rb = reinterpret_cast<derived*>(rd);
	rb->func();

} 