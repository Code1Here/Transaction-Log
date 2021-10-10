/** Anthony Duran
 *  Data Structures - 9 A.M.
 **************************
TYPEDEFS and MEMBER CONSTANTS for the transaction_log class:
    typedef ____ value_type
        transaction::value_type is the data type of the items in the transaction_log. It can be any object type
        that supports .value() and .id(), and more

    typedef value_type::value_type transaction_value_type;
        A convenience typedef that corresponds to the actual type of the number inside a transaction

    typedef double add_type;
        The type of value you expect to add into the transaction log, assuming it has less range than a transaction.
        However, easier to use than creating a transaction each time.

    typedef ____ size_type
        sequence::size_type is the data type of any variable that keeps track of how many items are in a sequence.

    static const size_type GROW_FACTOR = 2; //
        The initial state of a log will be zero capacity. On first insert or append, the size will be 1. However, each additional
        capacity increase will grow by GROW_FACTOR.

 CONSTRUCTOR for the sequence class:
    transaction_log()
        Default constructor, does NOT initialize anything on the heap
        Precondition: N/A
        Postcondition: Initialized object

    transaction_log(const transaction_log&)
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed log is created

 Destructor
    virtual ~transaction_log();
        Precondition: N/A
        Postcondition: All heap storage is reclaimed

 MODIFICATION MEMBER FUNCTIONS for the transaction_log class:
    void reserve(size_type new_capacity)
        Precondition: N/A
        Postcondition: The transaction_log's capacity is changed to the new_capacity
            (but not less that the number of items already in the log).

            The insert/append functions will work efficiently (without allocating new memory) until this new capacity
            is reached.

    transaction_log& operator=(const transaction_log &)
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed log is returned

   void reset()
     Precondition: At least one transaction in the log
     Postcondition: The first transaction log becomes the current item

    void prev( )
        Precondition: At least one transaction in the log
        Postcondition: The new current item is the item immediately before the original current item.
            If already the first item, current becomes invalid

    void next( )
        Precondition: At least one transaction in the log
        Postcondition: The new current item is the item immediately after the original current item.
            If already the last item, current becomes invalid

    void set_current_by_id(size_type target_id)
        Precondition: N/A
        Postcondition: Set current to whatever transaction has the target_id. In the event that target_id is not found,
            current will be invalid

    void insert(const value_type& entry)
        Postcondition: A new copy of entry has been inserted in the log
            before the current item. If there was no current item, then the new entry
            has been inserted at the front of the log. In either case, the newly
            inserted item is now the current item of the log.

    void append(const value_type& entry)
        Postcondition: A new copy of entry has been inserted in the log after
            the current item. If there was no current item, then the new entry has
            been appended to the end of the log. In either case, the newly
            inserted item is now the current item of the log.

     void insert(const add_type&);
        Precondition: N/A
        Postcondition: Converts item to value_type and inserts based on the rules given in previous insert

    void append(const add_type&);
        Precondition: N/A
        Postcondition: Converts item to value_type and appends based on the rules given in previous insert

    transaction_log& operator+=(const transaction_log& logIn);
        Precondition: N/A
        Postcondition: Appends the logIn transactions (from logIns current to end) into object after the current item.
            If current item is invalid, the transaction get added to the end. Current is not changed.
            Note: It is okay if the transaction ids are not preserved from logIn (however, would be cool if they were).

 CONSTANT MEMBER FUNCTIONS for the sequence class:
    size_type size( ) const
        Precondition: N/A
        Postcondition: The return value is the number of transactions in the log.

    bool has_prev() const;
        Precondition: N/A
        Postcondition: Returns true if their exists a transaction before the current, false otherwise

    bool has_next() const;
        Precondition: N/A
        Postcondition: Returns true if their exists a transaction after the current, false otherwise

    const value_type& current() const { return log[current_index]; }
        Precondition: Current is valid
        Postcondition: Returns a reference to the current transaction

    bool current_is_valid() const;
        Precondition: N/A
        Postcondition: Returns true if there is a current transaction, false otherwise.

    bool operator==(const transaction_log &) const;
        Precondition: N/A
        Postcondition: Returns true if the order of two transactions are equivalent. Note, transaction ids are ignored,
            only the transaction values matter. Only transactions from current to the end are inspected. Returns
            false otherwise.

    bool operator!=(const transaction_log &) const;
        Precondition: N/A
        Postcondition: The opposite of ==

    const value_type* transactions() const { return log; }
        Precondition: N/A
        Postcondition: Returns a constant pointer to the transaction log.

        transaction_value_type sum() const;
        Precondition: current is valid
        Postcondition: The return sum of the values in the transaction log from current to end of the log.

    const value_type& max() const;
        Precondition: current is valid
        Postcondition: Returns a reference to the maximum transaction in the transaction log from current to end of the log.
            This is based on the transaction value and not the transaction id.
/**
*** Data Structures - 9 A.M. **

Program Name: Smart Bank 2030
Programmer Name: Anthony Duran
Attempt Number: N/A
Purpose: Project #1

**************************
TYPEDEFS and MEMBER CONSTANTS for the transaction_log class:
    typedef ____ value_type
        transaction::value_type is the data type of the items in the transaction_log. It can be any object type
        that supports .value() and .id(), and more

    typedef value_type::value_type transaction_value_type;
        A convenience typedef that corresponds to the actual type of the number inside a transaction

    typedef double add_type;
        The type of value you expect to add into the transaction log, assuming it has less range than a transaction.
        However, easier to use than creating a transaction each time.

    typedef ____ size_type
        sequence::size_type is the data type of any variable that keeps track of how many items are in a sequence.

    static const size_type GROW_FACTOR = 2; //
        The initial state of a log will be zero capacity. On first insert or append, the size will be 1. However, each additional
        capacity increase will grow by GROW_FACTOR.

 CONSTRUCTOR for the sequence class:
    transaction_log()
        Default constructor, does NOT initialize anything on the heap
        Precondition: N/A
        Postcondition: Initialized object

    transaction_log(const transaction_log&)
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed log is created

 Destructor
    virtual ~transaction_log();
        Precondition: N/A
        Postcondition: All heap storage is reclaimed

 MODIFICATION MEMBER FUNCTIONS for the transaction_log class:
 TODO: Reserves will grow at a doubling rate e.g. 1, 2, 4, 8, 16, 32 ... and so on.

    void reserve(size_type new_capacity)
        Precondition: N/A
        Postcondition: The transaction_log's capacity is changed to the new_capacity
            (but not less that the number of items already in the log).

            The insert/append functions will work efficiently (without allocating new memory) until this new capacity
            is reached.
TODO: Copies an existing rhs object into the lhs. If nullptr, destroy the log and assign log nullptr.

    transaction_log& operator=(const transaction_log &)
        A memory safe copy constructor
        Precondition: N/A
        Postcondition: A copy of the passed log is returned
TODO: Move the cursor, no matter the state, to the first logged transaction.

   void reset()
     Precondition: At least one transaction in the log
     Postcondition: The first transaction log becomes the current item
TODO: Move the cursor towards the start of the customer's log. This may cause an out-of-bounds state.

    void prev( )
        Precondition: At least one transaction in the log
        Postcondition: The new current item is the item immediately before the original current item.
            If already the first item, current becomes invalid
TODO: Move the cursor towards the end of the customer's log. This may cause an out-of-bounds state.

    void next( )
        Precondition: At least one transaction in the log
        Postcondition: The new current item is the item immediately after the original current item.
            If already the last item, current becomes invalid
TODO: Search for a given ID tag to set cursor to or set cursor to an out-of-bounds state.

    void set_current_by_id(size_type target_id)
        Precondition: N/A
        Postcondition: Set current to whatever transaction has the target_id. In the event that target_id is not found,
            current will be invalid
TODO: Adds into log in a manner that pushes older transactions towards the end. Ex output w/ four items: [4, 3, 2, 1]
 Outputs strange patterns w/ cursor != zero. Prev Ex + two next() calls & two new items after: [6, 4, 5, 3, 2, 1]
 Cursor began assigned to "2". In the insertion process, cursor moves towards index 0 while creating a skipping pattern.

    void insert(const value_type& entry)
        Postcondition: A new copy of entry has been inserted in the log
            before the current item. If there was no current item, then the new entry
            has been inserted at the front of the log. In either case, the newly
            inserted item is now the current item of the log.
TODO: Adds into log in a manner that is rather familiar, directionally right. Ex output w/ four items: [1, 2, 3, 4]
 In the case our log appends elsewhere to the end, no skipping occurs. Older transactions are pushed towards the end.

    void append(const value_type& entry)
        Postcondition: A new copy of entry has been inserted in the log after
            the current item. If there was no current item, then the new entry has
            been appended to the end of the log. In either case, the newly
            inserted item is now the current item of the log.

     void insert(const add_type&);
        Precondition: N/A
        Postcondition: Converts item to value_type and inserts based on the rules given in previous insert

    void append(const add_type&);
        Precondition: N/A
        Postcondition: Converts item to value_type and appends based on the rules given in previous insert
TODO: Current is not changed on lhs object. lhs combines with rhs, if current is valid.

    transaction_log& operator+=(const transaction_log& logIn);
        Precondition: N/A
        Postcondition: Appends the logIn transactions (from logIns current to end) into object after the current item.
            If current item is invalid, the transaction get added to the end. Current is not changed.
            Note: It is okay if the transaction ids are not preserved from logIn (however, would be cool if they were).

 CONSTANT MEMBER FUNCTIONS for the sequence class: TODO: Current is not changed for this section of functions.
    size_type size( ) const
        Precondition: N/A
        Postcondition: The return value is the number of transactions in the log.


    bool has_prev() const;
        Precondition: N/A
        Postcondition: Returns true if their exists a transaction before the current, false otherwise


    bool has_next() const;
        Precondition: N/A
        Postcondition: Returns true if their exists a transaction after the current, false otherwise

    const value_type& current() const { return log[current_index]; }
        Precondition: Current is valid
        Postcondition: Returns a reference to the current transaction
TODO: Helpful function to avoid duplicate code & dictate control flow, dependant on a valid current item.

    bool current_is_valid() const;
        Precondition: N/A
        Postcondition: Returns true if there is a current transaction, false otherwise.

    bool operator==(const transaction_log &) const;
        Precondition: N/A
        Postcondition: Returns true if the order of two transactions are equivalent. Note, transaction ids are ignored,
            only the transaction values matter. Only transactions from current to the end are inspected. Returns
            false otherwise.

    bool operator!=(const transaction_log &) const;
        Precondition: N/A
        Postcondition: The opposite of ==

    const value_type* transactions() const { return log; }
        Precondition: N/A
        Postcondition: Returns a constant pointer to the transaction log.

    transaction_value_type sum() const;
        Precondition: current is valid
        Postcondition: The return sum of the values in the transaction log from current to end of the log.

    const value_type& max() const;
        Precondition: current is valid
        Postcondition: Returns a reference to the maximum transaction in the transaction log from current to end of the log.
            This is based on the transaction value and not the transaction id.

 VALUE SEMANTICS for the sequence class:
    Assignments and the copy constructor may be used with transaction_log objects.

 DYNAMIC MEMORY USAGE by the List
   If there is insufficient dynamic memory, then the following functions
   throw a BAD_ALLOC exception: The constructors, insert, append, reserve

 Invariant declaration
  The class will maintain the physical capacity of the array and the number of items
      the object has stored in the physical array.
      ...
******************
      TODO: STUDENT add to invariant how the is_item is handled related to next, prev, and so on.
          COPY this ENTIRE invariant declaration to the top of your transaction_log.cpp
******************

** Data Structures - 9 A.M. **

Program Name: Smart Bank 2030
Programmer Name: Anthony Duran
Attempt Number: N/A
Purpose: Project #1
*/

