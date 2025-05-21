class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> results;

        unordered_map<string,vector<string>> mp;

        int n = strs.size();

        for(int i = 0 ; i < n ;i++){
            string s = strs[i];

            sort(s.begin(),s.end());

            mp[s].push_back(strs[i]);

        }

        for(auto it : mp){
            results.push_back(it.second);
        }

        return results;

        
    }
};