classA = {}
function classA:getob(name)
    print(self)
    ob = {}
    setmetatable(ob, self)
    self.__index = self
    self.name = name
    return ob
end
function classA:getself()
    return self
end
c1 = classA:getob('A')
c2 = classA:getob('B')
print(string.rep('*', 30))
print(c1:getself())
print(c2:getself())
print(string.rep('*', 30))
------------------------继承------------------------
classB = classA:getob() ----非常重要，用于获取继承的self
function classB:getob(name, address)
    ob = classA:getob(name)
    setmetatable(ob, self)
    self.__index = self
    self.address = address
    return ob
end
c3 = classB:getob('gray.yang', 'shenzhen')
print(c3:getself())
