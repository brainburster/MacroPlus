#ifndef _MACROPLUS_HPP
#define _MACROPLUS_HPP

#define $arg_n( \
      _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
     _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
     _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
     _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
     _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
     _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
     _61,_62,_63,N,...) N

#define $rseq_n() \
     63,62,61,60,                   \
     59,58,57,56,55,54,53,52,51,50, \
     49,48,47,46,45,44,43,42,41,40, \
     39,38,37,36,35,34,33,32,31,30, \
     29,28,27,26,25,24,23,22,21,20, \
     19,18,17,16,15,14,13,12,11,10, \
     9,8,7,6,5,4,3,2,1,0

#define $fixbug(x) x //for fixing msvc's bug
#define $_zero_arg(...) = _0, ##__VA_ARGS__
#define $_narg_i(...) $fixbug($arg_n(__VA_ARGS__))
#define $_narg(...) $_narg_i($_zero_arg(__VA_ARGS__), $rseq_n())

#define $_cat(name, n) name ## n
#define $cat(name, n) $_cat(name, n)
#define $overload(func, ...)  $fixbug($cat(func, $_narg(__VA_ARGS__))(__VA_ARGS__))

//$normalize(1,2,,,,,,3) => 1,2,3
#define $normalize(...) $overload($_normalize_, __VA_ARGS__)
#define $_a_comma_b(a, b, ...) $fixbug($cat($cat($_a_comma_b_, $_narg(a)), $_narg(b))(a, b)), ##__VA_ARGS__
#define $_a_comma_b_00(a, b)
#define $_a_comma_b_01(a, b) b
#define $_a_comma_b_10(a, b) a
#define $_a_comma_b_11(a, b) a, b
#define $_normalize_0()
#define $_normalize_1(a) a
#define $_normalize_2(...) $fixbug($_a_comma_b(__VA_ARGS__))
#define $_normalize_3(a, ...) $_normalize_2(a, $_normalize_2(__VA_ARGS__))
#define $_normalize_4(a, b, c, ...) $_normalize_2(a, $_normalize_3(b, c, __VA_ARGS__))
#define $_normalize_5(a, b, c, ...) $_normalize_2(a, $_normalize_4(b, c, __VA_ARGS__))
#define $_normalize_6(a, b, c, ...) $_normalize_2(a, $_normalize_5(b, c, __VA_ARGS__))
#define $_normalize_7(a, b, c, ...) $_normalize_2(a, $_normalize_6(b, c, __VA_ARGS__))
#define $_normalize_8(a, b, c, ...) $_normalize_2(a, $_normalize_7(b, c, __VA_ARGS__))
#define $_normalize_9(a, b, c, ...) $_normalize_2(a, $_normalize_8(b, c, __VA_ARGS__))
#define $_normalize_10(a, b, c, ...) $_normalize_2(a, $_normalize_9(b, c, __VA_ARGS__))
#define $_normalize_11(a, b, c, ...) $_normalize_2(a, $_normalize_10(b, c, __VA_ARGS__))
#define $_normalize_12(a, b, c, ...) $_normalize_2(a, $_normalize_11(b, c, __VA_ARGS__))
#define $_normalize_13(a, b, c, ...) $_normalize_2(a, $_normalize_12(b, c, __VA_ARGS__))
#define $_normalize_14(a, b, c, ...) $_normalize_2(a, $_normalize_13(b, c, __VA_ARGS__))
#define $_normalize_15(a, b, c, ...) $_normalize_2(a, $_normalize_14(b, c, __VA_ARGS__))
#define $_normalize_16(a, b, c, ...) $_normalize_2(a, $_normalize_15(b, c, __VA_ARGS__))
#define $_normalize_17(a, b, c, ...) $_normalize_2(a, $_normalize_16(b, c, __VA_ARGS__))
#define $_normalize_18(a, b, c, ...) $_normalize_2(a, $_normalize_17(b, c, __VA_ARGS__))
#define $_normalize_19(a, b, c, ...) $_normalize_2(a, $_normalize_18(b, c, __VA_ARGS__))
#define $_normalize_20(a, b, c, ...) $_normalize_2(a, $_normalize_19(b, c, __VA_ARGS__))
#define $_normalize_21(a, b, c, ...) $_normalize_2(a, $_normalize_20(b, c, __VA_ARGS__))
#define $_normalize_22(a, b, c, ...) $_normalize_2(a, $_normalize_21(b, c, __VA_ARGS__))
#define $_normalize_23(a, b, c, ...) $_normalize_2(a, $_normalize_22(b, c, __VA_ARGS__))
#define $_normalize_24(a, b, c, ...) $_normalize_2(a, $_normalize_23(b, c, __VA_ARGS__))
#define $_normalize_25(a, b, c, ...) $_normalize_2(a, $_normalize_24(b, c, __VA_ARGS__))
#define $_normalize_26(a, b, c, ...) $_normalize_2(a, $_normalize_25(b, c, __VA_ARGS__))
#define $_normalize_27(a, b, c, ...) $_normalize_2(a, $_normalize_26(b, c, __VA_ARGS__))
#define $_normalize_28(a, b, c, ...) $_normalize_2(a, $_normalize_27(b, c, __VA_ARGS__))
#define $_normalize_29(a, b, c, ...) $_normalize_2(a, $_normalize_28(b, c, __VA_ARGS__))
#define $_normalize_30(a, b, c, ...) $_normalize_2(a, $_normalize_29(b, c, __VA_ARGS__))
#define $_normalize_31(a, b, c, ...) $_normalize_2(a, $_normalize_30(b, c, __VA_ARGS__))
#define $_normalize_32(a, b, c, ...) $_normalize_2(a, $_normalize_31(b, c, __VA_ARGS__))

