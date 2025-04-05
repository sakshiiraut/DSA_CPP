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
   int level(TreeNode* root){
     if(root==nullptr) return 0;
     return 1+max(level(root->left),level(root->right));
   }
   void nthlevel(TreeNode* root,int curr,int level,vector<int>&lev){
    if (root == nullptr) return;

    if(curr==level) {
        lev.push_back(root->val);
        return;
    }
    if(level%2==0){
        nthlevel(root->right,curr+1,level,lev);
        nthlevel(root->left,curr+1,level,lev);
    }else{
         nthlevel(root->left,curr+1,level,lev);
         nthlevel(root->right,curr+1,level,lev);
    }
   }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int>lev;
            nthlevel(root,1,i,lev);
            res.push_back(lev);
        }
        return res;
    }
};