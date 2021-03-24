#define __replacement____put_user__(x,ptr)  ({ *(ptr) = (x); 0; })
#define __replacement____get_user__(x,ptr)  ({ (x) = *((typeof((x))*)(ptr)); 0; })
#define __replacement____BUG_ON__(condition)({ if (condition) { int* ptr = 0; *ptr = 0; } })
