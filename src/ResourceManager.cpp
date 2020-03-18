#include <fstream>
#include "ResourceManager.h"

using namespace std;

ResourceManager::ResourceManager()
{
    this->resource_path = "res/";
}

vector<string> ResourceManager::fetch(string path) 
{
  vector<string> vData;
  string line;
  ifstream file(this->resource_path + path);
  if (!file.is_open()) {
    throw 1;
  }
  
  while (getline(file, line)) {
    vData.push_back(line);
  }
  return vData;
}