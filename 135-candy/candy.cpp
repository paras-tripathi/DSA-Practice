class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),ans=0;
        if(n<=1)return n;
        vector<int> num(n,1);
        for(int i=1;i<n; i++){
            if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]) num[i-1]=max(num[i]+1,num[i-1]);
            ans+=num[i];
        }
        return ans+num[0];
    }
};