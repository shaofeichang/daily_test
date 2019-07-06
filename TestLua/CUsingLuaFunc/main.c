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
static int multi_math(lua_State *L, int x, int y)
{
	int ret = 0;
	int add_ret = 0;
	int sub_ret = 0;
	int mul_ret = 0;
	//call lua_add
	lua_getglobal(L, "lua_add");//�Ѻ���lua_addѹ��ջ��
	stackDump(L);				//function
	lua_pushnumber(L, x);		//function 2
	lua_pushnumber(L, y);		//fucntion 2 1
	stackDump(L);				
	lua_call(L, 2, 1);//ָ����2��������1������ֵ���Ұ�function 2 1����ջ�����ѷ���ֵѹ��ջ
	stackDump(L);
	add_ret = (int)lua_tonumber(L, -1);
	stackDump(L);
	printf("add_ret = %d\n", add_ret);
	lua_pop(L, 1);				//����ջ��
	stackDump(L);
#if 0
	//call local lua_sub will cause running error 
	lua_getglobal(L, "lua_sub");
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	lua_call(L, 2, 1);
	sub_ret = (int)lua_tonumber(L, -1);
	printf("sub_ret = %d\n", sub_ret);
	lua_pop(L, 1);
#endif
	//call lua_mul
	lua_getglobal(L, "lua_mul");
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	lua_call(L, 2, 1);
	mul_ret = (int)lua_tonumber(L, -1);
	printf("mul_ret = %d\n", mul_ret);
	lua_pop(L, 1);

	return ret;
}

int main(int argc, char** argv)
{
	lua_State *L = luaL_newstate(); // ����Lua�����
	luaL_openlibs(L); // ��Lua״̬��"L"�е�����Lua��׼��

	printf("call lua ....\n");
	if (luaL_dofile(L, "main.lua"))//��������main.lua
	{
		printf("call lua failed!\n");
	} else if (multi_math(L, 2, 1)) {
		printf("call multi_math failed!\n");
	}

	lua_close(L); // �ر�Lua״̬��

	system("pause");

	return 0;
}