#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        // find 0 in 1st col or 1st element of each row
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                isFirstColZero = true;
                break;
            }
        }

        // find 0 in 1st row or 1st element of each col
        for (int j = 0; j < cols; j++)
        {
            if (matrix[0][j] == 0)
            {
                isFirstRowZero = true;
                break;
            }
        }

        // find 0 in (1,row) and (1,col) and set 0 to 1st row and 1st col
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set 0 for 0 in 1st row and 1st col
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // sets 1st col zero
        if (isFirstColZero)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // sets 1st row zero
        if (isFirstRowZero)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    Solution solution;
    solution.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}