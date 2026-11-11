class Solution {

private:
    bool dfs(vector<vector<int>>& g, int x, vector<int>& state, vector<int>& order) {
        if (state[x] == 1) return false;
        if (state[x] == 2) return true;
        state[x] = 1;
        for (int nx: g[x]) {
            if (!dfs(g, nx, state, order)) return false;
        }
        state[x] = 2;
        order.push_back(x);
        return true;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);

        for (auto& el : p) {
            g[el[0]].push_back(el[1]);
        }

        vector<int> state(n, 0);
        vector<int> order;
        order.reserve(n);
        for (int i = 0; i < n; i++) {
            if (state[i] == 0 && !dfs(g, i, state, order)) return {};
        }
        return order;
    }
};
