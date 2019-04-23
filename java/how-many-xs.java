/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int ntestCases = sc.nextInt();
	    while(ntestCases>0) 
	    {
	        ntestCases--;
	        int num = sc.nextInt();
	        int lbound = sc.nextInt();
	        int ubound = sc.nextInt();
	        int result= getOccurences(num,lbound+1, ubound-1);
	        System.out.println(result);
	    }
	}
	private static int getOccurences(int num, int lbound, int ubound) {
	    if(lbound >= ubound) {
	        return 0;
	    }
	    int count = 0;
	    while(lbound <= ubound) {
	        int val = lbound;
	        int div =10;
	        while(val >0) {
	            if(val%div == num) count++;
	            val = val/10;
	        }
	        lbound++;
	    }
	    return count;
	}
}