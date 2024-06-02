class Solution {
public:
    string reverseStr(string s, int k) {
        bool is_reverse = 0;
        int index = 0;
        while(index<s.size())
        {
            reverse(s, index, min(index+k, int(s.size())));
            index+=2*k;
        }
        return s;
    }
    void reverse(string& s, int begin, int end)
    {
        while(begin<end)
        {
            swap(s[begin++], s[--end]);
        }
    }
};