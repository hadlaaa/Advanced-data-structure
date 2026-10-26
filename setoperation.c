#include <stdio.h>
#include <stdbool.h>
#define MAX 100
// Helper function to check if an element is already in the set
bool contains(int set[], int size, int element) {
 for (int i = 0; i < size; i++) {
 if (set[i] == element) {
 return true;
 }
 }
 return false;
}
// Function to print a set
void printSet(int set[], int size) {
 printf("{ ");
 for (int i = 0; i < size; i++) {
 printf("%d", set[i]);
 if (i < size - 1) {
 printf(", ");
 }
 }
 printf(" }\n");
}
void findUnion(int setA[], int sizeA, int setB[], int sizeB) 
{
 int setC[MAX];
 int sizeC = 0;
 // Add all elements from set A
 for (int i = 0; i < sizeA; i++) {
 setC[sizeC++] = setA[i];
 }
 for (int i = 0; i < sizeB; i++) 
{
 if (!contains(setC, sizeC, setB[i])) 
{
 setC[sizeC++] = setB[i];
 }
 }
 printf("Union (A U B): ");
 printSet(setC, sizeC);
}
void findIntersection(int setA[], int sizeA, int setB[], int sizeB) 
{
 int setC[MAX];
 int sizeC = 0;
 for (int i = 0; i < sizeA; i++) {
 if (contains(setB, sizeB, setA[i])) {
 setC[sizeC++] = setA[i];
 }
 }
 printf("Intersection (A n B): ");
 printSet(setC, sizeC);
}
// Difference: Elements in A but NOT in B (A - B)
void findDifference(int setA[], int sizeA, int setB[], int sizeB) {
 int setC[MAX];
 int sizeC = 0;
 for (int i = 0; i < sizeA; i++) {
 if (!contains(setB, sizeB, setA[i])) {
 setC[sizeC++] = setA[i];
 }
 }
 printf("Difference (A - B): ");
 printSet(setC, sizeC);
}
int main() 
{
 // Define two example sets
 int setA[] = {1, 3, 5, 7, 9};
 int setB[] = {2, 3, 5, 8, 9, 10};
 int sizeA = sizeof(setA) / sizeof(setA[0]);
 int sizeB = sizeof(setB) / sizeof(setB[0]);
 // Print original sets
 printf("Set A: ");
 printSet(setA, sizeA);
 printf("Set B: ");
 printSet(setB, sizeB);
 printf("-------------------------------------------\n");
 findUnion(setA, sizeA, setB, sizeB);
 findIntersection(setA, sizeA, setB, sizeB);
 findDifference(setA, sizeA, setB, sizeB); // A - B
 findDifference(setB, sizeB, setA, sizeA); // B - A
 return 0;
}
