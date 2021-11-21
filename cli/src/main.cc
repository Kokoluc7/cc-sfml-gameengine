#include<iostream>
#include<string>
#include "CreateGameObject.hh"
#include "CreateAnimation.hh"
#include "CreateTileGroup.hh"

void CheckArguments(int& argc, char**& argv);

int main(int argc, char** argv)
{
  CheckArguments(argc, argv);
  return 0;
}

void CheckArguments(int& argc, char**& argv)
{
  std::string command{argv[1]};
  switch (argc)
  {
  case 3:
    std::cout << command;
    if(command == "creategameobject")
    {
      CreateGameObject(argv[2]);
      break;
    }
    if(command == "createtilegroup")
    {
      CreateTileGroup(argv[2]);
      break;
    }
    break;
  case 7:
    if(command == "createanimation")
    {
      CreateAnimation(argv);
    }
    break;
  default:
    break;
  }
}