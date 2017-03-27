/*******************************************************************************************************************************
	Nutzen:
	Definition der inline template Funktionalitaeten der Vektorklasse

	Autor:
	Alexander Bassov
*******************************************************************************************************************************/
//

// header
/* ... */

//_______________________________________________________________________________________________________________
// Konstruktor ohne Parameter
template <class T>
inline stVector2D<T>::stVector2D() :	x (T()),
										y (T())
{
	/* ... */

} // Konstruktor ()
//

//_______________________________________________________________________________________________________________
// Konstruktor mit Einem Wert
template <class T>
inline stVector2D<T>::stVector2D(T xy) :	x (xy),
											y (xy)
{
	/* ... */

} // Konstruktor (xy)
//

//_______________________________________________________________________________________________________________
// Konstruktor mit vollstaendiger Definition
template <class T>
inline stVector2D<T>::stVector2D(T x, T y) :	x (x),
												y (y)
{
	/* ... */

} // Konstruktor (x, y)
//

//_______________________________________________________________________________________________________________
//

//
//

//
//

//
//

//
//

//_______________________________________________________________________________________________________________
// = Operator (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator= (const stVector2D<T>& rhs)
{
	return stVector2D<T> (this->x = rhs.x,	this->y = rhs.y);

} // Operator = (Vektor)
//

//_______________________________________________________________________________________________________________
// = Operator (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator= (const T& rhs)
{
	return stVector2D<T> (this->x = rhs, this->y = rhs);

} // Operator = (Einzelwert)
//

//_______________________________________________________________________________________________________________
// Operator += (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator += (const stVector2D<T>& rhs)
{
	return stVector2D<T> (this->x += rhs.x,	this->y += rhs.y);

} // Operator += (Vektor)
//

//_______________________________________________________________________________________________________________
// Operator += (Einzelwert)
template <class T>
inline stVector2D<T> stVector2D<T>::operator += (const T& rhs)
{
	return stVector2D<T> (this->x += rhs, this->y += rhs);

} // Operator += (Einzelwert)
//

//_______________________________________________________________________________________________________________
// Operator -= (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator -= (const stVector2D<T>& rhs)
{
	return stVector2D<T> (this->x -= rhs.x,	this->y -= rhs.y);

} // Operator -= (Vektor)
//

//_______________________________________________________________________________________________________________
// Operator -= (Einzelwert)
template <class T>
inline stVector2D<T> stVector2D<T>::operator -= (const T& rhs)
{
	return stVector2D<T> (this->x -= rhs, this->y -= rhs);

} // Operator -= (Einzelwert)
//

//_______________________________________________________________________________________________________________
// Operator *= (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator *= (const stVector2D<T>& rhs)
{
	return stVector2D<T> (this->x *= rhs.x, this->y *= rhs.y);

} // Operator *= (Vektor)
//

//_______________________________________________________________________________________________________________
// Operator *= (Einzelwert)
template <class T>
inline stVector2D<T> stVector2D<T>::operator *= (const T& rhs)
{
	return stVector2D<T> (this->x *= rhs, this->y = rhs);

} // Operator *= (Einzelwert)
//

//_______________________________________________________________________________________________________________
// Operator /= (Vektor)
template <class T>
inline stVector2D<T> stVector2D<T>::operator /= (const stVector2D<T>& rhs)
{
	return stVector2D<T> (this->x /= rhs.x, this->y /= rhs.y);

} // Operator /= (Vektor)
//

//_______________________________________________________________________________________________________________
// Operator /= (Einzelwert)
template <class T>
inline stVector2D<T> stVector2D<T>::operator /= (const T& rhs)
{
	return stVector2D<T> (this->x /= rhs, this->y /= rhs);

} // Operator /= (Einzelwert)
//

//_______________________________________________________________________________________________________________
// Operator ++
template <class T>
inline stVector2D<T> stVector2D<T>::operator++ ()
{
	return stVector2D<T> (this->x + 1, this->y + 1);

} // Operator ++
//