#include <cassert>
#include "transaction_log.h"

namespace DS {
////Copy Constructor
    transaction_log::transaction_log(const transaction_log &source) {
        //Member variables are without value.
        log = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        std::copy(source.log, source.log + used, log);
        //Copied our values from customer's data.
    }

////Destructor
    transaction_log::~transaction_log() {
        delete[] log;
    }

////Mutators
    transaction_log &transaction_log::operator=(const transaction_log &rhs) {
        //SPECIAL CASE: rhs is equal to null pointer
        if (rhs.log == nullptr) {
            delete[] log;
            log = nullptr;
            return *this;
        }
        //SPECIAL CASE: Both logs point to the same memory address; ergo, they're the same log.
        if (this == &rhs)
            return *this;
        //Successful copy requires the same capacity.
        if (capacity != rhs.capacity) {
            value_type *new_log;
            new_log = new value_type[rhs.capacity];
            delete[] log;
            log = new_log;
            capacity = rhs.capacity;
        }
        //Capacity is guaranteed to be the same now.
        std::copy(rhs.log, rhs.log + used, log);
        used = rhs.used;
        current_index = rhs.current_index;
        return *this;
    }

    void transaction_log::reserve(size_type new_capacity) {
        //SPECIAL CASE: Capacity requirements are already met.
        if (new_capacity == capacity)
            return;
        //SPECIAL CASE: Destruction of customer data by reduction of 'used' variable.
        if (new_capacity < used)
            new_capacity = used;
        //Guaranteed to retain sensitive customer data. Proceed w/ doubling reserves of this log.
        value_type *new_log;
        new_log = new value_type[new_capacity];
        //SPECIAL CASE: Log is new i.e. assigned to nullptr
        if (log == nullptr) {
            log = new_log;
            return;
        }
        std::copy(log, log + used, new_log);
        delete[] log;
        log = new_log;
        capacity = new_capacity;
    }

