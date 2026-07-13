class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = string(s.rbegin(), s.rend());
        string candidate = s + "#" + rev;

        int n = candidate.size();
        vector<int> fail(n, 0);
        for (int i = 1; i < n; i++) {
            int j = fail[i - 1];
            while (j > 0 && candidate[i] != candidate[j])
                j = fail[j - 1];
            if (candidate[i] == candidate[j]) j++;
            fail[i] = j;
        }
        int palLen = fail.back();
        string suffix = s.substr(palLen); 
        string toAdd = string(suffix.rbegin(), suffix.rend());
        return toAdd + s;
    }
};