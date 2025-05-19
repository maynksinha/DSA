class Solution {
public:
    bool isTriangle(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0] + nums[1] > nums[2];
    }

    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (!isTriangle(nums)) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }
        else {
            return "scalene";
        }
    }
};
