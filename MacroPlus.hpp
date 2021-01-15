#ifndef _MACROPLUS_HPP
#define _MACROPLUS_HPP

#ifndef __GNUC__
#pragma region Macro$overload
#endif

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
#define $zero_arg(...) = _0, ##__VA_ARGS__
#define $narg_i(...) $fixbug($arg_n(__VA_ARGS__))
#define $narg(...) $narg_i($zero_arg(__VA_ARGS__), $rseq_n())

#define $_cat(name, n) name##n
#define $cat(name, n) $_cat(name, n)
#define $overload(func, ...)  $fixbug($cat(func, $narg(__VA_ARGS__))(__VA_ARGS__))

#ifndef __GNUC__
#pragma endregion
#endif

#ifndef __GNUC__
#pragma region Normalize
#endif

#define $a_comma_b(a, b, ...) $fixbug($cat($cat($a_comma_b_, $narg(a)), $narg(b))(a, b)), ##__VA_ARGS__
#define $a_comma_b_00(a, b)
#define $a_comma_b_01(a, b) b
#define $a_comma_b_10(a, b) a
#define $a_comma_b_11(a, b) a, b

#define $normalize(...) $overload($normalize_, __VA_ARGS__)
#define $normalize_0()
#define $normalize_1(a) a
#define $normalize_2(...) $fixbug($a_comma_b(__VA_ARGS__))
#define $normalize_3(a, ...) $normalize_2(a, $normalize_2(__VA_ARGS__))
#define $normalize_4(a, b, c, ...) $normalize_2(a, $normalize_3(b, c, __VA_ARGS__))
#define $normalize_5(a, b, c, ...) $normalize_2(a, $normalize_4(b, c, __VA_ARGS__))
#define $normalize_6(a, b, c, ...) $normalize_2(a, $normalize_5(b, c, __VA_ARGS__))
#define $normalize_7(a, b, c, ...) $normalize_2(a, $normalize_6(b, c, __VA_ARGS__))
#define $normalize_8(a, b, c, ...) $normalize_2(a, $normalize_7(b, c, __VA_ARGS__))
#define $normalize_9(a, b, c, ...) $normalize_2(a, $normalize_8(b, c, __VA_ARGS__))
#define $normalize_10(a, b, c, ...) $normalize_2(a, $normalize_9(b, c, __VA_ARGS__))
#define $normalize_11(a, b, c, ...) $normalize_2(a, $normalize_10(b, c, __VA_ARGS__))
#define $normalize_12(a, b, c, ...) $normalize_2(a, $normalize_11(b, c, __VA_ARGS__))
#define $normalize_13(a, b, c, ...) $normalize_2(a, $normalize_12(b, c, __VA_ARGS__))
#define $normalize_14(a, b, c, ...) $normalize_2(a, $normalize_13(b, c, __VA_ARGS__))
#define $normalize_15(a, b, c, ...) $normalize_2(a, $normalize_14(b, c, __VA_ARGS__))
#define $normalize_16(a, b, c, ...) $normalize_2(a, $normalize_15(b, c, __VA_ARGS__))
#define $normalize_17(a, b, c, ...) $normalize_2(a, $normalize_16(b, c, __VA_ARGS__))
#define $normalize_18(a, b, c, ...) $normalize_2(a, $normalize_17(b, c, __VA_ARGS__))
#define $normalize_19(a, b, c, ...) $normalize_2(a, $normalize_18(b, c, __VA_ARGS__))
#define $normalize_20(a, b, c, ...) $normalize_2(a, $normalize_19(b, c, __VA_ARGS__))
#define $normalize_21(a, b, c, ...) $normalize_2(a, $normalize_20(b, c, __VA_ARGS__))
#define $normalize_22(a, b, c, ...) $normalize_2(a, $normalize_21(b, c, __VA_ARGS__))
#define $normalize_23(a, b, c, ...) $normalize_2(a, $normalize_22(b, c, __VA_ARGS__))
#define $normalize_24(a, b, c, ...) $normalize_2(a, $normalize_23(b, c, __VA_ARGS__))
#define $normalize_25(a, b, c, ...) $normalize_2(a, $normalize_24(b, c, __VA_ARGS__))
#define $normalize_26(a, b, c, ...) $normalize_2(a, $normalize_25(b, c, __VA_ARGS__))
#define $normalize_27(a, b, c, ...) $normalize_2(a, $normalize_26(b, c, __VA_ARGS__))
#define $normalize_28(a, b, c, ...) $normalize_2(a, $normalize_27(b, c, __VA_ARGS__))
#define $normalize_29(a, b, c, ...) $normalize_2(a, $normalize_28(b, c, __VA_ARGS__))
#define $normalize_30(a, b, c, ...) $normalize_2(a, $normalize_29(b, c, __VA_ARGS__))
#define $normalize_31(a, b, c, ...) $normalize_2(a, $normalize_30(b, c, __VA_ARGS__))
#define $normalize_32(a, b, c, ...) $normalize_2(a, $normalize_31(b, c, __VA_ARGS__))

