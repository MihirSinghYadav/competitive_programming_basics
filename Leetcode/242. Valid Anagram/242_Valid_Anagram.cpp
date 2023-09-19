#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int store[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            store[s[i] - 'a']++;
            store[t[i] - 'a']--;
        }
        for (int n : store)
        {
            if (n != 0)
                return false;
        }
        return true;
    }
};

class Solution2
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (int i = 0; i < s.size(); i++)
        {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        for (int i = 0; i < s_map.size(); i++)
        {
            if (s_map[i] != t_map[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution2 solution;

    string s1 = "anagram";
    string t1 = "nagaram";
    bool result1 = solution.isAnagram(s1, t1);
    cout << "Are s1 and t1 anagrams? " << result1 << endl; // Expected output: true

    string s2 = "rat";
    string t2 = "car";
    bool result2 = solution.isAnagram(s2, t2);
    cout << "Are s2 and t2 anagrams? " << result2 << endl; // Expected output: false

    return 0;
}