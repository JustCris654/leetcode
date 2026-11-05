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

    struct NodeWithParent {
        TreeNode* u;
        TreeNode* p;
    };

private:
    NodeWithParent lookupNode(TreeNode* root, int key) {
        TreeNode* p = nullptr;
        while(root != nullptr && root->val != key) {
            p = root;
            if (key > root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return NodeWithParent {root, p};
    }

    void link(TreeNode* p, TreeNode* u, int key) {
        if (p != nullptr) {
            if (key < p->val) {
                p->left = u;
            } else {
                p->right = u;
            }
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        NodeWithParent node = lookupNode(root, key);
        if (node.u != nullptr) {
            if (node.u->left != nullptr && node.u->right != nullptr) {
                TreeNode* sP = node.u;
                TreeNode* s = node.u->right;
                while (s->left != nullptr) {
                    sP = s;
                    s = s->left;
                }
                node.u->val = s->val;
                node.u = s;
                node.p = sP;
                key = s->val;
            }
            TreeNode* t;
            if (node.u->left != nullptr && node.u->right == nullptr) {
                t = node.u->left;
            } else {
                t = node.u->right;
            }
            if (node.p == nullptr) {
                root = t;
            } else {
                link(node.p, t, key);
            }
            delete node.u;
        }
        return root;
    }
};
