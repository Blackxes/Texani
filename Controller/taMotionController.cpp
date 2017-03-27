/*******************************************************************************************************************************
	controlls a list of motions

	Author: Alexander Bassov - 10.01.2017
*******************************************************************************************************************************/

//
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

//_______________________________________________________________________________________________________________
// definitions
UINT taMotionController::m_uiInstanceCount = 0;

//_______________________________________________________________________________________________________________
// constructor
taMotionController::taMotionController()
{
	//
	m_uiInstanceCount++;

	std::cout << "taMotionController instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// destructor
taMotionController::~taMotionController()
{
	//
	m_uiInstanceCount--;

	//
	std::cout << "taMotionController instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// adds a motion to the current motion list via direct definition
bool taMotionController::addMotion(const taMotion& Motion)
{
	//
	if (!Motion.getInitialized())
		return false;

	//
	m_liMotions.push_back(new taMotion(Motion));
	m_mMotionRegister.insert(std::make_pair<std::string, int>(Motion.getDesignation(), (int) m_liMotions.size() - 1));

} // addMotion
//

//_______________________________________________________________________________________________________________
//
