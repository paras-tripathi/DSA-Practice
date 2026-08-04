class Solution {
public:
    int secondHighest(string s) {
        string alpha="abcdefghijklmnopqrstuvwxyz";
        int max1=-1, max2=-1;
        for(char i:s){
            if(!alpha.contains(i)){
                int digit = i-'0';
                if(digit>max1){
                    max2=max1;
                    max1=digit;
                }
                else if(digit>max2 && digit<max1) max2=digit;
            }
        }
        return max2;
    }
};  