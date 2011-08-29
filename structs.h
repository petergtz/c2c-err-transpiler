#include <string>

using namespace std;

struct FailSpecifier {
    FailSpecifier() : error_struct(0) {}
    FailSpecifier(char* error_struct) : error_struct(error_struct) {}
    
    char* error_struct;
};

struct DeclarationSpecifiers {
    string full;
    string storage_class;
    string type;
    string qualifier;
};

struct DirectFunctionDeclarator {
    string direct_declarator;
    string parameter_type_list;

    explicit DirectFunctionDeclarator(string const& direct_declarator, string const& parameter_type_list = "")
    : direct_declarator(direct_declarator)
    , parameter_type_list(parameter_type_list) {}

    string to_string() 
        { return direct_declarator + "(" + parameter_type_list + ")"; }
    string to_string(string const& return_type) 
        { return direct_declarator + "(" + parameter_type_list + ", " + return_type + "*)"; }
    string to_string(string const& return_type, string const& error_type) 
        { return direct_declarator + "(" + parameter_type_list + ", " + return_type + "*, " + error_type + "*)"; }
};

struct Pointer {
    string full;
    int num_pointers;
};

struct FunctionDeclarator {
    DirectFunctionDeclarator* direct_function_declarator;
    Pointer* pointer;

    FunctionDeclarator(DirectFunctionDeclarator* direct_function_declarator, Pointer* pointer)
    : direct_function_declarator(direct_function_declarator)
    , pointer(pointer) {}

    string to_string() 
        { return direct_function_declarator->to_string(); }
    string to_string(string const& return_type)  
        { return direct_function_declarator->to_string(return_type+string(pointer->num_pointers, '*')); }
    string to_string(string const& return_type, string const& error_type) 
        { return direct_function_declarator->to_string(return_type+string(pointer->num_pointers, '*'), error_type); }
};

struct CallExpression {
    CallExpression(string const& postfix_expression, string const& argument_expression_list)
    : postfix_expression(postfix_expression)
    , argument_expression_list(argument_expression_list) {}
    
    string postfix_expression;
    string argument_expression_list;
};

