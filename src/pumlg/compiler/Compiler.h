//
// Created by jgoppert on 4/2/18.
//

#ifndef PUMLG_COMPILER_H
#define PUMLG_COMPILER_H

#include <typeindex>
#include <memory>

#include <pumlg/parser/PumlgBaseListener.h>
#include <pumlg/parser/PumlgLexer.h>
#include "Ast.h"

using namespace pumlg_antlr;

namespace pumlg {

class Compiler : public PumlgBaseListener {

 protected:
  antlr4::ANTLRInputStream _input;
  std::shared_ptr<PumlgParser> _parser;
  PumlgLexer _lexer;
  antlr4::CommonTokenStream _tokenStream;
  ast::Root _root;
  std::deque<ast::ClassDefinition *> _scopeClass;
 public:
  explicit Compiler(std::ifstream &text);
  PumlgParser &getParser() { return *_parser; }
  antlr4::CommonTokenStream &getTokenStream() { return _tokenStream; }
  ast::Root &getAst() { return _root; }
  void enterUml(PumlgParser::UmlContext *ctx) override;
  void enterClass_declaration(PumlgParser::Class_declarationContext *ctx) override;
  void exitClass_declaration(PumlgParser::Class_declarationContext *ctx) override;
  void enterMethod(PumlgParser::MethodContext *ctx) override;
  void exitMethod(PumlgParser::MethodContext *ctx) override;
  void enterAttribute(PumlgParser::AttributeContext *ctx) override;
  void exitAttribute(PumlgParser::AttributeContext *ctx) override;
};

} // pumlg_cli

#endif //PUMLG_COMPILER_H
