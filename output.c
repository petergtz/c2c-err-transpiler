int ffp()(, int**);

char f0(int a, int b);

char f0(int a, int b){}
char *f1(int a, int b);

char *f1(int a, int b){}
struct StdError{
int var;
 };

char f2(){}
inline int f3(int p1, char p2, char*);

inline static int f3(int p1, char p2, char **);

int f3(int p1, char p2, char*){}
int f4(int p1, char p2, char*, StdError*){
char c;
char __tmp_result_var_0;
int __tmp_rc_var_0 = f3(1, 2, &__tmp_result_var_0);
if (__tmp_rc_var_0 != 0) {
} else {
c=__tmp_result_var_0;
}
char d;
char __tmp_result_var_1;
int __tmp_rc_var_1 = f3(3, 4, &__tmp_result_var_1);
if (__tmp_rc_var_1 != 0) {
} else {
d=__tmp_result_var_1;
}
char e;
char __tmp_result_var_2;
int __tmp_rc_var_2 = f3(1, 2, &__tmp_result_var_2);
if (__tmp_rc_var_2 != 0) {
} else {
char __tmp_result_var_3;
int __tmp_rc_var_3 = f3(3, __tmp_result_var_2, &__tmp_result_var_3);
if (__tmp_rc_var_3 != 0) {
} else {
e=__tmp_result_var_3;
}
}
char t = f0(3, 4);
}
