//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing C1-4
    @file PlainBox.cpp */
    
#include "Fleet.h"

template<class ItemType>
Fleet<ItemType>::Fleet()
{
}  // end default constructor

template<class ItemType>
Fleet<ItemType>::Fleet(const ItemType& theItem) : m_flagShip(theItem)
{
}  // end constructor

template<class ItemType>
void Fleet<ItemType>::setFlagShip(const ItemType& theItem)
{
    m_flagShip = theItem;
}  // end setItem

template<class ItemType>
ItemType Fleet<ItemType>::getFlagShip() const
{
   return m_flagShip;
}  // end getItem

template<class ItemType>
void Fleet<ItemType>::addFlotilla(const ItemType& theItem)
{ 
    m_flotilla.push_back(theItem);
}
template<class ItemType>
std::vector<ItemType> Fleet<ItemType>::getFlotilla()
{
    return m_flotilla;
}

