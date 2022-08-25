class Solution {
public:
    bool canConstruct(string ransomeNote, string magzine) {
        sort(ransomeNote.begin(),ransomeNote.end());
        sort(magzine.begin(),magzine.end());
        int cnt=0;
        for(int i=0;i<magzine.size();i++){
            if(ransomeNote[cnt]==magzine[i]){
                cnt++;
            }
        }
        if(cnt>=ransomeNote.length())return true;
        return false;
    }
};