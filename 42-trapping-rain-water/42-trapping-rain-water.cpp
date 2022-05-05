class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>a;
        a=height;
        int i=1;
        int sum=0;
        vector<int>left,right(n);
        int mx=INT_MIN;
        for(auto x:a)
        {
            mx=max(mx,x);
            left.push_back(mx);
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,a[i]);
            right[i]=mx;
        }
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            long long maxhold=0;
            long long x=min(left[i-1],right[i+1]);
            maxhold=max(0ll,x-height[i]);
            ans=ans+maxhold;
        }
        return ans;
    }
};