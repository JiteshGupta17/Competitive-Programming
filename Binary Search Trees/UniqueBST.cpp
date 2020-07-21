/*
Hope it will help you to understand :

    n = 0;     null

    count[0] = 1


    n = 1;      1

    count[1] = 1


    n = 2;    1__                    __2
                  \                 /
                 count[1]       count[1]

    count[2] = 1 + 1 = 2



    n = 3;    1__                     __2__                    __3
                  \                 /       \                 /
              count[2]        count[1]    count[1]      count[2]

    count[3] = 2 + 1 + 2  = 5



    n = 4;    1__                   __2__                      ___3___
                  \              /        \                   /       \
              count[3]       count[1]    count[2]         count[2]   count[1]

                 __4
               /
           count[3]

    count[4] = 5 + 2 + 2 + 5 = 14


And  so on...
*/

class Solution {
public:
    int numTrees(int n) {

        // Using DP
        // f(n) = sum f(i-1)*f(n-i) for i in 1 to n
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];

        // Catalan number series
        //C(2n,n)/(n+1)
        long long ans = 1;
        for (int i = n + 1; i <= 2 * n; i++) {
            ans = ans * i / (i - n);
        }
        return ans / (n + 1);

    }
};

// To generate all trees recursive solution
class Solution {
public:

    vector<TreeNode*> solve(int start, int end)
    {
        if (start > end) {
            return {NULL};
        }

        vector<TreeNode*> ans;

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;

                    ans.push_back(cur);
                }
            }

        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};