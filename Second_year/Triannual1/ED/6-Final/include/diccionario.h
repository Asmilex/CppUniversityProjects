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
	 * @brief: construye un diccionario vacío
	 */
	Diccionario () = default;

	/**
	 * @brief: constructor de copia
	 */
	Diccionario ( const Diccionario& diccionario );

	/**
	 * @brief: destructor de la clase
	 */
	~Diccionario () = default;

//
// ─── CONSULTA ───────────────────────────────────────────────────────────────────
//

	/**
	 * @brief: Consulta el tamaño
	 * @return: cantidad de palabras almacenadas
	 */	
	size_t size () const;

	/**
	 * @brief: Mira si existe dicha palabra
	 * @return: true si está, false si no
	 */
	bool word_exists ( const string & palabra ) const;

	/**
	 * @brief: consulta cuántas palabras tienen dicha longitud
	 * @return: vector con dicha cantidad de palabras
	 */
	vector< string > length ( const size_t longitud ) const;

//
// ─── MODIFICACION ───────────────────────────────────────────────────────────────
//

	/**
	 * @brief: añade una nueva palabra al diccionario
	 * @param nueva_palabra: palabra a añadir
	 */
	void add ( const string& nueva_palabra);

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

	typedef typename set< string >::iterator iter;
	typedef typename set< string >::const_iterator const_iter;

	iter begin ()				{  return datos.begin();  };
	iter end ()					{  return datos.end();    };
	const_iter begin ()	const	{  return datos.begin();  };
	const_iter end () const		{  return datos.end();    };
};

#include "../src/diccionario.cpp"
#endif