#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    ListNode *tail = dummy;
    while (true)
    {
        int count = 0;
        tail = pre;
        while (tail != NULL && count < k)
        {
            tail = tail->next; //退出循环后tail指向待反转链表的末尾节点
            count++;
        }
        if (tail == NULL)
            break;
        while (pre->next != tail)
        {                          //pre->next==tail时退出循环
            cur = pre->next;       //(1)
            pre->next = cur->next; //(1)  步骤(1):将cur从链表中切出来
            cur->next = tail->next; //(2)
            tail->next = cur;       //(2) 步骤(2):将cur添加到tail后
        }
        pre = head;
        tail = head;
        head = pre->next; //head指向新的待翻转的链表头
    }
    return dummy->next;
}

ListNode *reverseKGroup1(ListNode *head, int k)
{
    ListNode *pre = head;
    int count = 0;
    while (pre != NULL && count < k)
    {
        pre = pre->next;
        count++;
    } //退出循环后pre指向第k+1个节点
    if (count == k)
    {
        pre = reverseKGroup(pre, k);
        while (count > 0)
        {
            // head指向本次循环反转指向的节点
            // temp指向下次循环反转指向的节点
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
            count--;
        }
        head = pre;
    }
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(10);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(6);
    ListNode *l7 = new ListNode(7);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = NULL;
    ListNode *ret = reverseKGroup(l1, 3);
    system("pause");
    return 0;
}