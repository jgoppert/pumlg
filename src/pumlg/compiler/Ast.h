//
// Created by jgoppert on 4/2/18.
//

#ifndef PUMLG_AST_H
#define PUMLG_AST_H

#include <string>
#include <unordered_map>
#include <list>
#include <iostream>

namespace pumlg {
namespace ast {

// forward declarations
class Listener;

class Node {
 public:
  Node() = default;
  //Node(const Node &) = delete; // disallow copy
  virtual void walk(Listener &listener) = 0;
};

class Attribute : public Node {
 public:
  Attribute() = default;
  std::string name;
  std::string type;
  void walk(Listener &listener) override;
};

class Method : public Node {
 public:
  Method() = default;
  std::string name;
  void walk(Listener &listener) override;
};

class ClassDefinition : public Node {
 public:
  ClassDefinition(): name(), methods(), attributes() {
  };
  virtual ~ClassDefinition() = default;
  std::string name;
  std::list<Method> methods;
  std::list<Attribute> attributes;
  void walk(Listener &listener) override;
};

class Root : public Node {
 public:
  Root() = default;
  std::unordered_map<std::string, ClassDefinition > classes;
  void walk(Listener &listener) override;
};

class Listener {
 public:
  virtual void enterRoot(Root &) {};
  virtual void exitRoot(Root &) {};
  virtual void enterClassDefinition(ClassDefinition &) {};
  virtual void exitClassDefinition(ClassDefinition &) {};
  virtual void enterAttribute(Attribute &) {};
  virtual void exitAttribute(Attribute &) {};
  virtual void enterMethod(Method &) {};
  virtual void exitMethod(Method &) {};
};

} // namespace ast
} // namespace pumlg

#endif //PUMLG_AST_H
