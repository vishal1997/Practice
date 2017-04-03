#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 9999999
struct Point {
    int x,y;
};
float closest(struct Point P[], int size);
float closestUtil(struct Point Px[], struct Point Py[],int size);
float closestStrip(struct Point strip[],int size, float d) ;
int compareX(const void* x1, const void* x2);
void inputPoint(struct Point P[], int size);
int compareY(const void* y1, const void* y2);
float min(float x, float y);
float dist(struct Point P1, struct Point P2);

float bruteForce(struct Point P[], int size);
int
main() {
    int size;
    printf("\nEnter the no. of struct Points\n");
    scanf("%d",&size);
    struct Point P[size];
    //struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    printf("\nEnter the Points separated by space X Y :");
    inputPoint(P, size);
    printf("\nSmallest Distance=%f",closest(P,size));
}

float closestUtil(struct Point Px[], struct Point Py[],int size) {
    if(size<=3)
        return bruteForce(Px,size);
    int mid=size/2;
    struct Point midPoint=Px[mid];
    struct Point Pxl[mid+1];
    struct Point Pxr[size-mid-1];
    int li=0,
    ri=0,
    i;
    for(i=0;i<size;i++) {
        if(Px[i].x <= midPoint.x)
            Pxl[li++] = Px[i];
        Pxr[ri++] = Px [i];
    }
    float dl=closestUtil(Px,Pxl,mid);
    float dr=closestUtil(Px+mid,Pxr,size-mid);
    float d=min(dl,dr);
    struct Point strip[size];
    int j=0;
    for(i=0;i<size;i++) {
        if(abs(Py[i].x - midPoint.x)<d )
            strip[j]=Py[i];
            j++;
    }
    return min(d, closestStrip(strip,j,d));
}


float closestStrip(struct Point strip[],int size, float d) {
    int i,j;
    float min=d,
    distance=0;
    for(i=0;i<size;i++)
        for(j=i+1;j<size && (strip[j].y-strip[i].y)<min; j++) {
                distance=dist(strip[i],strip[j]);
                if(distance<min)
                    min=distance;
    }
    return min;
}


float bruteForce(struct Point P[], int size) {
    float min=MAX;
    int i,j;
    float distance=0;
    for(i=0;i<size;i++) {
        for(j=i+1;j<size;j++) {
                distance=dist(P[i],P[j]);
            if(min>distance)
                min=distance;
        }
    }
    return min;
}


int compareX(const void* x1, const void* x2) {
    struct Point *P1=(struct Point *)x1, *P2=(struct Point *)x2;
    return P1->x - P2->x;
}

int compareY(const void* y1, const void* y2) {
    struct Point *P1=(struct Point *)y1, *P2=(struct Point *)y2;
    return P1->y - P2->y;
}

float dist(struct Point P1, struct Point P2) {
    return sqrt( (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}

float min(float x, float y) {
    return (x<y)?x:y;
}

float closest(struct Point P[], int size) {
    struct Point Px[size];
    struct Point Py[size];
    int i;
    for(i=0;i<size;i++) {
        Px[i]=P[i];
        Py[i]=P[i];
    }
    qsort(Px,size, sizeof(struct Point),compareX);
    qsort(Py, size,sizeof(struct Point),compareY);
    return closestUtil(Px,Py,size);
}

void inputPoint(struct Point P[], int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("\nEnter %d Point",i+1);
        scanf("%d",&P[i].x);
        scanf("%d",&P[i].y);
    }
}

