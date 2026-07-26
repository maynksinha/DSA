class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int n = nums.size();

        vector<int> negative;
        vector<int> positive;

        sort(nums.begin(), nums.end());

        for (int x : nums) {
            if (x < 0)
                negative.push_back(x);
            else
                positive.push_back(x);
        }

        if (positive.size() == 0) {
            return negative[negative.size() - 1] *
                   negative[negative.size() - 2] *
                   negative[negative.size() - 3];
        }

        if (negative.size() == 0) {
            return positive[positive.size() - 1] *
                   positive[positive.size() - 2] *
                   positive[positive.size() - 3];
        }

        int option1 = INT_MIN;
        int option2 = INT_MIN;

        if (negative.size() >= 2 && positive.size() >= 1) {
            option1 = negative[0] * negative[1] * positive.back();
        }

  
        if (positive.size() >= 3) {
            option2 = positive[positive.size() - 1] *
                      positive[positive.size() - 2] *
                      positive[positive.size() - 3];
        }

        return max(option1, option2);
    }
};