#pragma once
#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
#define _CRT_SECURE_NO_WARNINGS

extern unsigned int g_sysClock;
namespace sdds {

	class Event {
		char* eventDesc;
		unsigned int eventTime; // Total time in seconds
		unsigned int eventTimeH; // Hours contained in eventTime
		unsigned int eventTimeM; // Minutes contained in eventTime
		unsigned int eventTimeS; // Seconds contained in eventTime
	public:
		Event();
		void display();
		void set();
		void set(const char* description);
	};
}

#endif // _SDDS_EVENT_H