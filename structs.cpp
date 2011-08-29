enum FailureType { 
    FAILURE_TYPE_NON_FAILING, 
    FAILURE_TYPE_CAN_FAIL, 
    FAILURE_TYPE_FAILS_WITH
};

typedef struct FunctionDecl_t {
    FailureType failure_type;
    string type;
    string name;
    string parameter_list;
} FunctionDecl;

typedef struct Decl_t {
    bool is_function_decl;
    union {
        char* other_decl;
        FunctionDecl* function_decl;
    } value;
} Decl;

