/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(path.length() == 0)
            return NULL;
        char slash = '/';
        if(path.length() == 1 && path[0] == slash)
            return path;
        string result;
        vector<string> splits;
        splits = getStrings(path);
        vector<string>::iterator iter;
        if(splits.size() == 0)
        {
            result = "/";
            return result;
        }
        for(iter = splits.begin(); iter!=splits.end(); iter++)
        {
            if(*iter != ".")
                result = result + '/' + *iter;
        }
        if(result == "")
            result = "/";
        return result;
    }
    
    vector<string> getStrings(string path)
    {
        vector<string> splits;
        string word;
        for(int i = 0; i < path.length(); i++)
        {
            if(path[i] == '/')
            {
                if(word.length() >0)
                {
                    splits.push_back(word);
                }
                word ="";
            }
            else if(path[i] == '.')
            {
                if((i + 1) < path.length() && path[i+1] == '.')
                {
                    if(splits.size() > 0)
                        splits.pop_back();
                    i++;
                }
                else if((i + 1) < path.length() && path[i+1] == '/')
                {
                    word = "";
                }
                else
                    word.insert(word.end(),path[i]); 
            }
            else
            {
                word.insert(word.end(),path[i]);    
            }
        }
        if(word.size() > 0)
            splits.push_back(word);
        return splits;
    }
};