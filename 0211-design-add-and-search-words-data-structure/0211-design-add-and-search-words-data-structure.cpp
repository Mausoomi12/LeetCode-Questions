class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];
    TrieNode() {
        isCompleteWord = false; 
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }


    void addWord(string word) {

        TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isCompleteWord = true;
    }


    bool search(string word) {
        return searchHelper(word, root);
    }


    bool searchHelper(string word, TrieNode* node){

        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->children)
                    if(c && searchHelper(word.substr(i+1), c)) 
                        return true;
                return false;
            }
            int idx = ch - 'a';
            if(node->children[idx]==NULL) 
                return false;
            node = node->children[idx];
        }
        return node->isCompleteWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */