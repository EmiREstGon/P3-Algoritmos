// AUTOR: Emilio Rafael Estévez González
// FECHA: 21/3/21
// EMAIL: alu0101389240@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {
 public: // De aquí en adelante los miembros son públicos a, no ser que se exprese lo contrario
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&,
		  const double = EPS);                  // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);
  
  ~sparse_vector_t(); // destructor
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // Entrada / Salida (E/S)
  void write(std::ostream& = std::cout) const;

 private: // De aquí en adelante los miembros son privados, a no ser que se exprese lo contrario
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  // poner el código aquí
}

// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

sparse_vector_t::~sparse_vector_t() {} // llamada del destructor "~sparse_vector_t()" que pertenece a la clase "sparse_vector_t"

inline int sparse_vector_t::get_nz() const { // llamada de "get_nz" como constante, y que pertenece a la clase "sparse_vector_t"
  return nz_;
}

inline int sparse_vector_t::get_n() const { // llamada de "get_n" como constante, y que pertenece a la clase "sparse_vector_t"
  return n_;
}

pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

// Entrada / Salida (E/S)
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) { // salida de texto en consola (http://www.cplusplus.com/reference/ostream/ostream/)
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_