#include "Acquaintance.h"

Acquaintance::Acquaintance(string nume)
{
	name = nume;
}
string Acquaintance::GetName() {
	return name;
}

ContactType Acquaintance::GetType()
{
	return ContactType::Friend;
}
