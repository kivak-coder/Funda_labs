#include "../include/liver.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

Liver * createLiver(size_t count, ...) {

    Liver * liver = (Liver *)malloc(sizeof(Liver));
    if (!liver) {
        return NULL;
    }

    va_list arg;
    va_start(arg, count);
    size_t j = 0;

    for (size_t i = 0; i < count; ++i) {
        void * num = va_arg(arg, void *); // ура воид!
    }
    return liver;
}

void deleteLiver(Liver *liver) {
    if (!liver) {
        return;
    }
    free(liver);
}