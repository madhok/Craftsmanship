/*
https://leetcode.com/problems/rectangle-area/description/

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/


class Solution {
public:
    struct Rect {
        int left;
        int right;
        int top;
        int bottom;
        Rect(int A, int B, int C, int D) : left(A),right(C),top(D),bottom(B) {}
        int area() {
            return (right-left) * (top-bottom);
        }
    };
    int area(Rect r1, Rect r2) {
        
        int area1 = r1.area();
        int area2 = r2.area();
    
        if(r1.right < r2.left || r2.right <r1.left || r1.bottom > r2.top || r1.top < r2.bottom)
            return area1 + area2;
        
        int left = max(r1.left,r2.left);
        int right = min(r1.right, r2.right);
        int bottom = max(r1.bottom, r2.bottom);
        int top = min(r1.top,r2.top);
        
        
        Rect inter(left,bottom,right,top);
        int area = inter.area();
        return area1+area2-area;
            
        
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        
        Rect r1(A,B,C,D);
        Rect r2(E,F,G,H);
        
        return area(r1,r2);
        
    }
};
