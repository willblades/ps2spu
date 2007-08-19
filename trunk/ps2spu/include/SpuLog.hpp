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

#ifndef PS2SPU_LOG_HPP
#define PS2SPU_LOG_HPP

#include <fstream>

namespace ps2spu
{
    static const char LOG_FILE_NAME[] = "ps2spu.log";

    //! \brief Class for writing to log file
    class Log
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        // Accessors
        ////////////////////////////////////////////////////////////////////////

        //! \brief Get the singleton instance as a pointer
        static Log* instance();

        ////////////////////////////////////////////////////////////////////////
        // Mutators
        ////////////////////////////////////////////////////////////////////////

        //! \brief Writes a single string into the log
        void write(const char message[]);
        //! \brief Writes a printf-formatted message to the log
        void write(const char format[], ...);
        //! \brief Delete the singleton instance
        static void deleteInstance();
    private:
        ////////////////////////////////////////////////////////////////////////
        // Constructor/Destructor
        ////////////////////////////////////////////////////////////////////////

        //! \brief Constructor
        Log();
        //! \brief Destructor
        ~Log();

        ////////////////////////////////////////////////////////////////////////
        // Member Variables
        ////////////////////////////////////////////////////////////////////////

        std::ofstream log_;
        static Log* instance_ptr_;
    };
}

#endif // PS2SPU_LOG_HPP