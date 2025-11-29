#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int ops = 0;
    vector<int> prev_row_vals(grid[0]);
    
    for (auto it = grid.begin()+1; it != grid.end(); it++) {
      for (size_t i = 0; i < it->size(); i++) {
	prev_row_vals[i] = max(++prev_row_vals[i], (*it)[i]);
	ops += max(0, prev_row_vals[i] - (*it)[i]);
      }
    }

    return ops;
  }
};

int main() {
  Solution s;

  {
    std::vector<std::vector<int>> arr = {{3,2},{1,3},{3,4},{0,1}};
    assert(s.minimumOperations(arr) == 15 && "Testcase 1");
  }

  {
    std::vector<std::vector<int>> arr = {{3,2,1},{2,1,0},{1,2,3}};
    assert(s.minimumOperations(arr) == 12 && "Testcase 2");
  }

  {
    std::vector<std::vector<int>> arr = {{0}, {50}};
    assert(s.minimumOperations(arr) == 0 && "Testcase 2");
  }

  {
    std::vector<std::vector<int>> arr = {{6,3,4},{9,1,3},{4,6,3}};
    assert(s.minimumOperations(arr) == 14 && "Testcase 2");
  }
}
