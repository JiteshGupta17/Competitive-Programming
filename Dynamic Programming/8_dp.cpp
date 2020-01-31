#include <bits/stdc++.h>
using namespace std;

int MCM_recur(int st, int end, vector<int> row, vector<int> column, vector<vector<int>> &dp)
{
    if (st == end)
    {
        return 0;
    }

    if (dp[st][end] != 0)
        return dp[st][end];

    int min_ = (int)1e8;
    for (int cut = st; cut < end; cut++)
    {
        int left = MCM_recur(st, cut, row, column, dp);       //dp[st][cut]
        int right = MCM_recur(cut + 1, end, row, column, dp); //dp[cut+1][end]

        int cost = left + row[st] * column[cut] * column[end] + right;
        // int cost = left + row[st] * row[cut+1] * row[end+1] + right; if given in one single array

        min_ = min(cost, min_);
    }

    dp[st][end] = min_;

    return min_;
}

string MCM_DP(vector<int>row, vector<int>column)
{
    int n = row.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<string>> ans(n, vector<string>(n, " "));

    for (int gap = 0; gap < n; gap++)
    {
        for (int st = 0, end = gap ; end < n ; st++, end++)
        {
            if (gap == 0)
            {
                ans[st][end] = string(1, (char)('A' + st));
                continue;
            }

            int min_ = 1e8;
            for (int cut = st ; cut < end; cut++)
            {
                int left = dp[st][cut];
                int right = dp[cut + 1][end];

                int cost = left + row[st] * column[cut] * column[end] + right;

                if (cost < min_)
                {
                    min_ = cost;
                    ans[st][end] = "(" + ans[st][cut] + ans[cut + 1][end] + ")";
                }

            }
            dp[st][end] = min_;
        }
    }

    for (auto v : ans)
    {
        for (string ele : v) cout << ele << " ";
        cout << endl;
    }

    return (ans[0][row.size() - 1] + " -> " + to_string(dp[0][row.size() - 1]));
}

// ===========================================================================================================

vector<vector<bool>> isPalindrome(string s)
{
    vector<vector<bool>> Palin(s.length(),vector<bool>(s.length(),false));

    for(int gap = 0;gap < s.length();gap++)
    {
        for(int i = 0,j = gap; j < s.length();i++,j++)
        {
            if(gap==0)
            {
                Palin[i][j] = true;
                continue;
            }

            if(gap==1 && s[i] == s[j])
            {
                Palin[i][j] = true;
                continue;
            }

            if(s[i]==s[j] && Palin[i+1][j-1])
                Palin[i][j] = true;
        }
    }

    return Palin;
}

int min_PalinCut_recur(string s,int st,int end,vector<vector<bool>> Palin)
{
    if(Palin[st][end]) return 0;

    int min_ = 1e8;
    for(int cut = st; cut < end;cut++)
    {
        int left = min_PalinCut_recur(s,st,cut,Palin);
        int right = min_PalinCut_recur(s,cut+1,end,Palin);

        int cur_ans = 1 + left + right; // 1 + due to current cut
        min_ = min(cur_ans,min_);
    }

    return min_;
}

int minPalinCut(string s,vector<vector<bool>> Palin)
{
    vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
    vector<vector<string>> ans(s.length(),vector<string>(s.length()," "));

    for(int gap = 0;gap < s.length();gap ++)
    {
        for(int st = 0,end = gap; end < s.length(); st++,end++)
        {
            if(Palin[st][end])
            {
                dp[st][end] = 0;
                ans[st][end] = "|" + s.substr(st,end-st+1) + "|";
            }
            else{
                int min_ = 1e8;
                for(int cut = st; cut < end;cut++)
                {
                    int left = dp[st][cut];
                    int right = dp[cut+1][end];

                    int cur_ans = 1 + left + right; // 1 + due to current cut
                    if(cur_ans < min_)
                    {
                        min_ = cur_ans;
                        ans[st][end] =  ans[st][cut] + ans[cut+1][end] ;
                    }
                }
                dp[st][end] = min_;
            }
        }
    }

    for(auto v : ans)
    {
        for(string ele : v)cout<<ele<<" ";
        cout<<endl;
    }

    return dp[0][s.length()-1];
}


int main() {

    /* Ques.1 Matrix Chain Multiplication */
    // 40, 20, 30, 10, 30
    // vector<int> row = {40, 20, 30, 10};
    // vector<int> column = {20, 30, 10, 30};

    // vector<vector<int>> dp(row.size(), vector<int>(column.size(), 0));

    // cout<<MCM_recur(0,3,row,column,dp)<<endl;
    // cout << MCM_DP(row, column);

    /* Ques.2 Min Palindromic cut */
    string s = "abccbc";
    vector<vector<bool>> Palin = isPalindrome(s);

    cout<<min_PalinCut_recur(s,0,s.length()-1,Palin)<<endl;
    cout<<minPalinCut(s,Palin);

}
