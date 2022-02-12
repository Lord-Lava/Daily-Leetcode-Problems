/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>res;
        if(root == NULL) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* n = st.top();
            st.pop();
            res.push_back(n->val);
            if(n->right!=NULL){
                st.push(n->right);
            }
            if(n->left!=NULL){
                st.push(n->left);
            }
        }
        return res;
    }
};