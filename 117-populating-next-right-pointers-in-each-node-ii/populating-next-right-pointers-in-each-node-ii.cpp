/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector <Node*> v ;
    void solve(int d , Node* root){
        if(!root) return ; 

        if(d > v.size()) v.push_back(root) ; 
        else{
            v[d-1]->next = root ; 
            v[d-1] = root ;
        }
        solve(d + 1, root->left) ; 
        solve(d + 1, root->right) ;
    }
    Node* connect(Node* root) {
        solve(1,root) ; 
        return root ;
    }
};