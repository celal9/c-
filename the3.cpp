#include "the3.h"

// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    you can use ceil function from cmath

*/
int countsort1(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26];
    std::string B[n]; 
    for (int i = 0; i < n; i++) {
        C[((int)(arr[i][exp])) - 65] = C[((int)(arr[i][exp])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[((int)(arr[i][exp])) - 65]] = arr[i];
        C[((int)(arr[i][exp])) - 65] = C[((int)(arr[i][exp])) - 65] - 1;
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int countsort2(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26*26+26];
    std::string B[n]; 
    for (int i = 0; i < n; i++) {
        C[(((int)(arr[i][exp])) - 65) * 26 + ((int)(arr[i][exp + 1])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26 + ((int)(arr[i][exp + 1])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26 * 26 + 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        //arr yerine b olacak
        B[C[(((int)(arr[i][exp])) - 65) * 26 + ((int)(arr[i][exp + 1])) - 65]] = arr[i];
        C[(((int)(arr[i][exp])) - 65) * 26 + ((int)(arr[i][exp + 1])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26 + ((int)(arr[i][exp + 1])) - 65] - 1;

        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int countsort3(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26 * 26*26 + 26 * 26 + 26];
    std::string B[n]; 
    for (int i = 0; i < n; i++) {
        C[(((int)(arr[i][exp])) - 65) * 26*26 + (((int)(arr[i][exp + 1])) - 65) * 26 + ((int)(arr[i][exp + 2])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26 + (((int)(arr[i][exp + 1])) - 65) * 26 + ((int)(arr[i][exp + 2])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26 * 26*26 + 26 * 26 + 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        //arr yerine b olacak
        B[C[(((int)(arr[i][exp])) - 65) * 26*26 + (((int)(arr[i][exp + 1])) - 65) * 26 + ((int)(arr[i][exp + 2])) - 65]] = arr[i];
        C[(((int)(arr[i][exp])) - 65) * 26*26 + (((int)(arr[i][exp + 1])) - 65) * 26 + ((int)(arr[i][exp + 2])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26 + (((int)(arr[i][exp + 1])) - 65) * 26 + ((int)(arr[i][exp + 2])) - 65] - 1;
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int countsort4(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26 * 26*26*26 + 26 * 26*26*26 + 26 * 26 + 26];
    std::string B[n]; 
    for (int i = 0; i < n; i++) {
        C[(((int)(arr[i][exp])) - 65) * 26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26 + (((int)(arr[i][exp + 2])) - 65) * 26 + ((int)(arr[i][exp + 3])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26 + (((int)(arr[i][exp + 2])) - 65) * 26 + ((int)(arr[i][exp + 3])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        //arr yerine b olacak
        B[C[(((int)(arr[i][exp])) - 65) * 26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26 + (((int)(arr[i][exp + 2])) - 65) * 26 + ((int)(arr[i][exp + 3])) - 65]] = arr[i];
        C[(((int)(arr[i][exp])) - 65) * 26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26 + (((int)(arr[i][exp + 2])) - 65) * 26 + ((int)(arr[i][exp + 3])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26 + (((int)(arr[i][exp + 2])) - 65) * 26 + ((int)(arr[i][exp + 3])) - 65] - 1;
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int countsort5(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26*26*26*26*26 + 26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26];
    std::string B[n]; 
    for (int i = 0; i < n; i++) {
        C[(((int)(arr[i][exp])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26 + (((int)(arr[i][exp + 3])) - 65) * 26 + ((int)(arr[i][exp + 4])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26 + (((int)(arr[i][exp + 3])) - 65) * 26 + ((int)(arr[i][exp + 4])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26 * 26*26*26*26 + 26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[(((int)(arr[i][exp])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26 + (((int)(arr[i][exp + 3])) - 65) * 26 + ((int)(arr[i][exp + 4])) - 65]] = arr[i];
        C[(((int)(arr[i][exp])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26 + (((int)(arr[i][exp + 3])) - 65) * 26 + ((int)(arr[i][exp + 4])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26 + (((int)(arr[i][exp + 3])) - 65) * 26 + ((int)(arr[i][exp + 4])) - 65] - 1;

        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int countsort6(std::string arr[], int n, int iter, int exp) {
    int* C = new int[26 * 26*26*26*26*26 + 26 * 26*26*26*26 + 26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26];
    std::string B[n];
    for (int i = 0; i < n; i++) {
        C[(((int)(arr[i][exp])) - 65) * 26*26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26*26+ (((int)(arr[i][exp + 3])) - 65) * 26*26 + (((int)(arr[i][exp + 4])) - 65) * 26 + ((int)(arr[i][exp + 5])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26*26 + (((int)(arr[i][exp + 3])) - 65) * 26*26 + (((int)(arr[i][exp + 4])) - 65) * 26 + ((int)(arr[i][exp + 5])) - 65] + 1;
        iter++;
    }
    for (int i = 1; i <= 26*26*26*26*26*26 + 26*26*26*26*26 + 26 * 26*26*26 + 26 * 26*26 + 26 * 26 + 26 - 1; i++) {
        C[i] = C[i] + C[i - 1];
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[(((int)(arr[i][exp])) - 65) * 26*26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26*26 + (((int)(arr[i][exp + 3])) - 65) * 26*26 + (((int)(arr[i][exp + 4])) - 65) * 26 + ((int)(arr[i][exp + 5])) - 65]] = arr[i];
        C[(((int)(arr[i][exp])) - 65) * 26*26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26*26 + (((int)(arr[i][exp + 2])) - 65) * 26*26*26 + (((int)(arr[i][exp + 3])) - 65) * 26*26 + (((int)(arr[i][exp + 4])) - 65) * 26 + ((int)(arr[i][exp + 5])) - 65] = C[(((int)(arr[i][exp])) - 65) * 26*26*26*26*26 + (((int)(arr[i][exp + 1])) - 65) * 26*26*26*26+ (((int)(arr[i][exp + 2])) - 65) * 26*26*26 + (((int)(arr[i][exp + 3])) - 65) * 26*26 + (((int)(arr[i][exp + 4])) - 65) * 26 + ((int)(arr[i][exp + 5])) - 65] - 1;
        iter++;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = B[i];
        iter++;
    }
    return iter;
}
int radixSortascending(std::string arr[], int n, int l) {
    int m = arr[0].length();
    int iter = 0;
    int a;
    if (l = 1) {
        for (int i = m - 1; i >= 0; i--) {
            iter = iter + countsort1(arr, n, iter, i);
            a=i;
        }
    }
    if (l = 2) {
        for (int i = m - 2; i >= 0; i -= 2) {
            iter = iter + countsort2(arr, n, iter, i);
            a=i;
        }
        if (m % 2 == 1 && a < 2) {
            iter = iter + countsort1(arr, n, iter, 0);
        }
    }
    if (l = 3) {
        for (int i = m - 3; i >= 0; i -= 3) {
            iter = iter + countsort3(arr, n, iter, i);
            a=i;
        }
        if (m % 3 == 1 && a < 3) {
            iter = iter + countsort1(arr, n, iter, 0);
        }
        if (m % 3 == 2 && a < 3) {
            iter = iter + countsort2(arr, n, iter, 0);
        }

    }
    if (l = 4) {
        for (int i = m - 4; i >= 0; i -= 4) {
            iter = iter + countsort4(arr, n, iter, i);
            a=i;
        }
        if (m % 4 == 1 && a < 4) {
            iter = iter + countsort1(arr, n, iter, 0);
        }
        if (m % 4 == 2 && a < 4) {
            iter = iter + countsort2(arr, n, iter, 0);
        }
        if (m % 4 == 3 && a < 4) {
            iter = iter + countsort3(arr, n, iter, 0);
        }

    }
    if (l = 6) {
        for (int i = m - 6; i >= 0; i -= 6) {
            iter = iter + countsort5(arr, n, iter, i);
            a=i;
        }
        if (m % 6 == 1 && a < 6) {
            iter = iter + countsort1(arr, n, iter, 0);
        }
        if (m % 6 == 2 && a < 6) {
            iter = iter + countsort2(arr, n, iter, 0);
        }
        if (m % 6 == 3 && a < 6) {
            iter = iter + countsort3(arr, n, iter, 0);
        }
        if (m % 6 == 4 && a < 6) {
            iter = iter + countsort4(arr, n, iter, 0);
        }
        if (m % 6 == 5 && a < 6) {
            iter = iter + countsort5(arr, n, iter, 0);
        }
    }
    return iter;
}
int radixSortdescending(std::string arr[], int n, int l) {
    int iter = 0;
    iter = iter + radixSortascending(arr, n, l);
    return iter;
}
int radixSort(std::string arr[], bool ascending, int n, int l) {


    if (ascending) {
        return radixSortascending(arr, n, l);
    }
    else {
        return radixSortdescending(arr, n, l);
    }

}
