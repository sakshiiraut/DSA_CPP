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
int count=0;
    int level(TreeNode* root){
    if(root==nullptr) return 0;
    return 1+max(level(root->left),level(root->right));
    }

    void nthlevel(TreeNode* root,int curr,int level){
    if (root == nullptr) return ;

    if(curr==level) {
        count++;
        return;
    }
        nthlevel(root->right,curr+1,level);
        nthlevel(root->left,curr+1,level);
   }
    int countNodes(TreeNode* root) {
       count=0;
        int n=level(root);
        for(int i=1;i<=n;i++){
            nthlevel(root,1,i);
        }
       return count;
    }
};