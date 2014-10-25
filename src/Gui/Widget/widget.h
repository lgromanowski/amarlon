#ifndef WIDGET_H
#define WIDGET_H

#include <memory>

class TCODConsole;

namespace amarlon { namespace gui {

class Widget
{
public:
  Widget();
  virtual ~Widget() {}

  virtual void render(TCODConsole& console) = 0;

  int getX() const;
  int getY() const;

  void setPosition(int x, int y);

protected:
  int _x;
  int _y;

};

typedef std::shared_ptr<Widget> WidgetPtr;

}}

#endif // WIDGET_H