    void transaction_log::insert(const transaction_value_type &entry) {
        /** Increase reserve() any time capacity has been reached **/
        //Construct an ID for the entry, to then process transaction.
        value_type value(entry);

        //SPECIAL CASE: For the precise case a customer's log is new.
        if (log == nullptr) {
            if (capacity == used == current_index != 0)
                capacity = used = current_index = 0;
            //Customer's log may have been corrupt. Reset data.
            ++used;
            reserve(used);
            ++capacity;
            log[current_index] = value;
            return;
        }
        //SPECIAL CASE: Double if customer's log is full.
        if (used == capacity)
            reserve(capacity * GROW_FACTOR);

        //SPECIAL CASE: Current index is invalid. Assign member variable to the start i.e. zeroth index.
        if (!(current_is_valid()))
            current_index = 0;
        //SPECIAL CASE: Inserting multiple transactions at the start of the log.
        //              Do not decrement, if so.
        if (current_index != 0)
            --current_index;

        //Create a static zone of storage for our variables. Do not use std::copy w/ target as source
        value_type dummyArray[used - current_index];
        std::copy(log + current_index, log + used, dummyArray);

        //Return our customer's remaining data back
        std::copy(dummyArray, dummyArray + (used - current_index), log + current_index + 1);
        log[current_index] = value;
        ++used;
    }

