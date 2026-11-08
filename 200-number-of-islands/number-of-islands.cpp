class Solution {

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

private:
    void bfs(vector<vector<char>>& grid, int startX, int startY) {
        queue<pair<int, int>> q;
        q.push(make_pair(startX, startY));
        grid[startX][startY] = '2';
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();

            for (int i = 0; i < dirs.size(); i++) {
                int x = pos.first + dirs[i][0];
                int y = pos.second + dirs[i][1];

                if (x >= 0 && x < grid.size() && y >= 0 &&
                    y < grid[pos.first].size() && grid[x][y] == '1') {
                    grid[x][y] = '2';
                    q.push(make_pair(x, y));
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
