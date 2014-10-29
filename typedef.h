/*
   ITU-T G.729A Speech Coder    ANSI-C Source Code
   Version 1.1    Last modified: September 1996

   Copyright (c) 1996,
   AT&T, France Telecom, NTT, Universite de Sherbrooke, Lucent Technologies
   All rights reserved.
*/

#include <stdint.h>

#if defined(_MSC_VER)
#	define G729_INLINE	__forceinline
#elif defined(__GNUC__) && !defined(__APPLE__)
#	define G729_INLINE	__inline
#else
#	define G729_INLINE	
#endif

#if ANDROID || TARGET_OS_EMBEDDED || defined(_WIN32_WCE)
#	define G729_ARM 1
#else
#	define G729_ARM 0
#endif
