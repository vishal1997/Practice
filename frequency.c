#include<stdio.h>
int
main()
{
	int length,
	array[100],
	i,
	count[100],
	large=0;;

	printf("Enter the length of the array");
	scanf("%d", &length);
	printf("\nEnter the array elements");

	for(i=0;i<length;i++)
		scanf("%d", &array[i]);

    for(i=0;i<length;i++)
        if(large<array[i])
            large=array[i];

	for(i=0;i<large;i++)
		count[i]=0;

	for(i=0;i<length;i++)
		count[array[i]-1]++;

	for(i=0;i<large;i++)
    {
        if(count[i]==0)
            continue;
        printf("\n%d=%d",i+1,count[i]);
    }
	return (0);
}
