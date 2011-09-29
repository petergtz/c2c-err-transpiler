typedef enum _StdError {
     A, B
} StdError;

int f3(int p1, char p2, char* __this_result);

StdError* f4(int p1, char p2, char* __this_result)
{
    char c;
    char __tmp_result_var_0;
    int __tmp_rc_var_0 = f3(1, 2, &__tmp_result_var_0);
    if (__tmp_rc_var_0 != 0) {
        __tmp_result_var_0 = 3;
    }
    c = __tmp_result_var_0;

    char d;
    char __tmp_result_var_1;
    int __tmp_rc_var_1 = f3(1, 2, &__tmp_result_var_1);
    if (__tmp_rc_var_1 != 0) {
        *__this_result = 1;
        return 0;
    }
    d = __tmp_result_var_1;

    char e;
    char __tmp_result_var_2;
    int __tmp_rc_var_2 = f3(1, 2, &__tmp_result_var_2);
    if (__tmp_rc_var_2 != 0) {
        StdError* __this_error = malloc(sizeof(StdError));
        *__this_error = A;
        return __this_error;
    }
    e = __tmp_result_var_2;

    return 2;
}

