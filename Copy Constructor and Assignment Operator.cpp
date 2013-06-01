#include <iostream>
// Implicit 
class Sample
{
private: 
		int x;

public:		
	Sample(int _x)
	{
		x= _x;
	}

};
Sample::Sample(const Sample& s)
{
	this.x = s.x;
}

Sample& Sample::operator =(const Sample& s)
{
	this.x = s.x;
	return *this;
}


//Use of Copy constructor is when u have raw pointers

class Sample 
{
private:
	int size;
	int *Array;
public:
	Sample(const Sample& other) //Always pass with const reference as non const references cannot bind to temporary objects
	{
		if(other == NULL)
		{
			cout  << "Copying NULL object" <<  endl;
			return;
		}
			
		Array = new int[other.size];
		for(int i = 0; i < other.size; i++)
		{
			Array[i] = other.Array[i];
		}
		size = other.size;
	}
	Sample& operator=(const Sample& other)
	{
		if(other == NULL)
		{
			cout << "Error : Assigning NULL operator" << endl;	
			return *this;
		}
		if(this != &other)  // Exception safe coding - To prevent copying the the same object
		{
			Array = new int[other.size];
			for(int i = 0; i < other.size; i++)
			{
				Array[i] = other.Array[i];  // this is not excaption safe as = cannot cause problem. Look down for more exception safe programming
			}
			size = other.size;
			return *this;	
		}
	}

	Sample& opeartor=(const Sample& rhs)
	{
		Sample tmp(rhs);

		std::swap(size, tmp.size);
		std::swap(Array, tmp.Array);

		return *this;
	}
}