#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>




char* getMessage() {
    char *msg = (char *)malloc(50 * sizeof(char)); 
    if(msg == NULL) {
      printf("Memory allocation failed.\n");
      exit(1);
    }
    strcpy(msg, "Welcome to C programming!");
    return msg;  
}
 
 
void processArray() {
    int *arr = (int *)malloc(3 * sizeof(int)); //Memory Allocated
    if (arr == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
 
    printf("Array first element: %d\n", arr[0]); 
    free(arr);
}
     
     
void allocateInt() {
    int *num = (int *)malloc(sizeof(int)); //Allocate Memory
    if (num == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }

    *num = 100;
    free(num);  //Free Memory 
}
 
 
void processVariadic(int count, ...) {
    va_list args;
    va_start(args, count);
 
 
    for (int i = 0; i < count; i++) {
        char *str = va_arg(args, char*);  // Reading string argument
 
 
        // Allocating memory 
        char *copy = (char *)malloc(strlen(str) + 1);
        if (copy == NULL) {
          printf("Memory Allocation failed\n");
          exit(1);
        }
        
        strcpy(copy, str);
        printf("Copied String: %s\n", copy);
        free(copy);
    }

    va_end(args);

}

int main() {
    char *msg = getMessage();
    printf("%s\n", msg);
    free(msg);
    
    processArray();
    allocateInt();
    processVariadic(2, "Hello", "Memory");
    
    return 0;
}