#include<stdio.h>
#include<stdlib.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static void stackDump (lua_State *L) 
{
	int i = 0;
	int top = lua_gettop(L);
	for (i = 1; i <= top; i++)
	{
		int t = lua_type(L, i);
		switch (t) 
		{
		case LUA_TSTRING: /* strings */
			printf("`%s'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN: /* booleans */
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER: /* numbers */
			printf("%g", lua_tonumber(L, i));
			break;
		default: /* other values */
			printf("%s", lua_typename(L, t));
			break;
		}
		printf(" "); /* put a separator */
	}
	printf("\n"); /* end the listing */
}

int main(int argc, char** argv)
{
	lua_State *L = luaL_newstate(); // 创建Lua虚拟机

	luaL_openlibs(L); // 打开Lua状态机"L"中的所有Lua标准库

	// 向虚拟栈中压入值
	lua_pushboolean(L, 1);  // true
	lua_pushnumber(L, 10); // 10
	lua_pushnil(L); // nil
	lua_pushstring(L, "hello"); // "hello"
	stackDump(L); // true  10  nil  'hello'

	lua_pushvalue(L, -4); // 将索引-4处的值的副本入栈
	stackDump(L); // true  10  nil  'hello'  true

	lua_replace(L, 3); // 将栈顶元素移动到索引3处，并覆盖原先的元素
	stackDump(L); // true  10  true  'hello'

	lua_settop(L, 6); // 将栈顶设置为索引6处，多出来的新元素被赋值为"nil"
	stackDump(L); // true  10  true  'hello'  nil  nil

	lua_remove(L, -3); // 移除索引-3处的元素，其上所有元素下移
	stackDump(L); // true  10  true  nil  nil

	lua_settop(L, -5); // 将栈顶设置为索引-5处
	stackDump(L); // true

	lua_close(L); // 关闭Lua状态机

	system("pause");//在Linux下编译，请注释调这行

	return 0;
}