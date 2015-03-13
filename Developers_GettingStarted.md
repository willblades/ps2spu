# General Philosophy #

The basic idea behind this project is to create a Playstation2 SPU2 emulator that not only works on a wide variety of platforms, but that also is code in a consistent, readable and well-documented fashion that serves as documentation for the hardware as well.

# Drop In And Say Hi #

We're usually all hanging around on IRC (EFNet in #emudev and #pcsx2) so please feel free to drop by and ask us questions, report bugs or just enjoy a chat.

# Design Details #

The project, while programmed in C++, is mostly composed of C code for performance reasons.  While C++ provides many unique tools, most of them were not right for this project.  The code is organized as follows

  * namespace ps2spu
    * namespace memory
    * namespace registers
    * namespace mixer
    * namespace audio

## The ps2spu namespace ##

This namespace contains all the basic data-types for the project, which are as follows:

  * u8, s8 - 8bit data types
  * u16, s16 - 16bit data types
  * u32, s32, uptr - 32bit data types
  * u64, s64 - 64bit data types (where supported)

In addition this namespace contains preprocessor directives with information about the operating system as well as the build version information.  The preprocessor directives are as follows:

  * **Operating systems/compilers**
    * PS2SPU\_WINDOWS - The machine is a windows computer
      * PS2SPU\_MSVC - The compiler is Microsoft Visual C++
      * PS2SPU\_MINGW32 - The compiler is MingW32
    * PS2SPU\_POSIX - The machine is Linux/BSD/Apple
      * PS2SPU\_APPLE - The machine is an apple computer
      * PS2SPU\_LINUX - The machine is some flavor of linux
  * **Build version information**
    * PS2SPU\_VERSION\_MAJOR - This number is the x in x.y
    * PS2SPU\_VERSION\_MINOR - This number is the y in x.y
    * PS2SPU\_COMPILE\_MODE - The build mode used on this compilation
      * PS2SPU\_COMPILE\_MODE\_DEBUG - The build is in debug mode
      * PS2SPU\_COMPILE\_MODE\_RELEASE - The build is in release mode