//_______________________________________________________________________________________________________________
// Operator --
template <class T>
inline stVector2D<T> stVector2D<T>::operator-- ()
{
	return stVector2D<T> (this->x - 1, this->y - 1);

} // Operator --
//

//_______________________________________________________________________________________________________________
//

//
//

//
//

//
//

//
//

//_______________________________________________________________________________________________________________
// + Operator (Vektor | Vektor)
template <class T>
inline stVector2D<T> operator + (const stVector2D<T>& lhs, const stVector2D<T>& rhs)
{
	//
	return stVector2D<T> (lhs.x + rhs.x, lhs.y + rhs.y);

} //
//

//_______________________________________________________________________________________________________________
// + Operator (Vektor | Einzelwert)
template <class T>
inline stVector2D<T> operator + (const stVector2D<T>& lhs, const T& rhs)
{
	//
	return stVector2D<T> (lhs.x + rhs, lhs.y + rhs);

} //
//

//_______________________________________________________________________________________________________________
// - Operator (Vektor | Vektor)
template <class T>
inline stVector2D<T> operator - (const stVector2D<T>& lhs, const stVector2D<T>& rhs)
{
	//
	return stVector2D<T> (lhs.x - rhs.x, lhs.y - rhs.y);

} //
//

//_______________________________________________________________________________________________________________
// - Operator (Vektor | Einzelwert)
template <class T>
inline stVector2D<T> operator - (const stVector2D<T>& lhs, const T& rhs)
{
	//
	return stVector2D<T> (lhs.x + rhs, lhs.y + rhs);

} // - Operator
//

//_______________________________________________________________________________________________________________
// * Operator (Vektor | Vektor)
template <class T>
inline stVector2D<T> operator * (const stVector2D<T>& lhs, const stVector2D<T>& rhs)
{
	//
	return stVector2D<T> (lhs.x * rhs.x, lhs.y * rhs.y);

} // Operator *
//

//_______________________________________________________________________________________________________________
// * Operator (Vektor | Einzelwert)
template <class T>
inline stVector2D<T> operator * (const stVector2D<T>& lhs, const T& rhs)
{
	//
	return stVector2D<T> (lhs.x * rhs, lhs.y * rhs);

} // Operator *
//

//_______________________________________________________________________________________________________________
// / Operator (Vektor | Vektor)
template <class T>
inline stVector2D<T> operator / (const stVector2D<T>& lhs, const stVector2D<T>& rhs)
{
	//
	return stVector2D<T> (lhs.x / rhs.x, lhs.y / rhs.y);

} // Operator /
//


//_______________________________________________________________________________________________________________
// / Operator (Vektor | Einzelwert)
template <class T>
inline stVector2D<T> operator / (const stVector2D<T>& lhs, const T& rhs)
{
	return stVector2D<T> (lhs.x / rhs, lhs.y / rhs); 

} // Operator /
//

//_______________________________________________________________________________________________________________
// == Operator (Vektor | Vektor)
template <class T>
inline bool operator ==	(const stVector2D<T>& lhs, const stVector2D<T> rhs)
{
	if ((lhs.x == rhs.x) && (lhs.y == rhs.y))
		return true;
	else
		return false;

} // Operator ==
//

//_______________________________________________________________________________________________________________
// == Operator (Vektor | Einzelwert)
template <class T>
inline bool operator ==	(const stVector2D<T>& lhs, const T rhs)
{
	if ((lhs.x == rhs) && (lhs.y == rhs))
		return true;
	else
		return false;
} // Operator ==
//

//_______________________________________________________________________________________________________________
// != Operator (Vektor | Vektor)
template <class T>
inline bool	operator != (const stVector2D<T>& lhs, const stVector2D<T> rhs)
{
	if ((lhs.x != rhs.x) && (lhs.y != rhs.y))
		return true;
	else
		return false;

} // Operator !=
//

//_______________________________________________________________________________________________________________
// != Operator (Vektor | Einzelwert)
template <class T>
inline bool	operator != (const stVector2D<T>& lhs, const T rhs)
{
	//
	if ((lhs.x != rhs) && (lhs.y != rhs))
		return true;
	else
		return false;

} // Operator !=
//

//_______________________________________________________________________________________________________________