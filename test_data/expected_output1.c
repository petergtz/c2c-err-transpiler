char f0(int a, int b);

char f0(int a, int b) {}
char *f1(int a, int b);

char *f1(int a, int b) {}
typedef struct _StdError {
     int var;
} StdError;

char f2() {}
inline int f3(int p1, char p2, char* __this_result);

inline static int f3static(int p1, char p2, char ** __this_result);

int f3(int p1, char p2, char* __this_result) {}
StdError* f4(int p1, char p2, char* __this_result);

StdError* f4(int p1, char p2, char* __this_result)
{
     char c;
     char __tmp_result_var_0;
     int __tmp_rc_var_0 = f3(1, 2, &__tmp_result_var_0);
     if (__tmp_rc_var_0 != 0) {
         exit(1);
     }
     c = __tmp_result_var_0;
     char d;
     char __tmp_result_var_1;
     int __tmp_rc_var_1 = f3(3, 4, &__tmp_result_var_1);
     if (__tmp_rc_var_1 != 0) {
         exit(1);
     }
     d = __tmp_result_var_1;
     char e;
     char __tmp_result_var_2;
     int __tmp_rc_var_2 = f3(1, 2, &__tmp_result_var_2);
     if (__tmp_rc_var_2 != 0) {
         exit(1);
     }
     char __tmp_result_var_3;
     int __tmp_rc_var_3 = f3(3, __tmp_result_var_2, &__tmp_result_var_3);
     if (__tmp_rc_var_3 != 0) {
         exit(1);
     }
     e = __tmp_result_var_3;
     char f;
     char g;
     char __tmp_result_var_4;
     int __tmp_rc_var_4 = f3(1, 2, &__tmp_result_var_4);
     if (__tmp_rc_var_4 != 0) {
         exit(1);
     }
     char __tmp_result_var_5;
     int __tmp_rc_var_5 = f3(3, g = __tmp_result_var_4, &__tmp_result_var_5);
     if (__tmp_rc_var_5 != 0) {
         exit(1);
     }
     f = __tmp_result_var_5;
     char t = f0(3, 4);
}
