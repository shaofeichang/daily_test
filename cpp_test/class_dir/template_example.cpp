#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;
template <class T>
class Stack
{
private:
    vector<T> elems; // 元素
public:
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    bool empty() const
    {
        return elems.empty(); // 如果为空则返回真。
    }
};
template <class T>
void Stack<T>::push(T const &elem)
{
    elems.push_back(elem); // 追加传入元素的副本
}
template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back(); // 删除最后一个元素
}
template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back(); // 返回最后一个元素的副本
}

int main()
{
    try
    {
        Stack<int> intStack;       // int 类型的栈
        Stack<string> stringStack; // string 类型的栈   
        for (int i = 0; i < 10; ++i)
        {
            intStack.push(i);   // 操作 int 类型的栈
        }
        cout << intStack.top() << endl;

        stringStack.push("hello");  // 操作 string 类型的栈
        stringStack.push("hello2");
        stringStack.push("hello3");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        system("pause");
        return -1;
    }
    system("pause");
    return 0;
}
