class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int i;
        unordered_map<char,int> map;
        for(i=0;i<n;i++){
            map[s[i]]++;
        }
        for(i=0; i<n; i++){
            if(map[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};