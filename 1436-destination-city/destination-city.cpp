#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_set<string> from_cities;

    for (const auto &path : paths) {
      from_cities.insert(path[0]);
    }

    for (const auto &path : paths) {
      if (from_cities.find(path[1]) == from_cities.end())
        return path[1];
    }

    assert(false && "It should not reach here");
  }
};

int main() {
  Solution s;

  {
    std::vector<std::vector<string>> arr = {
        {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    assert(s.destCity(arr) == "Sao Paulo" && "Testcase 1");
  }

  {
    std::vector<std::vector<string>> arr = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    assert(s.destCity(arr) == "A" && "Testcase 2");
  }

  {
    std::vector<std::vector<string>> arr = {{"A", "Z"}};
    assert(s.destCity(arr) == "Z" && "Testcase 3");
  }
}
