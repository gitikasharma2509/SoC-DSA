class Solution {
public:
    bool check(string s,string c){ 
        for(auto a : s){
            if(find(c.begin(),c.end(),a)==c.end()){
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        for(auto s: words){
            string l=s;
            transform(l.begin(),l.end(),l.begin(),::tolower);

            if(check(l,"qwertyuiop") or 
               check(l,"asdfghjkl") or 
               check(l,"zxcvbnm")) ans.push_back(s);
        }
        return ans;
    }
};