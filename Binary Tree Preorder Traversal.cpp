/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //非递归方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> visit;
        if(!root) return visit;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            visit.push_back(node->val);
            s.pop();
            if(node->right) s.push(node->right);    //push right first, then lchild will be traversed first
            if(node->left) s.push(node->left);
        }
        return visit;
    }
};

//递归方法
class Solution {
public:
    void preorder(TreeNode *root, vector<int> &visit){
        if(!root) return;
        visit.push_back(root->val);
        preorder(root->left, visit);
        preorder(root->right, visit);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> visit;
        preorder(root, visit);
        return visit;
    }
};
