#include "Pair.h"

namespace sdds {
	template<typename K, typename V>
	Pair<K, V>::Pair() {
		storedKey = 0;
		storedValue = 0;
	}

	template<typename K, typename V>
	Pair<K, V>::Pair(const K& key, const V& value) {
		storedKey = key;
		storedValue = value;
	}

	template<typename K, typename V>
	const V& Pair<K, V>::value() const {
		return storedValue;
	}

	template<typename K, typename V>
	const K& Pair<K, V>::key() const {
		return storedKey;
	}

	template<typename K, typename V>
	void Pair<K, V>::display(std::ostream& os) const {
		os << storedKey << " : " << storedValue << std::endl;
	}

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}