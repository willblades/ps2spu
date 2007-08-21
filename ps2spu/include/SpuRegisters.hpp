#ifndef PS2SPU_REGISTERS_HPP
#define PS2SPU_REGISTERS_HPP

#include "SpuMemory.hpp"

namespace ps2spu
{
    namespace registers
    {
        //! SPU2 Register Addresses
        static const unsigned int SPU2_TSA_ADDR = 0x01A8; // DMA start address

        //! SPU2 Register Macros
        #define REG_16(x) (ps2spu::memory::memory_ptr[(x)])
        #define REG_32(x) (*(u32*)(&ps2spu::memory::memory_ptr[(x)]))

        #define SPU2_TSA REG_32(ps2spu::registers::SPU2_TSA_ADDR)
    }
}

#endif // PS2SPU_REGISTERS_HPP