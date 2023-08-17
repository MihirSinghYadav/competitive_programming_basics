#include <iostream>
using namespace std;
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
int dp[1005];

int func(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int max_price = 0;
    for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
    {
        // for (int i = 0; i < len_to_cut; i++)
        //     max_price = max(max_price, prices[i] + func(len - len_to_cut, prices));
        if (len - len_to_cut >= 0)
            max_price = max(max_price, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
    }
    return dp[len] = max_price;
}

int cutRod(int price[], int n)
{
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price + n);
    return func(n, prices);
}

int main()
{

    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << cutRod(price, n) << endl;
}
/*
Input
8
1 5 8 9 10 17 17 20
Output
22
*/