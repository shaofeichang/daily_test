# 1. 简单对象模型(a simple object model)

在简单对象模型中，一个object是一系列的slot，每个slot指向一个members，members按照声明次序被指定一个slot。每个data member或者function member都有自己的slot。
![alt simple object model](https://github.com/shaofeichang/daily_test/blob/object_model/simple_object_model.png?raw=true)
members本身不放在object中，只有“指向member的指针”放在object内。避免members类型不同，需要不同的存储空间导致的问题。object中的members是以slot的索引值来寻址，class object的大小是指针大小*members的数目。

# 2. 表格对象模型

