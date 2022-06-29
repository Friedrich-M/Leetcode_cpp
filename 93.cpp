#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
private:
    vector<string> result;
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string &s, int startIndex, int pointNum){
        if (pointNum == 3){
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++){
            if (isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1); // 删除逗点
            }
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string &s, int start, int end){
        if (start > end)
            return false;
        if (s[start] == '0' && start != end)
            return false;
        int num;
        for (int i = 0; i < s.size(); i++){
            if (s[i] > '9' || s[i] < '0'){ // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255){ // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s){
        result.clear();
        if(s.size() > 12 || s.size() < 4)
            return result;
        backtracking(s, 0, 0);
        return result;
    }
};
