/*******************************************************************************************************************************
	the after class functions for the taMotion class

	Author: Alexander Bassov - 20.01.2017
*******************************************************************************************************************************/
#pragma once
//

//_______________________________________________________________________________________________________________
// header
/* ... */

//_______________________________________________________________________________________________________________
// makros/defines
/* ... */

//_______________________________________________________________________________________________________________
// global variables/extern declaration
/* ... */

//_______________________________________________________________________________________________________________
// forwarddeclaration
/* ... */

//_______________________________________________________________________________________________________________
// structs/enums/etc.
/* ... */





//_______________________________________________________________________________________________________________
// Operator == for the taMotion class
inline bool operator==(const taMotion& lhs, const taMotion& rhs)
{
	//
	if (lhs.m_iMotionId != rhs.m_iMotionId) return false;
	if (lhs.m_iDuration != rhs.m_iDuration) return false;
	if (lhs.m_vecMovement != rhs.m_vecMovement) return false;

	//
	return true;

} // Operator==
//

//_______________________________________________________________________________________________________________
// Operator !=
inline bool operator!=(const taMotion& lhs, const taMotion& rhs)
{
	//
	if (lhs == rhs)
		return false;
	//
	return true;

} // Operator!=
//

//_______________________________________________________________________________________________________________
//
