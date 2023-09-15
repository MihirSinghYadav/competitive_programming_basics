#include <iostream>
#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }
        return lists.front();
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    ListNode *list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *list3 = new ListNode(2, new ListNode(6));

    vector<ListNode *> lists = {list1, list2, list3};
    Solution solution;
    ListNode *mergedList = solution.mergeKLists(lists);

    while (mergedList != nullptr)
    {
        cout << mergedList->val << " -> ";
        mergedList = mergedList->next;
    }
    cout << "NULL" << endl;
    delete list1;
    delete list2;
    delete list3;
    return 0;
}