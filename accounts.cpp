// Description: Definition of a user account class

#include "accounts.h"

UserAccount::UserAccount()
{
  username = "user";
  password = "password"; // default password
  userlevel = REGULAR_;
}

UserAccount::UserAccount(std::string name, int level)
{
  username = name;
  password = "password"; // default password
  if (level == ADMIN_ || level == REGULAR_)
    userlevel = level;
  else
    userlevel = REGULAR_;
}

void UserAccount::SetUsername(std::string name)
{
  username = name;
}

bool UserAccount::SetPassword(std::string oldpassword, std::string newpassword)
{
  if (newpassword != "" && oldpassword == password)
  {
    password = newpassword;
    return true;
  }
  return false;
}

bool UserAccount::SetUserLevel(int level)
{
  if (level != userlevel && (level == ADMIN_ || level == REGULAR_))
  {
    userlevel = level;
    return true;
  }
  return false;
}


std::string UserAccount::GetUsername() const
{
  return username;
}

std::string UserAccount::GetPassword() const
{
  return password;
}

int UserAccount::GetUserLevel() const
{
  return userlevel;
}

bool UserAccount::operator==(const UserAccount& acct) const
{
  return (username == acct.username);
}

bool UserAccount::operator!=(const UserAccount& acct) const
{
  return !(*this == acct);
}