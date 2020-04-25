#pragma once

#include <string>
#include <vector>

using namespace std;

class ResourceManager
{
public:
  ResourceManager();
  vector<string> fetch(const string& path) const;
private:
  string resource_path;
};