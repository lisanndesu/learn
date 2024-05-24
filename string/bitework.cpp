// 题目名称：
// 实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现
// 题目内容：
// 实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现


#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;

namespace bit
{
	size_t npos = -1;
	class string
	
	{
	public:
	
		string(const char* str = "");
	
		string(const string &s);
	
		string& operator=(const string &s);
	
		~string()
		{
			delete[] _str;
//			cout<<"成功析构"<<endl;
		}
		
		size_t size();
		
		size_t capacity()
		{
			return _capacity;
		}
		
		char& operator[](int i);
		const char& operator[](int i) const;
		
//		ostream& operator<<(ostream&, string& str);

		void reserve(size_t n);

		void push_back(char ch);
		void append(const char* str);

		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		void swap(string& s);
		bit::string substr(size_t pos = 0, size_t len = npos);

		bool operator<(const string& s) const;
		bool operator>(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;
		void clear();
	
	private:
		size_t _capacity;
		size_t _size;
	
		char *_str;
	};
	
	size_t string::size()
	{
		return _size;
	}

	string::string(const char* str)
	{
	//	len = len(str);
		_str = new char[(strlen(str)+1)];
		memcpy(_str, str, strlen(str)+1);
		_capacity = strlen(str);
		_size = strlen(str);
		cout<<"进入string"<<endl;
	}
	
	char& bit::string::operator[](int i)
	{
		assert(_size>i);
		return _str[i];
	}
	
	const char& bit::string::operator[](int i) const
	{
		assert(_size>i);
		return _str[i];
	}
	
	ostream& operator<<(ostream& os, bit::string& str)
	{
		int i = 0;
		for(int i = 0; i < str.size(); i++)
		{
			cout<<str[i];
		}
		cout<<"			"<<"_size = "<<str.size()<<"\t_capacity =  "<<str.capacity()<<endl;
		return os;
	}
	
	//深度拷贝构造 
	string::string(const string &s)
	{
		_str = new char[s._capacity+1];
		memcpy(_str, s._str, strlen(s._str)+1);
		_size = s._size;
		_capacity = s._capacity;
		cout<<"深度拷贝构造"<<endl;
	}
	
	//赋值拷贝
	bit::string& string::operator=(const string &s)
	{
		delete[] _str;
		_str = new char[s._capacity+1];
		memcpy(_str, s._str, strlen(s._str)+1);
		_size = s._size;
		_capacity = s._capacity;
		cout<<"赋值拷贝"<<endl;
		return *this;
	}
	
	void bit::string::reserve(size_t n)
	{
		if(n>_capacity);
		{
			_capacity = n;
			char* tmp = new char[_capacity+1];
			memcpy(tmp, _str, strlen(_str)+1);
			
//			strcat(tmp, _str);
			delete[] _str;
			_str = tmp;
			cout<<"扩容成功_str = "<<_str<<endl;
		}
	}

