class Trie
{
public:
  char c;
  Trie* a[26];
  bool istail;
  Trie(char d)
  {
      c=d;
      for(int i=0;i<26;i++)
          a[i]=NULL;
      istail=false;
  }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie *root;
    WordDictionary() {
        root = new Trie('\0');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* p = root;
        for(int i=0;word[i];i++)
        {
            int index = word[i]-'a';
            if(p->a[index]==NULL)
            {
                Trie* t = new Trie(index);
                p->a[index]=t;
                p=t;
            }
            else
                p=p->a[index];
            
        }
        p->istail=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(Trie* root,string w,int k)
    {
        if(k>=w.size()) return root->istail;
        
        Trie* p = root;
        if(w[k]=='.')
        {
            for(int i=0;i<26;i++)
            {
                 if(p->a[i]!=NULL && dfs(p->a[i],w,k+1))
                     return true;
            }
        }
        else
        {
           int index = w[k]-'a';
           if(p->a[index]==NULL) return false;
           p=p->a[index];
            
           if(dfs(p,w,k+1)) return true;
        }
        return false;
    }
    bool search(string w) {
        return dfs(root,w,0);
    }
};