    void transaction_log::insert(const add_type &raw_data) {
        //Construct information out of raw_data passed w/ our numeric constructor.
        transaction_value_type value(raw_data);
        insert(value);
    }

    void transaction_log::append(const transaction_value_type &entry) {
        /** Increase reserve() any time capacity has been reached **/
        //Construct an ID for the entry, to then process transaction.
        value_type value(entry);

        //SPECIAL CASE: For the precise case a customer's log is new.
        if (log == nullptr) {
            if (capacity == used == current_index != 0)
                capacity = used = current_index = 0;
            //Customer's log may have been corrupt. Reset data.
            ++used;
            reserve(used);
            ++capacity;
            log[current_index] = value;
            return;
        }
        //SPECIAL CASE: Double if customer's log is full.
        if (used == capacity)
            reserve(capacity * GROW_FACTOR);

        //SPECIAL CASE: Current index is invalid. Assign member variable to the end.
        if (!(current_is_valid()))
            current_index = used - 1;

        //SPECIAL CASE: Inserting multiple transactions at the tail end of the log.
        if (current_index + 1 == used) {
            log[used] = value;
            ++current_index;
            ++used;
            return;
        }
        //Append after our customer's current item.
        ++current_index;

        //Created a static zone of storage for our variables. Do not use std::copy w/ target as source.
        value_type dummyArray[used - current_index];
        std::copy(log + current_index, log + used, dummyArray);

        //Return our customer's remaining data back.
        std::copy(dummyArray, dummyArray + (used - current_index), log + current_index + 1);
        log[current_index] = value;
        ++used;
    }

