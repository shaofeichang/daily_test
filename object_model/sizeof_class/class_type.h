#pragma once
#pragma pack(push)
//#pragma pack(1)
struct BitExample1
{
	unsigned int numa : 16; // 4
	unsigned int numb : 16; // 4
	unsigned int numc : 16; // 4
	char cnumd; // 1
};
struct BitExample
{
	unsigned int numa : 8;
	unsigned int numb : 4;//4
	int numc;      // 4
	int numca[33]; // 33 * 4 = 132
	char cnumd; // 4
};
class class_A {

};
class class_B {
	class_B() {}
	~class_B() {}
};
class class_C {
	class_C() {}
	virtual ~class_C() {}
};
class class_D {
public:
	class_D() {}
	~class_D() {}
private:
	int a;
	short b;
};
class class_E {
public:
	class_E() {}
	virtual ~class_E() {}
	int haha() { return b; }
	virtual int printint() { return a; }
private:
	char ch;
	int a;
	short b;
	double c;
};
class class_derived_E : public class_E {
public:
	class_derived_E() {}
	virtual ~class_derived_E() {}
	int hello() { return a1; }
	int printint() override { return a1; }
private:
	char ch;
	int a1;
};
#pragma pack(pop)