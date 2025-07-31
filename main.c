#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void euclidian_distance_c(int n, float* x1, float* x2, float* y1, float* y2, float* z) {
    for (int i = 0; i < n; i++) {
        float dx = x2[i] - x1[i];
        float dy = y2[i] - y1[i];
        z[i] = sqrtf(dx * dx + dy * dy);
    }
}

void initialize_array(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)(rand() % 1000) / 10.0f;
    }
}

void print_vector(float* arr, int n) {
    int limit = n > 10 ? 10 : n;
    for (int i = 0; i < limit; i++) {
        printf("z[%d] = %.8f\n", i, arr[i]);
    }
}


int main() {
    int n;
    printf("Enter the length of the vectors: ");
    scanf("%d", &n);

    float *x1 = (float*)malloc(sizeof(float) * n);
    float *x2 = (float*)malloc(sizeof(float) * n);
    float *y1 = (float*)malloc(sizeof(float) * n);
    float *y2 = (float*)malloc(sizeof(float) * n);
    float *z = (float*)malloc(sizeof(float) * n);

    if (!x1 || !x2 || !y1 || !y2 || !z) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    initialize_array(x1, n);
    initialize_array(x2, n);
    initialize_array(y1, n);
    initialize_array(y2, n);

    euclidian_distance_c(n, x1, x2, y1, y2, z);
    print_vector(z, n);

    free(x1); free(x2); free(y1); free(y2); free(z);
    return 0;
}
