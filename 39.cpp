#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;

    void backTracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if(sum > target)
            return;
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(5);
    int target = 8;
    vector<vector<int> > result = s.combinationSum(candidates, target);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}