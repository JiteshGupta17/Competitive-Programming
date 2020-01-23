#include<bits/stdc++.h>
using namespace std;

int calls = 0;
int minJumps_memo(int src, int dest, vector<int> arr, vector<int>& dp)
{
    if (src == dest)
    {
        dp[dest] = 0;
        return 0;
    }

    // calls++; //Without dp

    if (dp[src] != -1) return dp[src];

    int curEle = arr[src];

    // calls++; // With dp

    if (curEle == 0) {
        dp[src] = INT_MAX / 2;
        return dp[src];
    }

    int count = INT_MAX / 2;
    for (int i = 1; i <= curEle; i++)
    {
        if (i + src <= dest)
            count = min(count, 1 + minJumps_memo(src + i, dest, arr, dp));
    }

    dp[src] = count;
    return count;
}

int minJumps_tab(int src, int dest, vector<int> arr)
{
    int dp[dest + 1] = {0};

    //Start from 2nd last element
    for (int i = arr.size() - 2;i >= 0; i--)
    {
        int min_ans = INT_MAX / 2;

        for (int j = i + 1; j <= arr.size() - 1 && j <= i + arr[i]; j++)
        {
            min_ans = min(min_ans, dp[j]);
        }

        dp[i] = 1 + min_ans;
    }

    for (int i = 0; i <= dest; i++)
        cout << dp[i] << " ";
    cout << endl;

    return dp[src];
}

int SinglePairCount(int n)
{
    int dp[n + 1] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] * (i - 1);
    }

    for (int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;

    return dp[n];

}

int N_Ksets(int n,int k)
{
    int dp[n+1][k+1] = {0};

    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=k;j++)
        {
            if(i<j || j==0 || i==0){ // n less than sets or no set is present or no student is present
                dp[i][j] = 0;
                continue;
            }
            
            if(j==1 || i==j){ // when only one set or  n equal to number of sets 
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
        }
    }

    return dp[n][k];
}

int main() {

    // vector<int> arr = {1,3,0,4,0,0,2,1,1,0};

    // vector<int> dp(10,-1);
    // cout<<minJumps_memo(0,9,arr,dp)<<endl;

    // cout<<minJumps_tab(0,9,arr);

    // cout << SinglePairCount(5);

    cout<<N_Ksets(5,2);


}