class Solution {
public:
    int secondHighest(string s) {
        sort(s.begin(), s.end());
        int i = 0;
        while (i < s.size() && isdigit(s[i])) {
            i++;
        }
        for (int k = i - 1; k >= 0; k--) {
            if (s[k] - '0' != s[i - 1] - '0') {
                return s[k] - '0';
            }
        }
        return -1;
    }
};