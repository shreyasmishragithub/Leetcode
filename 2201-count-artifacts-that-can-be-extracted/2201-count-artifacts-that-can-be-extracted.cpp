class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& aa) {
        set<pair<int,int>>mp;
        for(auto &hr:aa){
            vector<int>v=hr;
            mp.insert({v[0],v[1]});
        }
        int cnt=0;
        for(auto it:a){
            vector<int>v=it;
            if(v[0]==v[2]&&v[1]==v[3]){
                if(mp.find({v[0],v[1]})!=mp.end()){
                    cnt++;  
                }
            }else if(v[0]!=v[2]&&v[1]!=v[3]){
                if(mp.find({v[0],v[1]})!=mp.end()&&mp.find({v[2],v[3]})!=mp.end()&&mp.find({v[0]+1,v[1]})!=mp.end()&&mp.find({v[0],v[1]+1})!=mp.end())
                {
                    cnt++;
                }         
            }else if(v[0]==v[2]&&v[1]!=v[3]){
                bool f=1;
                for(int i=v[1];i<=v[3];i++){
                    if(mp.find({v[0],i})==mp.end()){
                        f=0;break;
                    }
                }

                if(f==1){
                    cnt++;
                }
            }else if(v[0]!=v[2]&&v[1]==v[3]){
                bool f=1;
                for(int i=v[0];i<=v[2];i++){
                    if(mp.find({i,v[1]})==mp.end()){
                        f=0;break;
                    }
                }
                if(f==1){
                    cnt++;
                }
                
            }
        }
        
        return cnt;
    }
};