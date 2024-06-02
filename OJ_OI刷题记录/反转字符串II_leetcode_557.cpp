class Solution {
public:
    string reverseWords(string s) {
        int pcur = 0, prev = -1;
        while(pcur<s.size())
        {
            if(s[pcur]==' ')
            {
                reverse(s, prev, pcur);
                prev = pcur;
            }
            pcur++;
        }
        reverse(s, prev, pcur);
        return s;
    }

    void reverse(string& s, int begin, int end)
    {
        ++begin;
        --end;
        while(begin<end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};