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
    void Traversal(Node* root , int level , vector <Node*>&store){
        if(!root) return ; 
       // if(store[level] != NULL)  cout<<level<<" "<<store[level]->val<<" ";
        if(store[level] != NULL){
            Node* x = store[level] ; 
            x->next = root ; 
        }
        store[level] = root; 
        Traversal(root->left , level + 1 , store) ; 
        Traversal(root->right , level + 1 , store) ; 
    }
    Node* connect(Node* root) {
        vector <Node*> store(500 , NULL) ; 
        Traversal(root , 0 , store)  ;
        return root; 
        
    }
}; 