# Introduction #

The software writing philosophy on this project is simple.
  1. Design the code in small, modular units as much as possible.
  1. Keep the code base neat, clean, and well documented unlike many emulation projects.
  1. Give your variables descriptive names for maintainability.

# Naming Variables #

  1. Global variables will consist of all capital letters with underscore separated words.
    * `const int PLUGIN_VERSION_MAJOR = 0;`
  1. All other variables will consist of lowercase letters with underscore separated words.
    * `int num_devices = 0;`
  1. Pointer variables will use the same style as other variables, but end with _ptr.
    * `int* num_devices_ptr = NULL;`
    * `const IDevice* SOUND_DEVICE_PTR = NULL;`
  1. Handle variables will use the same style as other variables, but end with_handle.
    * `HWND GLOBAL_WINDOW_HANDLE = NULL;`
    * `HWND cancel_button_handle = NULL;`
  1. Class member variables shall use the same style rules, but end with an underscore.
    * `int channel_ = 0;`
  1. Use descriptive names everywhere, even when just iterating.
    * `for(int reg_index = 0; reg_index < NUM_REGS; reg_index++) { ... }`

# Function/Class/Struct/Enum/Macro Naming #

  1. The first word in a function name will be lowercase, subsequent words will start with an uppercase letter.
    * `void readMemory8();`
  1. Interface class will begin with the letter I followed by the class name with each word beginning with an uppercase letter.
    * `class ISoundDevice { ... };`
  1. Non-interface classes will begin with have each word beginning with an uppercase letter.
    * `class DirectSoundDevice : public ISoundDevice { ... };`
  1. Structs will follow the same naming convention as classes.
    * `struct SpuRegister { ... };`
  1. Enumerations will begin with the word enum followed by a descriptive name with each word beginning with an uppercase letter.
    * `enum EnumSpuInterrupts`
  1. Enumeration values will begin with the acronym of the enumeration name followed by an underscore and use the global variable naming convention.
    * `enum EnumSpuInterrupts { ESI_AUTO_DMA, ... };`
  1. All macros will use the global variable naming convention.
    * `#define GET_REG(x) ...`
  1. All macro code will be surrounded by `do { ... } while(0)` tags to avoid the various problems listed [here](http://kernelnewbies.org/FAQ/DoWhile0).
    * `#define GET_REG(x) do { ... } while(0)`

# Memory Allocation/Deallocation #

  1. All memory allocation will be done with the new operator.
    * `SpuCore* spu_core0_ptr = new SpuCore;`
    * `SpuVoice* core0_voices_ptr = new SpuVoice[NUM_VOICES_PER_CORE];`
  1. All memory deallocation will be done using the proper delete operator.
    * `delete spu_core0_ptr;`
    * `delete [] core0_voices_ptr;`

# Miscellaneous Styles #

  1. In your editor avoid tabs, instead configure 1 tab = 4 spaces
  1. Conditional and loop statements, no matter how short, will always contain brackets
    * Bad:
```
if(a == b)
    return true;
```
    * Good:
```
if(a == b)
{
    return true;
}
```
  1. Avoid clumping long mathematical expressions, use good spacing
    * Bad: `((a+b)/d)`
    * Good: `((a + b) / d)`
  1. Use cross-platform data types to ensure the right number of bits and save typing
    * Bad: `unsigned short reg_16;`
    * Good: `uint16 reg_16`
  1. Use C++ style comments, never C style comments
    * Bad: `/* Do something */`
    * Good: `// Do something`
  1. Use TODO comments to indicate tasks that are incomplete
    * Bad: `// Someone should check if the device is lost, it doesn't do it now`
    * Good: `// TODO: Check that the device has not been lost`
  1. Put comments before the code they describe:
    * Bad:
```
interrupt &= ~INTERRUPT_BIT; // Clear the interrupt bit
```
    * Good:
```
// Clear the interrupt bit
interrupt &= ~INTERRUPT_BIT;
```
  1. Initialize floating point values with a real number followed by a capital F
    * Bad: `float normal = 1;`
    * Good: `float normal = 1.0F`
  1. When incrementing variables prefer post-increment to pre-increment, and when passing by value or const reference use + 1.
    * Bad: `++a;`
    * Good: `a++;`
    * Bad: `f( v.begin()++ );` or `f( ++v.begin() );`
    * Good: `f( v.begin() + 1 );`
  1. Include guards will never coding any leading or following underscores, as per names with leading underscores being reserved in the C++ standard.
    * Bad: `#ifndef __PS2SPU_MEMORY_HPP__`
    * Good: `#ifndef PS2SPU_MEMORY_HPP`