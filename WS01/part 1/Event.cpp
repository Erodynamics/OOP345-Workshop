#include "Event.h"
#include <cstring>
#include <iostream>
#include <iomanip>

extern unsigned int g_sysClock = 0u; // A day is 86400 seconds long
namespace sdds {
	sdds::Event::Event() {
		set();
	}

	void Event::display() {
		unsigned int static COUNTER = 1;
		if (eventDesc == nullptr) {
			std::cout << COUNTER << ". | No Event |\n";
		} else {
			std::cout << COUNTER << ". ";
			std::cout << std::setw(2) << std::setfill('0') << eventTimeH << ':' << std::setw(2) << std::setfill('0') << eventTimeM << ':' << std::setw(2) << std::setfill('0') << eventTimeS;
			std::cout << " => " << eventDesc << std::endl;
		}
		COUNTER++;
	}
	
	void Event::set() {
		eventDesc = nullptr;
		eventTime = 0;
		eventTimeH = 0;
		eventTimeM = 0;
		eventTimeS = 0;
	}

	void Event::set(const char* description) {
		size_t descLen = strlen(description);
		unsigned int tempTime = g_sysClock;
		if (descLen == 0) {
			set();
		} else {
			eventTime = g_sysClock;
			eventDesc = new char[descLen + 1]();
			strcpy(eventDesc, description);
			eventTimeS = (unsigned int)tempTime % 60;
			eventTimeH = (unsigned int)trunc(tempTime / 3600);
			eventTimeM = (unsigned int)trunc(tempTime / 60) - eventTimeH * 60;
		}
	}
}