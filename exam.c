 
 ///leap year test.
 if ((yearNumber % 100 !=0 && yearNumber %4 == 0) || yearNumber % 400 == 0) {
        printf("%d is a leap year.\n", yearNumber);
    }   
    
    
////ascci 
int main(void) {
    int count = 32;
    while (count <= 126) {
        printf("%3d 0x%x %c\n", count, count, count);

        count++;
    }
    return 0;
}
//reapting scanf 
//scanf the number
    while (counter <= final 
           && scanf("%d", &scanned_in_value[counter]) == 1) {
        
        counter++;

    }
  
    counter--;
    
    //only letter input
    //remember getchar and putchar is int type.
    int ch = getchar ();
    while (ch != EOF) {
        putchar(ch);
        ch = getchar ();
    }
///calculate the max value, we should start from the firsr one,
    
void freeList(struct node *n) {
 while(n != NULL) {
 // keep track of the current node
 struct node *remNode = head;

 // move the looping pointer to the next node
 n = n->next;

 // free the current node
 free(remNode);
 }
}

printf("Who just got knocked out?\n");
        char ko_name[MAX_NAME];
        fgets(ko_name, MAX_NAME, stdin);
        // slightly dodgy way of removing the \n from the end of the string
        ko_name[strlen(ko_name) - 1] = '\0';
////////adding at start        
struct player *create_player(struct player *new_next, char new_name[MAX_NAME]) {
    struct player *new_player = malloc(sizeof(struct player));
    new_player->next = new_next;
    strcpy(new_player->name, new_name);
    return new_player;
}        

struct player *remove_player(struct player *head, char rem_name[MAX_NAME]) {
    // find the player node that matches rem_name
    struct player *cur_player = head;
    struct player *previous = NULL;
    while (cur_player != NULL && strcmp(cur_player->name, rem_name) != 0) {
        previous = cur_player;
        cur_player = cur_player->next;
    }
    if (cur_player != NULL) {
        // we found the right node, remove it
        if (previous == NULL) {
            // we are removing the first element of the list
            head = cur_player->next;
            free(cur_player);
        } else {
            // we are removing an element anywhere but the start of the list
            previous->next = cur_player->next;
            free(cur_player);
        }        
    }
    return head;
}

// Loop through the linked list, freeing all the player nodes
void free_list(struct player *head) {
    struct player *cur_player = head;
    while (cur_player != NULL) {
        struct player *free_player = cur_player;
        cur_player = cur_player->next;
        free(free_player);
    }
}

void queueAdd(Queue q, int item) {
    struct queueNode *newNode = createNode(item);
    if (q->tail == NULL) {
        // list is empty
        q->head = newNode;
        q->tail = newNode;
    } else {
        // list is not empty
        q->tail->next = newNode;
        q->tail = newNode;
    }    
}

// return the int from the head of the list
// remove head node from list
int queueRemove(Queue q) {
    int result = q->head->data;
    
    struct queueNode *remNode = q->head;
    q->head = q->head->next;
    free(remNode);
    
    return result;
}


// Destroy and Free the entire queue
void queueFree(Queue q) {
 while (q->head != NULL) {
 struct queueNode *current = q->head;
 q->head = q->head->next;
 free(current);
 }
 free(q);
}

// Helper function that creates a node
static struct queueNode *createNode(int item) {
    struct queueNode *newNode = malloc(sizeof(struct queueNode));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}
        
// Add an element on top of the stack
void stackPush(stack s, int item) {
 struct node *n = malloc(sizeof (struct node));
 if (n == NULL) {
 printf("Cannot allocate memory for a node.\n");
 exit(1);
 }
 n->data = item;
 n->next = s->top;
 s->top = n;
}


// Remove the top element from the stack
int stackPop(stack s) {
 if(s->top == NULL) {
 printf("Stack is empty, cannot pop.\n");
 exit(1);
 }
 // keep a pointer to the node so we can free it
 struct node *n = s->top;
 int item = n->data;
 s->top = s->top->next;
 free(n);
 return item;
}        
