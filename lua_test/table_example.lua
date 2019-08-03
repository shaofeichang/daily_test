--[[ table example ]]
--初始化表
mytable1 = {}
--移除引用
mytable1 = nil
-- 简单的 table
mytable = {}
print('mytable 的类型是 ', type(mytable))
mytable[1] = 'Lua'
mytable['wow'] = '修改前'
print('mytable 索引为 1 的元素是 ', mytable[1])
print('mytable 索引为 wow 的元素是 ', mytable['wow'])
-- alternatetable和mytable的是指同一个 table
alternatetable = mytable
print('alternatetable 索引为 1 的元素是 ', alternatetable[1])
print('mytable 索引为 wow 的元素是 ', alternatetable['wow'])
alternatetable['wow'] = '修改后'
print('mytable 索引为 wow 的元素是 ', mytable['wow'])
-- 释放变量
alternatetable = nil
print('alternatetable 是 ', alternatetable)
-- mytable 仍然可以访问
print('mytable 索引为 wow 的元素是 ', mytable['wow'])
mytable = nil
print('mytable 是 ', mytable)
mytable = {'Lua1', 'Lua2', 'Lua3'}
print('newtable is :', table.concat(mytable, ', ', 1, 3))
table.insert(mytable, 'Lua4')
table.insert(mytable, 3, 'Lua3.1')
table.remove(mytable, 4)
print(table.concat( mytable, ", ",1 ,4 ))
