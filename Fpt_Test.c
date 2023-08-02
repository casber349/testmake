/*
 * Fpt_Test.c
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: LCCHEN
 */
#include "prvBasicTest.h"

#include <stdio.h>

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
void BasicTest_Fpt_Test(void)
{
// disable this function so that not to use VFP instructions by default.
#if 1
	float fTest1 = 0.1f;
	float fTest2, fDiff;

	double fTest3 = 0.123412341234;
	double fTest4, lfDiff;

	long double fTest5 = 0.123412341234L;
	long double fTest6, LfDiff;

	// this part will need exe project to enable both
	//		1. Clib's stdio (printf), i.e., do not use tiny stdio like nu-stdio.
	//      2. enable config NEED_IO_FOR_FLOAT_POINT_NUMBER in Exe project.
	// however, this will bring in 20K code size more. try the following only when test.
	//
	// for printf format, %[total_width].[digits_after_decimal_point] f (single)/ lf(double) / Lf (long double)
	// 	 significant digits for generic single precision : 6~7 decimal digits.
	// 	 significant digits for generic double precision : > 12 decimal digits.
	// however ,
	//   A floating-point constant without an f, F, l, or L suffix has type double.
	//   If the letter f or F is the suffix, the constant has type float.
	//   If suffixed by the letter l or L, it has type long double
	/*
	printf("fp value print test : '%.3f','%.15lf','%.15Lf'\r\n", 0.02f, 0.1234123412341234, 0.1234123412341234L);
	*/

	// NOTICE
	//   We should not compare 2 floating point values by direct comparison equation like below :
	//       if (fp_val_a == fp_val_b) ...		// this cannot work.
	//   because there must be some imprecision in each floating value.
	//   we just take the epsilon (relative diffrence we can accept) small enough when comparing fp values.
	//   to see more details, refer to http://floating-point-gui.de/errors/comparison/
	printf("Single-precision Floating point number test : ");
	fTest2 = fTest1 * 0.2f;
	fDiff = (fTest2 - 0.02f)/0.02f;
	if (fDiff < 0) fDiff = -fDiff;
	if (fDiff >= 0.000001f) {	// take epsilon (relative difference acceptable) as 0.000001f here
		printf("Failed\r\n");
		return;
	}
	fTest2 /= 0.2f;
	fDiff = (fTest2 - 0.1f)/0.1f;
	if (fDiff < 0) fDiff = -fDiff;
	if (fDiff >= 0.000001f) {	// take epsilon (relative difference acceptable) as 0.000001f here
		printf("Failed\r\n");
		return;
	}
	printf("OK\r\n");

	printf("Double-precision Floating point number test : ");
	fTest4 = fTest3 * 0.3f;
	lfDiff = (fTest4 - 0.0370237023702)/0.0370237023702;
	if (lfDiff < 0) lfDiff = -lfDiff;
	if (lfDiff >= 0.000001) {
		printf("Failed\r\n");
		return;
	}
	fTest4 /= 0.3f;
	lfDiff = (fTest4 - 0.123412341234)/0.123412341234;
	if (lfDiff < 0) lfDiff = -lfDiff;
	if (lfDiff >= 0.000001) {
		printf("Failed\r\n");
		return;
	}
	printf("OK\r\n");

	printf("Long-Double-precision Floating point number test : ");
	fTest6 = fTest5 * 0.3f;
	LfDiff = (fTest6 - 0.0370237023702)/0.0370237023702;
	if (LfDiff < 0) LfDiff = -LfDiff;
	if (LfDiff >= 0.000001) {
		printf("Failed\r\n");
		return;
	}
	fTest6 /= 0.3f;
	LfDiff = (fTest6 - 0.123412341234)/0.123412341234;
	if (LfDiff < 0) LfDiff = -LfDiff;
	if (LfDiff >= 0.000001) {
		printf("Failed\r\n");
		return;
	}
	printf("OK\r\n");
#else
	printf("Floating point number test : skipped in order not to enable VFP.\r\n");
	printf("If this test is really needed, change HAVE_FLOAT_POINT_NUMBER as 'Y' in Lib_Config.inp.\r\n");
#endif
}



