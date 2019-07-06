luasql = require "luasql.mysql"
env = luasql.mysql()
print(env)
conn = env:connect("userinfo","root","root","127.0.0.1",3306)
conn:execute"SET NAMES UTF8"
cur = conn:execute("select * from leader")
row = cur:fetch({},"a")
--文件对象的创建
file = io.open("role.txt","w+");
while row do
    var = string.format("%d %s\n", row.id, row.name)
    print(var)
    file:write(var)
    row = cur:fetch(row,"a")
end
file:close()  --关闭文件对象
conn:close()  --关闭数据库连接
env:close()   --关闭数据库环境