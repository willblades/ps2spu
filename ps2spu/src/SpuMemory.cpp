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

#include "SPUMemory.hpp"
#include "SPUEssentials.hpp"
using namespace ps2spu;

u8* memory::memory_ptr = NULL;

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::init()
{
    memory_ptr = new u8[SPU2_MEMORY_SIZE];
    memset(memory_ptr, 0, SPU2_MEMORY_SIZE);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::shutdown()
{
    if(memory_ptr != NULL)
    {
        delete [] memory_ptr;
        memory_ptr = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

u8 memory::read8(const u32& address)
{
    if(address >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Error, memory::read8 addr out of range!");
    }

    return memory_ptr[address];
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::write8(const u32& address, const u8& data)
{
    if(address >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Error, memory::write8 addr out of range!");
    }

    memory_ptr[address] = data;
}