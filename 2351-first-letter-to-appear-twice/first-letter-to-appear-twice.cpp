#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  char repeatedCharacter(string s) {
    bool found_chars[26] = {false};

    for (const auto &el : s) {
      if (found_chars[el-'a'] == true) return el;
      found_chars[el-'a'] = true;
    }

    return 'a';
  }
};

int main() {
  Solution s;

  {
    string input = "abccbaacz";
    assert(s.repeatedCharacter(input) == 'c' && "Testcase 1");
  }

  {
    string input = "abcdd";
    assert(s.repeatedCharacter(input) == 'd' && "Testcase 2");
  }
}
