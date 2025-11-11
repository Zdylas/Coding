/*
Dominic McNulty

Testing how CIN and COUT works with various manipulators.
*/

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

/*
Various base conversions when outputting integer values

Read/write integer values using different base format
hex -> hexidecimal base
oct -> octal base
dec -> decimal base

*/
auto output_bases() -> void
{
    int value = 75;
    //Decimal -> Base 10 integer
    cout << hex << value << '\n'; // Prints 4b

    // Represents 0-9 as numbers and 10-15 as A-F respectively
    cout << oct << value << '\n'; // Prints 113
    
    //Octal -> Base 8 integer
    cout << dec << value << '\n'; // Prints 75
}


/*
boolalpha sets a format flag for the str stream

bool values are inserted by their textual representation ("true" or "false") instead of integer values
boolalpha flag is not set on initialization
*/
auto output_boolalpha() -> void
{
    int value = 1;

    // Without using boolalpha flag
    string response = (value == 1) ? "true" : "false";
    cout << response;

    // Using boolalpha flag
    cout << boolalpha << (value==1);

    // Output must be boolean
    cout << 1; // Prints 1
    cout << bool(1); //Prints true

    //Reset boolalpha
    cout << noboolalpha;
}

/*
endl functions the same way \n, the only difference being that endl causes flushing of the output buffer.

Output buffer is used to queue things to be outputted and then written to the device when the queue is full.
This is to ensure speed of execution as accesssing an external device becomes less frequent
*/
auto output_endl() -> void
{
    cout << "Hello\n"; // Does not flush output buffer
    cout << "Hello" << endl; // Flushes output buffer

    // Size of the output buffer
    cout << "stdout buffer size: " << BUFSIZ << " bytes\n"; 

    /* 
    Prints 512 bytes
    Research suggests that this varies based on implementation and destination.
    */

    auto start_n = chrono::high_resolution_clock::now();

    // Use 100,00 for actual test
    for (int i = 0; i < 1; i++) {
        cout << "A\n";
    }
    cout << endl;
    
    auto end_n = chrono::high_resolution_clock::now();

        auto start_endl = chrono::high_resolution_clock::now();
    
    //Use 100,000 for actual test
    for (int i = 0; i < 1; i++) {
        cout << "A" << endl;
    }
    auto end_endl = chrono::high_resolution_clock::now();

    cout << "Unflushed Writing" << chrono::duration_cast<chrono::milliseconds>(end_n - start_n).count() << " ms\n";
    cout << "Endl writing" << chrono::duration_cast<chrono::milliseconds>(end_endl - start_endl).count() << " ms\n";

    /*
    Tested with printing 100,000 "A"
        Unflushed writing gave 4299ms
        Endl writing gave 7585ms
        Difference caused by accessing external output device

    Flushing is automatically done by fclose and freopen, can be explicitly called using fflush
    */
}


auto output_manipulators() -> void
{
    cout << "**********BASES**********\n";
    output_bases();
    cout << "\n\n";

    cout << "**********ENDL**********\n";
    output_endl();
    cout << "\n\n";

    cout << "**********BOOLALPHA**********\n";
    output_boolalpha();
    cout << "\n\n";
}

auto input_manipulators() -> void
{

}

auto main() -> int
{
    output_manipulators();

}