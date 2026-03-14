#include "Serializer.hpp"

// public ----------------------------------------------------------------------

uintptr_t Serializer::serialize(Data *ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data *>(raw));
}

// private ---------------------------------------------------------------------

Serializer::Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs) {
  (void)rhs;
  return *this;
}

Serializer::Serializer(Serializer const &src) { (void)src; }

Serializer::~Serializer() {}
