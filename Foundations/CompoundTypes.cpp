#include <iostream>
#include <string>




int main()
{
	// Compound Types
	// Any Types is either a fundamental type or a compound type, therefore compound types are:
	// (array, function, object pointer, function pointer, member object pointer, member function pointer,
	//  reference, class, union, enumeration)
	// 
	

	// Reference Types:
	{
		// lvalue references:
		{
		std::string my_string = "is this editable";	
		std::string my_other_string = "is this also editable";
		// compile error: cannot bind non-const lvalue reference of type '' to an rvalue of type ''
		// std::string& my_ref = my_string + ": Yes";


		std::string& my_ref = my_string;
		my_ref += ": Yes";

		// cannot modify through reference to const
		const std::string& my_const_ref = my_other_string;
		// my_const_ref += ": No"; // compile error: invalid conversion from 'const char*' to 'char'

		std::cout << my_string << '\n';
		std::cout << my_other_string << '\n';
		
		// can also use the reference
		std::cout << my_const_ref << '\n';


		// Pointer to the object referred to by the reference
		std::string* my_ptr = &my_ref;

		std::cout << &my_string << " = " << my_ptr << '\n';
		}

		// rvalue references:
		{
			std::string my_string = "is this editable ";
			// compile error: cannot bind rvalue reference of type '' to lvalue of tpye ''
			// std::string&& my_ref = my_string;

			// accepted as my_string+my_string is a prvalue
			std::string&& my_rvalue_ref = my_string + my_string;
			std::cout << my_rvalue_ref << '\n';
			
			my_rvalue_ref =  "testing";
			std::cout << my_rvalue_ref << '\n';

			//std::string* can_this_exist = my_rvalue_ref;
		

			auto func_with_rvalue = [](int&& an_int) -> int {
				return an_int;
			};

			int&& my_int = 10;
			// compile error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
			// std::cout << func_with_rvalue(x);
		
			// works as std::move indicates object x may be moved from -> it is an rvalue again
			func_with_rvalue(std::move(my_int));


			// rvalue references can bind to xvalues, meaning they can refere to non-temporary objects
			{
				int my_int = 1;

				int& lvalue_ref = my_int;
				int&& rvalue_ref = std::move(my_int);
				
				lvalue_ref = 5;
				std::cout << "lvalue change: " << my_int << '\n';

				rvalue_ref = 10;
				std::cout << "rvalue change: " << my_int << '\n';

				// If both work the same, what is the difference?
				// function calls e.g. func(int& x) and func(int&& x) will resolve to the corresponding type.
			}
		}

		// Forwarding references:
		// Special kind of references that preserve the value category of a function argument
		
		// Forward references are either: 
		// Function parameters of a function template declared as rvalue reference to cv-unqualified...
		// type template parameter of that same function template.
		//
		// auto&& (except when deduced from a brace-enclosed intializer list or, when representing a template...
		// parameter of a class template argument deduction)
	}
}

