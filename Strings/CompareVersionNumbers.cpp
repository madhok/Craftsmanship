/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1 == version2) return 0;
        vector<int> version_arr1 = getsubversions(version1);
        vector<int> version_arr2 = getsubversions(version2);
        int minlen= version_arr1.size() > version_arr2.size()?version_arr2.size():version_arr1.size();
        
        int i = 0;
        for(; i < minlen; ++i) {
            if(version_arr1[i] > version_arr2[i]) return 1;
            else if(version_arr1[i] < version_arr2[i]) return -1;
        }
        int j = i;
        while(i< version_arr1.size()) {
            if(version_arr1[i] == 0) { i++; continue;}
            return 1;
        }
        i = j;
        while(i < version_arr2.size()) {
            if(version_arr2[i] == 0) { i++; continue;}
            return -1;
        }
        return 0;
    }
    vector<int> getsubversions(string version) {
        vector<int> result;
        string delimiter = ".";
        size_t pos =0;
        std::string::size_type sz;
        while((pos = version.find(delimiter)) != string::npos) {
            string token = version.substr(0,pos);
            result.push_back(stoi(token,&sz));
            version.erase(0,pos+delimiter.length());
        }
        result.push_back(stoi(version,&sz));
        return result;
    }
    
};