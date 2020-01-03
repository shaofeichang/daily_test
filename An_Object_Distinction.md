# 对象的差异(An Object Distinction)

C++程序设计支持三种 **programming paradigms**（程序设计典范）

## 1. 程序模型(procedural model)

类似与C语言的处理方式

```C/C++
    char boy[] = "Dany";
    char *p_son;
    ...
    p_son = new char[strlen(boy) + 1];
    strcpy(p_son, boy);
    ...
    if(!strcmp(p_son, boy))
        take_to_disneyland(boy);
```

## 2. 抽象数据类型模型(abstract data type model,ADT)

该模型所谓的“抽象”是和一组表达式（public接口）一起提供，而其运算定义仍然隐而未明。

```C/C++
    String girl = "Anna";
    String daughter;
    ...
    //String::operator==();
    daughter = girl;
    ...
    if(girl == daugnter)
        take_to_disneyland(girl);
```

## 3. 面向对象模型(object-oriented model)

在此模型中有一些彼此相关的类型，通过一个抽象的base class(用以提供共通接口)被封装起来。

```C/C++
    void checkIn(Library_materials *pmat)
    {
        if (pmat->late()) {
            pmat->fine();
        }
        pmat->check_in();
        if (Lender *plend = pmat->reserved()) {
            pmat->notify(plend);
        }
    }
```
