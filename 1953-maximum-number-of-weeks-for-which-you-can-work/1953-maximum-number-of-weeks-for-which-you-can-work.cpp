class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
    long long mx_element=0;
        long long sum=0;
        for(int i=0;i<m.size();i++)
        {
            sum+=m[i];
            mx_element=max(mx_element,m[i]*1ll);
        }
        
        long long remaining_sum = (sum-mx_element);
        
        if(remaining_sum<=mx_element-1) 
        {
            return 1ll*(2*remaining_sum+1);
        }
        else  // all projects are possible
        {
            return sum;
        }
    }
};