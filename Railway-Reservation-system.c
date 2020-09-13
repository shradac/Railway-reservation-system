#include<stdio.h>
#include<stdlib.h>

struct node {
  char * name;
  int ticket_number, age, amount;
  struct node * link;
};
typedef struct node * NODE;
NODE first = NULL;
NODE temp;
NODE last;
NODE ptr;
NODE prev;
NODE cur;

int ticket_number = 0;
NODE getnode() {
  NODE x;
  x = malloc(sizeof(struct node));
  if (x == NULL) {
    printf("overflow");
    exit(0);
  }
  return x;
}

void insert() {
  int age;
  temp - > name = (char * ) malloc(sizeof(char) * 10);
  printf("Enter name:");
  scanf("%s", temp - > name);
  printf("Enter age:");
  scanf("%d", & (temp - > age));
  temp - > ticket_number = ticket_number + 1;
  ticket_number += 1;
  if (first == NULL) {
    first = temp;
  } else {
    ptr = first;
    while (ptr - > link != NULL) {
      ptr = ptr - > link;
    }
    temp - > link = NULL;
    ptr - > link = temp;
  }
}
void delete() {
  int no, cashback, count, pos = -1;
  if (first == NULL) {
    printf("NO Bookings to delete! \n\n");
  } else {
    printf("Enter ticket number:");
    scanf("%d", & no);
    count = 1;
    cur = first;
    while (cur != NULL) {
      if (no == cur - > ticket_number) {
        pos = count;
        ptr = cur;
      }
      cur = cur - > link;
      count++;
    }
    last = cur;
    if (pos != -1) {
      if (pos == 1) {
        if (first - > link == NULL) {
          temp = first;
          cashback = temp - > amount * 0.5;
          first = NULL;
          printf("Ticket number: %d with Name: %s has been cancelled.\nRs %d will be credited back to your account.\nThank You! \n\n", temp - > ticket_number, temp - > name, cashback);
          free(temp);
        } else {
          temp = first;
          cashback = temp - > amount * 0.5;
          first = first - > link;
          printf("Ticket number: %d with Name: %s has been cancelled.\nRs %d will be credited back to your account.\nThank You! \n\n", temp - > ticket_number, temp - > name, cashback);
          free(temp);
        }
      } else if (pos == count) {
        if (no == ptr - > ticket_number) {
          temp = last;
          cashback = temp - > amount * 0.5;
          if (temp - > link == NULL) {
            printf("Ticket number: %d with Name: %s has been cancelled.\nRs %d will be credited back to your account.\nThank You! \n\n", temp - > ticket_number, temp - > name, cashback);
            free(temp);
            first = NULL;
          } else {
            prev - > link = NULL;
            printf("Ticket number: %d with Name: %s has been cancelled.\nRs %d will be credited back to your account.\nThank You! \n\n", temp - > ticket_number, temp - > name, cashback);
            free(temp);
          }
        }
      } else {
        count = 2;
        cur = first;
        while (count <= pos) {
          prev = cur;
          cur = cur - > link;
          count++;
        }
        prev - > link = cur - > link;
        temp = cur;
        cashback = temp - > amount * 0.5;
        printf("Ticket number: %d with Name: %s has been cancelled.\nRs %d will be credited back to your account.\nThank You! \n\n", temp - > ticket_number, temp - > name, cashback);
        free(temp);
      }
    } else
      printf("Ticket doesnt exist!\n\n");
  }
}
void display() {
  ptr = first;
  if (first == NULL) {
    printf("No Bookings to show!\n\n");
  } else {
    printf("Ticket No:\t Name:\t \tAge: \n");
    while (ptr != NULL) {
      printf("\t%d ", ptr - > ticket_number);
      printf("\t %s ", ptr - > name);
      printf("\t%d \n", ptr - > age);
      ptr = ptr - > link;
    }
  }
}
void main() {
  int op;
  int choice;
  int cashback;
  int amount;
  do {
    printf("1.Reserve ticket 2.Cancel Ticket 3.Display all passengers 4.Exit\n");
    printf("Enter Option\n");
    scanf("%d", & op);
    switch (op) {
    case 1:
      {
        do {
          printf("1.Bangalore to Delhi -Rs500\n2.Bangalore to Kolkata -Rs600\n3.Bangalore to Mumbai -Rs450\n4.Bangalore to Andhra Pradesh -Rs300\n5.Bangalore to Kerala-Rs300\n6.Bangalore to Tamil Nadu -Rs200\n");
          printf("Enter Destination\n");
          scanf("%d", & choice);
          switch (choice) {
          case 1:
            {
              temp = getnode();
              printf(" You have choosen: Bangalore to Delhi -Rs500 \n");
              amount = 500;
              cashback = 500 * 0.1;
              temp - > amount = amount;
              break;
            }
          case 2:
            {
              temp = getnode();
              printf("You have choosen: Bangalore to Kolkata - Rs600\n");
              amount = 600;
              cashback = 600 * 0.1;
              temp - > amount = amount;
              break;
            }
          case 3:
            {
              temp = getnode();
              printf("You have choosen: Bangalore to Mumbai - Rs450\n");
              amount = 450;
              cashback = 450 * 0.1;
              temp - > amount = amount;
              break;
            }
          case 4:
            {
              temp = getnode();
              printf("You have choosen: Bangalore to Andhra Pradesh - Rs300\n");
              amount = 300;
              cashback = 300 * 0.1;
              temp - > amount = amount;
              break;
            }
          case 5:
            {
              temp = getnode();
              printf("You have choosen: Bangalore to Kerala - Rs300\n");
              amount = 300;
              cashback = 300 * 0.1;
              temp - > amount = amount;
              break;
            }
          case 6:
            {
              temp = getnode();
              printf("You have choosen: Bangalore to Tamil Nadu - Rs200\n");
              amount = 200;
              cashback = 200 * 0.1;
              temp - > amount = amount;
              break;
            }
          default:
            if (choice != -1)
              printf("\nPlease enter correct destination from the below list or enter -1 to go back to prevoius menu\n");
          }
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != -1);
        if (choice != -1) {
          insert();
          printf("\nPay the above fee to confirm reservation and get 10percent cashback of Rs %d to your account\n", cashback);
          printf("Please pay by clicking on this 'link'\n\n");
        }
        break;
      }
    case 2:
      printf("By Cancelling the ticket you wil get only 50 percent of the ticket fare\n");
      delete();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Thank You!! \n");
      exit(0);
    }
  } while (op != 5);
}
