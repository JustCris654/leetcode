#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

      vector<bool> canBeJudge(n, true);
      vector<int> trustMeter(n, 0);
      for (int i = 0; i < trust.size(); i++) {
	canBeJudge[trust[i][0]-1] = false;
	trustMeter[trust[i][1]-1]++;
      }

      for (int i = 0; i < canBeJudge.size(); i++) {
	if (canBeJudge[i] && trustMeter[i] == n-1) {
	  return i+1;
	}
      }

      return -1;
    }
};

int main() {
  Solution s;

  {
    std::vector<std::vector<int>> arr = {{1,2}};
    assert(s.findJudge(2, arr) == 2 && "Testcase 1");
  }

  {
    std::vector<std::vector<int>> arr = {{1,3}, {2,3}};
    assert(s.findJudge(3, arr) == 3 && "Testcase 2");
  }

  {
    std::vector<std::vector<int>> arr = {{1,3}, {2,3}, {3,1}};
    assert(s.findJudge(3, arr) == -1 && "Testcase 3");
  }
}

