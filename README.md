# <center> Infinite Integer </center>

## Description

This is a program that contains a class which can present an
integer with "infinite" length.

## Functions

*InfinieInt()*: Default constructor for InfiniteInt, which contains a 
0 and radix is 10.<br/><br/>
*InfiniteInt(unsigned long long val)*: Construct an InfiniteInt with the given long, and radix is 10.<br/><br/>
*explicit InfiniteInt(std::vector<unsigned int>* new_digits)*: Construct an InfiniteInt with the given vector, and radix is 10.<br/><br/>
*InfiniteInt(const InfiniteInt &obj)*: Consttruct an InfiniteInt that is the same as the &obj.<br/><br/>
*InfiniteInt& operator=(const InfiniteInt &)*: The overloaded copy-assignment operator.<br/><br/>
*ostream& operator<< (ostream&, const InfiniteInt&)*: The overloaded operator *<<* for ostream and InfiniteInt.<br/><br/>
*ostream& operator>> (ostream&, const InfiniteInt&)*: The overloaded operator *>>* for istream and InfiniteInt.<br/><br/>
*bool operator< (const InfiniteInt&)*: Overloaded *<* that returns whether or not the value of the left hand side InfiniteInt is less than the other InfiniteInt.<br/><br/>
*bool operator> (const InfiniteInt&)*: Overloaded *>* operator that returns whether or not the value of the left hand side InfiniteInt is greater than the other InfiniteInt.<br/><br/>
*bool operator<= (const InfiniteInt&)*: Overloaded *<=* operator that returns whether or not the value of the left hand side InfiniteInt is less than or equal to the other InfiniteInt.<br/><br/>
*bool operator>= (const InfiniteInt&)*: Overloaded *>=* operator that returns whether or not the value of the left hand side InfiniteInt is greater than or equal to the other InfiniteInt.<br/><br/>
*bool operator== (const InfiniteInt&)*: Overloaded *==* operator that returns whether or not the value of the left hand side InfiniteInt is equal to the other InfiniteInt.<br/><br/>
*bool operator!= (const InfiniteInt&)*: Overloaded *!=* operator that returns whether or not the value of the left hand side InfiniteInt is not equal to the other InfiniteInt.<br/><br/>
*InfiniteInt operator+ (const InfiniteInt&)*: Overloaded *+*  operator that returns a new InfiniteInt which is the sum of the two InfiniteInt.<br/><br/>
*InfiniteInt operator- (const InfiniteInt&)*: Overloaded *-* operator that returns a new InfiniteInt which is the difference of the two InfiniteInt.<br/><br/>
*InfiniteInt operator+= (const InfiniteInt&)*: Overloaded *+=* operator that adds the right operand and the left operand and stores the new value in the left operand.<br/><br/>
*InfiniteInt operator-= (const InfiniteInt&)*: Overloaded *-=* operator that subtracts the right operand and the left operand and stores the new value in the left operand.<br/><br/>
*InfiniteInt& operator++ ()*: Overloaded the pre-increment *++* operator that adds 1 to the current In-finiteInt and returns the changed InfiniteInt.<br/><br/>
*InfiniteInt& operator-- ()*: Overloaded the pre-decrement *--* operator that subtracts 1 to the current In-finiteInt and returns the changed InfiniteInt.<br/><br/>
*InfiniteInt operator++ (int)*: Overloaded the post-increment *++* operator that adds 1 to the current In-finiteInt and returns the changed InfiniteInt.<br/><br/>
*InfiniteInt operator-- (int)*: Overloaded the post-decrement *--* operator that subtracts 1 to the current In-finiteInt and returns the changed InfiniteInt.<br/><br/>


## Compile

Using the command *make* to compile, and *make clean* to
delete the executable file.

## How to run it

After compling, there will be a file named *"InfiniteInt"*. Once it comes up, 
using *./InfiniteInt* to run it.

