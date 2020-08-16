class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(auto c:s)
        {
            m[c]++;
            m[c]=m[c]%2;
            if(m[c]==0) m.erase(c);
        }
        if(m.size()) return s.length()-m.size()+1;
        else return s.length();
    }
};
