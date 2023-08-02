#ifndef PUB_GNULIBSAMPLE_H

#define PUB_GNULIBSAMPLE_H

// public definitions, such as common definitions to be referenced by headers under AL and API dirs,
// and library-private headers. Notice it should NOT expose config headers generated to avoid conflict.
// ...
// DO NOT include "cfgGnuLibSample.h" !!

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

#endif
