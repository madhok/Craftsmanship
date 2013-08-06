#include <iostream>

using namespace std;

class animal
{
private:
    int weight;    
protected:
    int maxSpeed; 
    animal(int _weight)
    {
        weight = _weight;
    }       
public: 
    virtual void Draw() = 0;
    virtual void locomote() = 0;   
};

class bird:public animal
{
private:
    int wingspan;
public:
    bird(int weight, int _wingspan):animal(weight)
    {
        wingspan = _wingspan;
         //set max Speed here based on weight and wingspan 
         //Eg maxSpeed = weight + 6 * wingspan
    }
    virtual void Draw() = 0;    
    void locomote();    
};

class fish:public animal
{
private:
    int length;
public:
    fish(int weight,int _length):animal(weight)
    {
        length = _length;
        //set max Speed here based on weight and length  
        //Eg maxSpeed = weight + 2 * length
    }    
    virtual void Draw() = 0;    
    void locomote(); 
};

class landAnimal:public animal
{
private:
    int numberOfLegs;
public:
    landAnimal(int weight, int _numberOfLegs):animal(weight)
    {
        numberOfLegs = _numberOfLegs;
        //set max Speed here based on weight and numberOfLegs
        //Eg maxSpeed = weight + 6 * numberOfLegs
    }
    virtual void Draw() = 0;
    void locomote();
};

class zebra:public landAnimal
{
public:
    zebra(int weight, int numberOfLegs):landAnimal(weight,numberOfLegs){}
    void Draw()
    {
        //Draw the shape of Zebra
    }
};

class shark:public fish
{
public:
    shark(int weight,int length):fish(weight,length){}    
    void Draw()
    {
        //Draw the shape of shark
    }
};

class parrot:public bird
{
public:
    parrot(int weight, int wingspan):bird(weight,wingspan){}
    void Draw()
    {
        //Draw the shape of parrot
    }
};

int countBits(unsigned int number)
{
    unsigned int mask = 0x01;
    int count = 0;
    while(number >= mask && mask != 0)
    {
        if((number & mask) > 0)
        {
            count++;  
        }
       mask = mask << 1;
    }
    return count;
}

void print(string strInput)
{
    int nLetterCount = 0,nNumberCount = 0;
    for(int i = 0; i < strInput.length(); i++)
    {
        if(isalpha(strInput[i]))
            nLetterCount++;
        else if(isdigit(strInput[i]))
            nNumberCount++;
    }
    cout << "The number of letters in the string is : " << nLetterCount << endl;
    cout << "The number of digits in the string is : " << nNumberCount << endl;
    cout << "the total number of characters in the string is :" << strInput.length();             
}

int main()
{
   unsigned int num;
   string str;
   cout << "Enter the value of the string" << endl;
   cin >> str;
   print(str);
   //cout << "The number of bits set are " << countBits(num) << endl;
   return 0;
}