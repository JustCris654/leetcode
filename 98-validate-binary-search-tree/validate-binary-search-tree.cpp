/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int prev;
    bool prevValorized{false};

public:
    bool isValidBST(TreeNode* root) {
        if (root != nullptr) {
            if (!isValidBST(root->left)) {
                return false;
            }
            if (prevValorized && root->val <= prev) {
                return false;
            } else {
                prev = root->val;
                prevValorized = true;
            }
            return isValidBST(root->right);
        }

        return true;
    }
};
