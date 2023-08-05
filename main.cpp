/* NOTICE :
* To have good source dependence, always try to keep the rules :
*   1. for the "common include file" at a level, it ONLY includes the "common include file of its parent level".
*   2. for all the sources at a level, they ONLY include the "common include file of this level", and the "API
*      include files" under <root>/inc.
*   3. Only leave "API for public" in <root>/inc. Veil all the non-API details.
*
* "global API include files under <root>/inc", and let the current common include file includes its parent's
* common include file. That is, keep the dependency as "vertical and upward" instead of "horizontal or downward".
* For example, in this project :
*   1. the common include file "Arm_ShareDef_C.h" only includes files under <root>/inc.
*      All sources under ARM926EJS only include "Arm_ShareDef_C.h" and <root>/inc if necessary.
*   2. the common include file "N950_RegDef_C.h" only includes "Arm_ShareDef_C.h".
*      All sources under NUC950 only include "N950_RegDef_C.h" and <root>/inc if necessary.
*   3. All sources under NUC950EVB only include "N950_RegDef_C.h" and <root>/inc if necessary.
*/

#include "apiBasicTest.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("this program got %d arguments, argv[0]=%s", argc, argv[0]); 
	if (argc > 1){
		printf(", argv[1]=%s", argv[1]);
	}
	printf("\n");
	
	// try allocate memory by c-lib
	BasicTest_C_Test();

	// try floating point number operations
	BasicTest_Fpt_Test();

	// try C++ source in C++ language
	BasicTest_Cpp_Test();

	return 0;
}


