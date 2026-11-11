class Solution {
private:
    int time;
    vector<int> dt;
    vector<int> ft;

    bool cycle(vector<vector<int>>& g, int course) {
        dt[course] = ++time;

        for (int i = 0; i < g.size(); i++) {
            if (g[course][i] == 0)
                continue;

            if (dt[i] == 0) {
                if (cycle(g, i))
                    return true;
            } else if (ft[i] == 0) {
                return true;
            }
        }

        ft[course] = ++time;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>(numCourses));
        time = 0;
        dt.assign(numCourses, 0);
        ft.assign(numCourses, 0);

        for (auto& el : prerequisites) {
            if (el[0] == el[1])
                return false;

            if (g[el[1]][el[0]] == 1)
                return false;
            g[el[0]][el[1]] = 1;
        }

        bool ret = true;
        for (int i = 0; i < numCourses; i++) {
            if (dt[i] == 0 && cycle(g, i)) {
                return false;
            }
        }



        return ret;
    }
};
