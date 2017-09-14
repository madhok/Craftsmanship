/*
LCA of n-ary tree
Do a depth first search
*/

struct Node {
    int id;
    vector<Node> child;
    Node(int x) :id(x) {}
};

int LCA(int a, int b, Node root) {
    if(a == b) return a;
    if(a == root.id || b == root.id) return root.id;
    
    int count =0;
    int ret = -1;
    for(int i=0; i<root.child.size();++i) {
        int res = LCA1(a,b,root.child[i]);
        if(res != -1) {
            count++;
            ret = res;
        }
    }
    if(count == 2) return root.id;
    return ret;
}

// Driver code
int main()
{
	Node root(1);
	Node two(2);
	Node three(3);
	Node four(4);
	Node five(5);
	Node six(6);
	Node seven(7);
	
	four.child.push_back(five);
	four.child.push_back(six);
	four.child.push_back(seven);
	
	//two.child.push_back(three);
	two.child.push_back(four);
	
	root.child.push_back(two);
	root.child.push_back(three);
	
	cout << "LCA(4, 7) = " << LCA1(3,7,root) << endl;
	cout << "LCA(4, 6) = " << LCA1(4,6,root) << endl;
	return 0;
}
