#pragma once
#include<box2d/box2d.h>

class ContactEventManager : public b2ContactListener
{
private:

public:
  ContactEventManager();
  ~ContactEventManager();

  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;
};
