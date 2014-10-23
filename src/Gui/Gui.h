#ifndef GUI_H
#define GUI_H

#include "Utils/glodef.h"
#include <libtcod.hpp>
#include <string>
#include <list>
#include <vector>
#include <utility>

class Gui
{
public:
  struct LogEntry
  {
    std::string msg;
    TCODColor color;

    LogEntry(const std::string& m, TCODColor c)
      : msg(m)
      , color(c)
    {}
  };

  const size_t LogSize = 17;

  const int rightConWidth = 20;
  const int rightConHeight = gloScreenHeight;

  const int bottomConWidth = gloScreenWidth - 20;
  const int bottomConHeight = 20;

  const int logConWidth = (gloScreenWidth - 20) / 2;
  const int logConHeight = 20;

  const int viewConWidth = (gloScreenWidth - 20) / 2;
  const int viewConHeight = 20;

  Gui();
  ~Gui();

  void render();
  void renderRightPanel();
  void renderMessageLog();
  void renderViewPanel(std::vector<LogEntry> *items = nullptr);

  void message(std::string msg, TCODColor color = TCODColor::white);

private:

  std::list< LogEntry > _msgLog;
  TCODColor _frameColor;

  TCODConsole* rCon;
  TCODConsole* bCon;

  TCODConsole* logCon;
  TCODConsole* viewCon;


};

#endif // GUI_H
