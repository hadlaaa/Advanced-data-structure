#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node* prev;
 struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int val) 
{
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (!newNode) {
 printf("Memory allocation failed!\n");
 exit(1);
 }
 newNode->data = val;
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}
void insertFront(int val) 
{
 struct Node* newNode = createNode(val);
 if (head == NULL) {
 head = newNode;
 return;
 }
 head->prev = newNode;
 newNode->next = head;
 head = newNode;
}
void insertEnd(int val) 
{
 struct Node* newNode = createNode(val);
 if (head == NULL) {
 head = newNode;
 return;
 }
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
newNode->prev = temp;
}
struct Node* search(int key) 
{
 struct Node* temp = head;
 while (temp != NULL) {
 if (temp->data == key) return temp;
 temp = temp->next;
 }
 return NULL;
}
void deleteValue(int val) 
{
 if (head == NULL)
{
 printf("List is empty!\n");
 return;
 }
 
 struct Node* curr = search(val);
 if (curr == NULL) {
 printf("Value %d not found in the list.\n", val);
 return;
 }
 
 if (head == curr)
{
 head = curr->next;
 }
 
 if (curr->next != NULL) {
 curr->next->prev = curr->prev;
 }
 if (curr->prev != NULL) 
{
 curr->prev->next = curr->next;
 }
 
 free(curr);
 printf("Deleted %d successfully.\n", val);
}
void displayForward()
{
 struct Node* temp = head;
 if (temp == NULL) {
 printf("List is empty.\n");
 return;
 }
 printf("Forward List: ");
 while (temp != NULL) {
 printf("%d <-> ", temp->data);
temp = temp->next;
 }
 printf("NULL\n");
}
// Main function providing a menu-driven console interface
int main() {
 int choice, val;
 while (1) {
 printf("\n--- Doubly Linked List Operations ---\n");
 printf("1. Insert Front\n2. Insert End\n3. Delete Value\n4. Search\n5. Display\n6. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) 
{
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &val);
 insertFront(val);
 break;
 case 2:
 printf("Enter value to insert: ");
 scanf("%d", &val);
 insertEnd(val);
 break;
 case 3:
 printf("Enter value to delete: ");
 scanf("%d", &val);
 deleteValue(val);
 break;
 case 4:
 printf("Enter value to search: ");
 scanf("%d", &val);
 if (search(val) != NULL) printf("Element %d found!\n", val);
 else printf("Element %d not found!\n", val);
 break;
 case 5:
 displayForward();
 break;
 case 6:
 exit(0);
 default:
 printf("Invalid choice!\n");
 }
 }
 return 0;
}
