#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;

    void backTracking(int n, int k, int startIndex)
    {
        if(path.size() == k && accumulate(path.begin(), path.end(), 0) == n)
        {
            result.push_back(path);
            return;
        }
        if(path.size() > k || accumulate(path.begin(), path.end(), 0) > n)
            return;
        for (int i = startIndex; i <= 9-(k-path.size() + 1); i++)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        if((1+k)*k/2 > n)
            return result;
        backTracking(n, k, 1);
        return result;
    }
};


