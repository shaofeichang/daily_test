# 对象模型

## 1. 简单对象模型(a simple object model)

在简单对象模型中，一个object是一系列的slot，每个slot指向一个members，members按照声明次序被指定一个slot。每个data member或者function member都有自己的slot。

<div align=center><img src="https://github.com/shaofeichang/daily_test/blob/object_model/simple_object_model.png?raw=true" width="50%" height="50%"></div>

members本身不放在object中，只有“指向member的指针”放在object内。避免members类型不同，需要不同的存储空间导致的问题。object中的members是以slot的索引值来寻址，class object的大小是指针大小*members的数目。

## 2. 表格驱动对象模型

为了对所有class的所有objects都有一致的表达方式，将所有members相关的信息都抽象出来，放在data member table和一个member function table中，class object 本身则内含这两个表格的指针，member function table 是一系列的slots，每个slot指出一个member function，data member table则直接含有data本身。

<div align=center><img src="https://github.com/shaofeichang/daily_test/blob/object_model/table_driven_object_model.png?raw=true" width="50%" height="50%"></div>

## 3. C++对象模型（The C++ Object Model）

C++对象模型从简单模型派生而来，对内存空间和存取时间进行了优化。

1. nonstatic data members 配置于每一个class object中

2. static data members 存放在class object之外

3. static 和 nonstatic function members也被存放在所有的class object之外

virtual functions以两个步骤：

1. 每个class产生一堆指向virtual functions的指针，放在表格之中，称为virtual table(vtbl).

2. 每个class object被添加了一个指针，指向相关的virtual table(vptr).vptr的setting和resetting都由每个class的constructor、destructor和copy assignment运算符自动完成。每个class关联的type_info object（runtime type identification，RTTI）也经由virtual table指出，放在表格的第一个slot处。

<div align=center><img src="https://github.com/shaofeichang/daily_test/blob/object_model/cpp_object_model.png?raw=true" width="50%" height="50%"></div>
