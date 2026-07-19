class Solution {
public:
    string removeDuplicateLetters(string s) {

        int visitedarr[26] = {0};
        int lastindex[26];

        for(int i = 0; i < s.length(); i++) {
            lastindex[s[i] - 'a'] = i;
        }

        string result = "";

        for(int i = 0; i < s.length(); i++) {

            int index = s[i] - 'a';

            if(visitedarr[index])
                continue;

            while(!result.empty() &&
                  result.back() > s[i] &&
                  lastindex[result.back() - 'a'] > i)
            {
                visitedarr[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s[i]);
            visitedarr[index] = 1;
        }

        return result;
    }
};