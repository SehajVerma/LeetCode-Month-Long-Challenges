class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
              c++;
        }
        if(c==n || c==0 || (c==1 && word[0]>='A' && word[0]<='Z'))
            return true;
        else
            return false;
    }
};
