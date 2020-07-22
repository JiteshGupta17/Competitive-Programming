
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        multiset<int, greater<int>> left;
        multiset<int> right;

        auto bal = [&]()
        {
            if (right.size() > left.size())
            {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            else if (left.size() > 1 + right.size())
            {
                right.insert(*left.begin());
                left.erase(left.begin());
            }
        };

        left.insert(nums[0]);

        for (int i = 1; i < k; i++)
        {
            if (nums[i] >= *left.begin())
            {
                right.insert(nums[i]);
            }
            else {
                left.insert(nums[i]);
            }

            bal();
        }

        vector<double> ans(nums.size() - k + 1);
        int idx = 0;

        for (int i = k; i < nums.size(); i++)
        {
            if (left.size() == right.size())
            {
                ans[idx++] = ((long long) * left.begin() + *right.begin()) / 2.0;
            }
            else ans[idx++] = *left.begin();

            int prev_num = nums[i - k];
            auto it = left.find(prev_num);

            if (it != left.end())
            {
                // Present in left
                left.erase(it);
            }
            else {
                // Present in right
                right.erase(right.find(prev_num));
            }

            bal();

            if (nums[i] >= *left.begin())
            {
                right.insert(nums[i]);
            }
            else {

                left.insert(nums[i]);
            }

            bal();

        }

        if (left.size() == right.size())
        {
            ans[idx++] = ((long long) * left.begin() + *right.begin()) / 2.0;
        }
        else ans[idx++] = *left.begin();

        return ans;
    }
};