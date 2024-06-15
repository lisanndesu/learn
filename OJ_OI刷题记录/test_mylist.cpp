#include <iostream>
#include "mylist.h"
//#include "标头.h"

using namespace std;

void test()
{
	cout << "hello world" << endl;
	bite::list<int> mylist;
	bite::list<int> mylist2(5, 8);
	cout << "mylist2:" << endl;
	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;
	bite::list<int>::iterator it = mylist2.begin();
	cout << "mylist2.end() == mylist2.end(): " << (mylist2.end() == mylist2.end())<< endl;
	/*while (it != mylist2.end())
	{
		cout << *it << " ";
		it++;
	}*/

	bite::list<int> mylist3(mylist2.begin(), mylist2.end());
	cout << "mylist3:" << endl;
	for (auto e : mylist3)
	{
		cout << e << " ";
	}
	cout << endl;

	bite::list<int> mylist4(mylist3);
	mylist4.push_back(5);
	cout << "mylist4" << endl;
	for (auto e : mylist4)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "mylist4.empty():" << mylist4.empty() << endl;
	cout << "mylist4.size():" << mylist4.size() << endl;
	cout << "mylist4.front():" << mylist4.front() << endl;
	cout << "mylist4.back():" << mylist4.back() << endl;


}

int main()
{
	test();
	return 0;
}
