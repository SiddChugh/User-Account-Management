// Description: Definition of a user account class

#ifndef _ACCOUNTS_H_
#define _ACCOUNTS_H_

// user account types
#define ADMIN_   0
#define REGULAR_ 1

#include <string>

class UserAccount
{
private:
  std::string username;
  std::string password;
  int userlevel;   // ADMIN_ or REGULAR_

public:
  UserAccount();

  UserAccount(std::string name, int level);

  void SetUsername(std::string name);

  /**
    *update password attribute to new password and return true if oldpassword 
    *matches existing password
    *return false otherwise
    */
  bool SetPassword(std::string oldpassword, std::string newpassword);

  /**
    *update userlevel and return true if parameter is different from current 
    *userlevel
    *return false otherwise
    */
  bool SetUserLevel(int level);

  std::string GetUsername() const;

  std::string GetPassword() const;

  int GetUserLevel() const;

  bool operator==(const UserAccount& acct) const;
  bool operator!=(const UserAccount& acct) const;
};
#endif
