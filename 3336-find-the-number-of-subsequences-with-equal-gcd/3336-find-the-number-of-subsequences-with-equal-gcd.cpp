class Solution {
public:
 const int MOD = 1000000007;
    int solve(vector<vector<vector<int>>>& dp, vector<int>& nums, int i , int first, int second){
        // base case 
        if(i == nums.size()){
            bool nonEmpty = (first!=0 && second!=0);
            bool gcdequal = (first == second);

            return nonEmpty && gcdequal ? 1 : 0;
        }
        if( dp[i][first][second] != -1){
            return dp[i][first][second];
        }

        int skip = solve(dp,nums, i+1, first, second);
        int take1 = solve(dp,nums, i+1, __gcd(first, nums[i]), second);
        int take2 = solve(dp,nums, i+1, first,__gcd(second, nums[i]));

        return dp[i][first][second] = (0LL+skip+take1+take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        // vector<vector<vector<int>>> dp(n, vector<int>(201,vector<int>(201,-1)));
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(201, vector<int>(201, -1)));
        return solve(dp, nums,0,0,0);
        
    }
};