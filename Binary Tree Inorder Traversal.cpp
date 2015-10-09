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
	 vector<int> inorderTraversal(TreeNode* root) {
		 vector<int> visitNums;
		 if(!root) return visitNums;
		 
		 stack<TreeNode*> s;
		 TreeNode *p = root;
		 while(true){
		     while(p){
		         s.push(p);
		         p = p->left;
		     }
		     if(s.empty()) break;
		     p = s.top();
		     s.pop();
		     visitNums.push_back(p->val);
		     p = p->right;
		 }
		 return visitNums;
	 }
 };
 
 
 //递归方法
class Solution {
public:
    void inorder(TreeNode *root, std::vector<int> &visit){
        if(!root) return;
        inorder(root->left, visit);
        visit.push_back(root->val);
        inorder(root->right, visit);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> visit;
        inorder(root, visit);
        return visit;
    }
};
 
