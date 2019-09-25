#include <bits/stdc++.h>
using namespace std;

// #include <iostream>
// using namespace std;
// class Base
// {
// public:
//     inline virtual void who()
//     {
//         cout << "I am Base\n";
//     }
//     virtual ~Base() {}
// };
// class Derived : public Base
// {
// public:
//     inline void who() // 不写inline时隐式内联
//     {
//         cout << "I am Derived\n";
//     }
// };

// int main()
// {
//     // 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。
//     Base b;
//     b.who();

//     // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。
//     Base *ptr = new Derived();
//     ptr->who();

//     // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
//     delete ptr;
//     ptr = nullptr;

//     system("pause");
//     return 0;
// }
// range heap example
// int main()
// {
//     int myints[] = {10, 20, 30, 5, 15};
//     std::vector<int> v(myints, myints + 5);

//     cout << "NUM" << endl;
//     std::make_heap(v.begin(), v.end());
//     std::cout << "initial max heap   : " << v.front() << '\n';

//     std::pop_heap(v.begin(), v.end());
//     v.pop_back();
//     std::cout << "max heap after pop : " << v.front() << '\n';

//     v.push_back(99);
//     std::push_heap(v.begin(), v.end());
//     std::cout << "max heap after push: " << v.front() << '\n';

//     std::sort_heap(v.begin(), v.end());

//     std::cout << "final sorted range :";
//     for (unsigned i = 0; i < v.size(); i++)
//         std::cout << ' ' << v[i];

//     std::cout << '\n';

//     return 0;
// }
// 最小m段问题，比较经典动态规划问题，状态转移方程：state[i][j] = min{ max{state[i][1] - state[k][1], state[k][j-1]}}
// 这里state[i][j]表示前i个数据分成j段得最大最小值，state[i][1]表示前i个数据分成1段的值，这里其实就是前i个数据之和。
// 1 2......k......i 这里可以这样理解，前k个数据的j-1分段的值与k----i的值的最大值，其中k----i的值就是上面state[i][1]-state[k][1]的值。

// const int MAX_COUNT = 100;
// int state[MAX_COUNT][MAX_COUNT];
// int a[MAX_COUNT];
// int MinSum(int n, int m)
// {
//     int i = 0, j = 0, k = 0, temp = 0, MaxInt;
//     for (i = 1; i <= n; ++i)
//     {
//         state[i][1] = state[i - 1][1] + a[i];
//     }
//     for (j = 2; j <= m; ++j)
//     {
//         for (i = j; i <= n; ++i)
//         {
//             temp = 10000000;
//             for (k = j; k < i; ++k)
//             {
//                 MaxInt = max(state[i][1] - state[k][1], state[k][j - 1]);
//                 if (temp > MaxInt)
//                 {
//                     temp = MaxInt;
//                 }
//             }
//             state[i][j] = temp;
//         }
//     }
//     return state[n][m];
// }
// int main()
// {
//     a[0] = 0;
//     a[1] = 1;
//     a[2] = 5;
//     a[3] = 3;
//     a[4] = 4;
//     a[5] = 3;
//     cout << MinSum(5, 3) << endl;
//     system("pause");
//     return 0;
// }
#define N 10000
bool canArrangeWords(int num, char **arr)
{
    for (size_t i = 0; i < num - 1; i++)
    {
        if (arr[i][strlen(arr[i]) - 1] != arr[i + 1][0])
            return false;
        // cout << *(arr + i) << endl;
    }
    return true;
}
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    stack<TreeNode *> st;
    st.push(root);
    bool dir = false;
    while (!st.empty())
    {
        vector<int> vectemp;
        int size = st.size();
        stack<TreeNode *> te;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = st.top();
            st.pop();
            vectemp.push_back(temp->val);

            if (dir)
            {
                if (temp->right)
                    te.push(temp->right);
                if (temp->left)
                    te.push(temp->left);
            }
            if (!dir)
            {
                if (temp->left)
                    te.push(temp->left);
                if (temp->right)
                    te.push(temp->right);
            }
        }
        dir = !dir;
        st.swap(te);
        res.push_back(vectemp);
    }
    return res;
}
struct point
{
    int a;
    int *b;
} p;
int main()
{
    using ptrp = point;
    ptrp p1{12,nullptr};
    ptrp p2{12,NULL};
    char str[1000];
    memset(str, 0, 1000);
    cin.getline(str, 1000);
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = tolower(str[i]);
        }
        else if (str[i] == ' ')
        {
            str[i] = '0';
        }
    }
    i--;
    while (i >= 0)
    {
        cout << str[i];
        i--;
    }

    // reverse(str.begin(), str.end());
    // cout << str << endl;
    // TreeNode *t1 = new TreeNode(3);
    // TreeNode *t2 = new TreeNode(9);
    // TreeNode *t3 = new TreeNode(20);
    // TreeNode *t4 = new TreeNode(15);
    // TreeNode *t5 = new TreeNode(7);
    // t1->left = t2;
    // t1->right = t3;
    // t3->left = t4;
    // t3->right = t5;
    // zigzagLevelOrder(t1);
    // int row;
    // int col;
    // std::cin >> row >> col;
    // int **dem;
    // dem = new int *[row];
    // for (size_t i = 0; i < row; i++)
    // {
    //     dem[i] = new int[col];
    // }

    // for (size_t i = 0; i < row; i++)
    // {
    //     delete[] dem[i];
    // }

    // vector<int> vectemp = {1, 2, 3, 4, 5, 6, 7};
    // vector<int> vectemp1(10, 0);
    // vector<int>::iterator iter = vectemp1.begin();
    // int val = 123;
    // for (; iter != vectemp1.end(); iter++)
    // {
    //     *iter = val++;
    // }

    // vectemp1.push_back(123);
    // int i = 5;
    // printf("%d %d %d", ++i, i++, i++);
    // int *arr = new int;
    // arr[0] = 123;
    // int num;
    // cin >> num;
    // char *ch[N];
    // ;
    // for (size_t i = 0; i < num; i++)
    // {
    //     char *temp = new char;
    //     cin >> temp;
    //     ch[i] = temp;
    // }
    // cout << canArrangeWords(num, ch) << endl;
    system("pause");
    return 0;
}