////////////////////////////////////////////////////////////////////////////////
// ps2spu - SPU2 emulator for Pcsx2.
// Copyright (C) 2007 ps2spu team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
////////////////////////////////////////////////////////////////////////////////

#ifndef SPU_LIBRARY_HPP
#define SPU_LIBRARY_HPP

#undef PLUGINfuncs
#include "PS2Edefs.hpp"

namespace ps2spu
{
    //! \brief Manages access to an SPU2 DLL library
    class SpuLibrary
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        // (Con/De)structors
        ////////////////////////////////////////////////////////////////////////

        //! \brief Constructor
        //! \return Void
        SpuLibrary();
        
        //! \brief Destructor
        //! \return Void
        ~SpuLibrary();

        ////////////////////////////////////////////////////////////////////////
        // Mutators
        ////////////////////////////////////////////////////////////////////////

        //! \brief Attempts to load the given DLL file
        //! \return Boolean True if the library was loaded, false otherwise.
        bool load(const char* file_name_ptr);

        ////////////////////////////////////////////////////////////////////////
        // Accessors
        ////////////////////////////////////////////////////////////////////////
        
        //! \brief Loads the given function out of the library
        //! \return The address of the given function in the library
        void* getFunction(const char* function_name_ptr);
    protected:
        ////////////////////////////////////////////////////////////////////////
        // Member Variables
        ////////////////////////////////////////////////////////////////////////

        HINSTANCE lib_handle_;
    };
}

#endif // SPU_LIBRARY_HPP