class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<set<char>>vs;
        for(int i=0;i<words.size();i++){
            set<char>s(words[i].begin(),words[i].end());
            vs.push_back(s);
        }
        for(int i=0;i<words.size()-1;i++){
            int n=words[i].length();
            for(int j=i+1;j<words.size();j++){
                int m=words[j].length();
                bool f=true;
                for(auto x:vs[i]){
                    if(vs[j].find(x)!=vs[j].end()){
                        f=false;
                        break;
                    } 
                }
                if(f) ans=max(ans,n*m);
            }
        }
        return ans;
    }
};