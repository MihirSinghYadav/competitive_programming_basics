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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse second half
        ListNode *second = slow->next;
        ListNode *prev = nullptr;
        slow->next = nullptr;
        while (second != nullptr)
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        // merge both halves
        ListNode *first = head;
        second = prev;
        while (second != nullptr)
        {
            ListNode *temp1 = first->next, *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

int main()
{
    // Create a sample linked list
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // Create an instance of the Solution class
    Solution solution;
    solution.reorderList(head);
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
    current = head;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}