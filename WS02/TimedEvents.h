// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/10/03

#pragma once
#ifndef _SDDS_TIMEDEVENTS_H
#define _SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>

namespace sdds {
	struct Event {
		std::string name;
		long long nanoseconds = 0;
	};

	class TimedEvents {
		struct Event tEvents[10];
		unsigned int storedRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedEvents& sourceEvent);
	};
}

#endif // _SDDS_TIMEDEVENTS_H
