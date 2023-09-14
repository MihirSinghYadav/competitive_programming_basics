#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main()
{
    // ListNode *head = new ListNode(1);
    // ListNode *second = new ListNode(2);
    // ListNode *third = new ListNode(3);

    // head->next = second;
    // second->next = third;

    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *current = head;
    cout << "Original Linked List: ";
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    Solution solution;
    ListNode *reverseHead = solution.reverseList(head);
    current = reverseHead;
    cout << "Reversed Linked List: ";
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    while (reverseHead != nullptr)
    {
        ListNode *temp = reverseHead;
        reverseHead = reverseHead->next;
        delete temp;
    }
    return 0;
}