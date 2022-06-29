#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector< vector<int> > result;
    vector<int> path;
    void backtracking(vector<int> &num, int startIndex){
        result.push_back(path);
        if (startIndex >= num.size()){
            return;
        }
        for (int i = startIndex; i < num.size(); i++){
            path.push_back(num[i]);
            backtracking(num, i + 1);
            path.pop_back();
        }
    }

public:
    vector< vector<int> > subsets(vector<int> &nums)
    {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector< vector<int> > result = s.subsets(nums);
    vector< vector<int> >::iterator it = result.begin();
    while(it!=result.end())
    {
        vector<int>::iterator it2 = it->begin();
        while(it2!=it->end())
        {
            cout<<*it2<<" ";
            it2++;
        }
        cout<<endl;
        it++;
    }
    return 0;
}