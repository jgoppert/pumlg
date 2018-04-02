grammar Pumlg;

uml:
    '@startuml'
    (NEWLINE | class_diagram)
    '@enduml'
    ;

class_diagram
    : (class_declaration | connection | enum_declaration | hide_declaration | NEWLINE)*
    ;

class_declaration:
    class_type ident ('{'
    (attribute | method | NEWLINE)*
    '}' )?
    ;

hide_declaration:
    'hide' ident;

attribute:
    visibility?
    modifiers?
    type_declaration?
    ident
    NEWLINE
    ;

method:
    visibility?
    modifiers?
    type_declaration?
    ident
    '(' function_argument_list? ')'
    NEWLINE
    ;

connection_left:
    instance=ident ('"' attrib=ident mult=multiplicity? '"')?
    ;

connection_right:
    ('"' attrib=ident mult=multiplicity? '"')? instance=ident
    ;

connection:
    left=connection_left
    CONNECTOR
    right=connection_right
    (':' stereotype)?
    NEWLINE
    ;

multiplicity: ('*' | '0..1' '0..*' | '1..*' | '1');

visibility:
    '+'     # visibility_public
    |'-'    # visibility_private
    |'#'    # visibility_protected
    ;

function_argument:
    type_declaration? ident
    ;

function_argument_list:
    function_argument (',' function_argument)*
    ;


template_argument:
    type_declaration
    ;

template_argument_list:
    template_argument (',' template_argument)*
    ;

ident:
    IDENT
    ;

modifiers:
    static_mod='{static}'
    | abstract_mod='{abstract}'
    ;

stereotype:
    '<<' name=ident('(' args+=ident ')')? '>>'
    ;

type_declaration:
    ident '<' template_argument_list? '>'               # template_type
    | ident '[' ']'                                     # list_type
    | ident                                             # simple_type
    ;

class_type:
    'abstract' 'class'?
    | 'class'
    | 'interface' 'class'?
    ;

item_list:
    (ident NEWLINE)+
    ;

enum_declaration:
    'enum' ident ('{' NEWLINE
    item_list?
    '}' )?
    ;

CONNECTOR:
    '--'
    | '..'
    | '-->'
    | '<--'
    | '--*'
    | '*--'
    | '--o'
    | 'o--'
    | '<|--'
    | '--|>'
    | '..|>'
    | '<|..'
    | '*-->'
    | '<--*'
    | 'o-->'
    | '<--o'
    | '-'
    | '.'
    | '->'
    | '<-'
    | '-*'
    | '*-'
    | '-o'
    | 'o-'
    | '<|-'
    | '-|>'
    | '.|>'
    | '<|.'
    | '*->'
    | '<-*'
    | 'o->'
    | '<-o'
    ;

NEWPAGE : 'newpage' -> channel(HIDDEN)
    ;

NEWLINE  :   [\r\n];

IDENT : NONDIGIT ( DIGIT | NONDIGIT )*;
COMMENT :
    ('/' '/' .*? '\n' | '/*' .*? '*/') -> channel(HIDDEN)
    ;
WS  :   [ ]+ -> skip ; // toss out whitespace

//=========================================================
// Fragments
//=========================================================
fragment NONDIGIT : [_a-zA-Z];
fragment DIGIT :  [0-9];
fragment UNSIGNED_INTEGER : DIGIT+;
