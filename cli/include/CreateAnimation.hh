#pragma once
#include<fstream>
#include<iostream>

void CreateAnimation(char**& argv)
{
  //std::cout << "animation name: " << argv[2] << " " << "delay: " << argv[3] << " " << "row: " << argv[4] << " " << "startframe: " << argv[5] << " " << "endFrame: " << argv[6] << std::endl;
  std::string path{argv[2]};
  std::string delay{argv[3]};
  std::string row{argv[4]};
  std::string startFrame{argv[5]};
  std::string endFrame{argv[6]};
  std::ofstream* writer{new std::ofstream()};

  writer->open(path + ".anim");

  *writer << delay;
  *writer << " " + row;
  *writer << " " + startFrame;
  *writer << " " + endFrame;

  writer->close();
  delete writer;
}