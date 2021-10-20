//93% speed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * min(ListNode * a, ListNode * b) {
        if (b->val < a->val) {
            return b;
        }
        return a;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        for (auto iter = lists.begin(); iter != lists.end(); iter++){
            cout << distance(lists.begin(), iter) << " ";
            if (*iter==nullptr) {
                iter=lists.erase(iter);
                if (iter==lists.end()){
                    break;
                }
                //iter--;
            }
        }*/
        auto newend = remove_if(lists.begin(), lists.end(), [](const ListNode* node){
            if (node == nullptr) return true;
            return false;
        });
        lists.erase(newend,lists.end());
        /*
        int n = lists.size();
        if (n == 0){
            return nullptr;
        } if (n == 1) {
            return lists[0];
        }*/
        switch (lists.size()) {
            case 0: {
                return nullptr;
            }
            case 1: {
                return lists[0];
            }
        }
        vector<ListNode*> vec;
        for (int i0 =0; i0 < lists.size(); i0+=1){
            ListNode * node=lists[i0];
            while (node) {
                vec.push_back(node);
                node=node->next;
            }
        }
        sort(vec.begin(), vec.end(), [](ListNode* a, ListNode* b) {
            if (a->val < b->val)
                return true;
            return false;
        });
        for (int i=0; i < vec.size()-1; i+=1) {
            vec[i]->next=vec[i+1];
        }
        vec[vec.size()-1]->next=nullptr;
        return vec[0];

    }
};
