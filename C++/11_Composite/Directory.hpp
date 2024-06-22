#include <iostream>
#include <list>
#include <memory>
#include <string>

class IDirectoryEntry {
  public:
    virtual void remove() = 0;
};

class File : public IDirectoryEntry {
  private:
    std::string _name;

  public:
    File(std::string name) : _name(name) {}
    void remove() { std::cout << _name << " Deleted!" << std::endl; }
};

class Directory : public IDirectoryEntry {
  private:
    std::list<std::shared_ptr<IDirectoryEntry>> _list;
    std::string _name;

  public:
    Directory(std::string name) : _name(name), _list({}) {}
    void add(std::shared_ptr<IDirectoryEntry> entry) { _list.push_back(entry); }
    void remove() {
        for (auto &i : _list) {
            i->remove();
        }
        std::cout << _name << " Deleted!" << std::endl;
    }
};