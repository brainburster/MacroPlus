# MacroPlus

## Usage

```cpp

#include <iostream>
#include "MacroPlus.hpp"

#define sequence_1_5 1, 2, 3, 4, 5
#define Fibonacci(x) Fibo<x>::value
#define exec(x) process##x.exec()
#define square(x) (x*x)
#define $print(...) ::std::cout<< ' ' << $tocstr(__VA_ARGS__) << ::std::endl;

int main(int argc, char const *argv[])
{
    $print(
        $normalize(1,,,,,,,,,,2) \n
        $reduce(+, sequence_1_5) \n
        $reduce(+, $map(square, sequence_1_5)) \n
        $reduce(*, $map(Fibonacci, sequence_1_5)) \n
        $reduce(&&, $map(exec, sequence_1_5)) \n
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
 (1*1) + (2*2) + (3*3) + (4*4) + (5*5) 
 Fibo<1>::value * Fibo<2>::value * Fibo<3>::value * Fibo<4>::value * Fibo<5>::value 
 process1.exec() && process2.exec() && process3.exec() && process4.exec() && process5.exec() 

 $rm_check(strawberry) 
 $rm_check(tomato) 
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