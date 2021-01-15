# MacroPlus

## Usage

```cpp

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


```

## Output

```

1 + 2 + 3 + 4 + 5
power2(1), power2(2), power2(3), power2(4), power2(5)
power2(1) + power2(2) + power2(3) + power2(4) + power2(5)
Test<1>::value && Test<2>::value && Test<3>::value && Test<4>::value && Test<5>::value
dog1.bark() -> dog2.bark() -> dog3.bark() -> dog4.bark() -> dog5.bark()
5

1, 3, 5
1, 3, 4, 5

```