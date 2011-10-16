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

struct Jump;

struct CallExpression {
    CallExpression(string const& postfix_expression, 
                   string const& argument_expression_list, 
                   string const& or_on_error_expression = "",
                   Jump* or_on_error_jump = 0)
    : postfix_expression(postfix_expression)
    , argument_expression_list(argument_expression_list)
    , or_on_error_expression(or_on_error_expression)
    , or_on_error_jump(or_on_error_jump) {}
    
    string postfix_expression;
    string argument_expression_list;
    string or_on_error_expression;
    Jump* or_on_error_jump;
};

struct Jump {
    virtual string eval() = 0;
    virtual ~Jump() {}
};

struct Return : public Jump {
    Return(string const& expression = "") : expression(expression) {}
    string expression;
    string eval() {
        return "*__this_result = " + expression + ";\nreturn 0";
    }
};

struct Goto : public Jump {
    string eval() {
        return "goto ";
    }
};
struct Continue : public Jump {
    string eval() {
        return "continue ";
    }
};
struct Break : public Jump {
    string eval() {
        return "break ";
    }
};

struct FailWith : public Jump {
    FailWith(string const& error, string const& error_type) : error(error), error_type(error_type) {}
    string eval() {
        return error_type + "* __this_error = malloc(sizeof(" + error_type + "));\n"
               "*__this_error = " + error + ";\n"
               "return __this_error";
    }
    string error;
    string error_type;
};


