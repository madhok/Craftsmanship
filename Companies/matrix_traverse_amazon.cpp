/*
You are given a binary MxN matrix. You can walk through 1's, but not through 0's. You can walk in any of the 4 directions from each cell.
Find if there exists a path from one position to another position in the matrix. 
Eg. 
1 0 0 1
1 1 0 1
0 1 0 0
1 1 1 0

Here, there exists a path from (0,0) to (3,1), but not from (0,3) to (1,1)
*/
/*0,0 -> 1,0->1,1 -> 2,1->3,1->true
3,1 -> 4,1
        3,2
        2,1
        3,0
*/
        
struct point {
 int x;
 int y;
 point(int a, int b) :x(a),x(b){}
 int getval(int[][] m) {
     return m[x][y];
 }
 bool isvalid() {
     if (x <0 || y < 0 || x >= MX || y >= MY) return false;
     return true; 
 }
 bool equals(point p1) {
     if(p1.x == x && p1.y == y) return true;
     return false;
 }
};


bool is_path(int[][] matrix, point source, point dest, map<point, bool>& visited_map ) {
    if(!source.isvalid()) return false;
    if(!dest.isvalid()) return false;
    if(visited_map[source] == true) return false;
    
    if(source.getval(m) ==0 ) return false;
    if(dest.getval(m) == 0) return false;
        
    if(source.equals(dest)) return true;
    visited_map[source] = true;
         
    point point1 = new point(source.x-1,source.y);
    point point2 = new point(source.x,source.y-1);
    point point3 = new point(source.x+1,source.y);
    point point4 = new point(source.x,source.y+1);    
    return is_path(m,point1,dest,visited_map)|| is_path(m,point2,dest,visited_map) || 
            is_path(m,point3,dest,visited_map) || is_path(m,point4,dest,visited_map); 
}

p1 = -1,0
p2 = 0,-1
p3 = 1,0
p4 = 0,1

1,0
p1 = 0,0 -> 
p2 = 1,-1 
p3 = 2,0
p4 = 1,1


