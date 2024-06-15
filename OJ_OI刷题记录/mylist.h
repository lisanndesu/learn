#include<iostream>
#include <assert.h>
#include <algorithm>
using namespace std;


namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
        {
            _val = val;
        }
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        //friend list;
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr)
        {
            _pNode = pNode;
        }
        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }
        T& operator*()
        {
            return _pNode->_val;
        }
        PNode& operator->()
        {
            return this;
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self olditer(*this);
            _pNode = _pNode->_pNext;
            return olditer;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self olditer(*this);
            _pNode = _pNode->_pPre;
            return olditer;
        }
        bool operator!=(const Self& l)
        {
            //return (*(*this)) != (*l);
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            //return (*(*this)) == (*l);
           
            return _pNode == l._pNode;
        }
  //  private:
        PNode _pNode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
            cout << "成功list()" << endl;
        }
        list(int n, const T& value = T())
        {
            assert(n > 0);
            CreateHead();
            while (n--)
            {
                push_back(value);
            }
            cout << "成功list(int n, const T& value = T())" << endl;
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            Iterator it = first;
            while (it != last)
            {
                push_back(*it);
                it++;
            }
            cout << "成功list(Iterator first, Iterator last)" << endl;
        }
        list(const list<T>& l)
        {
            CreateHead();
            iterator it = l.begin();
            while (it != l.end())
            {
                push_back(*it);
                it++;
            }
            cout << "成功list(const list<T>& l)" << endl;
        }
        list<T>& operator=(const list<T> l);
        ~list()
        {
            Node* pcur = _pHead->_pNext;
            while (pcur != _pHead)
            {
                Node* tmp = pcur->_pNext;
                delete pcur;
                pcur = tmp;
            }
            delete pcur;
            cout << "成功~list()" << endl;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }

        iterator begin() const
        {
            return _pHead->_pNext;
        }
        iterator end() const
        {
            return _pHead;
        }


        const_iterator cbegin()
        {
            return _pHead->_pNext;
        }
        const_iterator cend()
        {
            return _pHead;
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            int size = 0;
            iterator it = begin();
            while (it != end())
            {
                size++;
                it++;
            }
            return size;
        }

        bool empty()const
        {
            return _pHead == _pHead->_pNext;
        }
        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return (_pHead->_pNext->_val);
        }
        const T& front()const
        {
            return (_pHead->_pNext->_val);
        }
        T& back()
        {
            return (_pHead->_pPre->_val);
        }
        const T& back()const
        {
            return (_pHead->_pPre->_val);
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            //pos--;
            Node* new_node = new Node(val);
            Node* node_pos = pos._pNode;
            new_node->_pNext = node_pos;
            new_node->_pPre = node_pos->_pPre;
            node_pos->_pPre->_pNext = new_node;
            node_pos->_pPre = new_node;
            return pos;
          
            cout << "insert成功" << endl;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            Node* pnode = pos._pNode;
            Node* ret = pnode->_pNext;
            pnode->_pPre->_pNext = pnode->_pNext;
            pnode->_pNext->_pPre = pnode->_pPre;
            delete pnode;
            return ret;
            
        }
        void clear()
        {
            Node* pcur = _pHead->_pNext;
            while (pcur != _pHead)
            {
                Node* tmp = pcur->_pNext;
                delete pcur;
                pcur = tmp;
            }
            delete pcur;
            CreateHead();
        }
        void swap(list<T>& l)
        {
            std::swap(l._pHead, _pHead);
        }
    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead->_pPre = _pHead;
        }
        PNode _pHead;
    };
};
