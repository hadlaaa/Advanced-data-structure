#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int parent[MAX];
void makeSet(int n) 
{
 for (int i = 0; i < n; i++)
{
 parent[i] = -1;
 }
}
int find(int i)
{
 int root = i;
 while (parent[root] >= 0) 
{
 root = parent[root];
 }
 return root;
}
void unionSets(int i, int j) 
{
 int rootI = find(i);
 int rootJ = find(j);
 if (rootI != rootJ) 
{
 parent[rootJ] = rootI;
 printf("Union completed: %d joined under %d\n", j, i);
 } else {
 printf("Elements %d and %d are already in the same set (Root: %d)\n", i, j, rootI);
 }
}
void display(int n) 
{
 printf("\nElement : ");
 for (int i = 0; i < n; i++) printf("%3d ", i);
 printf("\nParent : ");
 for (int i = 0; i < n; i++) printf("%3d ", parent[i]);
 printf("\n\n");
}
int main()
{
 int n = 7; 
 makeSet(n);
 printf("Initial Disjoint Sets:\n");
 display(n);
 unionSets(0, 1);
 unionSets(2, 3);
 unionSets(1, 3);
 unionSets(4, 5);
 printf("After Union Operations:\n");
 display(n);
 printf("Representative of element 3 is: %d\n", find(3));
 printf("Representative of element 5 is: %d\n", find(5));
 return 0;
}
