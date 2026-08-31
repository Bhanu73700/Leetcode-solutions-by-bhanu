
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prev = -1;
        int mindist = INT_MAX;
        int index = 1;
        ListNode* curr = head->next;
        while(curr->next!=NULL){
            int a = curr->val;
            int b = curr->next->val;
            int c = head->val;
            if((a < b && a < c) || (a > b && a > c)){
                if(first==-1) first  = index;
                if(prev!=-1) mindist = min(mindist,index - prev);
            
            prev = index;
            }
            head = head->next;
            curr = curr->next;
            index++;
        }
        if(first == prev) return {-1,-1};
        int maxdist = prev - first;

        return {mindist,maxdist};
    }
};