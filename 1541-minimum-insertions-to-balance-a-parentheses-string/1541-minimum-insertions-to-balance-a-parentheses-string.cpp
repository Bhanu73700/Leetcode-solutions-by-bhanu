class Solution {
public:
    int minInsertions(string s) {
       int ans = 0; // number of insertions needed
       int x = 0; // count of '('
       int n = s.length();
       for(int i=0;i<n;i++){
        if(s[i]=='(') x++;
        else{
            if(i<n-1&&s[i+1]==')'){ // check for consecutive ')'
                i++;
            }else{
                ans+=1;
            }
        
        if(x==0) ans+=1;
        else x--;
        }
       }
       ans += x*2;
       return ans; 
    }
};