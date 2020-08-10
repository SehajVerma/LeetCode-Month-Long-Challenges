class Solution 
{
public:
    int titleToNumber(string str) 
    {
        int result = 0;
        int n = str.size();
        
        for(int i = 0; i < n; i++)
        {
            result += int(str[i] - 'A' + 1) * pow(26, n - i - 1);
        }
        
        return result;
    }
};
