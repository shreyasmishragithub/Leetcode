class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(startValue<target){
            if(target%2==1){
                target=target+1;
            }else{
            target=target/2;
            }
            ans=ans+1;
        }
        return (startValue-target+ans);
    }
};