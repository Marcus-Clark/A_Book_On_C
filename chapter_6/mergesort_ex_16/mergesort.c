/* mergesort: use merge() to sort an array of size n.*/

#include "mergesort.h"

void mergesort(int key[], int n) {
    // key is the array, n is the number of elements
    int i, j, k, m;
    int *w;

    // allocate the working array
    w = calloc(n, sizeof(int));
    // abort the program on allocation failure
    assert(w != NULL);

    // for pairs of chunks of increasing sizes
    for (k = 1; k < n; k *= 2) {
        // as long as there are enough elements for a pair
        for (j = 0; j + k < n; j = j + k + m) {
            // compute the size of the second chunk: default to k
            m = k;
            if (j + k + m > n) {
                // chunk is the last one, size may be smaller than k
                m = n - j - k;
            }
            // merge adjacent chunks into the working array
            merge(key + j, key + j + k, w + j, k, m);
            // copy the resulting sorted list back to the key array
            for (i = 0; i < k + m; i++) {
                key[j + i] = w[j + i];
            }
        }
    }
    free(w);
}
