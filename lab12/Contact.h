#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include "ContactType.h"
using namespace std;
class Contact {
protected:
	string name;
public:
	virtual string GetName() = 0;
	virtual ContactType GetType() = 0;
};

#endif
