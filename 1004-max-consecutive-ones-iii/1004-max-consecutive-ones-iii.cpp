class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int zeros = 0;
        int n = nums.size();
        int i = 0, j = 0;

        while (i < n) {
            // Expand the window
            if (nums[i] == 0) {
                zeros++;
            }

            // If the number of zeros exceeds k, shrink the window from the left
            while (zeros > k) {
                if (nums[j] == 0) {
                    zeros--;
                }
                j++;
            }

            // Calculate the maximum length
            maxlen = max(maxlen, i - j + 1);
            i++;  // Move to the next element
        }

        return maxlen;
    }
};
