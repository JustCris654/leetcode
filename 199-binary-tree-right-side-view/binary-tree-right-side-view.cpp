#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
  };

public:
  // idea: fare una bfs navigando prima i nodi a destra e salvarsi
  // il valore e l'altezza, quando si arriva a nodi a sinistra si salva
  // il valore solo se l'altezza e' maggiore rispetto ai nodi piu' a destra
  // salvati
  vector<int> rightSideView(TreeNode *root) {
    vector<int> rs_values;

    visitTree(root, rs_values, 0);

    return rs_values;
  }

  void visitTree(TreeNode *n, vector<int> &rsv, int level) {
    if (n == nullptr)
      return;

    if (level >= rsv.size()) {
      rsv.push_back(n->val);
    }

    level += 1;
    visitTree(n->right, rsv, level);
    visitTree(n->left, rsv, level);
  }
};
