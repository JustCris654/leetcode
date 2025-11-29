#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_map<string, int> city_conns;
      
      for (const auto &path: paths) {
	const auto from = path[0];
	const auto to = path[1];
	
	
	// initialize at 1 if doesnt already exist or add 1
	if (const auto &it = city_conns.find(from); it == city_conns.end()) {
	  city_conns[from] = 1;
	} else {
	  city_conns[from]++;
	}

	// if doesnt exist initialize at 0, do nothing otherwise
	if (const auto &it = city_conns.find(to); it == city_conns.end()) {
	  city_conns[to] = 0;
	}
      }
      
      for (const auto &pair: city_conns) {
	if (pair.second == 0) return pair.first; 
      }
      
      assert(false && "It should not reach here");
    }
};


int main() {
  Solution s;

  {
    std::vector<std::vector<string>> arr = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    assert(s.destCity(arr) == "Sao Paulo" && "Testcase 1");
  }

  {
    std::vector<std::vector<string>> arr = {{"B","C"},{"D","B"},{"C","A"}};
    assert(s.destCity(arr) == "A" && "Testcase 2");
  }

  {
    std::vector<std::vector<string>> arr = {{"A","Z"}};
    assert(s.destCity(arr) == "Z" && "Testcase 3");
  }
}
