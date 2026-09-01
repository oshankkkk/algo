
class Solution {
public:
    bool isAnagram(string s, string t) {
		unordered_map<char, int> shash;
		unordered_map<char, int> thash;
		if (s.length()!=t.length()){
			return false;	
		}
		std::sort(s.begin(),s.end());	
		std::sort(t.begin(),t.end());	
		for(int x=0;x<t.length();x++){
			if(s[x]!=t[x]){
			return false;
			};
		}
return true;
    }
};