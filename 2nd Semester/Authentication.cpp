#include "Authentication.h"

bool Authentication::verifyLogin(AUsers *user, string email, string pass)
{
	return user->login(email, pass);
}

bool Authentication::logout(AUsers *user)
{
	return user->logOut();
}
