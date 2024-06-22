#pragma once
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
    void remove() override;
};

class Directory : public IDirectoryEntry {
  private:
    std::list<std::shared_ptr<IDirectoryEntry>> _list;
    std::string _name;

  public:
    Directory(std::string name) : _name(name), _list({}) {}
    void add(std::shared_ptr<IDirectoryEntry> entry);
    void remove() override;
};

class SymbolicLink : public IDirectoryEntry {
  private:
    std::string _name;

  public:
    SymbolicLink(std::string name) : _name(name) {}
    void remove() override;
};