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

#ifndef PS2SPU_MEMORY_HPP
#define PS2SPU_MEMORY_HPP

#include "PS2Etypes.hpp"

namespace ps2spu { 
    namespace memory {
        ////////////////////////////////////////////////////////////////////////
        // (Ini/Deini)tializers
        ////////////////////////////////////////////////////////////////////////

        //! \brief Allocates memory for the SPU2
        void init();
        //! \brief Deallocates memory for the SPU2
        void shutdown();

        ////////////////////////////////////////////////////////////////////////
        // Accessors
        ////////////////////////////////////////////////////////////////////////

        //! \brief Reads a value of the given type from memory
        u16 read(const u32& address);
        //! \brief Transfer data from SPU2 memory to host memory
        void read(const u32& base_addr, const u16 buffer[], const u32& size);

        ////////////////////////////////////////////////////////////////////////
        // Modifiers
        ////////////////////////////////////////////////////////////////////////

        //! \brief Writes the given value into memory at the given address
        void write(const u32& address, const u16& data);
        //! \brief Transfer the data from one buffer into memory
        void write(const u32& base_addr, const u16 buffer[], const u32& size);
        //! \brief Clears the entire memory area
        void clear();

        ////////////////////////////////////////////////////////////////////////
        // Variables
        ////////////////////////////////////////////////////////////////////////

        extern u16* memory_ptr; //!< The allocated chunk of memory for SPU2
        static const u32 SPU2_MEMORY_SIZE = (1024 * 1024); //!< 2 MB
        static const u32 SPU2_CLEAR_SIZE = (2 * SPU2_MEMORY_SIZE); //!< For clear()
    }
}

#endif // PS2SPU_MEMORY_HPP
