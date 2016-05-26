 /* Solution
  * --------
  *
  * We know, 
  *   - if a bulb can be switched to ON eventually, it must be switched by ODD times
  *   - Otherwise, if a bulb has been switched by EVEN times, it will be OFF eventually.
  * So, 
  *   - If bulb `i` ends up ON if and only if `i` has an ODD numbers of divisors.
  * And we know, 
  *   - the divisors come in pairs. for example: 
  *     12 - [1,12] [2,6] [3,4] [6,2] [12,1] (the 12th bulb would be switched by 1,2,3,4,6,12)
  *   - the pairs means almost all of the numbers are switched by EVEN times.
  *
  * But we have a special case - square numbers
  *   - A square number must have a divisors pair with same number. such as 4 - [2,2], 9 - [3,3]
  *   - So, a square number has a ODD numbers of divisors.
  *
  * At last, we figure out the solution is: 
  *    
  *    Count the number of the square numbers!! 
  */
  
class Solution {
public:
    int bulbSwitch(int n) {
        if(n <=0) return 0;
        //gettting (int)sqrt(n);
        int cnt = 0;
        for(int i = 1; i*i<=n; ++i) {
            cnt++;
        }
        return cnt;
    }
};
