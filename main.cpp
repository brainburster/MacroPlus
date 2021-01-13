#include <iostream>
#include "MacroPlus.hpp"

#define sequence_1_5 1, 2, 3, 4, 5
#define testvalue(a) Test<a>::value
#define dogbark(a) dog##a.bark()

int main(int argc, char const *argv[])
{
    using namespace std;

    cout << "$tocstr : \n" << $tocstr(
        abcdefg;
        hijklmn,
        opqrstu\n
        vwxyz
    ) <<endl;
    cout << "$map(power2, _1_5) \t\t\t:  " << $tocstr($map(power2, sequence_1_5)) <<endl;
    cout << "$reduce(+, _1_5) \t\t\t:  " << $tocstr($reduce(+, sequence_1_5)) <<endl;
    cout << "$reduce(+, $map(power2, _1_5)) \t\t:  " << $tocstr($reduce(+, $map(power2, sequence_1_5))) <<endl;
    cout << "$reduce(&&, $map(testvalue, _1_5)) \t:  " << $tocstr($reduce(&&, $map(testvalue, sequence_1_5))) <<endl;
    cout << "$reduce(->, $map(dogbark, _1_5)) \t:  " << $tocstr($reduce(-> , $map(dogbark, sequence_1_5))) <<endl;

    return 0;
}
