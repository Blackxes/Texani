/*******************************************************************************************************************************
	manages a group of motions in order to define a specific behaviour

	Author: Alexander Bassov - 08.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
#include <Core/Includer/taIncluder.h>

//_______________________________________________________________________________________________________________
// definitions
UINT taMotionGroup::m_uiInstanceCount = 0;

//_______________________________________________________________________________________________________________
// resets the whole instance
void taMotionGroup::reset()
{
	//
	m_sLabel				= std::string();
	m_vecStartFrame			= stVector2Di(0);
	m_itCurrMotion			= std::forward_list<taMotion>::iterator();

	m_liMotionList.clear();
	m_mMotionListRegister.clear();

	m_bDone					= false;
	m_bInternPermAnimate	= false;

	//

} // reset
//

//_______________________________________________________________________________________________________________
// checks the initialization state
bool taMotionGroup::checkInitialization()
{
	//
	if (m_sLabel.empty()) return false;

	//
	m_bInternPermAnimate = true;

	//
	return true;

} // checkInitialization
//

//_______________________________________________________________________________________________________________
// validates the motion id
stState taMotionGroup::checkMotionId(const int iMotionId)
{
	// check if the id 
	if (iMotionId < 0)
		return ST_CANCEL;

	// if the id is not in the register
	if (m_mMotionListRegister.find(iMotionId) == m_mMotionListRegister.end())
		return ST_NOT_FOUND;

	//
	return ST_OK;

} // validateMotionId
//

//_______________________________________________________________________________________________________________
// defines the configuration
stState taMotionGroup::setConfiguration(const taConfiguration* Configuration)
{
	//
	if (m_Configuration == nullptr)
		return ST_FAIL;
	//
	m_Configuration = Configuration;

	//
	return ST_OK;

} // setConfiguration
//

//_______________________________________________________________________________________________________________
// returns a usable id for a motion
int taMotionGroup::getFreeMotionId()
{
	//
	int iFreeId = (int) std::distance(m_liMotionList.begin(), m_liMotionList.end());
	// as long as the id is in the register
	// increase until its free
	while (this->checkMotionId(iFreeId) != ST_NOT_FOUND)
		iFreeId++;
	//
	return iFreeId;

} // getFreeMotionId
//

//_______________________________________________________________________________________________________________
// returns a none constant iterator of a motion
taMotion* taMotionGroup::getMotionPtr(const int iMotionId)
{
	// validate
	if (this->checkMotionId(iMotionId) != ST_OK)
		return nullptr;

	// return the iterator
	return m_mMotionListRegister[iMotionId];

} // getMotionPtr
//

//_______________________________________________________________________________________________________________
// adds an entity into the register
bool taMotionGroup::addRegister(taMotion* MotionEntity)
{
	// if motion id is negative
	if (this->checkMotionId(MotionEntity->getMotionId()) != ST_NOT_FOUND)
		return false;
	//
	m_mMotionListRegister.insert(std::make_pair(MotionEntity->getMotionId(), MotionEntity) );

	//
	return true;

} // addRegister
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// constructor
taMotionGroup::taMotionGroup(const std::string&				sLabel,
							 const std::string&				sTexturePath,
							 const stVector2Di&				vecStartFrame)
{
	// reset and define
	this->reset();

	// basic definition
	m_sLabel			= sLabel;
	m_vecStartFrame		= vecStartFrame;

	// load and define texture
	if (this->loadFromFile(sTexturePath))
		this->setTexture(*this);

	//
	this->checkInitialization();

	//
	m_uiInstanceCount++;
	std::cout << "taMotionGroup instance created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // constructor
//

//_______________________________________________________________________________________________________________
// destructor
taMotionGroup::~taMotionGroup()
{
	//
	this->reset();

	//
	m_uiInstanceCount--;

	//
	if (!m_uiInstanceCount)
		std::cout << "taMotionGroup no existing instances (existing instances: " << m_uiInstanceCount << ")" << std::endl;
	else
		std::cout << "taMotionGroup instance destroyed (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // destructor
//

//_______________________________________________________________________________________________________________
// copy constructor
taMotionGroup::taMotionGroup(const taMotionGroup& rhs)
{
	//
	m_uiInstanceCount++;

	//
	*this = rhs;

	//
	std::cout << "taMotionGroup copy created (existing instances: " << m_uiInstanceCount << ")" << std::endl;

} // copy constructor
//

//_______________________________________________________________________________________________________________
// Operator =
taMotionGroup& taMotionGroup::operator=(const taMotionGroup& rhs)
{
	//
	this->m_sLabel = rhs.m_sLabel;

	this->m_vecStartFrame = rhs.m_vecStartFrame;
	this->m_liMotionList = rhs.m_liMotionList;
	this->m_itCurrMotion = rhs.m_itCurrMotion;

	this->m_mMotionListRegister = rhs.m_mMotionListRegister;

	this->m_bDone = rhs.m_bDone;
	this->m_bInternPermAnimate = rhs.m_bInternPermAnimate;

	//
	return *this;

} // Operator =
//

//_______________________________________________________________________________________________________________
// Operator ==
bool taMotionGroup::operator==(const taMotionGroup& rhs)
{
	//
	if (this->m_sLabel != rhs.m_sLabel) return false;

	if (this->m_vecStartFrame != rhs.m_vecStartFrame) return false;
	if (this->m_liMotionList != rhs.m_liMotionList) return false;
	if (this->m_itCurrMotion != rhs.m_itCurrMotion) return false;

	if (this->m_mMotionListRegister != rhs.m_mMotionListRegister) return false;

	if (this->m_bDone != rhs.m_bDone) return false;
	if (this->m_bInternPermAnimate != rhs.m_bInternPermAnimate) return false;

	//
	return true;

} // Operator==
//

//_______________________________________________________________________________________________________________
// adds a motion to the motion list via instance
bool taMotionGroup::addMotion(const taMotion& Motion)
{
	// check if the motion is initialized
	if (!Motion.getInitialized())
		return false;

	// define position of the new motion
	auto itListPosition = m_liMotionList.end();

	// insert new copied created instance
	// and safe it as a pointer
	m_liMotionList.insert_after(m_liMotionList.end(), taMotion(Motion));
	taMotion* pNewMotion = &(*m_liMotionList.end());
	pNewMotion->setMotionId(this->getFreeMotionId());

	// define iterator
	if (!this->addRegister(pNewMotion))
		return false;

	//
	return true;

} // addMotion
//

//_______________________________________________________________________________________________________________
// adds a motion to the motion list via separate definition
bool taMotionGroup::addMotion(const stVector2Di& vecMovement, const int iDuration, const int iListPosition)
{
	// check duration
	int usedDuration = (iDuration < 0) ? TA_DEFAULT_FRAME_DURATION : iDuration;

	//
	return this->addMotion(taMotion(vecMovement, iDuration));

} // addMotion
//

//_______________________________________________________________________________________________________________
// resets the current selected motion via position
bool taMotionGroup::setCurrMotion(const int iPosition)
{
	// check if
	if ( (iPosition < 0) || (iPosition > (int) std::distance(m_liMotionList.begin(), m_liMotionList.end())) )
		return false;

	// reset and define it's pointing
	m_itCurrMotion = m_liMotionList.begin();
	std::advance(m_itCurrMotion, iPosition);

	//
	return true;

} // setCurrMotion
//

//_______________________________________________________________________________________________________________
//

//
//
//

//_______________________________________________________________________________________________________________
// defines the designation of this motion group
bool taMotionGroup::setLabel(const std::string& sLabel)
{
	// check if empty
	if (sLabel.empty())
		return false;
	//
	m_sLabel = sLabel;

	// check initialization cause the designation is part of it
	this->checkInitialization();

	//
	return true;

} // setDesignation
//

//_______________________________________________________________________________________________________________
// desines the start frame
bool taMotionGroup::setStartFrame(const stVector2Di& vecStartFrame)
{
	// if one of the values is negative
	if ( (vecStartFrame.x < 0) || (vecStartFrame.y < 0) )
		return false;
	//
	m_vecStartFrame = vecStartFrame;

	//
	return true;

} // setStartFrame
//

//_______________________________________________________________________________________________________________
// (re)defines the motion list completely
bool taMotionGroup:: setMotionList(const std::forward_list<taMotion>& liMotionList)
{
	//
	if (liMotionList.empty())
		return false;
	//
	m_liMotionList = std::forward_list<taMotion>(liMotionList);

	//
	return true;

} // setMotionList
//

//_______________________________________________________________________________________________________________
//
