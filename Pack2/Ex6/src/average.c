#include "../include/functions.h"
#include <math.h>

Returncode average(Student * students, int * sizeStuds, Student * foundStuds, double * avMax, int * sizeAv) {
    *avMax = 0.0;
    double av = 0.0;

    for (int i = 0; i < *sizeStuds; ++i) {
        av = 0.0;
        for (int j = 0; j < SCORES_SIZE; ++j) {
            av += (double)(students[i].scores[j]);
        }

        av /= SCORES_SIZE;
        if (av > *avMax) {
            *avMax = av;
        }
    }

    for (int i = 0; i < *sizeStuds; ++i) {
        av = 0.0;
        for (int j = 0; j < SCORES_SIZE; ++j) {
            av += (double)(students[i].scores[j]);
        }

        av /= SCORES_SIZE;
        if (fabs(av - *avMax) < EPS) {
            foundStuds[*sizeAv] = students[i]; 
            ++(*sizeAv);
        }
    }

    return OK;
}