class Solution {
public:
    bool isPowerOfThree(int n) {
        long long  x=3;
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(x>=3){
            while(1){
                if(x==(long long)n){
                    return true;
                }
                if(x>n){
                    return false;
                }
                x=x*3;
            }
        }
        return false;
    }
};