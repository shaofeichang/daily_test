#include <queue>
#include <vector>
#include <iostream> // std::cout
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};
class Solution
{
public:
    struct Status
    {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs) const
        {
            return val > rhs.val;
        }
    };
    priority_queue<Status> q;
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto node : lists)
        {
            if (node)
                q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next)
                q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

int main()
{
    vector<ListNode *> lists;
    ListNode *list11 = new ListNode(1);
    ListNode *list12 = new ListNode(3);
    ListNode *list13 = new ListNode(5);
    ListNode *list14 = new ListNode(7);
    ListNode *list21 = new ListNode(2);
    ListNode *list22 = new ListNode(4);
    ListNode *list23 = new ListNode(6);
    ListNode *list24 = new ListNode(8);
    list11->next = list12;
    list12->next = list13;
    list13->next = list14;
    list21->next = list22;
    list22->next = list23;
    list23->next = list24;
    lists.push_back(list21);
    lists.push_back(list11);
    Solution su;
    su.mergeKLists(lists);
    return 0;
}