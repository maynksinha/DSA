class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int ans = 0;
        vector<int> arr;

        for(int i = 0 ; i <s.length();i++ ){
            int num = s[i] - '0';
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end(), std::greater<int>());

        return arr[0]*arr[1];
        
    }
};