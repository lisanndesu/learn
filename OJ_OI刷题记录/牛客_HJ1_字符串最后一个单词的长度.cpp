#include <iostream>
#include <string>
using namespace std;

int main() {
    string get;
    int ans = 0;
    getline(cin, get);
    string::iterator end = get.end();
    while(1 && *end!=' ')
    {
        if(end==get.begin())
        {
            ans=get.size()+1;
            break;
        }
        // cout<<*end;
        end--;
        ans++;
    }
    cout<<ans-1;
}
// 64 位输出请用 printf("%lld")