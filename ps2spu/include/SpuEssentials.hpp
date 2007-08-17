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

#ifndef PS2SPU_ESSENTIALS_HPP
#define PS2SPU_ESSENTIALS_HPP

#include "PS2Edefs.hpp"
#include "PS2Etypes.hpp"
#include <iostream>
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>

namespace ps2spu
{
    //! Library name and version definitions
    #define PS2SPU_LIBRARY_NAME "ps2spu"
    #define PS2SPU_VERSION_MAJOR 0
    #define PS2SPU_VERSION_MINOR 0

    #define MAKE_PS2E_VERSION(maj,min) (((PS2E_SPU2_VERSION) << 16) | \
                                       ((maj & 0xFF) << 8) | \
                                       ((min & 0xFF)))

    // Compiler/OS definitions
    #if defined(_MSC_VER)
        #define PS2SPU_MSVC
        #define PS2SPU_WINDOWS
    #elif defined(__MINGW32__)
        #define PS2SPU_MINGW32
        #define PS2SPU_WINDOWS
    #elif defined(__APPLE__)
        #define PS2SPU_APPLE
        #define PS2SPU_POSIX
    #else
        #define PS2SPU_LINUX
        #define PS2SPU_POSIX
    #endif

    #define PS2SPU_COMPILE_MODE_DEBUG ('D' + 'E' + 'B' + 'U' + 'G')
    #define PS2SPU_COMPILE_MODE_RELEASE ('R' + 'E' + 'L' + 'E' + 'A' + 'S' + 'E')

    #ifndef PS2SPU_COMPILE_MODE
        #ifdef _DEBUG
            #define PS2SPU_COMPILE_MODE_STRING "DEBUG"
            #define PS2SPU_COMPILE_MODE PS2SPU_COMPILE_MODE_DEBUG
        #else
            #define PS2SPU_COMPILE_MODE_STRING "RELEASE"
            #define PS2SPU_COMPILE_MODE PS2SPU_COMPILE_MODE_RELEASE
        #endif
    #endif

    //! Handles used when dealing with the DLL in windows
    #ifdef PS2SPU_WINDOWS
        static HINSTANCE MODULE_HANDLE = NULL;
        static HWND      WINDOW_HANDLE = NULL;
    #else
    #endif

    //! Callbacks into PCSX2
    extern void (*SPU2_CALLBACK_PTR)(void);
    extern void (*DMA4_CALLBACK_PTR)(void);
    extern void (*DMA7_CALLBACK_PTR)(void);
}

#endif // PS2SPU_ESSENTIALS_HPP