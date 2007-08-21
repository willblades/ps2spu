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

#include "SpuMemory.hpp"
#include "SpuEssentials.hpp"
using namespace ps2spu;

u16* memory::memory_ptr = NULL;

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::init()
{
    memory_ptr = new u16[SPU2_MEMORY_SIZE];
    memory::clear();
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

u16 memory::read(const u32& address)
{
    if(memory_ptr == NULL)
    {
        throw std::runtime_error("Attempt to read when memory not alloced!");
    }

    if(address >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Attempt to read value out of range!");
    }

    return memory_ptr[address];
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::read(const u32& base_addr, const u16 buffer[], const u32& size)
{
    if(memory_ptr == NULL)
    {
        throw std::runtime_error("Attempt to read when memory not alloced!");
    }

    if(base_addr >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Attempt to read value out of range!");
    }

    memcpy((void*)buffer, &memory_ptr[base_addr], size);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::write(const u32& address, const u16& data)
{
    if(memory_ptr == NULL)
    {
        throw std::runtime_error("Attempt to write when memory not alloced!");
    }

    if(address >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Attempt to write value out of range!");
    }

    memory_ptr[address] = data;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::write(const u32& base_addr, const u16 buffer[], const u32& size)
{
    if(memory_ptr == NULL)
    {
        throw std::runtime_error("Attempt to write when memory not alloced!");
    }

    if(base_addr >= SPU2_MEMORY_SIZE)
    {
        throw std::out_of_range("Attempt to write value out of range!");
    }

    memcpy(&memory_ptr[base_addr], buffer, size);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void memory::clear()
{
    memset((char*)memory_ptr, 0, SPU2_CLEAR_SIZE);
}