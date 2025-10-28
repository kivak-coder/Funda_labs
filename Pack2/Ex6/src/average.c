#include "../include/functions.h"
#include <math.h>

Returncode average(Student * students, int * sizeStuds, Student * foundStuds, double * avMax, int * sizeAv) {
    *avMax = 0.0;
    double av = 0.0;
    Student * ptr = foundStuds;

    for (int i = 0; i < *sizeStuds; ++i) {
        for (int j = 0; j < SCORES_SIZE; ++j) {
            av += (double)students[i].scores[j];
        }

        av /= 5;
        if (fabs(av - EPS) < EPS) {
            *avMax = av;
            ptr = &students[i];
            ++foundStuds;
            ++(*sizeAv);
        }
    }
    return OK;
}