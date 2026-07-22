class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        s = "1" + s + "1";

        vector<int> zeronum;
        int cnt = 0;
        int activecnt = count(s.begin() + 1, s.end() - 1, '1');

        int i = 0;
        while (i < s.length()) {
            if (s[i] == '0') {
                cnt++;
            } else {
                if (cnt > 0) {
                    zeronum.push_back(cnt);
                    cnt = 0;
                }
            }
            i++;
        }

        if (cnt > 0)
            zeronum.push_back(cnt);

        int maxi = 0;

        for (int i = 1; i < zeronum.size(); i++) {
            maxi = max(maxi, zeronum[i - 1] + zeronum[i]);
        }

        return activecnt + maxi;
    }
};