    void transaction_log::append(const add_type &raw_data) {
        //Construct information out of raw_data passed w/ our numeric constructor.
        transaction_value_type value(raw_data);
        append(value);
    }

    transaction_log &transaction_log::operator+=(const transaction_log &logIn) {
        //SPECIAL CASE:logIn is null pointer. You can't add a non-value object.
        if (logIn.log == nullptr) {
            return *this;
        }
        //Doubling the existing capacity is how our data structure works, thus:
        while (used + logIn.used > capacity)
            reserve(capacity * GROW_FACTOR);

        //SPECIAL CASE: Current index is invalid. Add argument to the end of this log.
        if (!(current_is_valid())) {
            std::copy(logIn.log, logIn.log + logIn.used, log + used);
            used += logIn.used;
            return *this;
        }
        //Copy values after the cursor in a static zone.
        value_type dummyArray[used - current_index - 1];
        std::copy(log + current_index + 1, log + used, dummyArray);

        //Copy argument values into *this* log, starting after current item.
        std::copy(logIn.log + logIn.current_index, logIn.log + logIn.used, log + current_index + 1);

        //Return our customer's remaining data back.
        std::copy(dummyArray, dummyArray + (used - current_index - 1), log + (current_index + logIn.used +1));
        used += logIn.used;
        return *this;
    }

////Move the cursor
    void transaction_log::prev() {
        if (!(current_is_valid())) {
            return;
        }
        //SPECIAL CASE: We're at the first transaction of the customer's data. Return out-of-bounds index.
        if (current_index == 0) {
            current_index = capacity * capacity;
            return;
        }
        //Special cases circumvented. Move the cursor back one.
        --current_index;
    }

    void transaction_log::set_current_by_id(size_type target_id) {
        for (size_type i = 0; i < used; ++i)
            if (log[i].id() == target_id) {
                current_index = i;
                return;
            }
        //At this point, our search went unsuccessful. Return out-of-bounds index.
        current_index = capacity * capacity;
    }

    void transaction_log::next() {
        if (!(current_is_valid()))
            return;

        //SPECIAL CASE: We're at the last transaction of the customer's data. Return out-of-bounds index.
        if (current_index == used - 1) {
            current_index = capacity * capacity;
            return;
        }
        //Special cases circumvented. Move the cursor forward one.
        ++current_index;
    }

////Accessors
    bool transaction_log::has_prev() const {
        if (!(current_is_valid()))
            return false;

        //SPECIAL CASE: We are at the beginning of our customer's log.
        if (current_index == 0)
            return false;

        //Current_index has a positive value within-bounds and a transaction before it.
        return true;
    }

    bool transaction_log::has_next() const {
        if (!(current_is_valid()))
            return false;

        //SPECIAL CASE: We are at the end of our customer's log.
        if (current_index == used - 1)
            return false;

        //Current_index is within-bounds and has a transaction after it.
        return true;
    }

    bool transaction_log::current_is_valid() const {
        if (log == nullptr) {
            return false;
        }
        //SPECIAL CASE: Current index is out-of-bounds b/c used tracks transactions stored.
        if (current_index >= used) {
            return false;
        }
        //Current_index is within-bounds.
        return true;
    }

