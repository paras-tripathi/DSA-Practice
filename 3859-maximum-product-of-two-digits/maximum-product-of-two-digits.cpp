class Solution {
public:
    int maxProduct(int n) {
        int max=INT_MIN;
        int smax=INT_MIN;
        while(n){
            int r=n%10;
            if(r>max){
                smax=max;
                max=r;
            } else if(r>smax){
                smax=r;
            }
            n=n/10;
        }
        return max*smax;
    }
};