#include<bits/stdc++.h>
using namespace std;

int calls = 0;
int MazePathMulti_memo(int sr,int sc,int er,int ec,vector<vector<int>>& dp)
{
    if(sr==er && sc==ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    if(dp[sr][sc]!=0) return dp[sr][sc];

    // calls++;
    int count = 0;

    for(int jump = 1;sr + jump <= er;jump++)
    {
        count += MazePathMulti_memo(sr + jump,sc,er,ec,dp);
    }

    for(int jump = 1;sc + jump <= ec;jump++)
    {
        count += MazePathMulti_memo(sr,sc + jump,er,ec,dp);
    }

    for(int jump = 1;sr + jump <= er && sc + jump <= ec;jump++)
    {
        count += MazePathMulti_memo(sr + jump,sc + jump,er,ec,dp);
    }

    dp[sr][sc] = count;

    if(dp[0].size()==dp.size()) dp[sc][sr] = count; // For symmetrical matrix, REDUCES NO OF CALLS

    return count;
}

int MazePathMulti_tab(int sr,int sc,int er,int ec)
{
    vector<vector<int>> dp(er+1,vector<int>(ec+1,0));
    dp[er][ec] = 1;

    for(int x = er;x >= sr;x--)
    {
        for(int y = ec;y>=sc;y--)
        {
            for(int jump = 1;x + jump <= er;jump++)
            {
                dp[x][y]+= dp[x+jump][y];
            }

            for(int jump = 1;y + jump <= ec;jump++)
            {
                dp[x][y]+= dp[x][y+jump];
            }

            for(int jump = 1;x + jump <= er && y + jump <= ec;jump++)
            {
                dp[x][y]+= dp[x+jump][y+jump];
            }
        }
    }

    return dp[sr][sc];

}

int minCost(int sr,int sc,int er,int ec,vector<vector<int>>& dp,vector<vector<int>>& costs)
{
    if(sr==er && sc==ec)
    {
        dp[sr][sc] = costs[sr][sc];
        return dp[sr][sc];
    }

    if(dp[sr][sc]!=0) return dp[sr][sc];
    int min_cost = INT_MAX;

    if(sr+1 <= er)
    {
        min_cost = min(min_cost,minCost(sr+1,sc,er,ec,dp,costs));
    }

    if(sc+1 <= ec)
    {
        min_cost = min(min_cost,minCost(sr,sc + 1,er,ec,dp,costs));
    }

    dp[sr][sc] = costs[sr][sc] + min_cost;

    return dp[sr][sc];

}


int main(){

    int n = 3;
    int m = 3;

    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout<<MazePathMulti_memo(0,0,n-1,m-1,dp)<<endl;
    // cout<calls<<endl;

    // cout<<MazePathMulti_tab(0,0,n-1,m-1)<<endl;

    // n = 4;
    // m = 4;
    // vector<vector<int>> dp(n,vector<int>(m,0));
    // vector<vector<int>> costs = {{2,3,0,4},{0,6,5,2},{8,0,3,7},{2,6,4,2}};
    // cout<<minCost(0,0,n-1,m-1,dp,costs)<<endl;



}