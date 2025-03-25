#include <stdio.h>
#include <time.h>
#include <stdlib.h> // To recognize the exit function when compiling with gcc

// Function prototypes
void split(int[], int, int);
void combine(int[], int, int, int);

int main() {
    int a[90000], n, i, j, ch, temp;  // Increased array size to accommodate up to 90,000 elements
    clock_t start, end;

    while(1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 50000 to 90000");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter array elements: ");
            for(i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            start = clock();
            split(a, 0, n - 1);
            end = clock();

            printf("\nSorted array is: ");
            for(i = 0; i < n; i++) {
                printf("%d\t", a[i]);
            }

            printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
            break;

        case 2:
            n = 50000;
            while(n <= 90000) {
                for(i = 0; i < n; i++) {
                    a[i] = rand() % 1000;  // Random number between 0 and 999
                }

                start = clock();
                split(a, 0, n - 1);

                // Dummy loop to create delay (you can adjust or remove this)
                for(j = 0; j < 500000; j++) { temp = 38 / 600; }

                end = clock();
                printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);

                n = n + 1000;
            }
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice, please try again.");
        }

        // Add this to pause the program after executing a case (so you can read the output)
        getchar();
        getchar();
    }

    return 0;  // Indicate successful execution
}

void split(int a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        split(a, low, mid);
        split(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}

void combine(int a[], int low, int mid, int high) {
    int c[90000], i, j, k;  // Adjusted the size to handle up to 90,000 elements
    i = k = low;
    j = mid + 1;

    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            c[k] = a[i];
            ++k;
            ++i;
        } else {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    if(i > mid) {
        while(j <= high) {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    if(j > high) {
        while(i <= mid) {
            c[k] = a[i];
            ++k;
            ++i;
        }
    }

    for(i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
