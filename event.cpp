/* Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 05-25-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

unsigned g_sysClock = 0u;
namespace sdds{
	Event::Event(char* src) {
		if (src != nullptr) {
			desc = new char[strlen(src) + 1];
			strcpy(desc, src);
		}
		else {
			desc = nullptr;
		}
		time = 0;
	}
	Event::Event(const Event& copy) {
		/*time = copy.time;
		desc = new char[strlen(copy.desc) + 1];
		strcpy(desc, copy.desc);*/
		*this = copy; // it calles the copy assignement operator
	}
	Event& Event::operator=(const Event& e) {
		if (this != &e) {
			delete[] desc;
			desc = new char[strlen(e.desc) + 1];
			strcpy(desc, e.desc);
			time = e.time;
		}
		return *this;
	}
	Event::~Event() {
		delete[] desc;
		desc = nullptr;
	}
	void Event::display() const {
		static size_t counter = 0;
		if (desc != nullptr && desc[0] != '\0') {
			int hh = time / 60 / 60;
			int mm = (time - hh * 60 * 60) / 60;
			int ss = time - hh * 60 * 60 - mm * 60;
			std::cout.width(2);
			std::cout << ++counter << ". " << setw(2) << setfill('0') << hh << ":" <<  setw(2) << mm << ":" << setw(2)  << ss << " => " << desc << setfill(' ')<< std::endl;
		}
		else {
			std::cout.width(2);
			std::cout << ++counter << ". " << "| No Event |" << std::endl;
		}
	}
	void Event::set(const char* addr) {
		if (addr != nullptr && addr[0] != '\0') {
			time = ::g_sysClock;
			delete [] desc;
			desc = new char[strlen(addr) + 1];
			strcpy(desc, addr);
		}
		else {
			desc[0] = '\0';
		}
	}
}
