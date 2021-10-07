#pragma once
#ifndef _SDDS_PAIR_H
#define _SDDS_PAIR_H
#include <ostream>

namespace sdds {
	template <typename K, typename V>
	class Pair {
		K storedKey;
		V storedValue;
	public:
		Pair();
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		void display(std::ostream& os) const;
	};

	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair);
}

#endif