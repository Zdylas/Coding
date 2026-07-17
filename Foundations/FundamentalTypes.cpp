/* Dominic McNulty
 * Started Writing 12/07/2026
 *
 * 
 */

#include <iostream>
#include <limits>


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
			std::cout << "my_char: " << my_char << " and as an int: " << static_cast<int>(my_char) << '\n';

		}
		// Unsigned char - ranges from 0 to 255
		// This is the typical implementation of char for ARM and PowerPC
		{
			unsigned char my_char = 128;
			std::cout << "my_char: " << my_char << " and as an int: " << static_cast<int>(my_char) << '\n' << std::endl;
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
			std::cout << "Value of: " << another_int << '\n' << std::endl; 
		}

		// int:
		// equivalent to signed, signed int
		// Size of at least 16 bits. Most systems will be 32 bits including LLP64
		{
			int my_int = 2147483647; // min: -2147483648, max: 2147483647
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << '\n' << std::endl;
		}

		// long int:
		// equivalent to: long, signed long, signed long int
		// Size of at least 32 bits. On LLP64 it will be 32 bits but other data models it will be 64 bits (LP64)
		{
			long int my_int = 2147483647; // min: -2147483648, max: 2147483647
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << '\n' << std::endl;
		}

		// long long int:
		// equivalent to: long long, signed long long, signed long long int
		// Size of at least 64 bits. Added in C++11
		{
			long long int my_int = 9223372036854775807; // min: -92233720366854775808, max: 9223372036854775807
			std::cout << "Value of: " << my_int << ", Size: " << sizeof(my_int) << " bytes" << '\n' << std::endl;
	
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
	// float  	-> single precision floating-point type IEE-754 binary32 format.
	// double 	-> double precision floating-point type IEE-754 binary64 format.
	// long double  -> extended precision floating-point type: most well known is x87 80-bit extended precision format
	// 		   used by x86-64 implementations.
	//
	// min_subnormal: Describes the absolute smallest size that can be represented by the data type.
	//		  Sacrifices precision by allowing leading 0s for the significand to stop variable
	//		  truncating to zero.
	//
	//		  32-bit : +- 0x1p-149 std::numeric_limits<float>::denorm_min();  
	//		  64-bit : +- 0x1p-1074 std::numeric_limits<float>::denorm_min();  
	//		  80-bit : +- 0x1p-16445 std::numeric_limits<float>::denorm_min();  
	//		  128-bit: +- 0x1p-16494 std::numeric_limits<float>::denorm_min(); 
	//
	// min_normal   : Describes the smallest size that can be represented by the data type without losing precision.
	// 		  
	// 		  32-bit  : +- 0x1p-126 std::numeric_limits<float>::min();
	// 		  64-bit  : +- 0x1p-1022
	// 		  80-bit  : +- 0x1p-16382
	// 		  128-bit : +- 0x1p-16382
	//
	// max		: Largest value that can be represented by the data type.
	//			
	//		  32-bit  : +- 0x1.fffffep+127 std::numeric_limits<float>::max();
	//		  64-bit  : +- 0x1.fffffffffffffep+1023 std::numeric_limits<double>::max();
	//		  80-bit  : +- 0x1.fffffffffffffffep+16383 std::numeric_limits<long double>::max();
	//		  124-bit : +- 0x1.ffffffffffffffffffffffffffffp+16383 
	//
	// single precision floating-point type. IEE-754 binary32 format
	{
		// float
		{
			float my_true_min_float = std::numeric_limits<float>::denorm_min(); // same as subnormal
			float my_min_float = std::numeric_limits<float>::min();
			float my_max_float = std::numeric_limits<float>::max();
			std::cout << "Value of DENORM_MIN: " << my_true_min_float << '\n';
			std::cout << "Value of MIN: " << my_min_float << '\n';
			std::cout << "Value of MAX: " << my_max_float << '\n';
			std::cout << "Size: " << sizeof(my_max_float) << " bytes" << '\n';
			std::cout << std::endl;
		}

		// double
		{
			double my_true_min_double = std::numeric_limits<double>::denorm_min();
			double my_min_double = std::numeric_limits<double>::min();
			double my_max_double = std::numeric_limits<double>::max();
			std::cout << "Value of DENORM_MIN: " << my_true_min_double << '\n';
			std::cout << "Value of MIN: " << my_min_double << '\n';
			std::cout << "Value of MAX: " << my_max_double  << '\n';
			std::cout << "Size: " << sizeof(my_max_double) << " bytes" << '\n';
			std::cout << std::endl;
		}
		// long double
		{
			long double my_true_min_long_double = std::numeric_limits<long double>::denorm_min();
			long double my_min_long_double = std::numeric_limits<long double>::min();
			long double my_max_long_double = std::numeric_limits<long double>::max();
			std::cout << "Value of DENORM_MIN: " << my_true_min_long_double << '\n';
			std::cout << "Value of MIN: " << my_min_long_double << '\n';
			std::cout << "Value of MAX: " << my_max_long_double  << '\n';
			std::cout << "Size: " << sizeof(my_max_long_double) << " bytes" << '\n'; 
			std::cout << std::endl;
		}
	}
	
}
