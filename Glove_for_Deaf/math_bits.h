/*
 * math_bits.h
 *
 * Created: 3/5/2022 10:02:45 AM
 *  Author: Yasser & Mahmoud
 */ 


#ifndef MATH_BITS_H_
#define MATH_BITS_H_

#define SET_BIT(REG, BIT)    (REG |= (1<<BIT))
#define CLR_BIT(REG, BIT)    (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG, BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG, BIT)    ((REG>>BIT) & 0x01)


#endif /* MATH_BITS_H_ */