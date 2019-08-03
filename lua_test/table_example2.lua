require("lua_test/maxn")
tbl = {[1] = 2, [2] = 6, [3] = 34, [4] = 56, [26] =5}
print("tbl 最大值：", maxn.table_maxn(tbl))
print("tbl 长度 ", #tbl)