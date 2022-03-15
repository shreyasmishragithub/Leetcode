class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>sto;
        stack<pair<char,int>>stc;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                sto.push({'(',i});
            }
            if(s[i]==')'){
                if(sto.size()>0){
                    sto.pop();
                }else{
                stc.push({')',i});
                }
            }
            
        }
        vector<int>idxx;
while(sto.size()){
    idxx.push_back(sto.top().second);
    sto.pop();
}
        
while(stc.size()){
    idxx.push_back(stc.top().second);
    stc.pop();
}
        sort(idxx.begin(),idxx.end());
        string temp="";
        for(int i=n-1;i>=0;i--){
            if(idxx.size()>0){
                if(i==idxx.back()){
                    idxx.pop_back();continue;
                }
            }
            temp.push_back(s[i]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};