#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int array[5] = {5, 4, 3, 2, 1};
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
// Time complexity: O(n^2)