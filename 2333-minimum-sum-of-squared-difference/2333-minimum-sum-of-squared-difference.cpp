class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        static int size = 1e5;
        int n = nums1.size();
        long long ans = 0;
        int totalk = k1+k2;

        vector<int> diffarr(size + 1, 0);

        for(int i = 0 ; i < n ; i++){
            int diff = abs(nums1[i] - nums2[i]);
            diffarr[diff]++;
        }

        for(int j = size ; j > 0 && totalk > 0; j--){
            int freq = min(diffarr[j] , totalk);
            diffarr[j]-=freq;
            diffarr[j-1]+=freq;
            totalk-=freq;
        }

            for(int k = 0; k < size + 1; k++){
                ans += (long long)diffarr[k] * k * k;
            }

            return ans;
    }
};