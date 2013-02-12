#include <iostream>

using namespace std;
const int BOOK_PRICE = 8;
const int  MAX_BOOKS = 5;
double Min(double A, double B)
{
    return A<B?A:B;
}
double PriceAfterDiscount(int nSetBooks)
{
    switch(nSetBooks)
    {
        case 1:
            return (BOOK_PRICE);
        case 2:
            return (2 * BOOK_PRICE * 0.95);
        case 3:
            return (3 * BOOK_PRICE * 0.9);
        case 4:
            return (4 * BOOK_PRICE * 0.8);
        case 5:
            return (5 * BOOK_PRICE * 0.75);
        default:
            return -1;
    }
}

int GetBooksSetsOf2(int& nBook, int& nPairBook)
{
    int nSetsWithBook = 0;
    while(nBook != 0 && nPairBook != 0 )
    {
       nSetsWithBook++; 
       nBook--;
       nPairBook--;       
    }
    return nSetsWithBook;
}
int GetBooksSetsOf3(int& nBook, int& nPairBook1, int &nPairBook2)
{
    int nSetsWithBook = 0;
    while(nBook != 0 && nPairBook1 != 0 && nPairBook2 !=0)
    {
       nSetsWithBook++; 
       nBook--;
       nPairBook1--; 
       nPairBook2--;      
    }
    return nSetsWithBook;
}

int GetBooksSetsOf4(int& nBook, int& nPairBook1, int &nPairBook2, int &nPairBook3)
{
    int nSetsWithBook = 0;
    while(nBook != 0 && nPairBook1 != 0 && nPairBook2 !=0 && nPairBook3 != 0)
    {
       nSetsWithBook++; 
       nBook--;
       nPairBook1--; 
       nPairBook2--; 
       nPairBook3--;      
    }
    return nSetsWithBook;
}

int GetBooksSetsOf5(int& nBook, int& nPairBook1, int &nPairBook2, int &nPairBook3, int &nPairBook4)
{
    int nSetsWithBook = 0;
    while(nBook != 0 && nPairBook1 != 0 && nPairBook2 !=0 && nPairBook3 != 0 && nPairBook4 !=0)
    {
       nSetsWithBook++; 
       nBook--;
       nPairBook1--; 
       nPairBook2--; 
       nPairBook3--;  
       nPairBook4--;               
    }
    
    return nSetsWithBook; 
}

double PriceForSetof2Books(int& book1, int& book2, int& book3, int& book4, int& book5)
{
    int nSets = 0;
    
    nSets += GetBooksSetsOf2(book1, book2);
    nSets += GetBooksSetsOf2(book1, book3);
    nSets += GetBooksSetsOf2(book1, book4);
    nSets += GetBooksSetsOf2(book1, book5);
    
    nSets += GetBooksSetsOf2(book2, book3);
    nSets += GetBooksSetsOf2(book2, book4);
    nSets += GetBooksSetsOf2(book2, book5);
    nSets += GetBooksSetsOf2(book3, book4);
    nSets += GetBooksSetsOf2(book3, book5);
    
    nSets += GetBooksSetsOf2(book4, book5);
      
   int nRemainingBooks = book1 + book2 + book3 + book4 + book5;
   double nRemainingBookPrice = nRemainingBooks * BOOK_PRICE;
   
   return (nSets * PriceAfterDiscount(2)) + nRemainingBookPrice;     
}

double PriceForSetof3Books(int& book1, int& book2, int& book3, int& book4, int book5)
{
    int nSets = 0;

     nSets += GetBooksSetsOf3(book1,book2,book3);
     nSets += GetBooksSetsOf3(book1,book2,book4);
     nSets += GetBooksSetsOf3(book1, book2,book5);
     nSets += GetBooksSetsOf3(book1, book3,book4);
     nSets += GetBooksSetsOf3(book1, book3,book5);
     nSets += GetBooksSetsOf3(book1, book3,book4);
     nSets += GetBooksSetsOf3(book1, book3,book5);
     nSets += GetBooksSetsOf3(book1, book4,book5);     
     
     nSets += GetBooksSetsOf3(book2,book3,book4);
     nSets += GetBooksSetsOf3(book2,book3,book5);
     nSets += GetBooksSetsOf3(book2,book4,book5);
     
     nSets += GetBooksSetsOf3(book3, book4,book5);
     nSets += GetBooksSetsOf3(book2, book3,book5);
     nSets += GetBooksSetsOf3(book1, book4,book5);
    
    double nRemainingSetOf2Price = PriceForSetof2Books(book1, book2, book3, book4, book5);
    
   return (nSets * PriceAfterDiscount(3)) + nRemainingSetOf2Price;// + nRemainingBookPrice;       
}

double PriceForSetof4Books(int& book1, int& book2, int& book3, int& book4, int& book5)
{
    int nSets = 0;

     nSets += GetBooksSetsOf4(book1,book2,book3, book4);
     nSets += GetBooksSetsOf4(book1,book2,book3, book5);
     nSets += GetBooksSetsOf4(book1,book2,book4, book5);
     nSets += GetBooksSetsOf4(book1,book3,book4, book5);
     nSets += GetBooksSetsOf4(book2,book3,book4, book5);
     
     double nRemainingSetOf3Price = PriceForSetof3Books(book1, book2, book3, book4, book5);

    return ((nSets * PriceAfterDiscount(4)) + nRemainingSetOf3Price); 
}

