#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "Contact.h"
#include <vector>
using namespace std;
class AddressBook {

private:
	vector<Contact*> adrese;

public:
	bool Search(string nume);
	vector<Contact*> FriendList();
	void DeleteContact(string nume);
	void AddContact(Contact* nume);
};

#endif