    transaction_log::transaction_value_type transaction_log::sum() const {
        assert((current_is_valid()));

        //Create a counter to sum whilst iterating beginning w/ current.
        transaction_value_type sum(0.00);

        for (size_type i = current_index; i < used; ++i)
            sum += log[i].value();
        return sum;
    }

    const transaction_log::value_type &transaction_log::max() const {
        assert((current_is_valid()));

        //Create a counter and tracker tools for traversal.
        transaction_value_type maxValue(0.00);
        size_type indexOf_max;
        //Pinpoint highest transaction value in our customer's log starting w/ current.

        for (size_type i = current_index; i < used; ++i)
            if (maxValue < log[i].value()) {
                maxValue = log[i].value();
                indexOf_max = i;
            }
        return log[indexOf_max];
    }

    bool transaction_log::operator==(const transaction_log &right) const {
        //Test for matching sequence from each current_index to their respective ends.
        //None of the member variables need to be equal to return true. Requires a valid index
        if (!(current_is_valid()))
            return false;
        //Create a test variable to increment within the loop. Loop creates other test var.
        size_type rhs_index = right.current_index;

        for (size_type this_index = current_index; this_index < used; ++this_index) {
            if (log[this_index].value() != right.log[rhs_index].value())
                return false;
            ++rhs_index;
        }
        //Out of the for-if nested test for falseness.
        return true;
    }

    bool transaction_log::operator!=(const transaction_log &right) const {
        return !(*this == right);
    }
}
/** Data Structures - 9 A.M.

Program Name: Smart Bank 2030
Programmer Name: Anthony Duran
Attempt Number: N/A
Purpose: Project #1
*/
 VALUE SEMANTICS for the sequence class:
    Assignments and the copy constructor may be used with transaction_log objects.

 DYNAMIC MEMORY USAGE by the List
   If there is insufficient dynamic memory, then the following functions
   throw a BAD_ALLOC exception: The constructors, insert, append, reserve

 Invariant declaration
  The class will maintain the physical capacity of the array and the number of items
      the object has stored in the physical array.
      ...
******************
      TODO: STUDENT add to invariant how the is_item is handled related to next, prev, and so on.
          COPY this ENTIRE invariant declaration to the top of your transaction_log.cpp
******************

******* Anthony Duran
******* Data Structures - 9 A.M.
*/
#include "transaction_log.h"

namespace DS {
////Copy Constructor
    transaction_log::transaction_log(const transaction_log &source) {
        //Member variables are without value.
        log = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        std::copy(source.log, source.log + used, log);
        //Copied our values from customer's data.
    }

////Destructor
    transaction_log::~transaction_log() {
        delete[] log;
    }

////Mutators
    transaction_log &transaction_log::operator=(const transaction_log &rhs) {
        //SPECIAL CASE: rhs is equal to null pointer
        if (rhs.log == nullptr) {
            delete[] log;
            log = nullptr;
            return *this;
        }
        //SPECIAL CASE: Both logs point to the same memory address; ergo, they're the same log.
        if (this == &rhs)
            return *this;
        //Successful copy requires the same capacity.
        if (capacity != rhs.capacity) {
            value_type *new_log;
            new_log = new value_type[rhs.capacity];
            delete[] log;
            log = new_log;
            capacity = rhs.capacity;
        }
        //Capacity is guaranteed to be the same now.
        used = rhs.used;
        std::copy(rhs.log, rhs.log + used, log);
        return *this;
    }

    void transaction_log::reserve(size_type new_capacity) {
        //SPECIAL CASE: Capacity requirements are already met.
        if (new_capacity == capacity)
            return;
        //SPECIAL CASE: Destruction of customer data by reduction of 'used' variable.
        if (new_capacity < used)
            new_capacity = used;
        //Guaranteed to retain sensitive customer data. Proceed w/ doubling reserves of this log.
        value_type *new_log;
        new_log = new value_type[new_capacity];
        //SPECIAL CASE: Log is new i.e. assigned to nullptr
        if (log == nullptr) {
            log = new_log;
            return;
        }
        std::copy(log, log + used, new_log);
        delete[] log;
        log = new_log;
        capacity = new_capacity;
    }

