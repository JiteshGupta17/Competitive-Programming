#include <bits/stdc++.h>
using namespace std;

void NextGreaterOnLeft(vector<int> v)
{
    stack<int> s;
    vector<int> ans(v.size());

    s.push(v[0]);
    ans[0] = -1;

    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && v[i] >= s.top())
        {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();

        s.push(v[i]);

    }

    for (int ele : ans) cout << ele << " ";
}

int main() {
    vector<int> v = {1, 4, 2, 3, 8, 6, 5, 9, 1};

    NextGreaterOnLeft(v);
}
