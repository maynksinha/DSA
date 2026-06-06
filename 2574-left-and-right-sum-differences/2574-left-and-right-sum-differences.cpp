class Solution {
public:
    int sum(vector<int> nums, int flag, int i) {
        int sum = 0;

        if(flag == 0) {
            for(int j = 0; j < i; j++) {
                sum += nums[j];
            }
        }
        else {
            for(int j = nums.size() - 1; j > i; j--) {
                sum += nums[j];
            }
        }

        return sum;
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int leftsum = sum(nums, 0, i);
            int rightsum = sum(nums, 1, i);

            ans.push_back(abs(leftsum - rightsum));
        }

        return ans;
    }
};