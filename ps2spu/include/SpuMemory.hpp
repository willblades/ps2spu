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

        //! \brief Reads 8-bits from SPU2 memory at the given address
        u8 read8(const u32& address);
        //! \brief Reads 16-bits from SPU2 memory at the given address
        u16 readU16(const u32& address);
        //! \brief Reads 16-bits signed from SPU2 memory at the given address
        s16 readS16(const u32& address);
        //! \brief Reads 32-bits from SPU2 memory at the given address
        u32 read32(const u32& address);

        ////////////////////////////////////////////////////////////////////////
        // Modifiers
        ////////////////////////////////////////////////////////////////////////

        //! \brief Writes 8-bits into SPU2 memory at the given address
        void write8(const u32& address, const u8& data);
        //! \brief Writes 16-bits into SPU2 memory at the given address
        void writeU16(const u32& address, const u16& data);
        //! \brief Writes 16-bits signed into SPU2 memory at the given address
        void writeS16(const u32& address, const s16& data);
        //! \brief Writes 32-bits into SPU2 memory at the given address
        void write32(const u32& address, const u32& data);

        ////////////////////////////////////////////////////////////////////////
        // Variables
        ////////////////////////////////////////////////////////////////////////

        extern u8* memory_ptr;
        static const u32  SPU2_MEMORY_SIZE = (2 * 1024 * 1024); // 2MB of memory
    }
}

#endif // PS2SPU_MEMORY_HPP
