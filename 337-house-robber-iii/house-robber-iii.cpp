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
    int maxSum;
    unordered_map<TreeNode*,int>mp;
    int solve(TreeNode* root){
        if(!root) return 0;
        int not_pick=solve(root->left)+solve(root->right);
        int pick=root->val;
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        if(root->left){
            pick+=solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
            pick+=solve(root->right->left)+solve(root->right->right);
        }
        
        maxSum=max(pick,not_pick);
        return mp[root]=maxSum;

        
    }
    int rob(TreeNode* root) {
        maxSum=0;
        return solve(root);
    }
};