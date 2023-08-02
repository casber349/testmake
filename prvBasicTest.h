#ifndef __PRV_GNULIBSAMPLE_H

#define __PRV_GNULIBSAMPLE_H

// Only include config headers generated in private version !!
//#include "__cfgBasicTest.h"

// include those exposed to public
#include "pubBasicTest.h"

// library-private definitions. Not to be shared with external modules.
// NOTICE : DO NOT define basic types in public version of header.
//          This is to avoid conflict when multiple library were linked.
typedef unsigned char	__u8;
typedef unsigned short	__u16;
typedef unsigned long	__u32;
typedef char	__s8;
typedef short	__s16;
typedef long	__s32;

#define TRUE	1
#define FALSE	0
#ifndef NULL
	#define NULL	0
#endif

#define LSByte(word)	((__u8)((word) & 0xFF))
#define LSHalf(word)	((__u16)((word) & 0xFFFF))
#define MSByte(word)	((__u8)((word) >> 24))
#define MSHalf(word)	((__u16)((word) >>16))

#endif
