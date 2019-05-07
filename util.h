#ifndef __UTIL_H__
#define __UTIL_H__

#define set_bit(register_8, bit) (register_8 |= (1 << bit))
#define clear_bit(register_8, bit) (register_8 &= ~(1 << bit))
#define toggle_bit(register_8, bit) (register_8 ^= (1 << bit))

#endif // __UTIL_H__
