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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(level(p)!=level(q)) return false;
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr && q!=nullptr) return false;
        if(p==nullptr && q!=nullptr) return false;
        if(p->val != q->val) return false;
        bool leftAns=isSameTree(p->left,q->right);
        if(!leftAns) return false;
        bool rightAns=isSameTree(p->right,q->left);
        if(!rightAns) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isSameTree(root->left,root->right);
    }
};