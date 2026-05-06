class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        // Check if the array is non-decreasing
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                cnt++;
        
        // Check if the last element is greater than the first element
        if (nums[n - 1] > nums[0])
            cnt++;
        
        // If the count of violations is less than or equal to 1, return true
        return cnt <= 1;
        
    }
};