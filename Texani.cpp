/*******************************************************************************************************************************
	Main file for the "Texani" Texture Animation library
	every part of this library will find its use in here

	Author: Alexander Bassov - 02.01.2016
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

//_______________________________________________________________________________________________________________
// definitions
UINT Texani::m_uiInstanceCount = 0;

//_______________________________________________________________________________________________________________
// constructor
Texani::Texani()
{
	//
	m_uiInstanceCount++;

	std::cout << "Texani instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// destructor
Texani::~Texani()
{
	//
	m_uiInstanceCount--;

	//
	std::cout << "Texani instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
// copy constructor
Texani::Texani(const Texani& rhs)
{
	//
	m_uiInstanceCount++;

	//
	*this = rhs;

	//
	std::cout << "Texani copy created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // copy constructor
//

//_______________________________________________________________________________________________________________
// Operator=
Texani Texani::operator=(const Texani& rhs)
{
	//
	return *this;

} //
//

//_______________________________________________________________________________________________________________