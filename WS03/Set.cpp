#include "Set.h"

namespace sdds {
	template<typename T, typename N>
	size_t Set<T, N>::size() const {
		return currentSize;
	}

	template<typename N, typename T>
	const T& Set<N, T>::get(size_t idx) {
		return array[idx];
	}

	template<typename N, typename T>
	void Set<N, T>::operator+=(const T& item) {
		if (currentSize < maxSize) {
			array[currentSize] = item;
		}
	}
}