//
// Created by jgoppert on 4/2/18.
//

#include "Ast.h"
#include <iostream>

namespace pumlg {
namespace ast {

void Root::walk(Listener &listener) {
  listener.enterRoot(*this);
  for (auto &c: this->classes) {
    c.second.walk(listener);
  }
  listener.exitRoot(*this);
}

void ClassDefinition::walk(Listener &listener) {
  listener.enterClassDefinition(*this);
  for (auto &m: this->methods) {
    m.walk(listener);
  }
  for (auto &a: this->attributes) {
    a.walk(listener);
  }
  listener.exitClassDefinition(*this);
}

void Method::walk(Listener &listener) {
  listener.enterMethod(*this);
  listener.exitMethod(*this);
}

void Attribute::walk(Listener &listener) {
  listener.enterAttribute(*this);
  listener.exitAttribute(*this);
}

} // namespace ast
} // namespace pumlg_cli
