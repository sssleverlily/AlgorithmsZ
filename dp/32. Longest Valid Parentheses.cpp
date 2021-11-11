class Solution {
public:
/**
初始是‘’
f_next = 
**/
    int longestValidParentheses(string s) {
        int length = s.size();
        int result = 0;
        int dp[length];
        for(int i = 0;i<length;i++) dp[i] = 0;
        int j =  0;
        for(int i = 0;i<length;i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = dp[i-2]+2; //如果左右匹配了，那么直接ok
                }
                else{//s[i-1]是右括号
                     j = i - 1 - dp[i - 1];
                    if (j >= 0 and s[j] == '('){
                        dp[i] = dp[j - 1] + dp[i - 1] + 2;
                    }
                }
            }
            result = max(result,dp[i]);
        }
        return result;
    }
};
/**
 * 但上面这个没有A
 * 下面这个是对的
 **/
 int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                int j = i - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(') 
                    dp[i] = (i - j + 1) + ((j - 1) >= 0 ? dp[j - 1] : 0);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
