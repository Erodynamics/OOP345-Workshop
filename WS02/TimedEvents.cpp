// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/10/03

#include "TimedEvents.h"
#include <iostream>
#include <iomanip>

namespace sdds {
	TimedEvents::TimedEvents() {
		
		storedRecords = 0;
	}

	// Both startClock() and stopClock() just records the current time as of calling the function.
	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName) {	
		tEvents[storedRecords].name = eventName;
		tEvents[storedRecords].nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
		storedRecords++;
	}

	std::ostream& operator<<(std::ostream& ostr, const TimedEvents& sourceEvent) {
		ostr << "--------------------------\n";
		ostr << "Execution Times:\n";
		ostr << "--------------------------\n";
		for (Event currentEvent : sourceEvent.tEvents) {
			if (!currentEvent.name.empty()) {
				ostr << std::setw(21) << std::left << currentEvent.name << ' ' << std::setw(13) << std::right << currentEvent.nanoseconds << std::endl;
			}
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}