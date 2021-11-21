#pragma once
#include<fstream>

void CreateGameObject(std::string name)
{
  std::string REPLACE_WORD{"EntityTemplate"};

  std::ifstream* reader{new std::ifstream()};
  std::ofstream* writer{new std::ofstream()};

  reader->open("cli/templates/GameObjectHH.template");
  writer->open("include/" + name + ".hh");

  std::string currentLine{};

  while (std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(REPLACE_WORD)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, REPLACE_WORD.length(), name);
    }
    *writer << currentLine + "\n";
  }
  writer->close();
  reader->close();

  reader->open("cli/templates/GameObjectCC.template");
  writer->open("src/" + name + ".temp");

  while (std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(REPLACE_WORD)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, REPLACE_WORD.length(), name);
    }
    *writer << currentLine + "\n";
  }
  writer->close();
  reader->close();

  reader->open("src/" + name + ".temp");
  writer->open("src/" + name + ".cc");

  while (std::getline(*reader, currentLine))
  {
    size_t pos{currentLine.find(REPLACE_WORD)};

    if(pos != std::string::npos)
    {
      currentLine.replace(pos, REPLACE_WORD.length(), name);
    }
    *writer << currentLine + "\n";
  }
  writer->close();
  reader->close();

  std::string removeFile{"src/" + name + ".temp"};
  std::remove(removeFile.c_str());

  delete writer;
  delete reader;
}