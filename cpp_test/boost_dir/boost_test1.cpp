#include <vector>
#include <iostream>
#include <exception>
#include <boost/filesystem.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread/thread.hpp>
class CSample
{
public:
	CSample() ;
	~CSample();
	void Use() { std::cout << "Use" << std::endl; };
	bool Query() { return true; };
	void setI(int i) { this->i = i; };
	int getI()const { return this->i; };
private:
	int i;
};

CSample::CSample()
{
	std::cout << "构造函数被调用了" << std::endl;
}

CSample::~CSample()
{  
	this->i = 1; 
	std::cout << "析构函数被调用了" << std::endl;
}
void Sample1_Plain()
{
	CSample * pSample(new CSample);
	if (pSample->Query())
	// just some function...
	{
		delete pSample;
		return;
	}
	pSample->Use();
	delete pSample;
}
void Sample1_ScopedPtr()
{
	boost::scoped_ptr<CSample> samplePtr(new CSample);
	if (!samplePtr->Query())
		// just some function...
		return;
	samplePtr->Use();
}
void Sample2_Shared()
{
	typedef boost::shared_ptr<CSample> csamplePtr;
	csamplePtr c1 = boost::make_shared<class CSample>();
	csamplePtr c2 = boost::make_shared<CSample>();
	csamplePtr c3 = boost::make_shared<CSample>();
	c1->Use();
	c2->Use();
	printf("The Sample now has %i references\n", c1.use_count());

	// (A) 创建Csample类的一个实例和一个引用。
	boost::shared_ptr<CSample> mySample(new CSample);
	printf("The Sample now has %i references\n", mySample.use_count()); // The Sample now has 1 references
																		// (B) 付第二个指针给它。
	//boost::shared_ptr<CSample> mySample2 = mySample; // 现在是两个引用指针。
	mySample->setI(10);
	csamplePtr mySample2 = mySample;
	printf("The Sample now has %i references\n", mySample.use_count());
	printf("%d", mySample2->getI());
	// (C) 设置第一个指针为空。
	//mySample.reset();
	//printf("The Sample now has %i references\n", mySample2.use_count());  // 一个引用
																		  // 当mySample2离开作用域的时候，对象只有一个引用的时候自动被删除。
}
void Sample3_Container()
{
	typedef boost::shared_ptr<CSample> CSamplePtr;
	// (A) create a container of CSample pointers:
	std::vector<CSamplePtr> vec;
	// (B) add three elements
	vec.push_back(CSamplePtr(new CSample));
	vec.push_back(CSamplePtr(new CSample));
	vec.push_back(CSamplePtr(new CSample));
	// (C) "keep" a pointer to the second:
	CSamplePtr anElement = vec[1];
	// (D) destroy the vector:
	vec.clear();
	// (E) the second element still exists
	anElement->Use();
	printf("done. cleanup is automatic\n");
	// (F) anElement goes out of scope, deleting the last CSample instance
}

int main()
{
	Sample1_Plain();
	Sample2_Shared();
	Sample3_Container();
	std::cout << boost::thread::hardware_concurrency() << std::endl;
	system("pause");
    return 0;
}

