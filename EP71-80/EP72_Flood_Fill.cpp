#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != initialColor)
        return;
    image[i][j] = newColor;
    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialColor = image[sr][sc];
    if (initialColor != color)
        dfs(sr, sc, initialColor, color, image);
    return image;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns of the image: ";
    cin >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    cout << "Enter the elements of the image:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> image[i][j];
        }
    }

    int sr, sc, color;
    cout << "Enter sr, sc, and color: ";
    cin >> sr >> sc >> color;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    cout << "Output image:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Enter the number of rows and columns of the image: 3 3
Enter the elements of the image:
1 1 1
1 1 0
1 0 1
Enter sr, sc, and color: 1 1 2
Output image:
2 2 2
2 2 0
2 0 1
*/