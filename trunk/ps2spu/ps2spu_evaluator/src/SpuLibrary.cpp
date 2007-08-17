#include "SpuLibrary.hpp"

ps2spu::SpuLibrary::SpuLibrary()
: lib_handle_(NULL)
{
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

ps2spu::SpuLibrary::~SpuLibrary()
{
    if(lib_handle_ != NULL)
    {
        ::FreeLibrary(lib_handle_);
        lib_handle_ = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

bool ps2spu::SpuLibrary::load(const char* file_name_ptr)
{
    // Free any existing libraries
    if(lib_handle_ != NULL)
    {
        ::FreeLibrary(lib_handle_);
    }

    // Attempt to load the new library
    if((lib_handle_ = ::LoadLibrary(file_name_ptr)) == NULL)
    {
        return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void* ps2spu::SpuLibrary::getFunction(const char* function_name_ptr)
{
    return ::GetProcAddress(lib_handle_, function_name_ptr);
}