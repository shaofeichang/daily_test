#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct qnode
{ //数据结点
    ElemType data;
    struct qnode *next;
} QNode;

// typedef struct
// { //链队定义
//     QNode *rear;
// } LiQueue;

/*-------------一、不带头结点的循环单链表示队列---------------*/
void InitQu(QNode *&rear)
{
    rear = NULL;
}

//入队
void EnQu(QNode *&rear, ElemType x)
{
    QNode *s;
    s = (QNode *)malloc(sizeof(QNode));
    s->data = x;
    if (rear == NULL) //队列为空
    {
        s->next = s;
        rear = s;
    }
    else
    { //队列不为空
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
}

//出队
int DeQu(QNode *&rear, ElemType &x)
{
    QNode *q;
    if (rear == NULL)
        return 0;
    else if (rear->next == rear)
    {
        x = rear->data;
        free(rear);
        rear = NULL;
    }
    else
    {
        q = rear->next;
        x = q->data;
        rear->next = q->next;
        free(q);
    }
    return 1;
}

//判断队列是否为空
int QuEmpty(QNode *rear)
{
    return (rear == NULL);
}

/*-------------------二、用带头结点的循环单链表表示队列------------------*/
void InitQu1(QNode *&rear)
{
    rear = (QNode *)malloc(sizeof(QNode));
    rear->next = rear;
}

//进队
void EnQu1(QNode *&rear, ElemType x)
{
    QNode *s;
    s = (QNode *)malloc(sizeof(QNode));
    s->next = NULL;
    s->data = x;
    s->next = rear->next;
    rear->next = s;
    rear = s;
}

//出队
int DeQu1(QNode *&rear, ElemType &x)
{
    QNode *q;
    if (rear->next == rear)
        return 0;
    else if (rear->next->next == rear)
    {
        x = rear->data;
        q = rear->next;
        q->next = q;
        free(rear);
        rear = q;
        return 1;
    }
    else
    {
        q = rear->next->next;
        x = q->data;
        rear->next->next = q->next;
        free(q);
        return 1;
    }
}

int QuEmpty1(QNode *rear)
{
    return (rear->next == rear);
}

//不带头结点的循环单链表输出
void DispQueueR(QNode *&rear)
{
    if (rear == NULL)
        return;
    QNode *p = rear->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != rear->next);

    printf("\n");
}

//带头结点的循环单链表输出
void DispQueueR2(QNode *&rear)
{
    if (rear->next == rear)
        return;
    QNode *q = rear->next->next;

    while (q != rear)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    if (q == rear)
    {
        printf("%d ", q->data);
    }

    printf("\n");
}

int main()
{
    QNode *p;

    //不带头结点的循环单链表
     InitQu(p);
     int i=0;
     for (i=1;i<10;i++)
     {
         EnQu(p,i*i-1);
     }
     DispQueueR(p);

    //带头结点的循环单链表
    // InitQu1(p);
    // int j = 0;
    // for (j = 1; j < 10; j++)
    // {
    //     EnQu1(p, j * j - 1);
    // }
    // DispQueueR2(p);
    getchar();

}