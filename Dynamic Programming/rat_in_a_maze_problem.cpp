/*
http://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

Constraints:
1<=T<=10
2<=n<=10
0<=m[][]<=1

Example(To be used only for expected output):
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR 
 

 

**For More Examples Use Expected Output**





Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
bool isSafe(int m[MAX][MAX], int n, bool visited[MAX][MAX],
            string str,int row, int col) {
    if(row<0 || col <0) return false;
    if(row>=n  || col >=n) return false;
    if(m[row][col] == 0) return false;
    if(visited[row][col]) return false;
    
    return true;
}
void util(int m[MAX][MAX], int n, int row, int col,string str,bool visited[MAX][MAX],
            vector<string>& result) {
    if((row == n-1) && col == n-1) {
         result.push_back(str);
         return;
    }
    if(isSafe(m,n,visited,str,row+1,col)) {
        str +="D";
        visited[row+1][col] = true;
        util(m,n,row+1, col,str,visited,result);
        visited[row+1][col] = false;
        str = str.substr(0,str.length()-1);
    }
    if(isSafe(m,n,visited,str,row,col+1)) {
        str += "R";
        visited[row][col+1] = true;
        util(m,n,row, col+1,str, visited, result);
        visited[row][col+1] = false;
        str = str.substr(0,str.length()-1);
        
    }
    if(isSafe(m,n,visited,str,row-1,col)) {
        str += "U";
        visited[row-1][col] = true;
        util(m,n,row-1, col,str, visited, result);
        visited[row-1][col] = false;
        str = str.substr(0,str.length()-1);
    }
    if(isSafe(m,n,visited,str,row,col-1)) {
        str += "L";
        visited[row][col-1] = true;
        util(m,n,row, col-1,str, visited, result);
        visited[row][col-1] = false;
        str = str.substr(0,str.length()-1);
    }
}

std::vector<string> printPath(int m[MAX][MAX], int n)
{
    std::vector<string> result;
    int row=0,col=0;
    bool visited[MAX][MAX] = {false};
    string str ="";
     visited[row][col] = true;
    util(m,n,row,col,str,visited,result);
    sort(result.begin(),result.end());
    return result;
}
