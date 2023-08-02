// for library itself, its source refers to "private" version of headers when it is needed.
// notice the file is generated with filename as __prv$(FEATURE).h.
#include "prvBasicTest.h"

#include <stdio.h>
#include <stdlib.h>		// for malloc, free

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
void BasicTest_C_Test(void)
{
	__u32 * pu32Test1 = 0;

	printf("Allocate test \r\n");
	pu32Test1 = (__u32 *)malloc(sizeof(__u32));
	if (pu32Test1 != NULL) {
		printf("Allocated U32 buffer (adr=%p): origval=0x%08lx, ", pu32Test1, *pu32Test1);
		*pu32Test1 = 0x12345678;
		printf("newval=0x%08lx \r\n", *pu32Test1);
		free(pu32Test1);
	}
	else {
		printf("Allocate test failed !\r\n");
	}
}
