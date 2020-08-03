class Solution {
public:
    bool isPalindrome(string s) {
    
    // One test case didnt pass
        // string p1="";
        // string p2="";
         int n = s.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]>='0' && s[i]<='9')
        //     {
        //         p1+=s[i];
        //         p2=s[i]+p2;
        //     } 
        //     else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        //     {
        //         p1+=tolower(s[i]);
        //         char c =tolower(s[i]);
        //         p2=c+p2;
        //     }
        // }
        // if(p1==p2)
        //     return true;
        // else
        //     return false;
        
   //Efficient Code
        int st=0;
        int en=n-1;
        while(st<en)
        {
            while(st<en && !isalnum(s[st])) st++;
            while(st<en && !isalnum(s[en])) en--;
            if(st<en && tolower(s[st])!=tolower(s[en])) return false;
            st++;
            en--;
        }
        return true;
    }
};
