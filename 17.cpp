#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> result;
    string path;
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

private:
    void backTracking(const string digits, int index){
        if( digits.size() == index ){
            result.push_back(path);
            return ;
        }
 
        int tmp = digits[index] - '0';
        string letter = letterMap[tmp];
        for (int j = 0; j < letter.size(); j++){
            path.push_back(letter[j]);
            backTracking(digits, index+1);
            path.pop_back();
        }   
    }

public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.size() == 0)
        {
            return result;
        }
        backTracking(digits, 0);
        return result;
    }
};