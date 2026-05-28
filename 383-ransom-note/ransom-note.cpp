class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> rsm;
        unordered_map<char,int> mag;

        for(char c : ransomNote){
            rsm[c]++;
        }
        for(char c : magazine){
            mag[c]++;
        }

        for(auto it : rsm){
            if(mag[it.first] < it.second){
                return false;
            }
        }

        return true;
    }
};