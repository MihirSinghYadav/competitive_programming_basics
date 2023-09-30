#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = solution.groupAnagrams(strs);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}