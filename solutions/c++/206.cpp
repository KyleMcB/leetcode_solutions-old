//%77 speed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        vector<ListNode*> vec;
        while (head) {
            //vec.insert(vec.begin(), head);
            vec.push_back(head);
            head=head->next;
        }
        reverse(vec.begin(), vec.end());
        auto iter = vec.begin();
        auto end = vec.end()-1;
        while (iter != end){
            (*iter)->next=*(iter+1);
            iter++;
        }
        (*iter)->next=nullptr;
        return vec[0];
    }
};


//%0 speed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        vector<ListNode*> vec;
        while (head) {
            vec.insert(vec.begin(), head);
            head=head->next;
        }
        auto iter = vec.begin();
        auto end = vec.end()-1;
        while (iter != end){
            (*iter)->next=*(iter+1);
            iter++;
        }
        (*iter)->next=nullptr;
        return vec[0];
    }
};
