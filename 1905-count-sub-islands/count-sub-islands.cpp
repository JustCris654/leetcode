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
    // print_grid(grid1);
    // println("---------------");
    // print_grid(grid2);
    int sub_islands = 0;
    for (size_t i = 0; i < grid1.size(); i++) {
      for (size_t j = 0; j < grid1[0].size(); j++) {
        bool is_island = false;
        bool subisland = true;
        floodfill(grid2, grid1, make_pair(i, j), visited, is_island, subisland);
        if (is_island && subisland) {
          sub_islands += 1;
        }
      }
    }

    return sub_islands;
  }

private:
  void print_grid(vector<vector<int>> &g) {
    for (const auto &row : g) {
      for (const auto &el : row) {
        print("{} ", el);
      }
      println();
    }
  }

  void floodfill(vector<vector<int>> &grid, vector<vector<int>> &grid1,
                 pair<size_t, size_t> coords, vector<vector<bool>> &visited,
                 bool &is_island, bool &sub_island) {
    if (coords.first >= grid.size() || coords.second >= grid[0].size())
      return;

    if (grid[coords.first][coords.second] == 0 ||
        visited[coords.first][coords.second])
      return;

    visited[coords.first][coords.second] = true;

    is_island = true;

    if (grid1[coords.first][coords.second] == 0) {
      sub_island = false;
    }

    floodfill(grid, grid1, make_pair(coords.first + 1, coords.second), visited,
              is_island, sub_island);
    floodfill(grid, grid1, make_pair(coords.first - 1, coords.second), visited,
              is_island, sub_island);
    floodfill(grid, grid1, make_pair(coords.first, coords.second + 1), visited,
              is_island, sub_island);
    floodfill(grid, grid1, make_pair(coords.first, coords.second - 1), visited,
              is_island, sub_island);
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
