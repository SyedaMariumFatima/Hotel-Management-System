#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "AUsers.h"

class Authentication
{
public:
	static bool verifyLogin(AUsers *user, string email, string pass);
	static bool logout(AUsers *user);
};

#endif
