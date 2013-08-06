/*
 Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nh = strlen(haystack);
        int nn = strlen(needle);
        if(nh == 0 && nn == 0)
            return "";
        
        if(nh == 0)
            return NULL;
        
        if(nn == 0)
            return haystack;
        
        if(nn > nh)
            return NULL;
        int start;
        for(int i = 0; i<nh-nn+1; i++)
        {   
            int start = i;int j =0;
            while(haystack[i] == needle[j])
            {
                if(j == strlen(needle)-1)
                    return &haystack[start];
                i++;
                j++;
            }
            i = start;
        }
        return NULL;
    }
};