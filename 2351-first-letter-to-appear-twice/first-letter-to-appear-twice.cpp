#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  char repeatedCharacter(string s) {
    unordered_map<char, int> char_map = {
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0},
        {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0},
        {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0},
        {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

    for (const auto &el : s) {
      if (++char_map[el] == 2) {
        return el;
      }
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
