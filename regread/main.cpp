#include "include/reg_reader.h"
#include <iostream>

using namespace std;
using namespace reg;
//int main()
int main(int argc, const char** args)
{
    cout << args[0];
    if(argc>=2) cout << args[1];
    if(argc>=3) {
//        const _str pat("(rpool(/[^/]+){0,})"), file("/etc/fstab");
        const _str pat(args[1]), file(args[2]);
        _rex rx(pat);
        reg_reader reader(rx,file,64);
        while(reader.isGood())
            ++reader;
        for(auto i = reader.operator*().cbegin(), e = reader.operator*().cend(); i!=e ;++i) {
            cout << *i;
            cout << "\n";
        }
        return 0;
    }
    return 1;
}
