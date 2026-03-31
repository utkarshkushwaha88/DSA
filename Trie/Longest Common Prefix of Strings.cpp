                            //Time Complexity:O(NxM)
                            //Space Complexity:O(1)
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        if(arr.size()==0){
            return "";
        }
       string ans="";
        for(int i=0;i<arr[0].size();i++){
            char ch=arr[0][i];
            for(int j=1;j<arr.size();j++){
                if(i>=arr[j].size() || arr[j][i]!=ch){
                    return ans;
                }
            }
                ans.push_back(ch);
        }
        return ans;
    }
};



                            //By sorting  approch


// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        
        int n = arr.size();
        
        // sort the array
        sort(arr.begin(), arr.end());
        
        string first = arr[0];
        string last = arr[n-1];
        
        string ans = "";
        
        int len = min(first.size(), last.size());
        
        for(int i = 0; i < len; i++){
            if(first[i] == last[i]){
                ans.push_back(first[i]);
            }
            else{
                break;
            }
        }
        
        if(ans == "") return "-1";   // for GFG requirement
        
        return ans;
    }
};


                        //Using Trie


// User function template for C++

class TrieNode{
public:
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insertUtil(TrieNode* node,string &word,int i){

        if(i==word.size()){
            node->isTerminal=true;
            return;
        }

        int index=word[i]-'a';
        TrieNode* child;

        if(node->children[index]!=NULL){
            child=node->children[index];
        }
        else{
            child=new TrieNode();
            node->children[index]=child;
            node->childCount++;
        }

        insertUtil(child,word,i+1);
    }

    void insertWord(string &word){
        insertUtil(root,word,0);
    }

    string getLCP(string &first){

        string ans="";
        TrieNode* temp=root;

        for(int i=0;i<first.size();i++){

            if(temp->childCount==1 && !temp->isTerminal){
                ans.push_back(first[i]);
                int index=first[i]-'a';
                temp=temp->children[index];
            }
            else{
                break;
            }
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> arr) {

        int n=arr.size();

        if(n==0) return "";

        // Early check (prevents huge Trie creation)
        char ch=arr[0][0];
        for(int i=1;i<n;i++){
            if(arr[i][0]!=ch){
                return "";
            }
        }

        Trie t;

        for(int i=0;i<n;i++){
            t.insertWord(arr[i]);
        }

        string first=arr[0];

        return t.getLCP(first);
    }
};