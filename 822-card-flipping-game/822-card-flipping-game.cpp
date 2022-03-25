class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int>a;
        for(int i=0;i<backs.size();i++){
            if(fronts[i]==backs[i]){
                a.insert(fronts[i]);
            }
        }
        int ans=1000000000;;
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]!=backs[i]){
            if(a.find(fronts[i])==a.end()){
                ans=min(ans,fronts[i]);
            }
            }
            
        }
        
        for(int i=0;i<backs.size();i++){
            if(fronts[i]!=backs[i]){
            if(a.find(backs[i])==a.end()){
                ans=min(ans,backs[i]);
            }
            }
        }
        if(ans!=1000000000){
            return ans;
        }else{
            return 0;
        }
    }
};