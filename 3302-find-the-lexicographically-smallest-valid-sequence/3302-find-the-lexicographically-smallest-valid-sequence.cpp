class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // suffix[i] =
        // number of characters from the end of word2
        // that can be matched exactly using word1[i...]
        vector<int> suffix(n + 1, 0);

        int j = m - 1;

        // Build suffix information from right to left
        for (int i = n - 1; i >= 0; i--) {

            suffix[i] = suffix[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suffix[i]++;
                j--;
            }
        }

        vector<int> ans;

        int i = 0;
        j = 0;

        bool changed = false;

        while (i < n && j < m) {

            // Current characters match
            if (word1[i] == word2[j]) {

                ans.push_back(i);

                i++;
                j++;
            }

            // Current characters don't match
            else {

                int remaining = m - j - 1;

                // Use the one allowed modification
                // if the remaining suffix can be
                // matched exactly.
                if (!changed && suffix[i + 1] >= remaining) {

                    ans.push_back(i);

                    changed = true;

                    i++;
                    j++;
                }
                else {
                    // Current index cannot be used
                    i++;
                }
            }
        }

        if (ans.size() == m) {
            return ans;
        }

        return {};
    }
};