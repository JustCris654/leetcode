#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pt(numRows);
    for (int i = 0; i < numRows; i++) {
      pt[i].reserve(i+1);

      // base cases
      if (i == 0) {
        pt[i].push_back(1);
        continue;
      }
      if (i == 1) {
        pt[i].push_back(1);
        pt[i].push_back(1);
        continue;
      }

      for (int j = 0; j < i+1; j++) {
        if (j == 0 || j == i) {
          pt[i].push_back(1);
        } else {
          pt[i].push_back(pt[i - 1][j - 1] + pt[i - 1][j]);
        }
      }
    }

    return pt;
  }
};

int main() {
  Solution s;

  {
    int input = 5;
    const auto output = s.generate(input);
    const vector<vector<int>> expected = {
        {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    assert((output == expected) && "Testcase 1");
  }
  
  return 0;
}
