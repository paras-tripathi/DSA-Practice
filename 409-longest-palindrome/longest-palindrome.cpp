class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> val;
        for(char i: s){
            val[i]++;
        }
        int res = 0;
        bool odd = false;
        for(auto it : val){
            if(it.second%2==0){
                res=res+it.second;
            }
            else {
                res=res+it.second-1;
                odd = true;
            }
        }
        if(odd==true){
            return res+1;
        } else return res;
    }

};