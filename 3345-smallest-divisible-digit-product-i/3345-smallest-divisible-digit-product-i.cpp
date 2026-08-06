class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; ;i++){
            int mul = 1;
            int x=i;
            while(x>0){
                mul*=x%10;
                x/=10;
            }
            if(mul%t==0) return i;
        }
    }
};