double PriceForSetof5Books(int& book1, int& book2, int& book3, int& book4, int& book5)
{
    int nSets = 0;
    
    nSets = GetBooksSetsOf5(book1,book2,book3,book4,book5);
   
    double nRemainingSetOf4Price = PriceForSetof4Books(book1, book2, book3, book4, book5);    
    
    int nRemainingBooks = book1 + book2 + book3 + book4 + book5;
    double nRemainingBookPrice = nRemainingBooks * 8;
        
    return ((nSets * PriceAfterDiscount(5)) + nRemainingSetOf4Price);
}

double PriceFor44SetBooks(int& nBook1, int& nBook2, int& nBook3, int& nBook4, int& nBook5)
{     
    int nSetsOf4 = GetBooksSetsOf4(nBook1,nBook2,nBook3,nBook4);
    nSetsOf4 += GetBooksSetsOf4(nBook1,nBook2,nBook3,nBook5);
    nSetsOf4 += GetBooksSetsOf4(nBook1,nBook2,nBook4,nBook5);
    nSetsOf4 += GetBooksSetsOf4(nBook1,nBook3,nBook4,nBook5);
    nSetsOf4 += GetBooksSetsOf4(nBook2,nBook3,nBook4,nBook5);                
    
    double nRemainingSetOf3Price = PriceForSetof3Books(nBook1, nBook2, nBook3, nBook4, nBook5);
    return (nSetsOf4 * PriceAfterDiscount(4) + nRemainingSetOf3Price);  
}

double CalculatePrice(int nBook1, int nBook2, int nBook3, int nBook4, int nBook5)
{
    double nPriceSetOf5Book = 0, nPriceSetof44Book = INT_MAX;
    double nBestPrice =0;
  
    int ntempBook1 = nBook1;
    int ntempBook2 = nBook2;
    int ntempBook3 = nBook3;    
    int ntempBook4 = nBook4;
    int ntempBook5 = nBook5;

    nPriceSetOf5Book = PriceForSetof5Books(nBook1, nBook2, nBook3, nBook4, nBook5);  
      
    nBook1 = ntempBook1;
    nBook2 = ntempBook2;
    nBook3 = ntempBook3;
    nBook4 = ntempBook4;
    nBook5 = ntempBook5;
     //This is the H case where if 4 books are remaining, then spliting them into 4 and 4 is better than 5, 3 
     int nSetsOf5 = GetBooksSetsOf5(nBook1,nBook2,nBook3,nBook4,nBook5);
     if(nBook1 + nBook2 == 0 || nBook1 + nBook3 == 0 || nBook1 + nBook4 == 0 || nBook1 + nBook5 == 0 ||
        nBook2 + nBook3 == 0 || nBook2 + nBook4 == 0 || nBook2 + nBook4 == 0 ||
        nBook3 + nBook4 == 0 || nBook3 + nBook5 == 0 ||
        nBook4 + nBook5 == 0)
        {     
            nSetsOf5--;
            nBook1++;// = ntempBook1;
            nBook2++;// = ntempBook2;
            nBook3++;// = ntempBook3;
            nBook4++;// = ntempBook4;
            nBook5++;// = ntempBook5;
            nPriceSetof44Book = (nSetsOf5 * PriceAfterDiscount(5)) + PriceFor44SetBooks(nBook1,nBook2,nBook3,nBook4,nBook5); 
        }   
   
    nBestPrice = Min(nPriceSetOf5Book,nPriceSetof44Book);
    
    return nBestPrice;
}

int main()
{  
    /* Testing */
    bool bFail = false;
    if(CalculatePrice(1,1,1,1,1) != (BOOK_PRICE * 1 * 5 *0.75))
         bFail = true;
    if(CalculatePrice(0,1,0,0,1) != (BOOK_PRICE * 1 * 2 *0.95))
         bFail = true;     
    if(CalculatePrice(2,2,2,2,0) != (BOOK_PRICE * 2 * 4 * 0.80))
         cout << "FAiled here 2";
    if(CalculatePrice(3,2,2,2,1) != ((BOOK_PRICE * 1 * 5 * 0.75) +(BOOK_PRICE * 1 * 4 *0.80) + (BOOK_PRICE * 1 * 1)))
         bFail = true;
    if(CalculatePrice(0,0,0,0,0) != 0)
         bFail = true;
    if(CalculatePrice(2,2,2,1,1) != (BOOK_PRICE * 2 * 4 * 0.80))
         bFail = true;
    if(CalculatePrice(0,2,2,1,1) != (BOOK_PRICE * 1 * 4 * 0.80) + (BOOK_PRICE * 1 * 2 * 0.95))
         bFail = true;
    if(bFail)
    {
        cout << "FAILED to pass all the test" << endl;
        return -1;
    }
    else
    {
       cout << "All tests passed" << endl; 
    }
       
    

    int nBook1,nBook2,nBook3, nBook4, nBook5;
    cout << "Enter the number of Book1 copies " << endl;
    cin >> nBook1;
    
    cout << "Enter the number of Book2 copies " << endl;
    cin >> nBook2;
    
    cout << "Enter the number of Book3 copies " << endl;
    cin >> nBook3;
    
    cout << "Enter the number of Book4 copies " << endl;
    cin >> nBook4;
    
    cout << "Enter the number of Book5 copies " << endl;
    cin >> nBook5;
    cout << "The Total price is " << CalculatePrice(nBook1,nBook2,nBook3, nBook4, nBook5) << endl;

     return 0;
} 