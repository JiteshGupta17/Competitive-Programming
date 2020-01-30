#include<bits/stdc++.h>
using namespace std;

int DistinctSubseq(string str, int n, vector<int>& lastIdx)
{
	if (n < 0) return 1;

	int ans = DistinctSubseq(str, n - 1, lastIdx);
	ans *= 2;

	int ch = str[n] - 'a';

	// n > lastidx[ch] , this condition because of recursion
	// in case of second b, call goes to first 'a' and lastidx of 'a' was updated
	// by 2nd 'a' to 2 which should not effect the prev 'a'
	if (lastIdx[ch] != -1 && n > lastIdx[ch])
	{
		int prev_idx = lastIdx[ch] - 1;
		ans -= DistinctSubseq(str, prev_idx, lastIdx);
	}

	lastIdx[ch] = n;

	return ans;
}

int DistinctSubseq_DP(string str)
{

	str  = "$" + str; // For proper indexing

	vector<int> lastIdx(26, -1);
	vector<int> dp(str.length(), 0);

	dp[0] = 1;

	for (int i = 1; i < str.length(); i++)
	{
		dp[i] = 2 * dp[i - 1];

		int ch = str[i] - 'a';
		if (lastIdx[ch] != -1)
		{
			int prev_idx = lastIdx[ch] - 1;
			dp[i] -= dp[prev_idx];
		}

		lastIdx[ch] = i;
	}

	for (int ele : dp) cout << ele << " ";
	cout << endl;

	return dp[str.length() - 1];
}

// =============================================================================================

int CountSubseq(string str)
{
	vector<int> dp(26, 0); // Actual size will be no of distint char in str

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a')
		{
			dp[0] = 1 + 2 * dp[0];
		}
		else {
			int ch = str[i] - 'a';
			dp[ch] = dp[ch - 1] + 2 * dp[ch];
		}
	}

	return dp[2]; //Corresponding to c
}

// ======================================================================================================

int LIS_recur(vector<int> seq,int i,int prev)
{
    if(i==seq.size()) return 0;
    int taken = 0;
    if(seq[i] > prev)
    {
        taken = 1 + LIS_recur(seq,i+1,seq[i]);
    }

    int not_taken = LIS_recur(seq,i+1,prev);

    return max(taken,not_taken);
}

int LIS(vector<int> seq)
{
    if(seq.size()==0) return 0;
	vector<int> dp(seq.size(), 1);
	int ans = 1;

	for (int i = 1; i < seq.size(); i++)
	{
		int cur = 0;
		for (int j = 0; j <= i - 1; j++)
		{
			if (seq[j] < seq[i])
			{
				cur = max(cur, dp[j]);
			}
		}
		dp[i] += cur;
		ans = max(ans, dp[i]);
	}

	for (int ele : dp) cout << ele << " ";
	cout << endl;

	return ans;
}

int LIS_NlogN(vector<int> seq)
{
    if(seq.size()==0) return 0;
    
    vector<int> list;
    list.push_back(seq[0]);
    int len = 1;

    for(int i = 1;i<seq.size();i++)
    {
        if(seq[i] > list[len-1])
        {
            list.push_back(seq[i]);
            len++;
        }
        else{
            int l = 0, r = len-1;

            while(l < r)
            {
                int mid = (l + r) / 2;
                if (list[mid] < seq[i])
                    l = mid + 1;
                else
                    r = mid;
            }
            list[r] = seq[i];
        }
    }
    return len;
}

int main()
{
	/*Ques.1 -> No of distinct subsequences*/
	// vector<int> lastIdx(26, -1);
	// cout << DistinctSubseq("ababc", 4, lastIdx) << endl;
	// cout << DistinctSubseq_DP("ababc") << endl;

	/*Ques.2 -> Possible forms a^ib^j... i,j>0
	https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/*/
	// cout << CountSubseq("ababc");

	/*Ques.3 -> Longest Increasing Subseq LIS */
	vector<int> seq = {1, 3, 6, 7, 9, 4, 10, 5, 6};

    // cout << LIS_recur(seq,0,-1000000) << endl;
	// cout << LIS(seq) << endl; //O(n^2)
    cout << LIS_NlogN(seq);




}