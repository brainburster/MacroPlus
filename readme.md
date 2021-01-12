# MacroPlus

## Usage

```cpp

#include <iostream>
#include "MacroPlus.hpp"

#define _1_5 1, 2, 3, 4, 5
#define test(a) Test<a>::value
#define dog(a) dog##a.bark()

// int power2(int a)
// {
//     return a * a;
// }

int main(int argc, char const *argv[])
{
    using namespace std;

    cout << "_1_5 : " << $tocstr(_1_5)  <<endl;
    cout << "test(a) : " << $tocstr(test(a))  <<endl;
    cout << "dog(a) : " << $tocstr(dog(a))  <<endl;
    cout << endl;
    cout << "$map(power2, _1_5) \t\t: " << $tocstr($map(power2, _1_5)) <<endl;
    cout << "$reduce(+, _1_5) \t\t: " << $tocstr($reduce(+, _1_5)) <<endl;
    cout << "$reduce(+, $map(power2, _1_5)) \t: " << $tocstr($reduce(+, $map(power2, _1_5))) <<endl;
    cout << "$reduce(+, $map(test, _1_5)) \t: " << $tocstr($reduce(&&, $map(test, _1_5))) <<endl;
    cout << "$reduce(+, $map(dog, _1_5)) \t: " << $tocstr($reduce(and , $map(dog, _1_5))) <<endl;
    cout << "..." <<endl;

    return 0;
}


```

```

_1_5 : 1, 2, 3, 4, 5
test(a) : Test<a>::value
dog(a) : doga.bark()

$map(power2, _1_5)              : (power2(1)), (power2(2)), (power2(3)), (power2(4)), (power2(5))
$reduce(+, _1_5)                : (1) + (2) + (3) + (4) + (5)
$reduce(+, $map(power2, _1_5))  : ((power2(1))) + ((power2(2))) + ((power2(3))) + ((power2(4))) + ((power2(5)))
$reduce(+, $map(test, _1_5))    : ((Test<1>::value)) && ((Test<2>::value)) && ((Test<3>::value)) && ((Test<4>::value)) && ((Test<5>::value))
$reduce(+, $map(dog, _1_5))     : ((dog1.bark())) and ((dog2.bark())) and ((dog3.bark())) and ((dog4.bark())) and ((dog5.bark()))

```