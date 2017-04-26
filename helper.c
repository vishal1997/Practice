void inputArray(int *array, int size);
void displayArray(int *array, int size);
void swap(int *a, int *b);
void displayArray(int *array, int size) {
    int i;
    for(i=0;i<size;i++)
        printf(" %d ",array[i]);
}

void inputArray(int *array, int size) {
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&array[i]);
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
