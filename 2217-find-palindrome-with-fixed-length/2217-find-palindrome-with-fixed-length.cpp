class Solution {
public:
    set<string>s;
    void go(int x,int n,string str,int idx,char previous){
        if(idx==x&&str.length()==x){
            if(n%2==1){
                string tmp;
                tmp=str;
                reverse(tmp.begin(),tmp.end());
                for(char i='0';i<='9';i++){
                    s.insert(str+i+tmp);
                    s.insert(tmp+i+str);
                }
            }
            
            if(n%2==0){
                string tmp;
                tmp=str;
                reverse(tmp.begin(),tmp.end());
                    s.insert(str+tmp);
                    s.insert(tmp+str);
            }
        return ;
        }
        for(char i='0';i<='9';i++){
            char current=i;
            if(current>=previous){
                go(x,n,str+current,idx+1,current);
            }
            go(x,n,str,idx+1,current);
        }
        
    }
    #define ll long long
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> result;
        ll start = intLength % 2 == 0 ? pow(10, intLength/2 - 1) : pow(10, intLength/2);
        for(int q: queries) { 
            string s = to_string(start + q - 1);
            string palindrome = s;
            reverse(s.begin(), s.end());
            if(intLength % 2 == 0) {
                palindrome += s;
            } else {
                palindrome += s.substr(1, s.size() - 1);
            }
			
            if (palindrome.size() == intLength)
                result.push_back(stoll(palindrome));
            else
                result.push_back(-1);
        }
        
        return result;
    }
};