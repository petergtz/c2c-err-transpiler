and_propagate_errors;

int func(int a, int b) { ... }
void another_func(int x) { ... }

void operation() {
    int result;
    result = func(1, 2);
    another_func(3);
}



struct func_error { ... }
int func(int a, int b) fails_with func_error { ... }
void another_func(int x) can_fail { ... }

enum high_level_error { ERR_TYPE_1, ERR_TYPE_2 };

void operation() fails_with high_level_error {
    int result;
    
    result = func(1, 2)
        or_on_error(e) fail_with ERR_TYPE_1;
    another_func(3)
        or_on_error fail_with ERR_TYPE_2;
}



int func(int a, int b, int* this_result, func_error *e) { ... }
int another_func(int x, int* this_result) { ... }

int operation(high_level_error *this_error) {
    int rc1;
    func_error *error1;
    int rc2;
    
    int result;
    
    rc1 = func(1, 2, &result, &error1);
    if (rc < 0) {
        *this_error = ERR_TYPE_1;
        return -1;
    }
    rc2 = another_func(3);
    if (rc < 0) {
        *this_error = ERR_TYPE_2;
        return -1;
    }
    return 0;
}

