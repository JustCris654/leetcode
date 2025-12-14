#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int hs(vector<int> &workerTimes, long long elapsedSeconds) {
    long long sum = 0;
    for (const auto &el : workerTimes) {
      long long val = 1.0 + 8.0 * elapsedSeconds / el;
      long long wh = (sqrt(val) - 1) / 2;
      sum += wh;
    }

    return sum;
  }

public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    long long left = 0;

    int min_worker = workerTimes[0];
    for (int t : workerTimes)
      min_worker = min(min_worker, t); // calcolo il worker piu' veloce

    long long right = (long long)mountainHeight * (mountainHeight + 1) / 2 *
                      min_worker; // worst case (il worker piu' veloce fa tutto
                                  // il lavoro da solo)
    long long ans = right;

    // binary search iterativa
    while (left <= right) {
      long long mid = left + (right - left) / 2;

      if (hs(workerTimes, mid) >= mountainHeight) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  {
    int mountainheight = 100000;
    vector<int> workertimes{1};
    long long res = s.minNumberOfSeconds(mountainheight, workertimes);
    cout << res << endl;
    assert(res == 5000050000 && "testcase 1");
  }

  {
    int mountainheight = 4;
    vector<int> workertimes{2, 1, 1};
    long long res = s.minNumberOfSeconds(mountainheight, workertimes);
    assert(res == 3 && "testcase 1");
  }

  {
    int mountainHeight = 10;
    vector<int> workerTimes{3, 2, 2, 4};
    assert(s.minNumberOfSeconds(mountainHeight, workerTimes) == 12 &&
           "Testcase 2");
  }

  {
    int mountainHeight = 5;
    vector<int> workerTimes{1};
    assert(s.minNumberOfSeconds(mountainHeight, workerTimes) == 15 &&
           "Testcase 3");
  }
}
