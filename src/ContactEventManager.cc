#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjectDeleteList)
{
  this->gameObjectDeleteList = gameObjectDeleteList;
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
  //b2ContactListener::BeginContact(contact);

  GameObject* goA{(GameObject*) contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* goB{(GameObject*) contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(goA && goB)
  {
    if(goB->GetTagName().compare("chest") == 0)
    {
      gameObjectDeleteList->push_back(goB);
    }
  }
}
void ContactEventManager::EndContact(b2Contact *contact)
{
  //b2ContactListener::EndContact(contact);
}