#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H
#include "Contact.h"
class Acquaintance : public Contact {

private:
	string phoneNumber;
public:
	string GetName() override;
	Acquaintance(string);
	ContactType GetType() override;
};

#endif
