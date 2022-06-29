#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > result;
vector<int> path;

class Solution
{
private:
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k-path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector< vector<int> > combine(int n, int k)
    {
        path.clear();
        result.clear();
        backtracking(n, k, 1);
        return result;
    }
};


int main()
{
    Solution s;
    vector< vector<int> > result = s.combine(4, 2);
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