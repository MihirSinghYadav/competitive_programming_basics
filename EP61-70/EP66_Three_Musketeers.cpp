#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/
// The Three Musketeers

bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

vector<string> subsets(string s)
{
    int sz = (1 << s.size());
    vector<string> answer;
    for (int mask = 0; mask < sz; mask++)
    {
        string subset;
        for (int bit = 0; bit < s.size(); bit++)
        {
            if (mask & (1 << bit))
                subset.push_back(s[bit]);
        }
        if (subset.size() > 0)
            answer.push_back(subset);
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        unordered_map<string, int> umap;
        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vowels;
            for (char ch : str[i])
            {
                if (isVowel(ch))
                {
                    distinct_vowels.insert(ch);
                }
            }
            string vowel_string;
            for (char ch : distinct_vowels)
            {
                vowel_string.push_back(ch);
            }
            vector<string> subsetsAll = subsets(vowel_string);
            for (string vowel_subset : subsetsAll)
            {
                umap[vowel_subset]++;
            }
        }
        long long answer = 0;
        for (auto &pr : umap)
        {
            if (pr.second < 3)
                continue;
            long long ct = pr.second;
            long long ways = ct * (ct - 1) * (ct - 2) / 6;
            if (pr.first.size() % 2 == 0)
                answer -= ways;
            else
                answer += ways;
        }
        cout << answer << endl;
    }
}