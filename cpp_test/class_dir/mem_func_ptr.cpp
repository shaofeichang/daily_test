#include <iostream>
void func(void)
{
    std::cout << "FUNC" << std::endl;
}
struct Foo
{
    void operator()(void)
    {
        std::cout << "FOO OPERATOR" << std::endl;
    }
};
struct Bar
{
    using fr_t = void (*)(void);
    static void func(void)
    {
        std::cout << "BAR FUNC" << std::endl;
    }
    operator fr_t(void)
    {
        return func;
    }
};
struct A
{
    int a_;
    void mem_func(void)
    {
        std::cout << "A_MEM_FUNC" << std::endl;
    }
};

int main(void)
{
    void (*func_ptr)(void) = &func; //函数指针
    func_ptr();
    Foo foo; //仿函数
    foo();
    Bar bar; //可被转换为函数指针的类对象
    bar();
    void (A::*mem_func_ptr)(void) = &A::mem_func; //类成员函数指针
    int A::*mem_obj_ptr = &A::a_;                 //类成员指针
    A aa;
    (aa.*mem_func_ptr)();
    aa.*mem_obj_ptr = 123;
    system("pause");
    return 0;
}