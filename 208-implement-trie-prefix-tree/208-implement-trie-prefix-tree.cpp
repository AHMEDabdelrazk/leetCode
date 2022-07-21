class node{
public:
    char d;
    map<char,node*> children;
    bool end;
    node(){
        d = '\0'; end = false;
    }
    node(char t){
        d = t;  end = false;
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* tem = root;
        for(int i=0;i<word.length();i++){
            char t = word[i];
            if(tem->children[t] == NULL)
                tem->children[t] = new node(t);
            tem = tem->children[t];
        }
        tem->end = true;
    }
    
    bool search(string word) {
        node* tem = root;
        for(int i=0;i<word.length();i++){
            char t = word[i];
            if(tem->children[t] == NULL) return false;
            tem = tem->children[t];
        }
        return tem->end;
    }
    
    bool startsWith(string prefix) {
        node* tem = root;
        for(int i=0;i<prefix.length();i++){
            char t = prefix[i];
            if(tem->children[t] == NULL) return false;
            tem = tem->children[t];
        }
        return true;
    }
};