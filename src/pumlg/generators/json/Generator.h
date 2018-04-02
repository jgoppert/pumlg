//
// Created by jgoppert on 4/2/18.
//

#ifndef PUMLG_GENERATOR_H
#define PUMLG_GENERATOR_H

# include <pumlg/compiler/Ast.h>
#include <nlohmann/json.hpp>

namespace pumlg {
namespace generators {
namespace json {

class Generator : public ast::Listener {
 protected:
  nlohmann::json _json;
  std::list<std::string> _classScope;
 public:
  nlohmann::json getJson() { return _json; }
  void enterRoot(ast::Root &root) override;
  void exitRoot(ast::Root &root) override;
  void enterClassDefinition(ast::ClassDefinition &definition) override;
  void exitClassDefinition(ast::ClassDefinition &definition) override;
  void enterAttribute(ast::Attribute &attribute) override;
  void exitAttribute(ast::Attribute &attribute) override;
  void enterMethod(ast::Method &method) override;
  void exitMethod(ast::Method &method) override;
};

} // json
} // generators
} // pumlg

#endif //PUMLG_GENERATOR_H
