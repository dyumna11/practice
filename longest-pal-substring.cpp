class Solution {
  public:


    string getLongestPal(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    int mx = 1, start = 0;

    for(int i = n - 1; i >= 0; i--) {//necessary to compute from here
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                if(j - i <= 2)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];//here otherwise direction will be violated
            }

            if(dp[i][j] && mx < j - i + 1) {
                mx = j - i + 1;
                start = i;
            }
        }
    }

    return s.substr(start, mx);
}
    }
};
