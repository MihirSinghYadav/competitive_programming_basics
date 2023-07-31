#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        unordered_multiset<long long> bags;
        for (int i = 0; i < N; i++)
        {
            long long candyCount;
            cin >> candyCount;
            bags.insert(candyCount);
        }
        long long totalCandies = 0;
        for (int i = 0; i < K; i++)
        {
            auto lastBag = (--bags.end());
            long long candies = *lastBag;
            totalCandies += candies;
            bags.erase(lastBag);
            bags.insert(candies / 2);
        }
        cout << totalCandies << endl;
    }
}
// Input: 1 5 3 2 1 7 4 2
// Output: 14