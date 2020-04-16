#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <vector>

using namespace std;

class ResourceManager
{
public:
  ResourceManager();
  vector<string> fetch(const string& path);
private:
  string resource_path;
};


#endif // RESOURCE_MANAGER_H