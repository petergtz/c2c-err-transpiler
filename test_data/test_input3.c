typedef enum _StdError {
     A, B
} StdError;

char f3(int p1, char p2) can_fail;

char f4(int p1, char p2) fails_with StdError
{
    char c;
    c = f3(1,2) or_on_error 3;

    char d;
    d = f3(1,2) or_on_error return 1;

    char e;
    e = f3(1,2) or_on_error fail_with A;

    return 2;
}

