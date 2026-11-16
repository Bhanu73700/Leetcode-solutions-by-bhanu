class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            string next = "";
            for(int i=0;i<s.length();i+=k){// i ke increment ki condition imp hh
                int sum = 0;
                for(int j=i;j<s.length()&&j<i+k;j++){ // yeh imp loop hh
                    sum += s[j] - '0';
                }
            
            next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};