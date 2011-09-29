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
        { return direct_declarator + "(" + parameter_type_list + ", " + return_type + "* __this_result)"; }
        
    string to_string(string const& return_type, string const& error_type) 
        { return direct_declarator + "(" + parameter_type_list + ", " + return_type + "* __this_result, " + error_type + "*)"; }
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
        { return direct_function_declarator->to_string(return_type + string(pointer->num_pointers, '*')); }
        
    string to_string(string const& return_type, string const& error_type) 
        { return direct_function_declarator->to_string(return_type + string(pointer->num_pointers, '*'), error_type); }
};

struct CallExpression {
    CallExpression(string const& postfix_expression, 
                   string const& argument_expression_list, 
                   string const& or_on_error_expression = "",
                   string const& jump_statement = "")
    : postfix_expression(postfix_expression)
    , argument_expression_list(argument_expression_list)
    , or_on_error_expression(or_on_error_expression)
    , jump_statement(jump_statement) {}
    
    string postfix_expression;
    string argument_expression_list;
    string or_on_error_expression;
    string jump_statement;
};

