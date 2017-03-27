/*******************************************************************************************************************************
	configuration of one texture animation

	Author: Alexander Bassov - 08.01.2017
*******************************************************************************************************************************/

//
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

//_______________________________________________________________________________________________________________
// definitions
UINT taConfiguration::m_uiInstanceCount = 0;

//_______________________________________________________________________________________________________________
// constructor
taConfiguration::taConfiguration() :	m_iFPS				(0),
										m_fVelocity			(0.0),
										m_vecFrames			(stVector2Di(0)),
										m_vecFrameSize		(stVector2Di(0)),
										m_vecCurrFrame		(stVector2Di(0)),
										m_bPermAnimate		(false)
{
	//
	m_uiInstanceCount++;

	std::cout << "taConfiguration instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// destructor
taConfiguration::~taConfiguration()
{
	//
	m_uiInstanceCount--;

	//
	if (!m_uiInstanceCount)
		std::cout << "taMotion no existing instances (existing instances: " << m_uiInstanceCount << ")" << std::endl;
	else
		std::cout << "taConfiguration instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
// copy constructor
taConfiguration::taConfiguration(const taConfiguration& rhs)
{
	//
	m_uiInstanceCount++;

	//
	*this = rhs;

	//
	std::cout << "taConfiguration copy created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // copy constructor
//

//_______________________________________________________________________________________________________________
// Operator=
taConfiguration taConfiguration::operator=(const taConfiguration& rhs)
{
	//
	return *this;

} //
//

//_______________________________________________________________________________________________________________
// defines the speed of the animation
void taConfiguration::setVelocity(const float fVelocity)
{
	//
	m_fVelocity = fVelocity;

} // setVelocity
//

//_______________________________________________________________________________________________________________
// defines the frames of the axises
bool taConfiguration::setFrames(const stVector2Di& vecFrames)
{
	// check if one of the frames is negatives
	if ( (vecFrames.x < 0) || (vecFrames.y < 0) )
		return false;
	//
	m_vecFrames = stVector2Di(vecFrames);

	//
	return true;

} // setFrames
//

//_______________________________________________________________________________________________________________
// defines the frames of each axis separatly
bool taConfiguration::setFrames(const int iX, const int iY)
{
	//
	return this->setFrames(stVector2Di(iX, iY));

} // setFrames
//

//_______________________________________________________________________________________________________________
// defines the framesize via vector
bool taConfiguration::setFramesize(const stVector2Di& iFramesize)
{
	// check if one of the values is negative
	if ( (iFramesize.x < 0) || (iFramesize.y < 0) )
		return false;
	//
	m_vecFrameSize = stVector2Di(iFramesize);

	//
	return true;

} // setFramesize
//

//_______________________________________________________________________________________________________________
// defines the framesize separatly
bool taConfiguration::setFramesize(const int iWidth, const int iLength)
{
	//
	return this->setFramesize(stVector2Di(iWidth, iLength));

} // setFramesize
//

//_______________________________________________________________________________________________________________
// defines the permission to animate
void taConfiguration::setPermAnimate(const bool bPermission)
{
	//
	m_bPermAnimate = bPermission;

} // setPermAnimate
//

//_______________________________________________________________________________________________________________
//
