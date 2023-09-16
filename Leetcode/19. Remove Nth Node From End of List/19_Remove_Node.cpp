#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == nullptr)
            return head->next;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto ans = s.removeNthFromEnd(head, 2);
    while (ans != nullptr)
    {
        std::cout << ans->val << " ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}