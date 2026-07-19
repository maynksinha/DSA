class Solution {
public:
    string smallestSubsequence(string s) {
         vector<int> lastIndex(26);
        vector<bool> visited(26, false);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (visited[ch - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > ch &&
                   lastIndex[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};