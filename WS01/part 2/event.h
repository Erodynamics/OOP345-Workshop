// Name: Jean Blaise Odasco
// ID: 114351190
// Email: jbodasco@myseneca.ca
// Completion Date: 2021/09/26

#pragma once
#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H
#define _CRT_SECURE_NO_WARNINGS

extern unsigned int g_sysClock;
namespace sdds {

	class Event {
		char* eventDesc = nullptr;
		unsigned int eventTime; // Total time in seconds
		unsigned int eventTimeH; // Hours contained in eventTime
		unsigned int eventTimeM; // Minutes contained in eventTime
		unsigned int eventTimeS; // Seconds contained in eventTime
	public:
		Event();
		~Event();
		Event(const Event& source);
		Event& operator=(const Event& source);
		void display();
		void set();
		void set(const char* description);
	};
}

#endif // _SDDS_EVENT_H