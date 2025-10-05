
typedef enum ReturnCode {
    WRONG_TYPE,
    OVERFLOW,
    WRONG_NUM,
    WRONG_BASE,
    NULL_POINTER,
    OK
} ReturnCode;


ReturnCode toNsistem(char * str, const int base, long int num);
ReturnCode toDecInt(const char * str, const int base, long int * num);
ReturnCode parseBase(char * str, int * base);
ReturnCode parseNum(char * str, const int * base, int * underZero);