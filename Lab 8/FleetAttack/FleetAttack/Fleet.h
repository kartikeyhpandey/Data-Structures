//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing C1-3
    @file PlainBox.h */

#ifndef FLEET_
#define FLEET_

#include <vector>

template<class ItemType> // Indicates this is a template definition

// Declaration for the class PlainBox
class Fleet
{
private:
   // Data field
   ItemType m_flagShip;
   std::vector<ItemType> m_flotilla;
   
public:
   // Default constructor
    Fleet();
   
   // Parameterized constructor
    Fleet(const ItemType& flagship);
   
   // Mutator method that can change the value of the data field
   void setFlagShip(const ItemType& theItem);
   
   // Accessor method to get the value of the data field
   ItemType getFlagShip() const;

   void addFlotilla(const ItemType& theItem);

   std::vector<ItemType> getFlotilla();

}; // end PlainBox

#include "Fleet.cpp" // Include the implementation file
#endif