    void transaction_log::insert(const transaction_value_type &entry) {
        /** Increase reserve() any time capacity has been reached **/
        //Construct an ID for the entry, to then process transaction.
        value_type value(entry);

        //SPECIAL CASE: For the precise case a customer's log is new.
        if (log == nullptr) {
            if (capacity == used == current_index != 0)
                capacity = used = current_index = 0;
            //Customer's log may have been corrupt. Reset data.
            ++used;
            reserve(used);
            ++capacity;
            log[current_index] = value;
            return;
        }
        //SPECIAL CASE: Double if customer's log is full.
        if (used == capacity)
            reserve(capacity * GROW_FACTOR);
        //SPECIAL CASE: Current index is invalid. Assign member variable to the start i.e. zeroth index.
        if (!(current_is_valid()))
            current_index = 0;
        //SPECIAL CASE: Inserting multiple transactions at the start of the log.
        //              Do not decrement.
        if (current_index != 0)
            --current_index;

        //Guaranteed customer's log is capable of storing new information anywhere.

        value_type dummyArray[used - current_index];
        std::copy(log + current_index, log + used, dummyArray);
        //Created a static zone of storage for our variables. Do not use std::copy w/ target as source
        std::copy(dummyArray, dummyArray + (used - current_index), log + current_index + 1);
        ++used;
        log[current_index] = value;
    }

    void transaction_log::insert(const add_type &raw_data) {
        //Construct information out of raw_data passed w/ our numeric constructor.
        transaction_value_type value(raw_data);
        insert(value);
    }

    void transaction_log::append(const transaction_value_type &entry) {
        /** Increase reserve() any time capacity has been reached **/
        //Construct an ID for the entry, to then process transaction.
        value_type value(entry);

        //SPECIAL CASE: For the precise case a customer's log is new.
        if (log == nullptr) {
            if (capacity == used == current_index != 0)
                capacity = used = current_index = 0;
            //Customer's log may have been corrupt. Reset data.
            ++used;
            reserve(used);
            ++capacity;
            log[current_index] = value;
            return;
        }
        //SPECIAL CASE: Double if customer's log is full.
        if (used == capacity)
            reserve(capacity * GROW_FACTOR);
        //SPECIAL CASE: Current index is invalid. Assign member variable to the end
        if (!(current_is_valid()))
            current_index = used - 1;
        //SPECIAL CASE: Inserting multiple transactions at the tail end of the log.
        if (current_index + 1 == used) {
            log[used] = value;
            ++current_index;
            ++used;
            return;
        }

        //Guaranteed customer's log is capable of storing new information anywhere.
        ++current_index;

        value_type dummyArray[used - current_index];
        std::copy(log + current_index, log + used, dummyArray);
        //Created a static zone of storage for our variables. Do not use std::copy w/ target as source
        std::copy(dummyArray, dummyArray + (used - current_index), log + current_index + 1);
        ++used;
        log[current_index] = value;
    }

    void transaction_log::append(const add_type &raw_data) {
        //Construct information out of raw_data passed w/ our numeric constructor.
        transaction_value_type value(raw_data);
        append(value);
    }

    transaction_log &transaction_log::operator+=(const transaction_log &logIn) {
        //SPECIAL CASE:logIn is null pointer. You can't add a non-value object.
        if (logIn.log == nullptr) {
            return *this;
        }
        //Doubling the existing capacity is how our data structure works, thus:
        while (used + logIn.used > capacity)
            reserve(capacity * GROW_FACTOR);
        //SPECIAL CASE: Current index is invalid. Add argument to the end of this log.
        if (!(current_is_valid())) {
            std::copy(logIn.log, logIn.log + logIn.used, log + used);
            used += logIn.used;
            return *this;
        }

        value_type dummyArray[used - current_index];
        std::copy(log + current_index, log + used, dummyArray);
        //Created a static zone of storage for our variables. Do not use std::copy w/ target as source
        std::copy(logIn.log + current_index, logIn.log + logIn.used, log + current_index);
        //Copied logIn data into *this* log
        std::copy(dummyArray, dummyArray + (used - current_index), log + (current_index + logIn.used));
        //Returned our old data back
        used += logIn.used;
        return *this;
    }

////Move the cursor
    void transaction_log::prev() {
        //SPECIAL CASE: We are out-of-bounds with the customer's data. Return to the program.
        if (!(current_is_valid())) {
            return;
        }
        //SPECIAL CASE: We're at the first transaction of the customer's data. Return out-of-bounds index.
        if (current_index == 0) {
            current_index = capacity * capacity;
            return;
        }
        //Special cases circumvented. Move the cursor back one.
        --current_index;
    }

