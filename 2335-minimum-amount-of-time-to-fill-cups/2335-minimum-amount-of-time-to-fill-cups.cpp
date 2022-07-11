class Solution {
public:
    int fillCups(vector<int>& a)
    {
        sort(a.begin(),a.end(),greater<int>());
        int count=0;
        while(a[0]>0)
        {
            a[0]--;
            a[1]--;
            count++;
            sort(a.begin(),a.end(),greater<int>());
        }
        return count;
    }
};