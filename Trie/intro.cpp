#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            this->data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode('\0');

        }
        void insertUtil(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                root->isTerminal=true;
                return ;
            }
            int index=word[0]-'A';
            TrieNode* child;
            //present
            if(root->children[index]!=NULL){
                child=root->children[index]; 
            }
            //absent
            else{
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }
            insertUtil(child,word.substr(1));
        }
        void insertWord(string word){
            insertUtil(root,word);
        }
        bool searchUtil(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                return root->isTerminal;
            }
            int index=word[0]-'A';
            TrieNode* child;
            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            //absent
            else{
                return false;
            }
            return searchUtil(child,word.substr(1));
        }
        bool searchWord(string word){
            return searchUtil(root,word);
        }
       bool isEmpty(TrieNode* root){
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            return false;
        }
    }
    return true;
}

bool deleteUtil(TrieNode* root, string &word, int depth){
    
    if(root==NULL){
        return false;
    }

    // reached last character
    if(depth==word.length()){
        if(root->isTerminal){
            root->isTerminal=false;
        }

        // if node has no children delete it
        return isEmpty(root);
    }

    int index = word[depth]-'A';

    if(deleteUtil(root->children[index], word, depth+1)){
        
        delete root->children[index];
        root->children[index] = NULL;

        return (!root->isTerminal && isEmpty(root));
    }

    return false;
}

void deleteWord(string word){
    deleteUtil(root, word, 0);
}
};

int main() {
    Trie* t=new Trie;
    t->insertWord("AMCD");
    t->insertWord("ABCD");
    t->insertWord("AMHD");
    t->insertWord("BMCD");
    cout<<"present or not "<<t->searchWord("AMCD")<<endl;
    cout<<"present or not "<<t->searchWord("ACD")<<endl;
    t->deleteWord("AMCD");
    cout<<"AMCD is present or not "<<t->searchWord("AMCD")<<endl;

return 0;
}