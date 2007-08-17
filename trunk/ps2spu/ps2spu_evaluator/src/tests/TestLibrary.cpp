#include "SpuLibrary.hpp"
#include <iostream>
#include <UnitTest++/UnitTest++.h>
using namespace UnitTest;
using namespace ps2spu;

class MockSpuLibrary : public SpuLibrary
{
public:
    HINSTANCE getHandle() const
    {
        return lib_handle_;
    }
};

struct SpuLibraryFixture
{
    MockSpuLibrary lib_;
};

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

TEST_FIXTURE(SpuLibraryFixture, TestThatLibraryIsInitiallyNull)
{
    CHECK(lib_.getHandle() == NULL);
}

TEST_FIXTURE(SpuLibraryFixture, TestThatLoadingANonExistantLibraryFails)
{
    CHECK(lib_.load("bad__12.dll") == false);
}

TEST_FIXTURE(SpuLibraryFixture, TestThatLoadingAValidLibrarySucceeds)
{
    CHECK(lib_.load("ps2spu_vc2005.dll") == true);
}

TEST_FIXTURE(SpuLibraryFixture, TestThatFunctionLoadingFailsOnBadFunction)
{
    CHECK(lib_.getFunction("poop") == NULL);
}

TEST_FIXTURE(SpuLibraryFixture, TestThatFunctionLoadingSucceedsOnGoodFunction)
{
    lib_.load("ps2spu_vc2005.dll");
    CHECK(lib_.getFunction("PS2EgetLibName") != NULL);
}