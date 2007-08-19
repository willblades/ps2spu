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
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>
using namespace ps2spu;

TEST(TestThatMemoryPointerIsInitiallyNull)
{
    CHECK(memory::memory_ptr == NULL);
}

TEST(TestThatMemoryPointerIsNotNullAfterInitialization)
{
    memory::init();
    CHECK(memory::memory_ptr != NULL);
}

TEST(TestThatWritingAndReadingSixteenBitsWorks)
{
    memory::write(0x32, 0xAABB);
    CHECK_EQUAL(0xAABB, memory::read(0x32));
}

TEST(TestThatWritingSixteenBitsOutOfBoundsThrowsException)
{
    CHECK_THROW(memory::write(memory::SPU2_MEMORY_SIZE, 0x88), std::out_of_range);
}

TEST(TestThatReadingSixteenBitsOutOfBoundsThrowsException)
{
    CHECK_THROW(memory::read(memory::SPU2_MEMORY_SIZE), std::out_of_range);
}

TEST(TestThatMemoryPointerIsNullAfterShutdown)
{
    memory::shutdown();
    CHECK(memory::memory_ptr == NULL);
}