#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double eps = 1e-7;

double multiply(double mid, int n)
{
    double answer = 1;
    for (int i = 0; i < n; i++)
    {
        answer *= mid;
    }
    return answer;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double low = 1, high = x, mid;
    while (high - low > eps)
    {
        mid = (low + high) / 2;
        if (multiply(mid, n) < x)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << setprecision(10) << low << "\n"
         << high << endl;
    cout << "Pow: " << pow(x, 1.0 / n) << endl;
}