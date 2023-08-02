/// for library itself, its source refers to "private" version of headers when it is needed.
// notice the file is generated with filename as __prv$(FEATURE).h.
#include "prvBasicTest.h"

#include <stdio.h>

// NEVER USE iostream in embedded system !! it causes more code and more unresolved symbols pulled in !
// #include <iostream>
// using namespace std;

class CTestBase {
private:
	__u32 u32PrivData;
	__u32 u32ProtData;
protected:
	__u32 GetProtData(void) { return u32ProtData; }
public:
	__u32 u32PubData;

	CTestBase(void);
	CTestBase(__u32 PrivData, __u32 ProtData, __u32 PubData);
	virtual ~CTestBase();

	void ShowPrivateData(void);
	void ShowPublicData(void);
};

class CTestDerived : CTestBase {
private:
	__u32 u32PrivData;

public:
	CTestDerived(__u32 PrivData);
	~CTestDerived(void) { printf("destroy Derived instance %p\r\n", this); }
	void ShowAllData(void);
};

CTestBase::CTestBase(void)
{
	printf("create CTestBase instance with default data, %p\r\n", this);
	u32PrivData = 1234;
	u32ProtData = 5678;
	u32PubData = 90;
}

CTestBase::CTestBase(__u32 PrivData, __u32 ProtData, __u32 PubData)
{
	printf("create CTestBase instance with data specified, %p\r\n", this);

	u32PrivData = PrivData;
	u32ProtData = ProtData;
	u32PubData = PubData;
}

CTestBase::~CTestBase()
{
	printf("destroy CTestBase instance %p\r\n", this);
}

void CTestBase::ShowPrivateData(void)
{
	// NEVER USE iostream in embedded system !! it causes more code and more unresolved symbols pulled in !
	// cout << "Private Data = " << u32PrivData << endl;
	printf("Private Data = %ld\r\n", u32PrivData);
}

void CTestBase::ShowPublicData(void)
{
	printf("Public Data = %ld\r\n", u32PubData);
}

CTestDerived::CTestDerived(__u32 PrivData)
{
	u32PrivData = PrivData;
	printf("create derived instance %p with data=%ld\r\n", this, PrivData);
}

void CTestDerived::ShowAllData(void)
{
	printf("Private data of this obj is %ld, Protected data of base object is %ld \r\n",
			u32PrivData, GetProtData());
}

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
void BasicTest_Cpp_Test(void)
{
	CTestBase TestBase;
	
	TestBase.ShowPublicData();
	TestBase.ShowPrivateData();

	CTestDerived *pDerivedObj = new CTestDerived(34);
	pDerivedObj->ShowAllData();
	delete pDerivedObj;
}

