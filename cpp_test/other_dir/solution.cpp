#include <bits/stdc++.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
        return NULL;
    ListNode *p = new ListNode(0);
    ListNode *ret = p;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
            while (l2 != NULL)
            {
                p->val = l2->val;
                p = p->next;
                l2 = l2->next;
            }
        if (l2 == NULL)
            while (l1 != NULL)
            {
                p->val = l1->val;
                p = p->next;
                l1 = l1->next;
            }
        if (l1->val < l2->val)
        {
            p->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            p->val = l2->val;
            l2 = l2->next;
        }
        p = p->next;
    }
    return ret;
}
int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);

    mergeTwoLists(l1, l2);
    system("pause");
    return 0;
}