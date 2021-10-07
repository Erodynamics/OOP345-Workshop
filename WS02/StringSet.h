// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/10/03

#pragma once
#ifndef _SDDS_STRINGSET_H
#define _SDDS_STRINGSET_H
#include <string>

namespace sdds {
	class StringSet {
		std::string* strings;
		size_t arrSize = 0;
	public:
		StringSet();
		StringSet(const char* filename);
		StringSet(const StringSet& source);
		StringSet(StringSet&& source) noexcept;
		~StringSet();
		size_t size();
		std::string operator[](size_t index);
		StringSet& operator=(const StringSet& source);
		StringSet& operator=(StringSet&& source) noexcept;
	};
}

#endif // _SDDS_STRINGSET_H
