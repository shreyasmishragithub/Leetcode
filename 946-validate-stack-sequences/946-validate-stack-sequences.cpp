class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>a;
        reverse(pushed.begin(),pushed.end());
        reverse(popped.begin(),popped.end());
        int f=0;
        while(pushed.size()>0||popped.size()>0){
            
            if(popped.size()>0){
                if(a.size()>0){
                if(a.top()==popped.back()){
                    a.pop();
                    popped.pop_back();
                    continue;
                
                }
                }
            }
            if(pushed.size()>0){
                a.push(pushed.back());
                pushed.pop_back();
            }
            if(pushed.size()==0){
                if(f==1){
                    return false;
                }
                f++;
            }
            
        }
        if(pushed.size()==0&&popped.size()==0){
            return true;
        }
        return false;;
    }
};