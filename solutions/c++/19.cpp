//17% speed
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n==1 && head->next == NULL) return NULL;
       if (remover(head, head, 0, n))
        return head;
        else return head->next;
    }
    bool remover(ListNode* node, ListNode* tail, int dis, int n) {
        std::cout << "node: " << node->val << " tail: " << tail->val << " dis:" << dis << " n: " << n <<std::endl;

        if (tail->next == NULL) {
            //foud the end
            if (dis==n) {
                node->next=node->next->next;
                return true;
            }
            else {
            return false;
            }
        } else { //walk forward
       if (dis < n) {
            return remover(node, tail->next,dis+1,n);
        }
            return remover(node->next, tail->next, dis, n);

        }
    }

};
