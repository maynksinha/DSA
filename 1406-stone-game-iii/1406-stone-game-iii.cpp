class Solution {
public:
    int n;
    int solve(int i , vector<int>& stone, vector<int>& dp){
        if(i>=n) return 0;
        int result = INT_MIN;

        if(dp[i]!=-1) return dp[i];

        result = max(result, stone[i] - solve(i+1, stone, dp));
        if(i+2 <= n){
            result = max(result, stone[i] + stone[i+1] - solve(i+2, stone, dp));
        }
        if(i+3 <=n ){
            result = max(result, stone[i] + stone[i+1] + stone[i+2] - solve(i+3, stone, dp));
        }
       
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stone) {
        n = stone.size();
        vector<int> dp(n + 1, -1);
        int diff = solve(0, stone, dp);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        else return "Tie";
        
    }
};