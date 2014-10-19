TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    DataGateways/DataGateway.cpp \
    World/Map.cpp \
    DataGateways/MapGateway.cpp \
    DataGateways/TileDB.cpp \
    CommandExecutor.cpp \
    Actor/Actor.cpp \
    Commands/Command.cpp \
    Commands/CmdMove.cpp \
    DataGateways/ActorDB.cpp \
    Commands/CmdOpen.cpp \
    Commands/CmdFullscreen.cpp \
    Actor/ActorFeatures/Container.cpp \
    Commands/CmdInventory.cpp \
    Actor/ActorFeatures/Pickable.cpp \
    Commands/CmdPick.cpp \
    Utils/ItemPicker.cpp \
    Commands/CmdDrop.cpp \
    Utils/InventoryManager.cpp \
    Actor/ActorFeatures/Ai.cpp \
    Actor/ActorFeatures/MonsterAi.cpp \
    Gui/Gui.cpp \
    Utils/Utils.cpp \
    Engine.cpp \
    Actor/ActorFeatures/ActorFeature.cpp \
    Actor/ActorFeatures/Fighter.cpp \
    Gui/ItemPickerWindow.cpp \
    Gui/AmountWindow.cpp \
    Commands/CmdClose.cpp \
    Utils/DirectionSelector.cpp

HEADERS += \
    DataGateways/DataGateway.h \
    World/Map.h \
    DataGateways/MapGateway.h \
    World/MapId.h \
    World/TileType.h \
    Engine.h \
    DataGateways/TileDB.h \
    CommandExecutor.h \
    Actor/Actor.h \
    Commands/Command.h \
    Commands/CmdMove.h \
    DataGateways/ActorDB.h \
    Actor/ActorType.h \
    Commands/CmdOpen.h \
    Commands/CmdFullscreen.h \
    Actor/ActorFeatures/Container.h \
    Commands/CmdInventory.h \
    Actor/ActorFeatures/Pickable.h \
    Commands/CmdPick.h \
    Utils/ItemPicker.h \
    Commands/CmdDrop.h \
    Utils/InventoryManager.h \
    Actor/ActorFeatures/Ai.h \
    Actor/ActorFeatures/MonsterAi.h \
    Actor/ActorFeatures/AiType.h \
    Gui/Gui.h \
    Utils/glodef.h \
    Utils/Utils.h \
    Actor/ActorFeatures/ActorFeature.h \
    Actor/ActorFeatures/Fighter.h \
    Gui/ItemPickerWindow.h \
    Gui/AmountWindow.h \
    Commands/CmdClose.h \
    Utils/DirectionSelector.h


win32: LIBS += -L$$PWD/../lib/ -ltcod-mingw
unix:  LIBS += -L$$PWD/../lib/ -ltcod

INCLUDEPATH += $$PWD/../include
INCLUDEPATH += $$PWD/../include/libtcod
DEPENDPATH += $$PWD/../include
