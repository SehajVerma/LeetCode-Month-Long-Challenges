class Solution {
public:
    string addBinary(string a, string b) {
        string o="";
        int l1 = a.length()-1;
        int l2 = b.length()-1;
        
        //My Method//
        
//         char c='0';
//         while(l1>=0 && l2>=0)
//         {
//             char x = a[l1];
//             char y = b[l2];
//             if(x=='1' && y=='1')
//             {
//                 o=c+o;
//                 c='1';
//             }
//             else
//             {
//                 if((x=='1' && y=='0') || (x=='0' && y=='1'))
//                 {
//                     if(c=='0')
//                         o='1'+o;
//                     else{
//                         o='0'+o;
//                         c='1';
//                     }
                    
//                 }
//                 else
//                 {
//                    if(x=='0' && y=='0')
//                     {
//                         o=c+o;
//                         c='0';
//                     }
//                 }
//             }
//             l1--;
//             l2--;
//         }
//         while(l1>=0)
//         {
//            char x = a[l1];
//             if(c=='0')
//                 o=x+o;
//             else{
//                 if(x=='1')
//                   o='0'+o;
//                 else
//                 {
//                     o='1'+o;
//                     c='0';
//                 }
//             }
//             l1--;
//         }
//         while(l2>=0)
//         {
//            char y = b[l2];
//             if(c=='0')
//                 o=y+o;
//             else{
//                 if(y=='1')
//                   o='0'+o;
//                 else
//                 {
//                     o='1'+o;
//                     c='0';
//                 }
//             }
//             l2--;
//         }
//         if(c=='1')
//             o='1'+o;


         //Chota Method
         
         
        string result="";
        int carry=0;
        while(l1>=0 || l2>=0)
        {
            int sum=carry;
            if(l1>=0) sum+=a[l1--]-'0';
            if(l2>=0) sum+=b[l2--]-'0';
            
            carry = sum>1? 1: 0 ;
            result+=to_string(sum%2);
        }
        if(carry)  result+=to_string(carry);
            
         reverse(result.begin(),result.end());
        return result;
    }
};
