#ifndef ALIST_H
#define ALIST_H

#include <list>
#include <libtcod.hpp>
#include <awidget.h>
#include <utils/colored_string.h>

namespace amarlon { namespace gui {

class AList : public AWidget
{
public:
  typedef std::list<ColoredString>::iterator iterator;

  AList();
  virtual ~AList() {}

  virtual void render(TCODConsole& console);

  void pushBack(const ColoredString& entry);
  void pushFront(const ColoredString& entry);
  void popBack();
  void popFront();

  void clear();
  size_t size() const;

  iterator begin();
  iterator end();

  bool isAutosized() const;
  void setAutosize(bool autosize);

private:
  std::list<ColoredString> _entries;
  bool _autosize;

};

typedef std::shared_ptr<AList> AListPtr;

}}

#endif // LIST_H
