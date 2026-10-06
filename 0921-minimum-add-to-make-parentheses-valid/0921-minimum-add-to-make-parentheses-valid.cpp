class Solution {
public:
    int minAddToMakeValid(string s) {
       int l = 0;
       int m = 0;
       for(char c:s){
        if(c=='('){
            l++; 
        } else{
            if(l>0) l--;
            else m++;
        }
       } 
       int x = l + m;
       return x;
    }
};