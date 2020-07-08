class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>v;
        int carry=0;
        int n = digits.size();
        for(int i=n-1;i>=0;i--)
        {
           if((i==n-1 && digits[i]==9) || digits[i]==9 && carry) 
            {
                v.push_back(0);
                carry = 1;
            }
            else
            {
               if(i==n-1){
               v.push_back(digits[i]+1);
               }
               else
               v.push_back(digits[i]+carry);   
               carry=0;
            }
            
        }
        if(carry)
        v.push_back(1);
        
        reverse(v.begin(),v.end());
        
        return v;
    }
};
