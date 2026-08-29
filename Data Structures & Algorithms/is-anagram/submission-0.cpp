

class Solution {
public:
    bool isAnagram(string s, string t) {
		unordered_map<char, int> shash;
		unordered_map<char, int> thash;
		if (s.length()!=t.length()){
			return false;	
		}
		for(int x=0;x<s.length();x++){
			shash[s[x]]+=1;
		}
		for(int x=0;x<t.length();x++){
			thash[t[x]]+=1;
		}
		for(int x=0;x<t.length();x++){
			if(shash[s[x]]!=thash[s[x]]){
			return false;
			};
		}
return true;
    }
};
