class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans = 0;

        for(char c : s) mp[c]++;

        for(auto it : mp) {
            ans += (it.second / 2) * 2;
            if(ans % 2 == 0 && it.second % 2 == 1)
                ans++;
        }

        return ans;
    }
};