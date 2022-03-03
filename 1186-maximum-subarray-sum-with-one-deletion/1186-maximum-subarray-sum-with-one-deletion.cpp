class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int>l(arr.size()),r(arr.size());
        int mxsofar=arr[0];int mx=arr[0];
        l[0]=arr[0];
        
        for(int i=1;i<arr.size();i++){
            mx=max(arr[i],mx+arr[i]);
            l[i]=mx;
            mxsofar=max(mx,mxsofar);
        }
        r[arr.size()-1]=arr[arr.size() -1];
        ;mx=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            mx=max(mx+arr[i],arr[i]+0);
            r[i]=mx;
        }
        int ans=INT_MIN;
        ans=mxsofar;
        for(int i=1;i<arr.size()-1;i++){
            ans=max(ans,l[i-1]+r[i+1]);
        }
    return ans;}
};