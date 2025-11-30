#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      if (n == 0) return 1;
      if (n == 1) return 1;
      
      return climbStairs(n-1) + climbStairs(n-2);
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
