#include "AddressBook.h"
#include "ContactType.h"
#include "Contact.h"

bool AddressBook::Search(string nume) {
	for (auto contact : adrese)
	{
		if (contact->GetName() == nume)
			return true;
	}
	return false;
}

vector<Contact*> AddressBook::FriendList() {
	vector<Contact*> friends;
	for (auto contact : adrese)
	{
		if (contact->GetType() == ContactType::Friend)
			friends.pushback(contact);
	}
	return friends;
}

void AddressBook::DeleteContact(string name) {
	for (auto it = adrese.begin(); it != adrese.end(); ++it) {
		if ((*it)->GetName() == name) {
			delete* it; 
			adrese.erase(it); 
			break; 
		}
	}
}

void AddressBook::AddContact(Contact* nume) {
	adrese.push_back(nume);
}
