class Solution {
private:
        void dfs(vector<vector<int>>& g, int x, vector<bool>& v) {
            v[x] = true;
            for (int i = 0; i < g[x].size(); i++) {
                if (g[x][i] == 1 && !v[i]) {
                    dfs(g, i, v);
                }
            }
        }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = 0;
        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                n++;
            }
        }

        return n;
    }
};
