bool isPrime(int n)
{
    if(n < 2)
        return false;
    else if(n == 2)
        return true;
    else if(n % 2 == 0)
        return false;        
    else
    {
        for(int i = 3; i < sqrt(n); i=i+2)
        {
            if(n % i == 0)
                return false;
        }
    }
    return true;    
}

double getNextPrime(double number)
{
    for(double  i = n; ; i++)
    {
        if(isPrime(i))
            return i;
    }
}