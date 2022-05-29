typedef long double ld;
class Solution {
public:
	string discountPrices(string s, int discount) {
		vector<string>arr;
		for(int i=0;i<size(s);i++){
			if(s[i]=='$'){
				i++;
				string str;
				int l = 0;
				while(i<size(s) and !isspace(s[i])){
					if(s[i]=='$' or isalpha(s[i])) l++;
					str+=s[i++];
				}
				if(size(str) and !l){
					ld num = stold(str);
					num = num - (ld)(num*(ld)discount/100.00);
					string ans = to_string(num),k="$"; 
					for(int j=0;j<size(ans);j++){
						k.push_back(ans[j]);
						if(ans[j]=='.'){
							k.push_back(ans[j+1]);
							k.push_back(ans[j+2]);
							break;
						}
					}

					arr.push_back(k);
				}
				else {
					string k = "$";
					k+=str;
					arr.push_back(k);
				}
			}
			else{
				string str;
				while(i<size(s) and !isspace(s[i])) str+=s[i++];
				arr.push_back(str);
			}
		}
		string res;
		for(auto x:arr) res+=x,res.push_back(' ');
		res.pop_back();
		return res;
	}
};