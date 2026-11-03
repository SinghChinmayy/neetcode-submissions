/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * cur = head; 
        int listSize = 0;
        while(cur != nullptr){
            listSize++;
            cur = cur->next;
        }
        int removePos = listSize - n + 1;
        
        cur = head;
        ListNode* prev = nullptr;
        int i = 1;
        while(i != removePos){
            prev = cur;
            cur = cur->next;
            i++;
        }
        ListNode* after = cur->next;

        
        if(cur == head){
            head = cur->next;
        }else{
            prev->next = after;
        }
        delete cur;
        return head;
    }
};
