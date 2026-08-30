
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, vector<string>>hash;
		vector<vector<string>> result;
	
		vector<string> temp;
		
		for(int i=0;i<strs.size();i++){
			int count[26]={0};

		for(int x=0;x<strs[i].size();x++){
			count[strs[i][x]-'a']+=1;
		}

		string key;
		for(int x=0;x<26;x++){
			key+=count[x];
			key+="#";
		}
        

		hash[key].push_back(strs[i]);
		

		}     
        for(auto fst=hash.begin();fst!=hash.end();fst++){
			result.push_back(fst->second);
		}   
		return result;
	}
};
