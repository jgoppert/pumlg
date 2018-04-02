//
// Created by jgoppert on 4/2/18.
//

#include "Compiler.h"

namespace pumlg {

Compiler::Compiler(std::ifstream &text) :
    _parser(nullptr),
    _input(text),
    _lexer(&_input),
    _tokenStream(&_lexer),
    _root() {
  _tokenStream.fill();
  _parser = std::make_shared<PumlgParser>(&_tokenStream);
  antlr4::tree::ParseTree *tree = _parser->uml();
  antlr4::tree::ParseTreeWalker::DEFAULT.walk(this, tree);
}
void Compiler::enterUml(PumlgParser::UmlContext *ctx) {
  std::cout << "enter uml" << std::endl;
}
void Compiler::enterClass_declaration(PumlgParser::Class_declarationContext *ctx) {
  auto name = ctx->ident()->getText();
  _root.classes[name] = ast::ClassDefinition();
  auto & cdef = _root.classes[name];
  cdef.name = name;
  _scopeClass.emplace_back(&cdef);
}
void Compiler::exitClass_declaration(PumlgParser::Class_declarationContext *ctx) {
  _scopeClass.pop_back();
}
void Compiler::enterMethod(PumlgParser::MethodContext *ctx) {
  auto cdef = _scopeClass.back();
  std::string name = ctx->ident()->getText();
  cdef->methods.emplace_back(ast::Method());
  auto & m = cdef->methods.back();
}
void Compiler::exitMethod(PumlgParser::MethodContext *ctx) {
}
void Compiler::enterAttribute(PumlgParser::AttributeContext *ctx) {
  auto cdef = _scopeClass.back();
  auto name = ctx->ident()->getText();
  auto type = ctx->type_declaration()->getText();
  cdef->attributes.emplace_back(ast::Attribute());
  auto & a = cdef->attributes.back();
  a.name = name;
  a.type = type;
}
void Compiler::exitAttribute(PumlgParser::AttributeContext *ctx) {
}

} // pumlg_cli
