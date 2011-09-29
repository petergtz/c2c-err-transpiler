
enum Error {
    A, B
}

int calc(int i) can_fail;

int operation() fail_with Error
{
    int x = calc(3) or_on_error -1;

    int x = calc(3) or_on_error return -1;

    int x = calc(3) or_on_error fail_with A;
    
    int x = calc(another_calc("jkhkj") or_on_error 2) or_on_error -1;
    
    command() or_on_error {
        do_something();
    }

    command() or_on_error {
        do_something();
    }


}


Error* operation(int* result )
{
    int x;
    int rc = calc(3, &x);
    if (rc != 0) x = -1;
    
    
    int x;
    int rc = calc(3, &x);
    if (rc != 0) {
        *result = -1;
        return NULL;
    }

    int x;
    int rc = calc(3, &x);
    if (rc != 0) {
        Error* error = malloc(sizeof(Error));
        *error = A;
        return error;
    }
    
    int x;
    int tmp0;
    int rc0 = another_calc("jkhkj", &tmp0)
    if (rc != 0) tmp0 = 2;
    int rc = calc(tmp0, &x);
    if (rc != 0) x = -1;
}


