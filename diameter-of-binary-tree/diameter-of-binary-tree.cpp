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
    
    int diameterOfBinaryTree(TreeNode* root){   
        int res=INT_MIN;
        diameter(root, res);
        return res-1;
    }
    
    int diameter(TreeNode* root, int& res){
        if(root == NULL) return 0;

        int l = diameter(root->left,res);
        int r = diameter(root->right,res);

        int temp = 1 + max(l,r);
        res = max(res,1+l+r);

        return temp;
    }
};