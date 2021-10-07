// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/10/03

#include "StringSet.h"
#include <iostream>
#include <fstream>

namespace sdds {
	StringSet::StringSet() {
		strings = nullptr;
		arrSize = 0;
	}

	StringSet::StringSet(const char* filename) {
		char currentWord[256]{ 0 };
		unsigned int wordCount = 0;
		strings = nullptr;

		// Opens a file with the name passed onto the function. If inaccessible, it will exit the function.
		std::ifstream file(filename);
		if (file.is_open() == false) {
			std::cout << "ERROR: File not found or is inaccessible\n";
		} else {
			// Reads the text file, using space as a delimiter. Counts how many words to use for initializing heap.
			do {
				file.getline(currentWord, 256, ' ');
				wordCount++;
			} while (file.good());

			// Clears the ifstream and rewinds back to the beginning of the file.
			file.clear();
			file.seekg(0);
			arrSize = wordCount;

			// Creates space in the heap for the strings, and reads the file again to put words into the array.
			strings = new std::string[wordCount]{};
			for (unsigned int i = 0; i < wordCount; i++) {
				file.getline(currentWord, 256, ' ');
				strings[i] = currentWord;
			}
		}

		file.close();
	}

	StringSet::StringSet(const StringSet& source) {
		this->arrSize = source.arrSize;
		strings = new std::string[source.arrSize]();
		for (unsigned int i = 0; i < source.arrSize; i++) {
			this->strings[i] = source.strings[i].c_str();
		}
	}

	StringSet::StringSet(StringSet&& source) noexcept {
		this->strings = source.strings;
		this->arrSize = source.arrSize;
		source.strings = nullptr;
		source.arrSize = 0;
	}

	StringSet::~StringSet() {
		delete[] this->strings;
		this->strings = nullptr;
	}

	size_t StringSet::size() {
		return arrSize;
	}

	std::string StringSet::operator[](size_t index) {
		size_t arraySize = this->size();
		if (index < arraySize) {
			return strings[index];
		} else {
			return std::string();
		}
	}

	StringSet& StringSet::operator=(const StringSet& source) {
		if (this != &source){
			delete[] this->strings;
			strings = new std::string[source.arrSize]();
			for (unsigned int i = 0; i < source.arrSize; i++) {
				this->strings[i] = source.strings[i].c_str();
			}
			this->arrSize = source.arrSize;
		}
		return *this;
	}
	StringSet& StringSet::operator=(StringSet&& source) noexcept {
		if (this != &source) {
			delete[] this->strings;
			this->strings = source.strings;
			this->arrSize = source.arrSize;
			source.strings = nullptr;
			source.arrSize = 0;
		}
		return *this;
	}
}