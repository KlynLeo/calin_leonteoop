#ifndef COLLEAUGE_H
#define COLLEAUGE_H
#include "Contact.h"
class Colleauge : public Contact {

private:
	string phoneNumber;
	string company;
	string address;

public:
	string GetName() override;
	Colleauge(string);
	ContactType GetType() override;
};

#endif
