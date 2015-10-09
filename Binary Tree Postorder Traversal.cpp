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
 class Solution1 {
 public:
	 vector<int> postorderTraversal(TreeNode* root) {
		 vector<int> visit;
		 if (!root) return visit;
		 stack<pair<TreeNode*, bool>> s;
		 s.push(make_pair(root, false));
		 while (!s.empty()){
			 TreeNode *node = s.top().first;
			 if (s.top().second){
				 s.pop();
				 visit.push_back(node->val);
			 }
			 else{
				 s.top().second = true;
				 if (node->right) s.push(make_pair(node->right, false));
				 if (node->left) s.push(make_pair(node->left, false));
			 }
		 }
		 return visit;
	 }
 };
 
 //递归方法
class Solution2 {
public:
    void postorder(TreeNode *root, vector<int> &visit){
        if(!root) return;
        postorder(root->left, visit);
        postorder(root->right, visit);
        visit.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> visit;
        postorder(root, visit);
        return visit;
    }
};
