#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
  int heightOfWorkersAtSeconds(vector<int> &workerTimes,
                               long long elapsedSeconds) {
    int sum{0};
    for (const auto &el: workerTimes) {
      float wh = (sqrt(8 * elapsedSeconds / el + 1) - 1) / 2;
      sum += (int)floor(wh);
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

    long long seconds{0};
    while (true) {
      seconds++;
      int heightAtSeconds = heightOfWorkersAtSeconds(workerTimes, seconds);
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
    long long res = s.minNumberOfSeconds(mountainheight, workertimes);
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
