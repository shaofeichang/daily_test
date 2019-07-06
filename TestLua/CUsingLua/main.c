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
	lua_State *L = luaL_newstate(); // ����Lua�����

	luaL_openlibs(L); // ��Lua״̬��"L"�е�����Lua��׼��

	// ������ջ��ѹ��ֵ
	lua_pushboolean(L, 1);  // true
	lua_pushnumber(L, 10); // 10
	lua_pushnil(L); // nil
	lua_pushstring(L, "hello"); // "hello"
	stackDump(L); // true  10  nil  'hello'

	lua_pushvalue(L, -4); // ������-4����ֵ�ĸ�����ջ
	stackDump(L); // true  10  nil  'hello'  true

	lua_replace(L, 3); // ��ջ��Ԫ���ƶ�������3����������ԭ�ȵ�Ԫ��
	stackDump(L); // true  10  true  'hello'

	lua_settop(L, 6); // ��ջ������Ϊ����6�������������Ԫ�ر���ֵΪ"nil"
	stackDump(L); // true  10  true  'hello'  nil  nil

	lua_remove(L, -3); // �Ƴ�����-3����Ԫ�أ���������Ԫ������
	stackDump(L); // true  10  true  nil  nil

	lua_settop(L, -5); // ��ջ������Ϊ����-5��
	stackDump(L); // true

	lua_close(L); // �ر�Lua״̬��

	system("pause");//��Linux�±��룬��ע�͵�����

	return 0;
}