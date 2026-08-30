
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, int>hash;
		vector<vector<string>> result;
		vector<string> temp;

		for(int i;i<strs.size();i++){

			string word=strs[i];
			sort(word.begin(),word.end());
			
			if(hash.contains(word)){
				result[hash[word]].push_back(strs[i]);
			}else{
				temp.push_back(strs[i]);
				result.push_back(temp);
				hash[word]=result.size()-1;
                temp.clear();
			}
		}        
		return result;
    }
};
