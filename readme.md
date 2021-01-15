# MacroPlus

## Usage

```cpp

#include <iostream>
#include "MacroPlus.hpp"

#define sequence_1_5 1, 2, 3, 4, 5
#define testvalue(x) Test<x>::value
#define dogbark(x) dog##x.bark()
#define $print(...) ::std::cout<< ' ' << $tocstr(__VA_ARGS__) << ::std::endl;

int main(int argc, char const *argv[])
{
    $print(
        $normalize(1,,,,,,,,,,2) \n
        $reduce(+, sequence_1_5) \n
        $reduce(+, $map(power2, sequence_1_5)) \n
        $reduce(&&, $map(testvalue, sequence_1_5)) \n
        $reduce(->, $map(dogbark, sequence_1_5)) \n
    )


#define FRUITS apple, banana, orange, tomato, strawberry, eggplant 
#define $rm_tomato $remove() //remove tomato
#define $rm_eggplant $remove() //remove eggplant

    $print(
        $rm_check(strawberry) \n
        $rm_check(tomato) \n
        $filter(FRUITS) \n
    )

#undef $rm_tomato

    $print(
        $filter(FRUITS) \n
        $unpack(7) \n
        $unpack(((7))) \n
        $unpack((7, 7)) \n
    )

#define Tree (1, 2, (3, 4), (5, (6, 7)), 8, (((9))))

    $print(
        $flat(Tree) \n
        $flat2(Tree) \n
        $flat3(Tree) \n
        $flat4(Tree) \n
    )

    return 0;
}




```

## Output

```

 1, 2 
 1 + 2 + 3 + 4 + 5 
 power2(1) + power2(2) + power2(3) + power2(4) + power2(5) 
 Test<1>::value && Test<2>::value && Test<3>::value && Test<4>::value && Test<5>::value 
 dog1.bark() -> dog2.bark() -> dog3.bark() -> dog4.bark() -> dog5.bark() 

 strawberry 
 
 apple, banana, orange, strawberry 

 apple, banana, orange, tomato, strawberry 
 7 
 (7) 
 7, 7 

 1, 2, (3, 4), (5, (6, 7)), 8, (((9))) 
 1, 2, 3, 4, 5, (6, 7), 8, ((9)) 
 1, 2, 3, 4, 5, 6, 7, 8, (9) 
 1, 2, 3, 4, 5, 6, 7, 8, 9 

```