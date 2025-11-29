#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    unordered_map<int, int> connections;

    for (int i = 0; i < 2; i++) {
      const int &el1 = edges[i][0];
      const int &el2 = edges[i][1];
      if (const auto &it = connections.find(el1); it == connections.end()) {
        connections[el1] = 1;
      } else {
        connections[el1]++;
      }

      if (const auto &it = connections.find(el2); it == connections.end()) {
        connections[el2] = 1;
      } else {
        connections[el2]++;
      }
    }

    const auto max_pair = *std::max_element(
        connections.begin(), connections.end(),
        [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
          return p1.second < p2.second;
        });

    return max_pair.first;
  }
};

int main() {
  Solution s;

  {
    std::vector<std::vector<int>> arr = {{1, 2}, {2, 3}, {4, 2}};
    assert(s.findCenter(arr) == 2 && "Testcase 1");
  }

  {
    std::vector<std::vector<int>> arr = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    assert(s.findCenter(arr) == 1 && "Testcase 2");
  }
}
