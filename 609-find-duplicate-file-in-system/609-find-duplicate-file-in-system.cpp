class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        /*Wayyyyyy too confusing still TC-(paths.length * (paths[i].length)) */
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<paths.size(); i++){
            string temp= paths[i],path="";
            int n=temp.size();
            for(int j=0; j<n; j++){
                if(temp[j]!=' '){
                    path.push_back(temp[j]);
                }
                else {
                    fornext:
                    j++;
                    string name="";
                    for(; j<n; j++){
                        if(temp[j]!='('){
                            name+= temp[j];
                        }else{
                            j++;
                            string content="";
                            for(; j<n; j++){
                                if(temp[j]!=')'){
                                    content+= temp[j];
                                }else{
                                    mp[content].push_back(path+"/"+name);
                                    j++;
                                    goto fornext;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(auto i: mp){
            if(i.second.size()>1)
            ans.push_back(i.second);
        }
        return ans;
    }
};