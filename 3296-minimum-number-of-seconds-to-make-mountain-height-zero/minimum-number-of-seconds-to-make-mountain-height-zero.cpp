#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  struct workerState {
    int timeToProgress;
    long long actualTimeToProgress;
    int mFactor;
    int progress;
  };

  int heightOfWorkersAtSeconds(vector<workerState> &workerStates,
                               long long elapsedSeconds) {
    int sum{0};
    for (auto &el : workerStates) {
      if (elapsedSeconds >= el.actualTimeToProgress) {
        el.actualTimeToProgress += el.timeToProgress * el.mFactor++;
        el.progress++;
      }

      sum += el.progress;
    }

    return sum;
  }

public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    if (workerTimes.size() == 1) {
      int t = workerTimes[0]; 
      long long m = mountainHeight;
      return m*(m+1)/2*t;
    }


    vector<workerState> workerStates(workerTimes.size());
    for (size_t i = 0; i < workerTimes.size(); i++) {
      const auto &el = workerTimes[i];
      workerStates[i] = {
          .timeToProgress = el,
          .actualTimeToProgress = el,
          .mFactor = 2,
          .progress = 0,
      };
    }

    long long seconds{0};
    while (true) {
      seconds++;
      // check worker progress for each worker and sum it up
      // if workers progress summed is mountainHeight return seconds
      int heightAtSeconds = heightOfWorkersAtSeconds(workerStates, seconds);
      if (heightAtSeconds >= mountainHeight)
        return seconds;
    }
  }
};

int main() {
  Solution s;

  {
    int mountainheight = 100000;
    vector<int> workertimes{1};
    int res = s.minNumberOfseconds(mountainheight, workertimes);
    assert(res == 3 && "testcase 1");
  }

  {
    int mountainheight = 4;
    vector<int> workertimes{2, 1, 1};
    int res = s.minNumberOfseconds(mountainheight, workertimes);
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
