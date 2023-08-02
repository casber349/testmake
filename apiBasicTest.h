#ifndef API_SAMPLE1_H

#define API_SAMPLE1_H

// for public info exposed by library, only public headers (files with name not led by "__") can be included.
// Notice the header file is generated with file name as pub$(FEATURE).h
#include "pubBasicTest.h"

//-------------------- C++ function ----------
// Every prototype declaration of C language source should be enclosed by this so that C++ module
// won't call them with assumed default function name mangling. just call it with this name exactly.
#ifdef __cplusplus
extern "C" {
#endif

/** \note
* Notice !!
*
* All the public header files to be included by other should have file names led by "module(feature)"
* instead of library "filename", so that to reduce the effort when changing library options for a single feature.
* in this case, this file should be named as pub"BasicTest".h instead of pub"GnuLibSample".h.
*
* This also applies to content of these files to be published. The content (definitions, prototypes)
* defined in these AL/API/common header files for public should have their names led by "feature-oriented"
* string, i.e. "BasicTest"_C_Test(...) instead of "GnuLibSample"_C_Test(...).
* Consider the case : if there are 2 libraries providing the same feature (say, USBH), with library name as
* libUSBH1.a and libUSBH2.a. If their definitions and prototypes were named USBH***, the gluing tasks during
* transferring from libUSBH1.a to libUSBH2.a will be much easier.
*/

void BasicTest_C_Test(void);
void BasicTest_Fpt_Test(void);

	#if (CONFIG_OS != NONOS)
void BasicTest_Rtos_Test(void);
	#endif

#ifdef __cplusplus
}
#endif
//-------------------- C++ function ----------
void BasicTest_Cpp_Test(void);

#endif
