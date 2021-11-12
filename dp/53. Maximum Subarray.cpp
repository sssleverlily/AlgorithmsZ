class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = 0;
        int length = nums.size();
        vector<int> dp(length);
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < length; i++)
        {
            //转移方程
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};