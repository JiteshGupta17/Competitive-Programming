#include <bits/stdc++.h>
using namespace std;

// Method 1
int MaxAreaInHistogram(vector<int> arr)
{
    // arr.push_back(-1); This can be done to prevent the outer while loop

    //stack will hold the indices
    stack<int> s;

    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }

        int top = s.top();
        if (arr[i] >= arr[top])
        {
            s.push(i);
        }
        else {

            //Calculating curArea at each removal
            while (arr[i] < arr[top])
            {
                int curArea = 0;
                s.pop();

                if (s.empty())
                {
                    curArea = arr[top] * i;
                    maxArea = max(curArea, maxArea);
                    break;
                }
                else {
                    curArea = arr[top] * (i - s.top() - 1);
                    maxArea = max(curArea, maxArea);
                }
                top = s.top();
            }

            // pushing the element at each its correct position
            s.push(i);
        }
    }

    // Might be stack is not empty
    while (!s.empty())
    {
        int i = arr.size();
        int top = s.top();
        int curArea = 0;
        s.pop();

        if (s.empty())
        {
            // Smallest element
            curArea = arr[top] * i;
        }
        else {
            curArea = arr[top] * (i - s.top() - 1);
        }

        maxArea = max(curArea, maxArea);
    }

    return maxArea;
}

// Method 2
int HistogramArea(vector<int> arr) {

    stack<int> s;
    int maxArea = 0;
    arr.push_back(-1);

    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty()) s.push(i);
        else
        {
            int top = s.top();

            while (arr[i] < arr[top])
            {
                s.pop();
                if (s.empty())
                {
                    int CurArea = arr[top] * i;
                    maxArea = max(maxArea, CurArea);
                    break;
                }
                else {
                    int CurArea = arr[top] * (i - s.top() - 1);
                    maxArea = max(maxArea, CurArea);
                }
                top = s.top();
            }

            s.push(i);
        }
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;

    int maxArea = 0;
    vector<int> cur(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '0')
            {
                cur[j] = 0;
            }
            else {
                cur[j] += 1;
            }
        }

        int curArea = HistogramArea(cur);
        maxArea = max(maxArea, curArea);
    }

    return maxArea;
}


int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    cout << MaxAreaInHistogram(arr);

    vector<vector<int>> matrix = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};

    cout << maximalRectangle(matrix);


}
