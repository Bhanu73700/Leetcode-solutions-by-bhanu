class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long prod = 1;
        int x = n;
        while(x>0){
            int digit=x%10;
            sum+=digit;
            prod*=digit;
            x/=10;
        }
        long long result = sum + prod;
        if(n%result==0) return true;
        else return false;
    }
};