//$reduce(op,1,2,3) => 1 op 2 op 3
#define $reduce(...) $overload($_reduce_, __VA_ARGS__)
#define $_reduce_0()
#define $_reduce_1(op)
#define $_reduce_2(op, a)      a
#define $_reduce_3(op, a, b)   a op b
#define $_reduce_4(op, a, ...) $fixbug(a op $_reduce_3(op, __VA_ARGS__))
#define $_reduce_5(op, a, ...) $fixbug(a op $_reduce_4(op, __VA_ARGS__))
#define $_reduce_6(op, a, ...) $fixbug(a op $_reduce_5(op, __VA_ARGS__))
#define $_reduce_7(op, a, ...) $fixbug(a op $_reduce_6(op,  __VA_ARGS__))
#define $_reduce_8(op, a, ...) $fixbug(a op $_reduce_7(op,  __VA_ARGS__))
#define $_reduce_9(op, a, ...) $fixbug(a op $_reduce_8(op,  __VA_ARGS__))
#define $_reduce_10(op, a, ...) $fixbug(a op $_reduce_9(op,  __VA_ARGS__))
#define $_reduce_11(op, a, ...) $fixbug(a op $_reduce_10(op,  __VA_ARGS__))
#define $_reduce_12(op, a, ...) $fixbug(a op $_reduce_11(op,  __VA_ARGS__))
#define $_reduce_13(op, a, ...) $fixbug(a op $_reduce_12(op,  __VA_ARGS__))
#define $_reduce_14(op, a, ...) $fixbug(a op $_reduce_13(op,  __VA_ARGS__))
#define $_reduce_15(op, a, ...) $fixbug(a op $_reduce_14(op,  __VA_ARGS__))
#define $_reduce_16(op, a, ...) $fixbug(a op $_reduce_15(op,  __VA_ARGS__))
#define $_reduce_17(op, a, ...) $fixbug(a op $_reduce_16(op,  __VA_ARGS__))
#define $_reduce_18(op, a, ...) $fixbug(a op $_reduce_17(op,  __VA_ARGS__))
#define $_reduce_19(op, a, ...) $fixbug(a op $_reduce_18(op,  __VA_ARGS__))
#define $_reduce_20(op, a, ...) $fixbug(a op $_reduce_19(op,  __VA_ARGS__))
#define $_reduce_21(op, a, ...) $fixbug(a op $_reduce_20(op,  __VA_ARGS__))
#define $_reduce_22(op, a, ...) $fixbug(a op $_reduce_21(op,  __VA_ARGS__))
#define $_reduce_23(op, a, ...) $fixbug(a op $_reduce_22(op,  __VA_ARGS__))
#define $_reduce_24(op, a, ...) $fixbug(a op $_reduce_23(op,  __VA_ARGS__))
#define $_reduce_25(op, a, ...) $fixbug(a op $_reduce_24(op,  __VA_ARGS__))
#define $_reduce_26(op, a, ...) $fixbug(a op $_reduce_25(op,  __VA_ARGS__))
#define $_reduce_27(op, a, ...) $fixbug(a op $_reduce_26(op,  __VA_ARGS__))
#define $_reduce_28(op, a, ...) $fixbug(a op $_reduce_27(op,  __VA_ARGS__))
#define $_reduce_29(op, a, ...) $fixbug(a op $_reduce_28(op,  __VA_ARGS__))
#define $_reduce_30(op, a, ...) $fixbug(a op $_reduce_29(op,  __VA_ARGS__))
#define $_reduce_31(op, a, ...) $fixbug(a op $_reduce_30(op,  __VA_ARGS__))
#define $_reduce_32(op, a, ...) $fixbug(a op $_reduce_31(op,  __VA_ARGS__))
//...

