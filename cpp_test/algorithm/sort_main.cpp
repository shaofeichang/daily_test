#include "sort_function.h"

int main()
{
    vector<int> vec = {12, 5, 61, 2, 63, 66, 22, 88};
    // s_bubble(vec);
    // s_selection(vec);
    // s_insert(vec);
    // s_shell(vec);
    // s_merge(vec);
    s_quick(vec);
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}