#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    int isBorrowed;
    struct Book* next;

};

struct Book* head = NULL;

// Add Book 

void addBook(int id, const char* title, const char* author) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->isBorrowed = 0;
    newBook->next = head;
    head = newBook;
}  

//Display Books

void displayBooks() {
    struct Book* temp = head;
    printf("\n--- Book List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Author: %s | Status: %s\n",
        temp->id, temp->title, temp->author, temp->isBorrowed ? "Borrowed" : "Available");
        temp = temp->next;
    }
}

//Search Book

void searchBook(int id){
    struct Book* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nBook Found!\n");
            printf("Name: %s | Author: %s | Status: %s\n",
            temp->title, temp->author,
        (temp->isBorrowed) ? "Borrowed" : "Available");
            found = 1;
            break;
        }    
        temp = temp->next;
    }

    if (found == 0) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

//Borrow Book

void borrowBook(int id) {
    struct Book* temp = head;

    while(temp != NULL) {
        if (temp->id == id) {
            if (temp->isBorrowed == 1){
                printf("\nSorry, the book '%s' is already borrowed !\n", temp->title);
            } else {
                temp->isBorrowed = 1;
                printf("\nYou have successfully borrowed '%s' !\n", temp->title);
            }
            return;
            }
            temp = temp->next;
        }
        printf("\nBook with ID %d not found.\n", id);
    };

    //Return Book

void returnBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->isBorrowed == 0) {
                printf("\nThis book is already in the libary!\n");
            } else {
                temp->isBorrowed = 0;
                printf("\n'%s' has been successfully returned!\n", temp->title);
            }
            return;
        }
        temp = temp->next;
    }
            printf("\nBook with ID %d not found.\n", id);
}

//Remove Book
    
void removeBook(int id) {
    struct Book* temp = head, *prev = NULL;

    if (temp == NULL) {
        printf("\nLibary is empty!\n");
        return;
    }
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("\nBook with ID %d has been removed.\n", id);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nBook with ID %d not found.\n", id);
        return;
}
    prev->next = temp->next;
    free(temp);
    printf("\nBook with ID %d has been removed.\n", id);
}

void sortBook(int id) {
 
    
}
 

int main() {
  int choice, id;
  char title[100], author[50];

  while (1) {
    printf("\n--- Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Borrow Book\n");
    printf("5. Return Book\n");
    printf("6. Remove Book\n");
    printf("0. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("\nExiting the program. Goodbye!\n");
        break;
    }

    switch (choice) {
        case 1:
            printf("ID:"); scanf("%d", &id);
            getchar();
            printf("Title: "); fgets(title, 100, stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Author: "); fgets(author, 50, stdin);
            author[strcspn(author, "\n")] = 0;
            addBook(id, title, author);
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            printf("\nEnter book ID to search: ");
            scanf("%d", &id);
            searchBook(id);
            break;
        case 4:
            printf("\nEnter book ID to borrow: ");
            scanf("%d", &id);
            borrowBook(id);
            break;
        case 5:
            printf("\nEnter book ID to return: ");
            scanf("%d", &id);
            returnBook(id);
            break;
        case 6:
            printf("\nEnter book ID to remove: ");
            scanf("%d", &id);
            removeBook(id);
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
  }
  }
  return 0;
};