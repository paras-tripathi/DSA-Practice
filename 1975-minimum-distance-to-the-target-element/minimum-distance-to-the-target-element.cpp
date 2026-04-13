class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n= nums.size();
        int res = INT_MAX;
        for(int i=start;i<n;i++){
            if(nums[i]==target && abs(i-start)<res){
                res= abs(i-start);
            }
        }
        for(int i=0;i<=start;i++){
            if(nums[i]==target && abs(i-start)<res){
                res= abs(i-start);
            }
        }
        return res;
    }
};