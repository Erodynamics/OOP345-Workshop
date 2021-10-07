// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/09/26

#include "event.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <math.h>

unsigned int g_sysClock = 0u; // A day is 86400 seconds long
namespace sdds {
	sdds::Event::Event() {
		set();
	}

	Event::~Event() {
		delete[] eventDesc;
		eventDesc = nullptr;
	}

	sdds::Event::Event(const Event& source) {
		if (source.eventDesc != nullptr) {
			this->eventDesc = new char[strlen(source.eventDesc) + 1]();
			strcpy(this->eventDesc, source.eventDesc);
		} else {
			this->eventDesc = nullptr;
		}

		this->eventTime = source.eventTime;
		this->eventTimeH = source.eventTimeH;
		this->eventTimeM = source.eventTimeM;
		this->eventTimeS = source.eventTimeS;
	}
	Event& Event::operator=(const Event& source){
		delete[] this->eventDesc;

		if (source.eventDesc != nullptr) {
			this->eventDesc = new char[strlen(source.eventDesc) + 1]();
			strcpy(this->eventDesc, source.eventDesc);
		} else {
			this->eventDesc = nullptr;
		}

		this->eventTime = source.eventTime;
		this->eventTimeH = source.eventTimeH;
		this->eventTimeM = source.eventTimeM;
		this->eventTimeS = source.eventTimeS;

		return *this;
	}

	void Event::display() {
		unsigned int static COUNTER = 1;

		if (eventDesc == nullptr) {
			std::cout << std::setw(2) << std::setfill(' ') << COUNTER << ". | No Event |\n";
		} else {
			if (strcmp(eventDesc, "")) {
				std::cout << std::setw(2) << std::setfill(' ') << COUNTER << ". ";
				std::cout << std::setw(2) << std::setfill('0') << eventTimeH << ':' << std::setw(2) << std::setfill('0') << eventTimeM << ':' << std::setw(2) << std::setfill('0') << eventTimeS;
				std::cout << " => " << eventDesc << std::endl;
			} else {
				std::cout << COUNTER << ". | No Event |\n";
			}
		}

		COUNTER++;
	}

	void Event::set() {
		delete[] eventDesc;
		eventDesc = nullptr;
		eventTime = 0;
		eventTimeH = 0;
		eventTimeM = 0;
		eventTimeS = 0;
	}

	void Event::set(const char* description) {
		unsigned int tempTime = g_sysClock;

		delete[] eventDesc;
		eventDesc = nullptr;

		if (description != nullptr && description[0] != '\0') {
			eventDesc = new char[strlen(description) + 1]();
			strcpy(this->eventDesc, description);
		} else {
			eventDesc = nullptr;
		}

		eventTime = g_sysClock;
		eventTimeS = (unsigned int)tempTime % 60;
		eventTimeH = (unsigned int)trunc(tempTime / 3600);
		eventTimeM = (unsigned int)trunc(tempTime / 60) - eventTimeH * 60;
	}
}