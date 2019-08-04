mytable =
    setmetatable(
    {key1 = 'value1'},
    {
        __index = function(mytable, key)
            if key == 'key2' then
                return 'metatablevalue'
            else
                return nil
            end
        end
    }
)

print(mytable.key1, mytable.key2)

other = {foo = 3}
t = setmetatable({}, {__index = other})

mymetatable = {}
mytable = setmetatable({key1 = 'value1'}, {__newindex = mymetatable})

print(mytable.key1)

mytable.newkey = '新值2'
print(mytable.newkey, mymetatable.newkey)

mytable.key1 = '新值1'
print(mytable.key1, mymetatable.key1)


mytable =
    setmetatable(
    {key1 = 'value1'},
    {
        __newindex = function(mytable, key, value)
            rawset(mytable, key, '"' .. value .. '"')
        end
    }
)

mytable.key1 = 'new value'
mytable.key2 = 4

print(mytable.key1, mytable.key2)
