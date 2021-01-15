#include <iostream>
#include "MacroPlus.hpp"

#define sequence_1_5 1, 2, 3, 4, 5
#define testvalue(a) Test<a>::value
#define dogbark(a) dog##a.bark()

int main(int argc, char const *argv[])
{
    using namespace std;

    cout << $tocstr($reduce(+, sequence_1_5)) << endl;
    cout << $tocstr($map(power2, sequence_1_5)) << endl;
    cout << $tocstr($reduce(+, $map(power2, sequence_1_5))) << endl;
    cout << $tocstr($reduce(&&, $map(testvalue, sequence_1_5))) << endl;
    cout << $tocstr($reduce(->, $map(dogbark, sequence_1_5))) << endl;

#define $rm_2 $remove()
#define $rm_4 $remove()

    cout << $tocstr($rm_check(5)) << endl;
    cout << $tocstr($rm_check(4)) << endl;
    cout << $tocstr($filter(sequence_1_5)) << endl;

#undef $rm_4

    cout << $tocstr($filter(sequence_1_5)) << endl;

    return 0;
}