	void bit::string::push_back(char ch)
	{
		if(_size+1>=_capacity)
		{
			this->reserve(2*_capacity);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
		cout<<"成功尾插"<<endl;
	}
	
	//尾插字符串 
	void bit::string::append(const char* str)
	{
//		cout<<this->size()<<endl;
//		cout<<*this<<endl;
		int end = _size;
		_size = _size + strlen(str);
		if(_size>_capacity)
		{
			this->reserve(_size+5);
		}
//		char* tmp = _str;
		cout<<"_str  "<<_str<<endl; 
//		strcat(_str, str);
		memcpy(_str+end, str, strlen(str)+1);
		cout<<"_str  "<<_str<<endl<<endl; 
//		cout<<_strk<<endl;
//		if(int(tmp) == int(_str))
//		{
//			cout<<"strcat返回destination地址，不会另开空间"<<endl;
//		}
//		else
//		{
//			cout<<"strcat另开空间"<<endl;
//		}
//		cout<<"成功append"<<endl;
	}
//
	string& bit::string::operator+=(char ch)
	{
		push_back(ch);
		cout<<"成功+=字符"<<endl;
		return *this;
	}
	string& bit::string::operator+=(const char* str)
	{
		append(str);
		cout<<"成功+=字符串"<<endl;
		return *this;
	}
//
	void bit::string::insert(size_t pos, char ch)
	{
		assert(pos<=_size);
		if(_size == _capacity)
		{
			reserve(2*_capacity);
		}

		for(int i = _size; i+1 > pos+1; i--)
		{
			_str[i] = _str[i-1];
		}
		_str[pos] = ch;
		_size++;
	}
	void bit::string::insert(size_t pos, const char* str)
	{
		assert(pos<=_size);
		if(_size+strlen(str)-1>=_size)
		{
			reserve(_size+strlen(str));
		}
		
		for(int i = _size; i+1>pos+1; i--)
		{
			_str[i-1+strlen(str)] = _str[i-1];
		}
		memcpy(_str+pos, str, strlen(str));
		_size+=strlen(str);
	}
	void bit::string::erase(size_t pos, size_t len)
	{
		assert(pos<=_size);
		if(pos+len>_size)
		{
			_size = pos;
			return;
		}
		memcpy(_str+pos, _str+pos+len, strlen(_str+pos+len));
		_size-=len;
	}
//
	size_t bit::string::find(char ch, size_t pos)
	{
		assert(pos<=_size);
		for(int i = pos; i < _size; i++)
		{
			if(_str[i]==ch)
			{
				return i;
			}
		}
		return -1;
	}
	
	bool same_str(char* str1, const char* str2)
	{
		int i = 0;
		while(str2[i]!='\0')
		{
			if(str1[i]!=str2[i])
			{
				return false;
			}
			i++;
		}
		return true;
	}
	
	size_t bit::string::find(const char* str, size_t pos)
	{
		assert(pos+strlen(str)-1<=_size);
		for(int i = pos; i < _size-strlen(str)+1; i++)
		{
			if(same_str(_str+i, str))
			{
				return i;
			}
		}
		return -1;
		
	}
	
//
	void bit::string::swap(string& s)
	{
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
		std::swap(_str, s._str);
	}
	bit::string bit::string::substr(size_t pos , size_t len)
	{
		assert(pos<_size);
		if(pos+len-1>_size)
		{
			return _str+pos;
		}
		bit::string ret;
		for(int i = 0; i < len; i++)
		{
			ret.push_back(_str[i+pos]);
		}
		return ret;
//		return "success";
	}
//
	bool bit::string::operator<(const bit::string& s) const
	{
		int _min = _size<s._size?_size:s._size;
		int _max = _size>s._size?_size:s._size;
		bit::string max_str = _size>s._size?*this:s;
		int i = 0;
		while(i<_min)
		{
			if(this->operator[](i) < s.operator[](i))
//			ostream& operator<<(ostream& os, bit::string& str)
			{
//				cout<<"this->operator[](i) < s.operator[](i)"<<endl;
				return true;
			}
			if(this->operator[](i) > s[i])
			{
//				cout<<"this->operator[](i) > s[i]"<<endl;
				return false;
			}
			i++;
		}
		while(i<_max)
		{
			if(max_str[i]!='a')
			{
				if(max_str==s)
				{
					return true;
				}
				return false;
			}
			i++;
		}
	}
	bool bit::string::operator>(const string& s) const
	{
		if(*this==s||*this<s)
		{
			return false;
		}
		return true;
	}
	bool bit::string::operator<=(const string& s) const
	{
		if(*this<s||*this==s)
		{
			return true;
		}
		return false;
	}
	bool bit::string::operator>=(const string& s) const
	{
		if(*this<s)
		{
			return false;
		}
		return true;
	}
	
	bool bit::string::operator==(const string& s) const
	{
		return strcmp(_str, s._str)==0;
	}
	bool bit::string::operator!=(const string& s) const
	{
		return !(*this==s);
	}
	void bit::string::clear()
	{
		free(_str);
		_str = new char('\0');
		_size = _capacity = 1;
	}
	
}

int main()
{
//    cout<<"hello world"<<endl;
	bit::string str("test");
//	cout<<"str: "<<str<<endl;
//	cout<<"str: "<<bit::string("test")<<endl;
	
	bit::string str2;
	str2 = str;
	cout<<"str2 = "<<str2<<endl;
	
	str2[1] = 'h';
	cout<<str2<<endl;
	
	str2.reserve(10);
	cout<<str2<<endl;
	
	str2.push_back('x');
	str2.push_back('y');
	cout<<str2<<endl;
	
	str2.append("zzz");
	cout<<str2<<endl; 
	
//	str2+="hell0";
	str2.append("hello");
	cout<<str2<<endl;
	
	char* str3 = "hhh";
//	cout<<"sizeof(\"str3 == \")"<<sizeof(str3)<<endl;
//	cout<<"sizeof(\"hhh\")  == "<<sizeof("hhh")<<endl;
	str2+="hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
	cout<<str2<<endl;
	
	str2.insert(0, 'h');
	cout<<str2<<endl;
	
	bit::string str4("work");
	str4.insert(0, "hhhhhhhhhhh");
	cout<<str4<<endl;
	str4.erase(0, 5);
	cout<<str4<<endl;
	
	printf("str4.find(k, 4) ==%d\n", str4.find('k', 4));
	
	printf("str4.find(\"work\", 3) == %d\n", str4.find("work", 3));
	
	cout<<"交换前"<<endl;
	cout<<"str4: " <<str4<<endl;
	cout<<"str2: "<<str2<<endl;
	str4.swap(str2);
	cout<<"交换后"<<endl;
	cout<<"str4: "<<str4<<endl;
	cout<<"str2: "<<str2<<endl;
	
	bit::string ret = str2.substr(3, 5);
	cout<<"str2.substr(3, 5)=="<<ret<<endl;
//	cout<<bit::string(str2.substr());
//	cout<<bit::string("successful")<<endl;
//	cout<<str4<<endl;
	
	 
	cout<<"str2<str4 == "<<(true?"<":">")<<endl;
	
//	cout<<bit::string(bit::string("suc"))<<endl;
	
	bit::string str5 = "abcd";
	bit::string str6 = "bcd";
	cout<<"str5:"<<endl;
	cout<<str5<<endl;
	cout<<"str6"<<endl;
	cout<<str6<<endl;
	cout<<"str5>str6=="<<((str5>str6)?"true":"false")<<endl;
	cout<<"str5!=str6=="<<((str5!=str6)?"true":"false")<<endl;
	cout<<"str5<=str6=="<<((str5<=str6)?"true":"false")<<endl;
	cout<<"str5>=str6=="<<((str5>=str6)?"true":"false")<<endl;
	cout<<"str5<str6=="<<(str5<str6?"true":"false")<<endl;
	str5.clear();
	cout<<"after clear str5=="<<str5<<endl;
	
	
    return 0;
}


