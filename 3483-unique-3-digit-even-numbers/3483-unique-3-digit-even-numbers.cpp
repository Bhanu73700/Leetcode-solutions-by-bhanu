class Solution {
public:
    int totalNumbers(vector<int>& arr) {
      set<int> st;
      int n = arr.size();
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i==j||j==k||i==k) continue;
                if(arr[i]==0) continue;
                if(arr[k]%2!=0) continue;
                int a = arr[i]*100+arr[j]*10+arr[k];
                st.insert(a);
            }
        }
      } 
      return st.size(); 
    }
};