/*
A child is running up a staircase with n steps, and can hop either 1 step, 
2 steps, or 3 steps at a time. Implement a method to count how many possible 
ways the child can run up the stairs
*/



int NumberOfSteps(int x)
{
    
    if(x < 1)
        return 0;
    if(x == 1)
        return 1;
    
    if(x == 2)
        return 2;
    
    if(x == 3)
        return 1+2+1;
        
    
    return NumberOfStep(x-1) + NumberOfStep(x-2) + NumberOfStep(x-3);
}


int NumberofStepsDP(int x)
{
    int prev1 = 0;
    int prev2 = 0;
    int prev3 = 0;
    
   if(x == 1)
        return 1;
    
    if(x == 2)
        return 2;
    
    if(x == 3)
        return 3+2+1;
    
    
   for(int i = 4; i < x; i++)
   {
        int total = prev1 +prev2+ prev3;
        prev1 = prev2;
        prev2 = prev3;
        prev3 = total;
   }
     return prev3;   
}