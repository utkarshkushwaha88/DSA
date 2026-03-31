class Solution {
  public:
    string reverseWords(string &s) {
        string ans = "";
        string temp = "";
        
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '.') {
                if(!temp.empty()) {   // ✅ important fix
                    reverse(temp.begin(), temp.end());
                    
                    if(!ans.empty()) ans.push_back('.'); // avoid leading dot
                    
                    ans += temp;
                    temp = "";
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }
        
        // last word
        if(!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if(!ans.empty()) ans.push_back('.');
            ans += temp;
        }
        
        return ans;
    }
};