//$map(func, 1, 2, 3) => func(1), func(2), func(3)
#define $map(...) $overload($_map_, __VA_ARGS__)
#define $_map_0()
#define $_map_1(func)
#define $_map_2(func, a) func(a)
#define $_map_3(func, a, b) func(a), func(b)
#define $_map_4(func, a, ...) func(a), $fixbug($_map_3(func, __VA_ARGS__))
#define $_map_5(func, a, ...) func(a), $fixbug($_map_4(func, __VA_ARGS__))
#define $_map_6(func, a, ...) func(a), $fixbug($_map_5(func, __VA_ARGS__))
#define $_map_7(func, a, ...) func(a), $fixbug($_map_6(func, __VA_ARGS__))
#define $_map_8(func, a, ...) func(a), $fixbug($_map_7(func, __VA_ARGS__))
#define $_map_9(func, a, ...) func(a), $fixbug($_map_8(func, __VA_ARGS__))
#define $_map_10(func, a, ...) func(a), $fixbug($_map_9(func, __VA_ARGS__))
#define $_map_11(func, a, ...) func(a), $fixbug($_map_10(func, __VA_ARGS__))
#define $_map_12(func, a, ...) func(a), $fixbug($_map_11(func, __VA_ARGS__))
#define $_map_13(func, a, ...) func(a), $fixbug($_map_12(func, __VA_ARGS__))
#define $_map_14(func, a, ...) func(a), $fixbug($_map_13(func, __VA_ARGS__))
#define $_map_15(func, a, ...) func(a), $fixbug($_map_14(func, __VA_ARGS__))
#define $_map_16(func, a, ...) func(a), $fixbug($_map_15(func, __VA_ARGS__))
#define $_map_17(func, a, ...) func(a), $fixbug($_map_16(func, __VA_ARGS__))
#define $_map_18(func, a, ...) func(a), $fixbug($_map_17(func, __VA_ARGS__))
#define $_map_19(func, a, ...) func(a), $fixbug($_map_18(func, __VA_ARGS__))
#define $_map_20(func, a, ...) func(a), $fixbug($_map_19(func, __VA_ARGS__))
#define $_map_21(func, a, ...) func(a), $fixbug($_map_20(func, __VA_ARGS__))
#define $_map_22(func, a, ...) func(a), $fixbug($_map_21(func, __VA_ARGS__))
#define $_map_23(func, a, ...) func(a), $fixbug($_map_22(func, __VA_ARGS__))
#define $_map_24(func, a, ...) func(a), $fixbug($_map_23(func, __VA_ARGS__))
#define $_map_25(func, a, ...) func(a), $fixbug($_map_24(func, __VA_ARGS__))
#define $_map_26(func, a, ...) func(a), $fixbug($_map_25(func, __VA_ARGS__))
#define $_map_27(func, a, ...) func(a), $fixbug($_map_26(func, __VA_ARGS__))
#define $_map_28(func, a, ...) func(a), $fixbug($_map_27(func, __VA_ARGS__))
#define $_map_29(func, a, ...) func(a), $fixbug($_map_28(func, __VA_ARGS__))
#define $_map_30(func, a, ...) func(a), $fixbug($_map_29(func, __VA_ARGS__))
#define $_map_31(func, a, ...) func(a), $fixbug($_map_30(func, __VA_ARGS__))
#define $_map_32(func, a, ...) func(a), $fixbug($_map_31(func, __VA_ARGS__))
//...

#define $_tocstr(...) #__VA_ARGS__
#define $tocstr(...)  $_tocstr(__VA_ARGS__)

#define $_get_sec(x, n, ...) n
#define $_check(x, ...) $fixbug($_get_sec(__VA_ARGS__, x))
#define $remove(x) x, 
//usage:
//#define $rm_42 $remove()
//$rm_test(5) => 5
//$rm_test(42) => 0
#define $rm_test(x) $_check(x, $fixbug($_cat($rm_, x)))

//#define $rm_4 $remove()
//$filter(1,2,3,4,5)=> 1, 2, 3, 5
#define $filter(...) $normalize($map($rm_test, __VA_ARGS__))

//$pack(1,2,3,4,5) => (1,2,3,4,5)
#define $pack(...) (__VA_ARGS__)
#define $expand(...) __VA_ARGS__
#define $_unpack_get_sec(x, n, ...) $expand n
#define $_unpack_check(x, ...) $fixbug($_unpack_get_sec(__VA_ARGS__, x))
#define $_unpack(...) (__VA_ARGS__), (__VA_ARGS__)
//$unpack((1,2,3,4,5)) => 1, 2, 3, 4, 5
#define $unpack(x) $_unpack_check((x),$_unpack x)

#define $flat(...) $map($unpack, __VA_ARGS__) //$flat1
#define $flat1(...) $map($unpack, __VA_ARGS__)
#define $flat2(...) $map($unpack, $flat1(__VA_ARGS__))
#define $flat3(...) $map($unpack, $flat2(__VA_ARGS__))
#define $flat4(...) $map($unpack, $flat3(__VA_ARGS__))
#define $flat5(...) $map($unpack, $flat4(__VA_ARGS__))
#define $flat6(...) $map($unpack, $flat5(__VA_ARGS__))
#define $flat7(...) $map($unpack, $flat6(__VA_ARGS__))
#define $flat8(...) $map($unpack, $flat7(__VA_ARGS__))

#endif // !_MACROPLUS_HPP
