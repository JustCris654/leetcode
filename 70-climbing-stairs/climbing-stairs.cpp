#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 3)
      return n;

    int n1 = 2, n2 = 3, res = 0;

    for (int i = 3; i < n; i++) {
      res = n1 + n2;
      n1 = n2;
      n2 = res;
    }

    return res;
  }
};

int main() {
  Solution s;

  {
    int input = 1;
    assert(s.climbStairs(input) == 1 && "Testcase 1");
  }

  {
    int input = 2;
    assert(s.climbStairs(input) == 2 && "Testcase 2");
  }

  {
    int input = 3;
    assert(s.climbStairs(input) == 3 && "Testcase 3");
  }

  {
    int input = 4;
    assert(s.climbStairs(input) == 5 && "Testcase 4");
  }

  {
    int input = 5;
    assert(s.climbStairs(input) == 8 && "Testcase 5");
  }
}
