class Solution {
public:
    bool isVowel(char c){
        char lower_c = tolower(c);
        return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            while(i<j && !isVowel(s[i])){
                i++;
            }
            while(i<j && !isVowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};