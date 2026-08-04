class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n=nums[nums.size()-1];
        int j=0;
        for(int i=nums[0];i<n;i++){
            if(nums[j]!=i){
                    ans.push_back(i);
                    
            }else{
                j++;
            }
            
        }
        return ans;
    }
};