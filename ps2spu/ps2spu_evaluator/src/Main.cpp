#include "SpuLibrary.hpp"
#include "PS2Edefs.hpp"
#include <iostream>
#include <UnitTest++/UnitTest++.h>
using namespace std;

int main(int argc, char* argv[])
{
    // First run tests on this program itself
    cout << "Evaluator Unit Test Results" << endl;
    cout << "============================" << endl;

    UnitTest::RunAllTests();
    cout << endl << endl;

    // Attempt to load the library provided as the first argument
    ps2spu::SpuLibrary library;

    if(!library.load(argv[1]))
    {
        cout << "Could not load library: " << argv[1] << endl;
        return EXIT_FAILURE;
    }

    // Output some generic shit about the library
    cout << "Library Details" << endl;
    cout << "================" << endl;

    // Get the library name
    _PS2EgetLibName PS2EgetLibName = (_PS2EgetLibName)library.getFunction("PS2EgetLibName");
    cout << "Name: " << PS2EgetLibName() << endl;

    // Get the library version
    _PS2EgetLibVersion2 PS2EgetLibVersion = (_PS2EgetLibVersion2)library.getFunction("PS2EgetLibVersion2");
    u32 version = PS2EgetLibVersion(PS2E_LT_SPU2);
    u32 version_maj = (version >> 8) & 0xFF;
    u32 version_min = (version) & 0xFF;
    cout << "Version: " << version_maj << "." << version_min << endl;

    // Run the library unit tests
    cout << endl << endl;
    cout << "Library Test Results" << endl;
    cout << "=====================" << endl;
    _SPU2test SPU2test = (_SPU2test)library.getFunction("SPU2test");
    SPU2test();

    return EXIT_SUCCESS;
}