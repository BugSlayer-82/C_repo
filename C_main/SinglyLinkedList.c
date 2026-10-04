#include <stdio.h> // Include the standard input/output library for printf() and scanf().
#include <stdlib.h> // Include the standard library for malloc() and memory allocation.

/* Function prototype for LinkedList */
// Declare the function prototypes before main() so the compiler knows about these functions.
void addFirst(int data); // Function to add a new node at the beginning of the linked list.
void addLast(int data); // Function to add a new node at the end of the linked list.
void addAtPosition(int pos, int data); // Function to add a new node at a specific position.
void deleteFirst(); // Function to delete the first node.
void deleteLast(); // Function to delete the last node.
void deleteFromPosition(int pos); // Function to delete a node from a specific position.
void printList(); // Function to print all nodes of the linked list.
int countNode(); // Function to count and return the total number of nodes.
void search(int element); // Function to search for a given element in the linked list.

/* Structure of Node */
// Define the structure of a node in the linked list.
struct Node
{
	int data; // Store the data value of the node.
	struct Node *next; // Store the address of the next node.
};

/* Declare a variable called head*/
// Create a pointer named head that points to the first node of the linked list.
struct Node *head = NULL; // Initially, the linked list is empty, so head points to NULL.

int main()
{
	addFirst(3); // Add 3 at the beginning of the linked list.
	addFirst(2); // Add 2 at the beginning of the linked list.
	addFirst(1); // Add 1 at the beginning of the linked list.
	addLast(5); // Add 5 at the end of the linked list.
	addLast(6); // Add 6 at the end of the linked list.
	addLast(7); // Add 7 at the end of the linked list.
	printList(); // Print all elements of the linked list.

	addAtPosition(4, 4); // Add 4 at position 4 in the linked list.
	printList(); // Print the updated linked list.

	deleteFirst(); // Delete the first node from the linked list.
	printList(); // Print the linked list after deleting the first node.

	deleteLast(); // Delete the last node from the linked list.
	printList(); // Print the linked list after deleting the last node.

	deleteFromPosition(5); // Delete the node at position 5.
	printList(); // Print the linked list after deleting the node.

	int x; // Declare a variable to store the element entered by the user.
	printf("Enter your element you want : "); // Ask the user to enter an element.
	scanf("%d",&x); // Read the element entered by the user.
	search(x); // Search for the entered element in the linked list.
	printf("Total Nodes in the list : %d \n", countNode()); // Count and print the total number of nodes.
	return 0; // End the main() function and return 0 to the operating system.
}

void addFirst(int data)
{
	// Create a new node dynamically using malloc().
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data; // Store the given data in the new node.
	newNode->next = head; // Make the new node point to the current first node.
	head = newNode; // Make the new node the new first node of the list.
	// printf("Data inserted \n"); // This line can be used to print a message after insertion.
}

void addLast(int data)
{
	// Create a new node dynamically using malloc().
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data; // Store the given data in the new node.
	newNode->next = NULL; // The new node will be the last node, so its next is NULL.
	if (head == NULL) // Check whether the linked list is empty.
	{
		head = newNode; // If the list is empty, make the new node the first node.
		return; // Stop the function because the node has been added.
	}
	struct Node *currNode = head; // Create a pointer that starts from the first node.
	while (currNode->next != NULL) // Continue moving until the last node is reached.
	{
		currNode = currNode->next; // Move currNode to the next node.
	}
	currNode->next = newNode; // Connect the current last node to the new node.
	newNode = currNode; // Assign currNode to newNode.
	// printf("Data Inserted \n"); // This line can be used to print a message after insertion.
}

void addAtPosition(int pos, int data)
{
	if (pos < 1) // Check whether the given position is less than 1.
	{
		printf("Invalid position ...! \n"); // Print an error message for an invalid position.
		return; // Stop the function.
	}
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically.
	newNode->data = data; // Store the given data in the new node.
	int i = 1; // Start counting the positions from 1.
	if (pos == 1) // Check if the new node should be inserted at the first position.
	{
		newNode->next = head; // Make the new node point to the current first node.
		head = newNode; // Make the new node the new first node.
		return; // Stop the function because insertion is complete.
	}
	struct Node *prevNode = head; // Create a pointer that starts from the first node.
	while (prevNode != NULL && i < pos - 1) // Move to the node just before the required position.
	{
		prevNode = prevNode->next; // Move prevNode to the next node.
		i++; // Increase the position counter by 1.
	}
	if (prevNode == NULL) // Check whether the required position is outside the list.
	{
		printf("Position not found ..! \n"); // Print a message if the position does not exist.
		free(newNode); // Free the memory allocated for the new node.
		return; // Stop the function.
	}
	newNode->next = prevNode->next; // Make the new node point to the node currently after prevNode.
	prevNode->next = newNode; // Connect prevNode to the new node.
}

