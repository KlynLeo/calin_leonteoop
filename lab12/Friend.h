#ifndef FRIEND_H
#define FRIEND_H
#include "Contact.h"
class Friend : public Contact {

private:
	string dateOfBirth;
	string phoneNumber;
	string address;

public:
	string GetName() override;
	Friend(string);
	ContactType GetType() override;
};

#endif
