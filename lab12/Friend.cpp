#include "Friend.h"

string Friend::GetName() {
	return name;
}

ContactType Friend::GetType()
{
	return ContactType::Friend;
}

Friend::Friend(string nume)
{
	name = nume;
}