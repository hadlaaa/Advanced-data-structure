#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 
int hashTable[SIZE];
void initTable() {
 for (int i = 0; i < SIZE; i++) {
 hashTable[i] = -1;
 }
}
int hashFunction(int key) 
{
 return key % SIZE;
}
void insert(int key) {
 int index = hashFunction(key);
 int originalIndex = index;
 while (hashTable[index] != -1) 
{
index = (index + 1) % SIZE; 
if (index == originalIndex) 
{
 printf("Hash Table is Full! Cannot insert key %d\n", key);
 return;
 }
 }
 hashTable[index] = key;
 printf("Inserted %d at index %d\n", key, index);
}
void displayTable() 
{
 printf("\n--- Hash Table Contents ---\n");
for (int i = 0; i < SIZE; i++) 
 {
 if (hashTable[i] != -1) {
 printf("Index %d: %d\n", i, hashTable[i]);
 } 
else {
 printf("Index %d: Empty\n", i);
 }
 }
 printf("---------------------------\n\n");
}
int main() 
{
 initTable();
 insert(12); // 12 % 10 = index 2
 insert(22); // 22 % 10 = index 2 (Collision -> placed at index 3)
 insert(42); // 42 % 10 = index 2 (Collision -> placed at index 4)
 insert(15); // 15 % 10 = index 5
 displayTable();
 return 0;
}
