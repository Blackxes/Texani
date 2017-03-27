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
// resets the object
void taMotionController::reset()
{
	//
	this->m_itCurrMotionGroup = std::forward_list<taMotionGroup>::iterator();
	this->m_DefaultMotionGroup = nullptr;

	this->m_mMotionGroupRegister.clear();
	this->m_liMotionGroups.clear();

} // reset
//

//_______________________________________________________________________________________________________________
// constructor
taMotionController::taMotionController()
{
	// resets the object
	this->reset();

	//
	m_uiInstanceCount++;
	std::cout << "taMotionController instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// constructor
taMotionController::taMotionController(std::string sTexturePath)
{
	//
	this->reset();

	//
	m_sTexturePath = sTexturePath;

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
	this->reset();

	//
	m_uiInstanceCount--;

	//
	if (!m_uiInstanceCount)
		std::cout << "taMotionController no existing instances (existing instances: " << m_uiInstanceCount << ")" << std::endl;
	else
		std::cout << "taMotionController instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// adds a motion group to the current motion group list via direct definition
bool taMotionController::addMotionGroup(const taMotionGroup& MotionGroup)
{
	// check designation and motion group
	if (!MotionGroup.getInitialized())
		return false;

	// insert and register
	m_liMotionGroups.push_front(MotionGroup);
	//
	taMotionGroup* newMotionGroup = &(m_liMotionGroups.front());
	m_mMotionGroupRegister.insert(m_mMotionGroupRegister.begin(), std::make_pair(MotionGroup.getDesignation(), newMotionGroup));

	// if this was the first motion
	// define it as the default motion group
	if (std::distance(m_liMotionGroups.begin(), m_liMotionGroups.end()) == 1)
		m_DefaultMotionGroup = newMotionGroup;

	//
	return true;

} // addMotion
//

//_______________________________________________________________________________________________________________
//
