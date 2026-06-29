class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int p:nums){
            if(!mp.count(p+1) && !mp.count(p-1)&& mp[p]==1){
                ans.push_back(p);
            }
        }
        return ans;
    }
};