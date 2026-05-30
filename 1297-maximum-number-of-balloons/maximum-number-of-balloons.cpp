class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int> txt;
        unordered_map<char,int> bln;

        string bal = "balloon";

        for(char c : text){
            txt[c]++;
        }

        for(char c : bal){
            bln[c]++;
        }

        int ans = INT_MAX;

        for(auto it : bln){
            ans = min(ans, txt[it.first] / it.second);
        }

        return ans;
    }
};