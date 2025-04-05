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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//          vector<vector<int>> res;

//         if (root == nullptr) return res;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(q.size()>0){
//            int levelSize = q.size();
//             vector<int> level;

//             for (int i = 0; i < levelSize; i++) {
//                 TreeNode* temp = q.front();
//                 q.pop();

//                 level.push_back(temp->val);

//                 if (temp->left != nullptr) q.push(temp->left);
//                 if (temp->right != nullptr) q.push(temp->right);
//             }

//             res.push_back(level); // Add current level to result
//         }
//         return res;
//     }
// };
class Solution {
public:
    int levels(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthlevels(TreeNode* root, int curr, int level, vector<int> &lev) {
        if (root == nullptr) return;
        if (curr == level) {
            lev.push_back(root->val);
            return;
        }
        nthlevels(root->left, curr + 1, level, lev);
        nthlevels(root->right, curr + 1, level, lev);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int n = levels(root);

        for (int i = 1; i <= n; i++) {
            vector<int> lev;
            nthlevels(root, 1, i, lev);
            result.push_back(lev);
        }
        return result;
    }
};
