// AUTOR: Emilio Rafael Estévez González
// FECHA: 21/3/21
// EMAIL: alu0101389240@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {

 public: // De aquí en adelante los miembros son públicos a, no ser que se exprese lo contrario
  // constructores
  pair_t(void); 
  pair_t(T, int);
  
  ~pair_t(void); // destructor

  // getters & setters
  T get_val(void) const;    // getter del valor, de nombre: "get_val"
  int get_inx(void) const;  // getter del índice, de nombre: "get_inx"
  void set(T, int);

  // Entrada / Salida (E/S)
  std::istream& read(std::istream& is = std::cin);          // lectura de consola => entrada
  std::ostream& write(std::ostream& os = std::cout) const;  // escritura en consola => salida

 private: // De aquí en adelante los miembros son privados, a no ser que se exprese lo contrario
  T val_;   // declaración variable "val_" (valor) como tipo T
  int inx_; // declaración variable "inx_" (índice) como tipo int
};

// operaciones
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

template<class T> pair_t<T>::~pair_t() {} // llamada del destructor "~pair_t()" que pertenece a la clase "pair_t<T>"

template<class T> void pair_t<T>::set(T val, int inx) { // llamada de la función "set" que pertenece a la clase "pair_t<T>"
  val_ = val;
  inx_ = inx;
}

template<class T> int pair_t<T>::get_inx() const { // llamada de "get_inx" como constante, y que pertenece a la clase "pair_t<T>"
  return inx_;
}

template<class T> T pair_t<T>::get_val() const { // llamada de "get_val" como constante, y que pertenece a la clase "pair_t<T>"
  return val_;
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) { // lectura de consola => entrada
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const { // escritura en consola => salida
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) { // escritura en consola => salida
  p.write(os);
  return os;
}

#endif  // PAIRT_H_