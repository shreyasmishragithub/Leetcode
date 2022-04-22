class Solution {
public:
    long long check(string texts,string pattern){
        long long  b=0;long long c=0;
        for(int i=0;i<texts.length();i++){
            if(texts[i]==pattern[1]){
                b++;
            }
        }
        if(pattern[0]==pattern[1]){
            return (long long)(b*(b-1))/(long long)2;
        }
        for(int i=0;i<texts.length();i++){
            if(texts[i]==pattern[1]){
                b--;continue;
            }
            if(texts[i]==pattern[0]){
                c=c+b;
            }
        }
        return c;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        int a,b;
        a=0;
        b=0;
        string text2=text;
        reverse(text2.begin(),text2.end());
        text2.push_back(pattern[0]);
        reverse(text2.begin(),text2.end());
        text.push_back(pattern[1]);
        return max(check(text,pattern),check(text2,pattern));
        
    }
};