/*********************************************************
 * File name: pando_types.h
 * Author: xiaoxiao
 * Versions: 1.0
 * Description: declare the types.
 * History:
 *   1.Date: Oct 28, 2015
 *     Author: xiaoxiao
 *     Modification:
 *********************************************************/

#ifndef _PANDO_TYPES_H_
#define _PANDO_TYPES_H_

#include "c_types.h"

typedef unsigned char       uint8_t;
typedef signed char         sint8_t;
typedef signed char         int8_t;
typedef unsigned short      uint16_t;
typedef signed short        sint16_t;
typedef signed short        int16_t;
typedef unsigned long       uint32_t;
typedef signed long         sint32_t;
typedef signed long         int32_t;
typedef signed long long    sint64_t;
typedef unsigned long long  uint64_t;
typedef signed long long    int64;
typedef signed long long    int64_t;
typedef unsigned long long  u_int64_t;
typedef float               real32_t;
typedef double              real64_t;

typedef unsigned char       uint8;
typedef unsigned char       u8;
typedef signed char         sint8;
typedef signed char         int8;
typedef signed char         s8;
typedef unsigned short      uint16;
typedef unsigned short      u16;
typedef signed short        sint16;
typedef signed short        s16;
typedef unsigned int        uint32;
typedef unsigned int        u_int;
typedef unsigned int        u32;
typedef signed int          sint32;
typedef signed int          s32;
typedef int                 int32;
typedef signed long long    sint64;
typedef unsigned long long  uint64;
typedef unsigned long long  u64;
typedef float               real32;
typedef float               float32;
typedef double              real64;
typedef double              double64;

typedef unsigned int        size_t;

//define data handler callback
typedef void (* data_handler_callback)(uint8_t *buffer, uint16_t length);

#ifndef NULL
#define NULL (void *)0
#endif /* NULL */

#define BIT(nr)                 (1UL << (nr))

#define REG_SET_BIT(_r, _b)  (*(volatile uint32_t*)(_r) |= (_b))
#define REG_CLR_BIT(_r, _b)  (*(volatile uint32_t*)(_r) &= ~(_b))

/*#ifdef ESP8266_PLANTFORM
#include "c_types.h"
#else
#define FUNCTION_ATTRIBUTE
#endif*/

#ifndef __cplusplus
typedef unsigned char   bool;
#define BOOL            bool
#define true            (1)
#define false           (0)
#define TRUE            true
#define FALSE           false

#endif /* !__cplusplus */

#endif /* _PANDO_TYPES_H_ */

