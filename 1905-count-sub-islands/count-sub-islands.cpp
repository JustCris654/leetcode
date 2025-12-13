#include <cassert>
#include <cmath>
#include <iostream>
#include <print>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    vector<vector<bool>> visited(grid1.size(),
                                 vector<bool>(grid1[0].size(), false));

    int island_num = 2;
    for (size_t i = 0; i < grid1.size(); i++) {
      for (size_t j = 0; j < grid1[0].size(); j++) {
        bool island_found = false;
        floodfill(grid2, make_pair(i, j), 1, island_num, visited, island_found);
        if (island_found) {
          island_num++;
        }
      }
    }

    set<int> possible_islands;
    set<int> banned_islands;

    for (size_t i = 0; i < grid1.size(); i++) {
      for (size_t j = 0; j < grid1[0].size(); j++) {
        if (grid2[i][j] > 1) {
          if (banned_islands.contains(grid2[i][j])) {
          } else {

            possible_islands.insert(grid2[i][j]);
          }

          if (grid1[i][j] == 0) {
            possible_islands.erase(grid2[i][j]);
            banned_islands.insert(grid2[i][j]);
          }
        }
      }
    }

    return possible_islands.size();
  }

private:
  void floodfill(vector<vector<int>> &grid, pair<size_t, size_t> coords,
                 int pre_val, int post_val, vector<vector<bool>> visited,
                 bool &island_found) {
    if (coords.first >= grid.size() || coords.second >= grid[0].size())
      return;

    if (visited[coords.first][coords.second]) {
      return;
    }

    visited[coords.first][coords.second] = true;

    if (grid[coords.first][coords.second] != pre_val) {
      visited[coords.first][coords.second] = true;
      return;
    }

    grid[coords.first][coords.second] = post_val;
    island_found = true;
    visited[coords.first][coords.second] = true;

    floodfill(grid, make_pair(coords.first + 1, coords.second), pre_val,
              post_val, visited, island_found);
    floodfill(grid, make_pair(coords.first - 1, coords.second), pre_val,
              post_val, visited, island_found);
    floodfill(grid, make_pair(coords.first, coords.second + 1), pre_val,
              post_val, visited, island_found);
    floodfill(grid, make_pair(coords.first, coords.second - 1), pre_val,
              post_val, visited, island_found);
  }
};

int main() {
  Solution s;

  {
    vector<vector<int>> grid1{{1, 1, 1, 0, 0},
                              {0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2{{1, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1},
                              {0, 1, 0, 0, 0},
                              {1, 0, 1, 1, 0},
                              {0, 1, 0, 1, 0}};
    int res = s.countSubIslands(grid1, grid2);
    println("Testcase 1 res: {}", res);
    assert(res == 3 && "testcase 1");
  }

  {
    vector<vector<int>> grid1{{1, 0, 1, 0, 1},
                              {1, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1},
                              {1, 0, 1, 0, 1}};
    vector<vector<int>> grid2{{0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1},
                              {0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0},
                              {1, 0, 0, 0, 1}};
    int res = s.countSubIslands(grid1, grid2);
    println("Testcase 2 res: {}", res);
    assert(res == 2 && "testcase 2");
  }
}
