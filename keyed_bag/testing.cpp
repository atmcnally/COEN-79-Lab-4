//
//  testing.cpp
//  coen79lab
//
// implemented by Uma Bahl, tested by Angelus McNally

#include <stdio.h>
#include "keyed_bag.h"

using namespace std;
using namespace coen79_lab4;


// TESTS ALL THE CAPABILITIES OF THE KEYED_BAG CLASS

int main()
{
    int onevals[6] = {1, 2, 3, 4, 5, 6};
    int onekeys[6] = {10, 12, 8, 91, 15, 2};
    
    keyed_bag first;
    
    cout << "testing insert" << endl;
    cout << "INSERTING 10: 1, 12: 2, 8: 3, 91: 4, 15: 5, 2: 6" << endl;
    
    
    for (int i = 0; i < 6; i++)
    {
        first.insert(onevals[i], onekeys[i]);
    }
    
    cout << "printing bag" << endl;
    
    first.print();
    
    cout << "testing has key" << endl;
    cout << "has key 8? " << first.has_key(8) << endl;
    
    cout << "testing erase" << endl;
    cout << "erasing key 8" << endl;
    
    first.erase(8);
    
    cout << "has key 8? " << first.has_key(8) << endl;
    
    cout << "printing bag" << endl;
    
    first.print();
    
    cout << "adding 3 in twice" << endl;
    
    first.insert(3, 3);
    first.insert(3, 9);
    
    cout << "printing " << endl;
    first.print();
    
    cout << "count 3 " << endl;
    cout << first.count(3) << endl;
    
    cout << "creating another bag, 1: 15, 2: 30, 3: 90"  << endl;
    
    keyed_bag second;
    second.insert(15, 1);
    second.insert(30, 2);
    second.insert(90, 3);
    
    second.print();
    
    cout << "do first and second have a duplicate key? " << first.hasDuplicateKey(second) << endl;
    
    cout << "removing duplicates " << endl;
    first.erase(3);
    first.erase(2);
    
    cout << "printing first bag " << endl;
    first.print();
    
    cout << "do first and second have a duplicate key? " << first.hasDuplicateKey(second) << endl;
    
    cout << "adding first and second" << endl;
    cout << "first: " << endl;
    first.print();
    cout << "second: " << endl;
    second.print();
    keyed_bag third;
    third = first + second;
    cout << "result: " << endl;
    third.print();
    
    cout << "testing +=" << endl;
    cout << "first: " << endl;
    first.print();
    cout << "second: " << endl;
    second.print();
    first += second;
    cout << "first += second. first: " << endl;
    first.print();
    cout << "second: " << endl;
    second.print();
    
    cout << "TESTING SUCCESSFULLY COMPLETED" << endl;
    
    
}