#ifndef __GNUC__
#pragma endregion
#endif

#ifndef __GNUC__
#pragma region Reduce
#endif

#define $reduce_0() 
#define $reduce_1(op)
#define $reduce_2(op, a)      (a)
#define $reduce_3(op, a, b)   (a) op (b)
#define $reduce_4(op, a, ...) $fixbug((a) op $reduce_3(op, __VA_ARGS__))
#define $reduce_5(op, a, ...) $fixbug((a) op $reduce_4(op, __VA_ARGS__))
#define $reduce_6(op, a, ...) $fixbug((a) op $reduce_5(op, __VA_ARGS__))
#define $reduce_7(op, a, ...) $fixbug((a) op $reduce_6(op,  __VA_ARGS__))
#define $reduce_8(op, a, ...) $fixbug((a) op $reduce_7(op,  __VA_ARGS__))
#define $reduce_9(op, a, ...) $fixbug((a) op $reduce_8(op,  __VA_ARGS__))
#define $reduce_10(op, a, ...) $fixbug((a) op $reduce_9(op,  __VA_ARGS__))
#define $reduce_11(op, a, ...) $fixbug((a) op $reduce_10(op,  __VA_ARGS__))
#define $reduce_12(op, a, ...) $fixbug((a) op $reduce_11(op,  __VA_ARGS__))
#define $reduce_13(op, a, ...) $fixbug((a) op $reduce_12(op,  __VA_ARGS__))
#define $reduce_14(op, a, ...) $fixbug((a) op $reduce_13(op,  __VA_ARGS__))
#define $reduce_15(op, a, ...) $fixbug((a) op $reduce_14(op,  __VA_ARGS__))
#define $reduce_16(op, a, ...) $fixbug((a) op $reduce_15(op,  __VA_ARGS__))
#define $reduce_17(op, a, ...) $fixbug((a) op $reduce_16(op,  __VA_ARGS__))
#define $reduce_18(op, a, ...) $fixbug((a) op $reduce_17(op,  __VA_ARGS__))
#define $reduce_19(op, a, ...) $fixbug((a) op $reduce_18(op,  __VA_ARGS__))
#define $reduce_20(op, a, ...) $fixbug((a) op $reduce_19(op,  __VA_ARGS__))
#define $reduce_21(op, a, ...) $fixbug((a) op $reduce_20(op,  __VA_ARGS__))
#define $reduce_22(op, a, ...) $fixbug((a) op $reduce_21(op,  __VA_ARGS__))
#define $reduce_23(op, a, ...) $fixbug((a) op $reduce_22(op,  __VA_ARGS__))
#define $reduce_24(op, a, ...) $fixbug((a) op $reduce_23(op,  __VA_ARGS__))
#define $reduce_25(op, a, ...) $fixbug((a) op $reduce_24(op,  __VA_ARGS__))
#define $reduce_26(op, a, ...) $fixbug((a) op $reduce_25(op,  __VA_ARGS__))
#define $reduce_27(op, a, ...) $fixbug((a) op $reduce_26(op,  __VA_ARGS__))
#define $reduce_28(op, a, ...) $fixbug((a) op $reduce_27(op,  __VA_ARGS__))
#define $reduce_29(op, a, ...) $fixbug((a) op $reduce_28(op,  __VA_ARGS__))
#define $reduce_30(op, a, ...) $fixbug((a) op $reduce_29(op,  __VA_ARGS__))
#define $reduce_31(op, a, ...) $fixbug((a) op $reduce_30(op,  __VA_ARGS__))
#define $reduce_32(op, a, ...) $fixbug((a) op $reduce_31(op,  __VA_ARGS__))
//...
#define $reduce(...) $overload($reduce_, __VA_ARGS__)

