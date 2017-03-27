/*******************************************************************************************************************************
	Nutzen/Aufgabe:
	Erzeugt ein 2 dimensionalen Vector vom Typ T

	Diese Klasse beinhaltet arithmetische/logische und Vergleichs operatoren. 

	Note:
	Vergleichsoperatoren sind standardmaessig auskommentiert
	Bei Bedarf entkommentieren. 

	Autor:
	Alexander Bassov
*******************************************************************************************************************************/

//
#pragma once
//

//_______________________________________________________________________________________________________________
// header
/* ... */

//_______________________________________________________________________________________________________________
// Makros/Defines
/* ... */

//_______________________________________________________________________________________________________________
// globale Variablen/Externe Deklarationen
/* ... */

//_______________________________________________________________________________________________________________
// Vorwaertsdeklarationen
/* ... */

//_______________________________________________________________________________________________________________
// Strukturen/enums/etc.
/* ... */





//_______________________________________________________________________________________________________________
// Klasse
template <class T>
class stVector2D
{

	//===============================================================================================================
	public:
		
		//===========================================================================================================
		// Basisvariablen	
		union 
		{
			struct
			{
				T	x;
				T	y;
			};

			T c[2];
		};
	

		//===========================================================================================================
		// Initialmethoden - Konstruktor/Kopierkonstruktor/Destruktor - Initfunktion
		//

		// Konstruktor
		stVector2D();

		// Konstruktor
		stVector2D(T xy);

		// Konstruktor
		stVector2D(T x, T y);

		// Kopierkonstruktor
		/* ... */

		// template Konstuktor
		template <class U>
		explicit stVector2D(stVector2D<U>& rhs)
		{
			//
			x = (T) rhs.x;
			y = (T) rhs.y;
		}

		// Destruktor
		~stVector2D() {};

		// Cast-Operator
		/* ... */
		
		//
		//===========================================================================================================
		// Arithmetische Operatoren Part I
		//
		inline stVector2D operator =  (const stVector2D<T>& rhs);			// Zuweisung mit Vektor
		inline stVector2D operator =  (const T& rhs);						// Zuweisung mit Einzelwert
		inline stVector2D operator += (const stVector2D<T>& rhs);			// Zuweisungsaddition mit Vektor
		inline stVector2D operator += (const T& rhs);						// Zuweisungsaddition mit Einzelwert
		inline stVector2D operator -= (const stVector2D<T>& rhs);			// Zuweisungssubtraktion mit Vektor
		inline stVector2D operator -= (const T& rhs);						// Zuweisungssubtraktion mit Einzelwert
		inline stVector2D operator *= (const stVector2D<T>& rhs);			// Zuweisungsmultiplikation mit Vektor
		inline stVector2D operator *= (const T& rhs);						// Zuweisungsmultiplikation mit Einzelwert
		inline stVector2D operator /= (const stVector2D<T>& rhs);			// Zuweisungsdivision mit Vektor
		inline stVector2D operator /= (const T& rhs);						// Zuweisungsdivision mit Einzelwert

		inline stVector2D operator++ ();									// Inkrementieren
		inline stVector2D operator-- ();									// Dekerementieren

		// Nicht anwenden wenn das wissen besteht das (x > rhs.x und y < rhs.y) - Es wird kein brauchbares Ergebnis geliefert
		//
		//	inline bool operator <  (const stVector2Df& rhs)							{ if ( (this->x < rhs.x)	and (this->y < rhs.y) )		return true; else return false; };
		//	inline bool operator <  (const float& v)									{ if ( (this->x < v)		and (this->y < v) )			return true; else return false; };
		//	inline bool operator >  (const stVector2Df& rhs)							{ if ( (this->x > rhs.x)	and (this->y > rhs.y) )		return true; else return false; };
		//	inline bool operator >  (const float& v)									{ if ( (this->x > v)		and (this->y > v) )			return true; else return false; };

}; //
//

//_________________________________________________________________________________________________________________________________________________________________________________________________
		// Streamoperatoren
		//
		template <class T>
		std::ostream& operator << (std::ostream& out, stVector2D<T> vec)
		{
			out << "(X: " << vec.x << " | Y: " << vec.y << ")";
			return out;
		}

//_________________________________________________________________________________________________________________________________________________________________________________________________
		// Arithmetische Operatoren Part II
		template <class T>
		inline stVector2D<T> operator + (const stVector2D<T>& lhs, const stVector2D<T>& rhs);			// Addition mit Vektor
		
		template <class T>
		inline stVector2D<T> operator + (const stVector2D<T>& lhs, const T& rhs);						// Addition mit Einzelwert

		template <class T>
		inline stVector2D<T> operator - (const stVector2D<T>& lhs, const stVector2D<T>& rhs);			// Subtraktion mit Vektor

		template <class T>
		inline stVector2D<T> operator - (const stVector2D<T>& lhs, const T& rhs);						// Subtraktion mit Einzelwert

		template <class T>
		inline stVector2D<T> operator * (const stVector2D<T>& lhs, const stVector2D<T>& rhs);			// Multiplikation mit Vektor

		template <class T>
		inline stVector2D<T> operator * (const stVector2D<T>& lhs, const T& rhs);						// Multiplikation mit Einzelwert

		template <class T>
		inline stVector2D<T> operator / (const stVector2D<T>& lhs, const stVector2D<T>& rhs);			// Division mit Vektor

		template <class T>
		inline stVector2D<T> operator / (const stVector2D<T>& lhs, const T& rhs);						// Division mit Einzelwert

//_________________________________________________________________________________________________________________________________________________________________________________________________
		// Logische Operatoren
		template <class T>
		inline bool operator ==	(const stVector2D<T>& lhs, const stVector2D<T> rhs);					// Gleichheitsprüfung Vektor

		template <class T>
		inline bool operator ==	(const stVector2D<T>& lhs, const T rhs);								// Gleichheitsprüfung Einzelwert

		template <class T>
		inline bool	operator != (const stVector2D<T>& lhs, const stVector2D<T> rhs);					// Ungleichheitspruüfung Vektor

		template <class T>
		inline bool	operator != (const stVector2D<T>& lhs, const T rhs);								// Ungleichheitspruüfung Einzelwert

//
//_________________________________________________________________________________________________________________________________________________________________________________________________
		// Vektoren mit anderen Datentypen
		#include <Core/Defaults/Vector2D.inl>
		
		//
		using stVector2Di = stVector2D<int>;		// int
		using stVector2Ds = stVector2D<short>;		// short
		using stVector2Df = stVector2D<float>;		// float
		using stVector2Dd = stVector2D<double>;		// double
		using stVector2Dl = stVector2D<long>;		// long

		using stVector2Db = stVector2D<bool>;		// bool | Operatoren sind alle vorhanden - machen aber weitgehend keinen Sinn bei einem boolschen Wert
//
//_________________________________________________________________________________________________________________________________________________________________________________________________
