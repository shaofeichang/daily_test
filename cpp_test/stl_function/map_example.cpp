// multimap::insert (C++98)
#include <iostream>
#include <map>

int main()
{
    {
        std::multimap<char, int> mymultimap;
        std::multimap<char, int>::iterator it;

        // first insert function version (single parameter):
        mymultimap.insert(std::pair<char, int>('a', 100));
        mymultimap.insert(std::pair<char, int>('z', 150));
        it = mymultimap.insert(std::pair<char, int>('b', 75));
        mymultimap.insert(std::pair<char, int>('a', 500));
        // second insert function version (with hint position):
        mymultimap.insert(it, std::pair<char, int>('c', 300)); // max efficiency inserting
        mymultimap.insert(it, std::pair<char, int>('z', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        std::multimap<char, int> anothermultimap;
        anothermultimap.insert(mymultimap.begin(), mymultimap.find('c'));

        // showing contents:
        std::cout << "mymultimap contains:\n";
        for (it = mymultimap.begin(); it != mymultimap.end(); ++it)
            std::cout << (*it).first << " => " << (*it).second << '\n';

        std::cout << "anothermultimap contains:\n";
        for (it = anothermultimap.begin(); it != anothermultimap.end(); ++it)
            std::cout << (*it).first << " => " << (*it).second << '\n';
    }
    {
        std::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::map<char, int> mymap;
        std::cout << "Max Size: " << mymap.max_size() << std::endl;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        int psize;
        std::map<char, int> mymap;
        std::pair<const char, int> *p;

        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);

        // assign some values to array
        psize = sizeof(std::map<char, int>::value_type) * 5;

        std::cout << "The allocated array has a size of " << psize << " bytes.\n";

        mymap.get_allocator().deallocate(p, 5);
    }
    system("pause");
    return 0;
}