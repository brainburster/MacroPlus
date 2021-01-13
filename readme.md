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

```

```

$tocstr : 
abcdefg; hijklmn, opqrstu
 vwxyz
$map(power2, _1_5)                      :  (power2(1)), (power2(2)), (power2(3)), (power2(4)), (power2(5))
$reduce(+, _1_5)                        :  (1) + (2) + (3) + (4) + (5)
$reduce(+, $map(power2, _1_5))          :  ((power2(1))) + ((power2(2))) + ((power2(3))) + ((power2(4))) + ((power2(5)))
$reduce(&&, $map(testvalue, _1_5))      :  ((Test<1>::value)) && ((Test<2>::value)) && ((Test<3>::value)) && ((Test<4>::value)) && ((Test<5>::value))
$reduce(->, $map(dogbark, _1_5))        :  ((dog1.bark())) -> ((dog2.bark())) -> ((dog3.bark())) -> ((dog4.bark())) -> ((dog5.bark()))

```