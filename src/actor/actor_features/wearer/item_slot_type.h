#ifndef ITEM_SLOT_TYPE_H
#define ITEM_SLOT_TYPE_H

namespace amarlon {

enum class ItemSlotType
{
  Null = 0,

  Helmet = 1,
  Amulet = 2,
  Armor = 3,
  Belt = 4,  
  Hands = 5,
  Boots = 6,
  MainHand = 7,
  Offhand = 8,
  LeftRing = 9,
  RightRing = 10,
  Cloak = 11,
  Arrows = 12,
  Bolts = 13,
  Bullets = 14,

  End = 15
};

static inline const char* ItemSlotType2Str(ItemSlotType slot)
{
  return (const char *[]){
          "Invalid-Null",

          "Helmet",
          "Amulet",
          "Armor",
          "Belt",
          "Hands",
          "Boots",
          "Main hand",
          "Offhand",
          "Left ring",
          "Right ring",
          "Cloak",
          "Arrows",
          "Bolts",
          "Bullets",

          "Invalid-End"
          }[(int)slot];
}

static inline const char* ItemSlotType2Str(int slot)
{
  return ItemSlotType2Str(static_cast<ItemSlotType>(slot));
}


}

#endif // ITEM_SLOT_TYPE_H
