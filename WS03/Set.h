#pragma once
#ifndef _SDDS_SET_H
#define _SDDS_SET_H

namespace sdds {
	template <typename N, typename T>
	class Set {
		int currentSize = 0;
		T* array;
		size_t maxSize = N;
	public:
		size_t size() const;
		const T& get(size_t idx);
		void operator+=(const T& item);
	};
}

#endif