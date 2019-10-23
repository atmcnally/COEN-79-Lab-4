// implemented by Uma Bahl, tested by Angelus McNally

#include <cstdlib>  // Provides size_t
#include <string>
#include <cassert>
#include "keyed_bag.h"

using namespace coen79_lab4;

namespace coen79_lab4
{

// structure: two arrays, one for keys and one for values
// the corresponding value for a key is found in the same index in the values array
// when a value is erased, the last item is placed in that index

// constructor: create a keyed bag. Intialize the numItems
keyed_bag::keyed_bag()
{
    numItems = 0;
}

// Postcondition: This keyed_bag is emptied of all items and keys.
void keyed_bag::erase()
{
    numItems = 0;
}

// find the index of the item, and replace it with the last item in keys and vals.
// Postcondition: If key was in the keyed_bag, then the key and its value have been removed. Otherwise the keyed_bag is unchanged. A true return value indicates that an item was removed. False indicates that nothing was removed.
bool keyed_bag::erase(const key_type &key)
{
    bool hasKey = has_key(key);
    if (hasKey)
    {
        size_type index = 0;
        for (int i = 0; i < numItems; i++)
        {
            if (keys[i] == key)
                index = i;
        }
        numItems--;
        keys[index] = keys[numItems];
        vals[index] = vals[numItems];
    }
    return hasKey;
}

// Precondition: size( ) < CAPACITY, and the keyed_bag does not yet contain the given key.
// Postcondition: A new copy of entry has been added to the keyed_bag with the corresponding key.
void keyed_bag::insert(const value_type &entry, const key_type &key)
{
    if (size() >= CAPACITY || has_key(key))
    {
        cout << "invalid operation" << endl;
        return;
    }
    else{
        keys[numItems] = key;
        vals[numItems] = entry;
        numItems++;
    }
}

// Go through the addend's keys, and if the bag does not have the key, add it to the bag
// Precondition:  size( ) + addend.size( ) <= CAPACITY. The intersection of the keyed_bags' key tables is empty (i.e. the keyed_bags) share no keys.
// Postcondition: Each item and its key in addend has been added to this keyed_bag.
void keyed_bag::operator+=(const keyed_bag &addend)
{
    if (size() + addend.size() > CAPACITY)
    {
        cout << "invalid operation" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < addend.size(); i++)
        {
            if (!has_key(addend.keys[i]))
            {
                insert(addend.vals[i], addend.keys[i]);
            }
        }
    }
}

// Go through all the keys and check if any match
// Postcondition: The return value is whether or not the given key is in the keyed_bag's list of keys.
bool keyed_bag::has_key(const key_type &key) const
{
    for (int i = 0; i < numItems; i++)
    {
        if (key == keys[i])
        {
            return true;
        }
    }
    return false;
}

// Precondition: has_key returns true for the given key.
// Postcondtion: the data value corresponding to the given key is returned.
keyed_bag::value_type keyed_bag::get(const key_type& key) const
{
    assert (has_key(key));
    
    int index = 0;
    for (int i = 0; i < numItems; i++)
    {
        if (key == keys[i])
        {
            index = i;
        }
    }
    return vals[index];
}

// Postcondition: The return value is the total number of items in the keyed_bag
keyed_bag::size_type keyed_bag::size() const
{
    return numItems;
}

// Postcondition: The return value is number of times target is in the keyed_bag.
keyed_bag::size_type keyed_bag::count(const value_type &target) const
{
    size_type result = 0;
    
    for (int i = 0; i < numItems; i++)
    {
        if (vals[i] == target)
        {
            result++;
        }
    }
    
    return result;
}

// for each key in the bag check if the other bag has this key
// Postcondition: The return value is true if there is at least one key used by both this bag and the "otherBag". In other words, this function checks if there is any shared key by the two bags.
bool keyed_bag::hasDuplicateKey(const keyed_bag &otherBag) const
{
    for (int i = 0; i < numItems; i++)
    {
        for (int j = 0; j < otherBag.numItems; j++)
        {
           if (keys[i] == otherBag.keys[j])
               return true;
        }
    }
    return false;
}

// print the elements
void keyed_bag::print()
{
    for (int i = 0; i < numItems; i++)
    {
        cout << keys[i] << ": " << vals[i] << endl;
    }
}


// Precondition:  b1.size( ) + b2.size( ) <= keyed_bag::CAPACITY. The intersection of the keyed_bags' key tables is empty. (i.e. The two keyed_bag's have no keys in common.)
// Postcondition: The keyed_bag returned is the union of b1 and b2.
keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
{
    assert (b1.size() + b2.size() <= keyed_bag::CAPACITY && !b1.hasDuplicateKey(b2));
            
    keyed_bag result;
    result += b1;
    result += b2;
    return result;
}

}
