#pragma once
#include<fstream>
#include<iostream>

void CreateTileGroup(std::string path)
{
  std::ofstream* writer{new std::ofstream()};
  writer->open(path + ".tg");

  writer->close();
  delete writer;
}