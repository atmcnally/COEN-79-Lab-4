#include <cstdlib>  // Provides size_t
#include <string>

using namespace std;

namespace coen79_lab4
{
	class keyed_bag
	{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef int value_type;
		typedef string key_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;

		keyed_bag() {
			iCount = 0;

		}
		//Postcondition: The keyed_bag has been initialized as an empty keyed_bag.

		void erase() {
			//remove all items and keys
			iCount = 0;
		}
		//Postcondition: This keyed_bag is emptied of all items and keys.

		bool erase(const key_type& key) {
			if (has_key()) {
				//remove key and value
				iCount--;
				return true;
			}

			return false;
		}
		//Postcondition: If key was in the keyed_bag, then the key and its value have been removed; 
		//otherwise the keyed_bag is unchanged. A true return value indicates that an item was removed; false indicates that nothing was removed.

		void insert(const value_type& entry, const key_type& key) {
			assert(size() < CAPACITY);
			assert(!keyed_bag.has_key(key));
			//insert entry
			iCount++;
		}
		//Postcondition: A new copy of entry has been added to the keyed_bag with the corresponding key.

		void operator +=(const keyed_bag& addend) {
			assert(size() + addend.size() <= CAPACITY);
		}
		//The intersection of the keyed_bags' key tables is empty (i.e. the keyed_bags) share no keys.
		//Postcondition: Each item and its key in addend has been added to this keyed_bag.

		bool has_key(const key_type& key) const {

		}
		//Postcondition: The return value is whether or not the given key is in the keyed_bag's list of keys.
			
		value_type get(const key_type& key) const {
			assert(has_key(key));

		}
		//Postcondtion: the data value corresponding to the given key is returned.
			
		size_type size() const {
			return iCount;
		}
		//Postcondition: The return value is the total number of items in the keyed_bag.

		size_type count(const value_type& target) const {

		}
		//Postcondition: The return value is number of times target is in the keyed_bag.
			
		bool hasDuplicateKey(const keyed_bag& otherBag) const {

		}
		//Postcondition: The return value is true if there is at least one key used by both this bag and the "otherBag". 
		//In other words, this function checks if there is any shared key by the two bags.

	};

	keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2) {
		assert(b1.size() + b2.size() <= keyed_bag::CAPACITY);
		assert(!b1.hasDuplicateKey(b2));

	}

	//Postcondition: The keyed_bag returned is the union of b1 and b2.
}