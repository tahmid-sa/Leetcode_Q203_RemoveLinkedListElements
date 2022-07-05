#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev, * curr;

    if (head == nullptr) {
        return nullptr;
    }


    while (head->val == val && head != nullptr) {
        ListNode* tmp = head;
        head = head->next;

        if (head == nullptr) {
            return nullptr;
        }
    }

    prev = head;

    for (curr = head->next; curr != nullptr; ) {
        if (curr->val == val) {
            prev->next = curr->next;
            curr = curr->next;
        }
        else if (curr->val != val) {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    ListNode n6(6, nullptr);
    ListNode n3(3, &n6);
    ListNode n61(6, &n3);
    ListNode n2(2, &n61);
    ListNode n62(6, &n2);
    ListNode n63(6, &n62);

    ListNode* head = removeElements(&n63, 6);

    for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->val;
        cout << endl;
    }

    return 0;
}