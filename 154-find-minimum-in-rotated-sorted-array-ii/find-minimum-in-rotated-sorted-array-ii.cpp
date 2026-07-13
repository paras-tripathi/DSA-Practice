class Solution { 
public:
    int findMin(vector<int>& nums) {
        int minimumvalue = INT_MAX; 
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minimumvalue){ 
                minimumvalue = nums[i]; 
            }
        }
        return minimumvalue;
    }
};