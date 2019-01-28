#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <set>
#include <string>
#include <vector>
using namespace std;

//
// ────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: C L A S E   D I C C I O N A R I O : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────
//

class Diccionario {
private:

	set <string> datos;

public:

//
// ─── CONSTRUCTORES ──────────────────────────────────────────────────────────────
//

	/**
	 * @brief Construye un diccionario vacío
	 */
	Diccionario () = default;

	/**
	 * @brief Constructor de copia
	 */
	Diccionario ( const Diccionario& diccionario );

	/**
	 * @brief Destructor de la clase
	 */
	~Diccionario () = default;

//
// ─── CONSULTA ───────────────────────────────────────────────────────────────────
//

	/**
	 * @brief Consulta el tamaño
	 * @return Cantidad de palabras almacenadas
	 */
	size_t size () const;

	/**
	 * @brief Mira si existe dicha palabra
	 * @return true si está, false si no
	 */
	bool word_exists ( const string & palabra ) const;

	/**
	 * @brief Consulta cuántas palabras tienen dicha longitud
	 * @return Vector con dicha cantidad de palabras
	 */
	vector< string > length ( const size_t longitud ) const;

//
// ─── MODIFICACION ───────────────────────────────────────────────────────────────
//

	/**
	 * @brief Añade una nueva palabra al diccionario
	 * @param nueva_palabra Palabra a añadir
	 */
	void add ( const string& nueva_palabra );

//
// ─── SOBRECARGA DE OPERADORES ───────────────────────────────────────────────────
//

	Diccionario& operator= ( const Diccionario& diccionario );
	friend istream&  operator>> ( istream& is, const Diccionario& diccionario );
	friend ostream&  operator<< ( ostream& os, 	     Diccionario& diccionario );
	friend ifstream& operator>> ( ifstream& in,      Diccionario& diccionario );

//
// ─── ITERADORES ─────────────────────────────────────────────────────────────────
//

	typedef typename set< string >::iterator 	   iter;
	typedef typename set< string >::const_iterator const_iter;

	iter begin ()				{  return datos.begin();  };
	iter end ()					{  return datos.end();    };
	const_iter begin ()	const	{  return datos.begin();  };
	const_iter end () const		{  return datos.end();    };
};

#include "../src/diccionario.cpp"
#endif