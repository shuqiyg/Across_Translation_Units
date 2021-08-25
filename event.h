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

#ifndef EVENT_H_
#define EVENT_H_


extern unsigned g_sysClock;
namespace sdds {
	class Event {
		char *desc = nullptr;
		unsigned time = 0;
	public:
		Event(char* src = nullptr);
		Event(const Event&);
		Event& operator=(const Event& e);
		~Event();
		void display() const;
		void set(const char* addr = nullptr);
	};
}
#endif