#pragma once
#include<box2d/box2d.h>
#include "GameObject.hh"
#include<vector>

class ContactEventManager : public b2ContactListener
{
private:
  std::vector<GameObject*>* gameObjectDeleteList;
public:
  ContactEventManager(std::vector<GameObject*>*& gameObjectDeleteList);
  ~ContactEventManager();

  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;
};