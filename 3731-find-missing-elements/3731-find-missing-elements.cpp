class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> compare;
        vector<int> ans;

        for (int i = nums.front(); i <= nums.back(); i++) {
            compare.push_back(i);
        }

        int i = 0;
        int j = 0;

        while (i < nums.size() && j < compare.size()) {

            if (nums[i] == compare[j]) {
                i++;
                j++;
            } else {
                ans.push_back(compare[j]);
                j++;
            }
        }

        while (j < compare.size()) {
            ans.push_back(compare[j]);
            j++;
        }

        return ans;
    }
};