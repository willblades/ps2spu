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

#include "SpuLog.hpp"
#include <cstdarg>

const int VARGS_BUFFER_SIZE = 1024;
ps2spu::Log* ps2spu::Log::instance_ptr_ = NULL;

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

ps2spu::Log::Log()
{
    log_.open(LOG_FILE_NAME);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

ps2spu::Log::~Log()
{
    log_.close();
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

ps2spu::Log* ps2spu::Log::instance()
{
    if(instance_ptr_ == NULL)
    {
        instance_ptr_ = new Log();
        atexit(ps2spu::Log::deleteInstance);
    }

    return instance_ptr_;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void ps2spu::Log::write(const char message[])
{
    log_ << message << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void ps2spu::Log::write(const char format[], ...)
{
    // Convert the variadic arguments to a string
    static char buffer_ptr[VARGS_BUFFER_SIZE];

    va_list args_list;
    va_start(args_list, format);
    vsnprintf(buffer_ptr, VARGS_BUFFER_SIZE, format, args_list);
    va_end(args_list);

    // Write the message into the log
    log_ << buffer_ptr << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

void ps2spu::Log::deleteInstance()
{
    if(instance_ptr_ != NULL)
    {
        delete instance_ptr_;
        instance_ptr_ = NULL;
    }
}