void deleteFirst()
{
	if (head == NULL) // Check whether the linked list is empty.
	{
		printf("List is empty ...!\n"); // Print a message if there is no node.
		return; // Stop the function.
	}
	struct Node *temp = head; // Store the address of the first node in temp.
	head = head->next; // Move head to the second node.
	free(temp); // Free the memory of the old first node.
}

void deleteLast()
{
	if (head == NULL) // Check whether the linked list is empty.
	{
		printf("List is empty ...!\n"); // Print a message if there is no node.
		return; // Stop the function.
	}
	if (head->next == NULL) // Check whether the list contains only one node.
	{
		free(head); // Free the only node in the list.
		head = NULL; // Set head to NULL because the list is now empty.
		return; // Stop the function.
	}
	struct Node *currNode = head; // Create a pointer that starts from the first node.
	while (currNode->next->next != NULL) // Move until currNode becomes the second-last node.
	{
		currNode = currNode->next; // Move currNode to the next node.
	}
	printf("%d : deleted successfully \n", currNode->next->data); // Print the data of the last node before deleting it.
	free(currNode->next); // Free the memory of the last node.
	currNode->next = NULL; // Make the second-last node the new last node.
}

void deleteFromPosition(int pos)
{
	if (pos < 1) // Check whether the given position is less than 1.
	{
		printf("Invalid Position \n"); // Print an error message for an invalid position.
		return; // Stop the function.
	}
	int i = 1; // Start counting the positions from 1.
	struct Node *prevNode = head; // Create a pointer to store the previous node.
	struct Node *currNode = head; // Create a pointer to store the current node.
	if (pos == i) // Check whether the node to delete is the first node.
	{
		head = head->next; // Move head to the second node.
		printf("%d : is deleted \n", prevNode->data); // Print the data of the node being deleted.
		free(prevNode); // Free the memory of the first node.
		return; // Stop the function because deletion is complete.
	}
	while (currNode != NULL) // Continue traversing while the current node exists.
	{
		if (i == pos) // Check whether the current position is the position to delete.
		{
			printf("%d : is deleted \n", currNode->data); // Print the data of the node being deleted.
			prevNode->next = currNode->next; // Connect the previous node directly to the next node.
			free(currNode); // Free the memory of the current node.
			return; // Stop the function because deletion is complete.
		}
		prevNode = currNode; // Move prevNode to the current node.
		currNode = currNode->next; // Move currNode to the next node.
		i++; // Increase the position counter by 1.
	}
	printf("Position not found \n"); // Print a message if the given position does not exist.
}

int countNode()
{
	if (head == NULL) // Check whether the linked list is empty.
	{
		return 0; // Return 0 because there are no nodes.
	}
	struct Node *currNode = head; // Create a pointer that starts from the first node.
	int count = 0; // Create a variable to store the number of nodes.
	while (currNode != NULL) // Continue until the end of the linked list.
	{
		count++; // Increase the node count by 1.
		currNode = currNode->next; // Move to the next node.
	}
	return count; // Return the total number of nodes.
}

void search(int x)
{
	struct Node *currNode = head; // Create a pointer that starts from the first node.
	int i = 0; // Start the position counter from 0.
	while (currNode != NULL) // Continue searching while the current node exists.
	{
		if (currNode->data == x) // Check whether the current node contains the searched element.
		{
			printf("Element is found : %d , at : %d \n", x, i); // Print the element and its position.
			return; // Stop the function because the element has been found.
		}
		currNode = currNode->next; // Move to the next node.
		i++; // Increase the position counter by 1.
	}
	printf("Element is not found : %d \n", x); // Print a message if the element is not found.
}

void printList()
{
	if (head == NULL) // Check whether the linked list is empty.
	{
		printf("NULL \n"); // Print NULL because there are no nodes.
		return; // Stop the function.
	}
	struct Node *currNode = head; // Create a pointer that starts from the first node.
	while (currNode != NULL) // Continue until the end of the linked list.
	{
		printf("%d -> ", currNode->data); // Print the data of the current node followed by an arrow.
		currNode = currNode->next; // Move to the next node.
	}
	printf("NULL \n"); // Print NULL to show the end of the linked list.
}