#ifndef __GNUC__
#pragma endregion
#endif

#ifndef __GNUC__
#pragma region Map
#endif
#define $map_0() 
#define $map_1(func) 
#define $map_2(func, a)      (func(a))
#define $map_3(func, a, b)   (func(a)), (func(b))
#define $map_4(func, a, ...) (func(a)), $fixbug($map_3(func, __VA_ARGS__))
#define $map_5(func, a, ...) (func(a)), $fixbug($map_4(func, __VA_ARGS__))
#define $map_6(func, a, ...) (func(a)), $fixbug($map_5(func, __VA_ARGS__))
#define $map_7(func, a, ...) (func(a)), $fixbug($map_6(func, __VA_ARGS__))
#define $map_8(func, a, ...) (func(a)), $fixbug($map_7(func, __VA_ARGS__))
#define $map_9(func, a, ...) (func(a)), $fixbug($map_8(func, __VA_ARGS__))
#define $map_10(func, a, ...) (func(a)), $fixbug($map_9(func, __VA_ARGS__))
#define $map_11(func, a, ...) (func(a)), $fixbug($map_10(func, __VA_ARGS__))
#define $map_12(func, a, ...) (func(a)), $fixbug($map_11(func, __VA_ARGS__))
#define $map_13(func, a, ...) (func(a)), $fixbug($map_12(func, __VA_ARGS__))
#define $map_14(func, a, ...) (func(a)), $fixbug($map_13(func, __VA_ARGS__))
#define $map_15(func, a, ...) (func(a)), $fixbug($map_14(func, __VA_ARGS__))
#define $map_16(func, a, ...) (func(a)), $fixbug($map_15(func, __VA_ARGS__))
#define $map_17(func, a, ...) (func(a)), $fixbug($map_16(func, __VA_ARGS__))
#define $map_18(func, a, ...) (func(a)), $fixbug($map_17(func, __VA_ARGS__))
#define $map_19(func, a, ...) (func(a)), $fixbug($map_18(func, __VA_ARGS__))
#define $map_20(func, a, ...) (func(a)), $fixbug($map_19(func, __VA_ARGS__))
#define $map_21(func, a, ...) (func(a)), $fixbug($map_20(func, __VA_ARGS__))
#define $map_22(func, a, ...) (func(a)), $fixbug($map_21(func, __VA_ARGS__))
#define $map_23(func, a, ...) (func(a)), $fixbug($map_22(func, __VA_ARGS__))
#define $map_24(func, a, ...) (func(a)), $fixbug($map_23(func, __VA_ARGS__))
#define $map_25(func, a, ...) (func(a)), $fixbug($map_24(func, __VA_ARGS__))
#define $map_26(func, a, ...) (func(a)), $fixbug($map_25(func, __VA_ARGS__))
#define $map_27(func, a, ...) (func(a)), $fixbug($map_26(func, __VA_ARGS__))
#define $map_28(func, a, ...) (func(a)), $fixbug($map_27(func, __VA_ARGS__))
#define $map_29(func, a, ...) (func(a)), $fixbug($map_28(func, __VA_ARGS__))
#define $map_30(func, a, ...) (func(a)), $fixbug($map_29(func, __VA_ARGS__))
#define $map_31(func, a, ...) (func(a)), $fixbug($map_30(func, __VA_ARGS__))
#define $map_32(func, a, ...) (func(a)), $fixbug($map_31(func, __VA_ARGS__))
//...
#define $map(...) $overload($map_, __VA_ARGS__)

#ifndef __GNUC__
#pragma endregion
#endif

#define $_tocstr(...) #__VA_ARGS__
#define $tocstr(...)  $_tocstr(__VA_ARGS__)


#endif // !_MACROPLUS_HPP