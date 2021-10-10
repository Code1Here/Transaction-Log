# transaction_log
A smart bank

Data Structures
Programming Assignment 1
This assignment tests the concepts of
Dynamic arrays
Working with classes that explicitly utilize the heap
Give you experience in using a test program to track down bugs in a class’s implementation
Program Objective
A smart bank will use a transaction log so that at any point they can replay events that led to a specific value. Our transaction log will allow forking of the logs order, this will be based on where our “current transction” points to. At any time, a transaction log will have a current (ie: active) transaction.

You will implement the provided transaction_log class, the header file is given to you with pre/post conditions that you will work off of. The data structure used will be a dynamic array that will grow as needed during the lifetime of the object.

You will want to create a robust test plan to check all posibilities. A small driver is given.

Transaction log class notes:

The major difference between the authors bag class and the transaction log class is that ORDER matters
Because you are dynamically allocating memory within your class, you will need to define and implement a copy constructor, an assignment operator, and a destructor.
The transaction log depends on the transaction class.
A transaction has two main parts
Transaction id, a unique number of every transaction, which should automatically increment (without any work by you)
Transaction value, this is the amount of money ADDED (positive) or REMOVED (negative)
The value is yet another class, called long_decimal
long_decimal is a integer encoded decimal with a larger range of values than int, long, or double
The min value is -18,446,744,073,709,551,615.99
The max value is +18,446,744,073,709,551,615.99
Compared to long which is -9,223,372,036,854,775,808 to +9,223,372,036,854,775,807
Even less if assume this long contains cents instead of dollars
Copy and paste the invariant from transaction_log.h to your transaction_log.h file. Update the invariant for your implementation.
Do your work in small steps. Create a stub for EVERY function in the header file that is not already implmented inline.
Do not modify the transaction_log header file since your project will be compiled and graded using the original version.
Provided files:
transaction_log.h: The header and prototype of the transaction_log class. You will be implementing all of the functions that are not already defined inline. All of your implementation must go in transaction_log.cpp. Do not modify this header.

transaction(.h/.cpp): Provided class and implementation of transaction. Documention coming soon. These files should not be modified.

long_decimal(.h/.cpp): Provided class and implementation of transaction. Documention coming soon. These files should not be modified.

helpers(.h/.cpp): Provided functions that utilize the transaction logs current, next, and has_next to display the transaction log to output streams. These files should not be modified.

main.cpp: Driver of the transaction_log. A rough start to creating an awesome test driver for your code. It would be wise to build this first. You will want to add your test plan to this file, however, you do not submit this file.

DELIVERABLES:
Description	Filename (all lowercase)
transaction_log Implementation	transaction_log
Submitted assignments without the above files named correctly will render your assignment as uncompilable and will be detrimental to your assignment grade. Please do not submit stats.h or driver.cpp

Hints
Read chapter 3 and 4 of the textbook
Check Boundary Values
For example, the current pointer moving off the transaction log.

Check Preconditions
Your implementations should use the assert function to check preconditions of all functions. However, I personally will not verify these tests.

Input and Output
Your implementations must NOT produce any output to cout, nor expect any input from cin. All the interaction with the member functions occurs through their parameters.

Implement and Test Small Pieces
Don’t tackle to whole project at once. Start by implementing what you can, using “stubs” for the harder functions. A “stub” is the implementation of a function with the lines of the body omitted. For example:

bool transaction_log::current_is_valid() const {
{
    return true; // TODO: This is just a stub, to be implemented later.
}
Other Requirements
This project must be your own work, it is NOT a team effort. Any code/algorithm utilizied must have proper attribution.
ALL member and non-member functions defined in transaction_log.h must be fully implemented, taking into account what the pre/post conditions say. You do not need to confirm any preconditions. Your code will not compile by the grader unless you have at the very least all stubs for each member function defined in transaction_log.h.
Your container must not produce any output, NO couts
Your code must not add any global variables
For full credit your code should have zero compiler warnings.
Your code will be checked for memory leaks. Memory leaks will be verified via a tool called “valgrind” as well as visually.
The data structure used for sequence must be a dynamic array
Usage of any STL containers will affect grade detrimentally.
Usage of recursion will result in no credit
You may not modify the provided files with “main.cpp” being an exception.
Avoid all STL includes in sequence.cpp, however, cassert is allowed if you want to verify preconditions.
Only submit the file(s) listed in deliverables, submitting object files, IDE project files, and executables will impact grade.
Don’t forget to document your code, see course outline for details.
Example output
Output generated from the provided driver
[1, 2, 3, 4, 8, 9, 10, 11, 5, 6, 7]
Transactions:
[01] + $34.00
[02] + $35.00
[03] - $36.00
[04] + $37.00
[08] + $41.41
[09] + $42.00
[10] - $43.00
[11] + $44.00
[05] + $38.00
[06] + $39.00
[07] + $40.00
SUM:271.41
