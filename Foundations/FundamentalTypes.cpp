/* Dominic McNulty
 * Started Writing 12/07/2026
 *
 * 
 */

#include <iostream>


int main()
{
	// 64 bit systems:
	//   Windows -> LLP64: int and long are 32-bit, pointer is 64-bit
	//   Linux/Mac -> LP64: int is 32-bit, long and pointer are 64-bit
	
	// All information following is bsaed on LLP64

	// Char: 
	// Implementation depended version of signed or unsigned char
	// Both these code snippets print the same thing as signed char wraps to -128 when it reaches 127 
	{
		// Signed char - ranges from -128 to 127
		// This is the typical implementation of char for x86 and x84 machines
		{
			signed char my_char = -128;
			std::cout << "my_char: " << my_char << " and as an int: " << static_cast<int>(my_char) << std::endl;

		}
		// Unsigned char - ranges from 0 to 255
		// This is the typical implementation of char for ARM and PowerPC
		{
			unsigned char my_char = 128;
			std::cout << "my_char: " << my_char << " and as an int: " << static_cast<int>(my_char) << std::endl;
		}
	}

	// Integer:
	// LLP64 standard designates minimum width in bytes each type has
	{
		// short int:
		// equivalent to: short, signed short, signed short int
		// Size of 16 bits
		{
			short int my_int = 32767; // min: -32768, max: 32767
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << std::endl;

			// out-of-range will fail silently for all integer types: overflows and wraps to -32768
			short int another_int = 32768; 
			std::cout << "Value of: " << another_int << std::endl; 
		}

		// int:
		// equivalent to signed, signed int
		// Size of at least 16 bits. Most systems will be 32 bits including LLP64
		{
			int my_int = 2147483647; // min: -2147483648, max: 2147483647
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << std::endl;
		}

		// long int:
		// equivalent to: long, signed long, signed long int
		// Size of at least 32 bits. On LLP64 it will be 32 bits but other data models it will be 64 bits (LP64)
		{
			long int my_int = 2147483647; // min: -2147483648, max: 2147483647
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << std::endl;
		}

		// long long int:
		// equivalent to: long long, signed long long, signed long long int
		// Size of at least 64 bits. Added in C++11
		{
			long long int my_int = 9223372036854775807; // min: -92233720366854775808, max: 9223372036854775807
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << std::endl;
	
			// Note: Code below causes compile error as integer cannot be represented by any integer type
			// unsigned long long int another_int = 18446744073709551616;
		}	
	}

	// Bool:
	// Integer type that hold either true or false. sizeof(bool) is implementation defined
	{
		bool my_bool = true; // same as bool my_bool = 1
		std::cout << "Value of: " << my_bool << ", Size: " << sizeof(my_bool) << " bytes" << std::endl;
	}

	// Floats:
	// 

}