    void transaction_log::set_current_by_id(size_type target_id) {
        for (size_type i = 0; i < used; ++i)
            if (log[i].id() == target_id) {
                current_index = i;
                return;
            }
        //At this point, our search went unsuccessful. Return out-of-bounds index.
        current_index = capacity * capacity;
    }

    void transaction_log::next() {
        //SPECIAL CASE: We are already out-of-bounds with the customer's data. Return to the program.
        if (!(current_is_valid()))
            return;

        //SPECIAL CASE: We're at the last transaction of the customer's data. Return out-of-bounds index.
        if (current_index == used - 1) {
            current_index = capacity * capacity;
            return;
        }
        //Special cases circumvented. Move the cursor forward one.
        ++current_index;
    }

////Accessors
    bool transaction_log::has_prev() const {
        //SPECIAL CASE: Current index is out-of-bounds of counted transactions.
        if (!(current_is_valid()))
            return false;

        //SPECIAL CASE: We are at the beginning of our customer's log.
        if (current_index == 0)
            return false;
        //Current_index has a positive value within-bounds and a transaction before it.
        return true;
    }

    bool transaction_log::has_next() const {
        //SPECIAL CASE: Current index is out-of-bounds of counted transactions.
        if (!(current_is_valid()))
            return false;

        //SPECIAL CASE: We are at the end of our customer's log.
        if (current_index == used - 1)
            return false;

        //Current_index is within-bounds and has a transaction after it.
        return true;
    }

    bool transaction_log::current_is_valid() const {
        //SPECIAL CASE: log is not initialized.
        if (log == nullptr) {
            return false;
        }
        //SPECIAL CASE: Current index is out-of-bounds if it equals used b/c arrays start at zero.
        if (current_index >= used)
            return false;
        //Current_index is within-bounds.
        return true;
    }

    transaction_log::transaction_value_type transaction_log::sum() const {
        //Create a counter to sum whilst iterating.
        transaction_value_type sum(0.00);
        for (size_type i = 0; i < used; ++i)
            sum += log[i].value();
        return sum;
    }

    const transaction_log::value_type &transaction_log::max() const {
        //Create a counter and tracker tools for traversal.
        transaction_value_type maxValue(0.00);
        size_type indexOf_max;
        //Pinpoint highest transaction value in our customer's log.
        for (size_type i = 0; i < used; ++i)
            if (maxValue < log[i].value()) {
                maxValue = log[i].value();
                indexOf_max = i;
            }
        return log[indexOf_max];
    }

    bool transaction_log::operator==(const transaction_log &right) const {
        //Test for matching sequence from each current_index to their respective ends.
        //None of the member variables need to be equal to return true. Requires a valid index
        if (!(current_is_valid()))
            return false;
        //Guaranteed to be within-bounds of customer's log
        size_type rhs_index = right.current_index;

        for (size_type this_index = current_index; this_index < used; ++this_index) {
            if (log[this_index].value() != right.log[rhs_index].value())
                return false;
            ++rhs_index;
        }
        //Out of the for-if nested test for falseness.
        return true;
    }

    bool transaction_log::operator!=(const transaction_log &right) const {
        return !(*this == right);
    }
}
/**
*** Anthony Duran
*** Data Structures - 9 A.M.
*/
