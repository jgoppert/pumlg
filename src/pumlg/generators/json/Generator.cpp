//
// Created by jgoppert on 4/2/18.
//

#include "Generator.h"
#include <iostream>

namespace pumlg {
namespace generators {
namespace json {

void Generator::enterRoot(ast::Root &root) {
  _json["root"] = {};
}
void Generator::exitRoot(ast::Root &root) {
}
void Generator::enterClassDefinition(ast::ClassDefinition &definition) {
  _json["root"][definition.name] = {
      {"name", definition.name},
      {"attributes", {}},
      {"methods", {}}
  };
  _classScope.emplace_back(definition.name);
}
void Generator::exitClassDefinition(ast::ClassDefinition &definition) {
  _classScope.pop_back();
}
void Generator::enterAttribute(ast::Attribute &attribute) {
  _json["root"][_classScope.back()]["attributes"] = {
      {"name", attribute.name},
      {"type", attribute.type}
  };
}
void Generator::exitAttribute(ast::Attribute &attribute) {
}
void Generator::enterMethod(ast::Method &method) {
}
void Generator::exitMethod(ast::Method &method) {
}
} // json
} // generators
} // pumlg
