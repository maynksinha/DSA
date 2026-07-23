class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        long long currSum = 0;
        long long ans = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            currSum += nums[right];
            freq[nums[right]]++;

            // Shrink window if size > k
            if (right - left + 1 > k) {

                currSum -= nums[left];

                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }

            // Check valid window
            if (right - left + 1 == k && freq.size() == k) {
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};