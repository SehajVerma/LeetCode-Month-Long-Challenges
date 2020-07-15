#Not able to do with strtok function
!!!!!Dont know why!!!!!
But covered 16 test cases out of 25 with strtok


class Solution {
public:
    string reverseWords(string s) {
        // if(s.empty())
        //     return "";
        // string o;
        // char c[1000000];
        // for(int i=0;s[i];i++)
        //     c[i]=s[i];
        // char *ptr=strtok(c," ");
        // while(ptr!=NULL)
        // {
        //     o=ptr+o;
        //     ptr = strtok(NULL," "); 
        //     if(ptr!=NULL)
        //         o=" "+o;
        // }
        // return o;
        int i=0;
        int n = s.length();
        string result;
        while(i<n)
        {
            while(i<n && s[i]==' ')
                i++;
            if(i>=n) break;
            int j = i+1;
            while(j<n && s[j]!=' ')
                j++;
            string w = s.substr(i,j-i);
            if(result.length()==0) result=w;
            else
                result = w+" "+result;
            i=j+1;
            
        }
        return result;
    }
};
