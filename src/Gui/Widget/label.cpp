#include "label.h"

namespace amarlon { namespace gui {

Label::Label()
  : _color(TCODColor::white)
  , _bgcolor(TCODColor::black)
  , _aligment(TCOD_LEFT)
{
}

void Label::render(TCODConsole &console)
{
  console.setDefaultForeground(_color);
  console.setDefaultBackground(_bgcolor);
  console.printEx(_x, _y,
                  _bgcolor == TCODColor::black ? TCOD_BKGND_NONE : TCOD_BKGND_SET,
                  _aligment, "%s", _value.c_str());
}
std::string Label::getValue() const
{
  return _value;
}

void Label::setValue(const std::string &value)
{
  _value = value;
}
TCODColor Label::getColor() const
{
  return _color;
}

void Label::setColor(const TCODColor &color)
{
  _color = color;
}
TCOD_alignment_t Label::getAligment() const
{
  return _aligment;
}

void Label::setAligment(const TCOD_alignment_t &aligment)
{
  _aligment = aligment;
}
TCODColor Label::getBgcolor() const
{
  return _bgcolor;
}

void Label::setBgcolor(const TCODColor &bgcolor)
{
  _bgcolor = bgcolor;
}





}}