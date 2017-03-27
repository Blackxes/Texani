/*******************************************************************************************************************************
	defines a specific behaviour of a defined frame range

	Example:
		forwards on the same axis from the beginning

	Author: Alexander Bassov - 08.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

//_______________________________________________________________________________________________________________
// definitions
UINT taMotion::m_uiInstanceCount = 0;

//_______________________________________________________________________________________________________________
// resets the object
void taMotion::reset()
{
	//
	this->m_iMotionId			= 0;
	this->m_iDuration			= 0;
	this->m_vecMovement			= stVector2Di();

} // reset
//

//_______________________________________________________________________________________________________________
// defines the motion id
bool taMotion::setMotionId(const int iMotionId)
{
	//
	if (iMotionId < 0)
		return false;
	//
	m_iMotionId = iMotionId;

	//
	return true;

} // setMotionId
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// constructor
taMotion::taMotion()
{
	//
	m_uiInstanceCount++;

	//
	std::cout << "taMotion instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// constructor
taMotion::taMotion(const stVector2Di	vecMovement,
				   const int			iDuration)
{
	// reseten
	this->reset();

	// definition
	m_iDuration		= (iDuration < 0) ? TA_DEFAULT_FRAME_DURATION : iDuration;
	m_vecMovement	= vecMovement;

	//
	m_uiInstanceCount++;

	std::cout << "taMotion instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// destructor
taMotion::~taMotion()
{
	//
	m_uiInstanceCount--;

	//
	if (!m_uiInstanceCount)
		std::cout << "taMotion no existing instances (existing instances: " << m_uiInstanceCount << ")" << std::endl;
	else
		std::cout << "taMotion instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
// copy constructor
taMotion::taMotion(const taMotion& rhs)
{
	//
	m_uiInstanceCount++;

	//
	*this = rhs;

	//
	std::cout << "taMotion copy created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // copy constructor
//

//_______________________________________________________________________________________________________________
// Operator=
taMotion& taMotion::operator=(const taMotion& rhs)
{
	//
	this->m_iMotionId			= rhs.m_iMotionId;
	this->m_iDuration			= rhs.m_iDuration;
	this->m_vecMovement			= rhs.m_vecMovement;

	this->m_bInitialized		= rhs.m_bInitialized;

	//
	return *this;

} // Operator==
//

//_______________________________________________________________________________________________________________
// initialization
bool taMotion::Init(const stVector2Di& vecMovement, const int iDuration)
{
	// when the duration is negative
	int usedDuration = iDuration;
	if (usedDuration < 0)
		usedDuration = TA_DEFAULT_FRAME_DURATION;
	//
	this->m_iDuration		= iDuration;
	this->m_vecMovement		= vecMovement;
	//
	this->m_bInitialized = true;
	//
	return true;

} // Init
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// defines the duration of this motion
bool taMotion::setDuration(const int iDuration)
{
	//
	if (iDuration < 0)
		return false;
	//
	m_iDuration = iDuration;

	//
	return true;

} // setDuration
//

//_______________________________________________________________________________________________________________
// defines the movement of this motion
void taMotion::setMovement(const stVector2Di vecMovement)
{
	//
	m_vecMovement = vecMovement;
	
} // setMovement
//

//_______________________________________________________________________________________________________________
//