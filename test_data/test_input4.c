char f0(int a, int b);

char f0(int a, int b) {
}

char *f1(int a, int b);

char *f1(int a, int b) {
}

typedef struct _StdError {
     int var;
} StdError;

char f2() {}

inline char f3(int p1, char p2) can_fail;
inline static char const* const f3static(int p1, char p2) can_fail;

char f3(int p1, char p2) can_fail
{
}

char f4(int p1, char p2) fails_with StdError;

char f4(int p1, char p2) fails_with StdError
{
    char c;
    c = f3(1,2);
    
    char d;
    d = f3(3,4);
    
    char e;
    e = f3(3, f3(1, 2));
    
    char f;
    char g;
    f = f3(3, g = f3(1, 2));
    
    char t = f0(3,4);
/*    d = f3(5, 6) or_on_error {
        int error = 1;
    }*/
}

