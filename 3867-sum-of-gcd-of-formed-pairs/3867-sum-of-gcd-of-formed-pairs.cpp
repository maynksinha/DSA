class Solution {
public:
    long long gcdSum(vector<int>& nums) {
    vector<int> prefixGcd;
    int maxi = 0;
    for(int i = 0 ; i < nums.size(); i++){
        maxi = max(maxi,nums[i]);
        prefixGcd.push_back(__gcd(nums[i], maxi));
    }

    sort(prefixGcd.begin(), prefixGcd.end());
    int i = 0 ; 
    int j = prefixGcd.size()-1;
    long long ans = 0;

    while(i<j){
        ans += __gcd(prefixGcd[i],prefixGcd[j]);
        i++;
        j--;
    }

        return ans;
   
        
    }
};