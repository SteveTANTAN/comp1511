// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.c
//
// Xingyu TAN (z5237560)
// on 14/11/2019
//
// Version 2.0.0: Release

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pokedex.h"

#define TRUE 1
#define FALSE 0
#define TOTAL_NUM_TYPES 20


struct pokedex {
    struct pokenode *head;
    int num_pokemon;
    
};

struct pokenode {
    Pokemon pokemon;
    struct pokenode *next;
    int foundstate;
    int current_select;
    struct pokenode *evolution;
    
};





static struct pokenode *new_pokenode(Pokemon pokemon);


//////////////////////////////////////////////////////////////////////
//                         MY function                              //
//////////////////////////////////////////////////////////////////////
static int check_repeat_input(Pokemon pokemon,Pokedex pokedex);
static void pokemon_noseen_output (struct pokenode *pokemon);
static void pokemon_seen_output (struct pokenode *pokemon);
static void star_name(const char *pokemon_name);
static void print_pokemon_name_vertical 
(Pokedex pokedex, struct pokenode *pokenode); 
static void print_arrow (struct pokenode *pokenode);
static void copy_type_into_string(int *array, struct pokenode *node);
static void print_Out_TotalTYPE (int *array);
static void test_first_type (int *array,struct pokenode *node);
static struct pokenode *search_id (Pokedex pokedex,int id);
static struct pokenode *get_select(Pokedex pokedex); 
static void printEVO (struct pokenode *pokenode);
static int compare(struct pokenode *node, pokemon_type type);
static void add_in_new_pokedex (Pokedex pokedex, struct pokenode *node);
static void order_pokenode(Pokedex pokedex, struct pokenode *node); 
static int searchAndCompare (char *text, struct pokenode *node);
static int if_text_in_name (char *name, int count, char *text);



// Creates a new pokenode struct and returns a pointer to it.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    pokedex->head = NULL;
    pokedex->num_pokemon = 0;

    

    return pokedex;
}

// Create a new pokenode struct and returns a pointer to it.

static struct pokenode *new_pokenode(Pokemon pokemon) {

    struct pokenode *add = malloc(sizeof(struct pokenode));
    if (add == NULL) {
        printf("memory is not malloced\n");
        exit(1);
    }
    //reset for every pokenode.
    add->pokemon = pokemon;
    add->next = NULL;
    add->foundstate = FALSE;
    add->current_select = FALSE;
    add->evolution = NULL;
    
    

    return add;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    
    
    struct pokenode *new = pokedex->head;
    
    //if there is no pokenode in this pokedex,
    //sub this pokenode as the first one in the whole list.
    if (new == NULL) {
        new = new_pokenode(pokemon);  
        pokedex->head = new;
        new->current_select = TRUE;
        pokedex->num_pokemon++;
     
    } else {
        //if there are pokenodes in this list, we need iterate the list 
        //to find the last one,
        //then add the pokenode at the last position. 
        while (new->next != NULL) {
            new = new->next;
        }
        
        //if the pokedex we input has been in the list, 
        //we do nothing and exit.
        if (check_repeat_input(pokemon, pokedex) == FALSE) {
            
            printf("an appropriate repeated input error\n");
            exit(1);
        } else {
            new->next = new_pokenode(pokemon);
            pokedex->num_pokemon++;
            
        }
    }
}


// Print out the details of the currently selected Pokemon.
void detail_pokemon(Pokedex pokedex) {
    struct  pokenode *node = pokedex->head;
    //in this part, if the list is empty, we do nothing.
    //and we need consider maybe the pokenode has not been found,
    //if it has been found, we print out the whole information of it,
    //if not, we only print few stars to cover the truly information.
    while (node != NULL) {
        if (node->current_select == TRUE) {
            if (node->foundstate == TRUE) {
                pokemon_seen_output (node);
            } else {
                pokemon_noseen_output (node);    
            }
                
        }
        node = node->next;
    }
    
    
}


// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    //if the pokedex is empty, we do nothing.
    if (pokedex->head == NULL) {
        printf("there is no current pokemon as Pokedex is empty\n");
        return NULL;        
    } 
    struct pokenode *current = pokedex->head;
    //iterate the whole list until we got the pokenode, 
    //which has been selected.
    while (current->current_select != TRUE) {
        current = current->next;
    }
    return (current->pokemon);
}


// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    //iterate the whole list, change the foundstate
    //into TRUE, if it has been set as current select.
    struct  pokenode *node = pokedex->head;
    while (node != NULL) {
        if (node->current_select == TRUE) {
            node->foundstate = TRUE;       
        }
        node = node->next;
    }
    
}


// Print out all of the Pokemon in the Pokedex.
void print_pokemon(Pokedex pokedex) {
    //iterate the whole list
    //then, print out the information one by one.
    struct pokenode *pokenode = pokedex->head;
    while (pokenode != NULL) {
        print_pokemon_name_vertical (pokedex, pokenode);
        pokenode = pokenode->next;
    }
}


//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    //if the pokedex is empty, we do nothing.
    if (node == NULL) {
    
    } else {
        //iterate the whole list until we found the current_select node.
        //then, modify its current_select status.
        //then, change the node into next one,
        //and change its current_select status.
        while (node->next != NULL && node->current_select != TRUE) {
            
            node = node->next;
        }
        if (node->next != NULL) {
            node->current_select = FALSE;
            node->next->current_select = TRUE;
        }
    }
}


// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    //if the pokedex is empty, we do nothing.
    if (node == NULL) {
    
    } else {
        //iterate the whole list until we found the current_select node.
        //then, modify its current_select status.
        //then, change the node into previous one,
        //and change its current_select status.
        
        while (node->next != NULL) {
            if (node->next->current_select == TRUE) {
                node->next->current_select = FALSE;
                node->current_select = TRUE;
            }
            node = node->next;    
        }
    }
}


// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *node = pokedex->head;
    int count = FALSE;
    //firstly, we need check if the ID is in this list.
    //if not, we do nothing.
    while (node != NULL) {
        if (pokemon_id(node->pokemon) == id) {
            count = TRUE;
        }
        node = node->next; 
    }
    
    node = pokedex->head;
    
    //then, we need iterate the whole list,
    //to find the the pokemon with this id, chage its
    //current_select status
    //then find the old one, change its status.
    while (node != NULL && count == TRUE) {
        if (pokemon_id(node->pokemon) == id) {
            node->current_select = TRUE;
        }
        
        if (pokemon_id(node->pokemon) != id 
        && node->current_select == TRUE) {
            node->current_select = FALSE;
        }
        node = node->next; 
    }
     
}


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    struct pokenode *before = NULL;
       
    //firstly, considering the the pokenode 
    //only has no or only one pokemon.  
    if (node != NULL && node->next == NULL) {
        destroy_pokemon(node->pokemon);
        free(node);
        pokedex->head = NULL;
        pokedex->num_pokemon = 0;    
    } else {
        //if the pokenode has one more pokemon,
        //we need iterate the whole list to find the node which we need use,
        //meanwhile, copy the previous one and next one.
        //then connect each other, and free the useless pokenode
        //and its pokemon. 
        while (node != NULL && node->current_select != TRUE) {
            before = node;
            node = node->next;
        } 
            
         
        if (node != NULL && before == NULL) {
            node->next->current_select = TRUE;
            pokedex->head = node->next;
            destroy_pokemon(node->pokemon);
            free(node);
            pokedex->num_pokemon --;
        } else if (node != NULL) {
            before->next = node->next;
            if (node->next != NULL) {
                node->next->current_select = TRUE;
            } else {
                before->current_select = TRUE;
            }
            
            destroy_pokemon(node->pokemon);
            free(node);
            pokedex->num_pokemon --;
        }  
                
        
    }    
}      
    
    
// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *temp =NULL;
    //in order to free the whole pokedex,
    //we need destroy the pokenode one by one, 
    //and its pokemon information.
    while (pokedex->head != NULL) {
        temp = pokedex->head;
        pokedex->head = pokedex->head->next;
        destroy_pokemon(temp->pokemon);
        free(temp);
    }
    free(pokedex);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
void show_types(Pokedex pokedex) {
    //firstly, we creat a new array which be used for copy the types
    //we need iterate the whole list, then check the pokenode one by one
    //then use the fuction [copy_type_into_string]:
    //If the type IS not in the array, it would be add into it
    //if not, skept it.
    //then use the fuction to print out all the types in the array.
    int array[TOTAL_NUM_TYPES] = {'\0'};  
    struct pokenode *node = pokedex->head;
    while (node != NULL) {
        copy_type_into_string(array, node);
        node = node->next;
    }   
    print_Out_TotalTYPE(array);
    
}


// Set the first not-yet-found Pokemon of each type to be found.
void go_exploring(Pokedex pokedex) {
    ////firstly, we creat a new array which be used for recording pokenodes
    //we need iterate the whole list, then check the pokenode one by one
    //if the pokemon has not been found, 
    //then we use the fuction :[test_first_type]
    //to check and record its type and change its foundstatus.
    //if the type is not in the array, we change its status 
    //and add its type in the array. 
    int array[TOTAL_NUM_TYPES] = {'\0'};  
    struct pokenode *node = pokedex->head;
    while (node != NULL) {
        if (node->foundstate == FALSE) {
        
            test_first_type(array, node);
        }
        node = node->next;
    }       
}


// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    //take out the number of pokemon
    //which has been recorded while adding and remove pokemon.
    return pokedex->num_pokemon;
}


// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    int count = 0;
    //iterate the whole to find out the pokemon which has been found
    // and record the sum.
    while (node != NULL) {
        if (node->foundstate == TRUE) {
            count++;
        }
        node = node->next;
    }
    return count;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    //firtly we need avoid the situation, if the frome id is 
    //as same as to id.
    if (from_id == to_id ) {
        printf("input repeat, appropriate error\n");
        exit(1);
    }
    //the we need check if the fromid and toid 
    //are real exist in our list.
    //if not we exist the program.    
    struct pokenode *from_node =  search_id (pokedex, from_id);
    struct pokenode *to_node =  search_id (pokedex, to_id);
    
    if (from_node == NULL || to_node == NULL) {
        printf("NO ID can be found, appropriate error\n");
        exit(1); 
    
    
    } else {
        //if yes we add its next evolution
        from_node->evolution = to_node;
    
    }
    
}


// Show the evolutions of the currently selected Pokemon.
void show_evolutions(Pokedex pokedex) {
    //firstly, use get_select 
    //to find out the current select pokemon
    //then if the current_select node has next evolution
    //use printEVO to print its evolution.
    //then change the node to its evolution node.
    //then print the new pokemon's evolution.
    //and repeat it until no evolution.
    if (pokedex->head != NULL) {
        struct pokenode *node = get_select(pokedex);
        while (node->evolution != NULL) {
            printEVO (node);
            printf(" --> ");
            node = node->evolution;
            
        }
        printEVO (node);
        printf("\n");
    }
}


// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    //if there is no pokenode in pokedex, we return DNE.
    if (pokedex->head == NULL) {
        return DOES_NOT_EVOLVE;
    }
    //then, use get_select 
    //to find out the current select pokemon
    struct pokenode *node = get_select(pokedex);
    int pokemonID = 0;
    //if the current_select pokemon has no evolution
    //return DNE
    //if yes, return out its evolution's id.
    if (node->evolution == NULL) {
        pokemonID = DOES_NOT_EVOLVE;
    } else {
        node = node->evolution;
        pokemonID = pokemon_id(node->pokemon);
    }
    return pokemonID;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                        //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    //firstly, we need check it is not the special TYPE,
    //if yes, we exit the program.
    if (type == NONE_TYPE || type == INVALID_TYPE 
    || type == MAX_TYPE) {
        printf("invalid type, appropriate error\n");
        exit(1);
    }
    //then we creat a new pokedex.
    Pokedex newdex = new_pokedex();
    
    int has_same = FALSE;
    //the we use [compare] fuction to compare each pokemon.
    //if there is a type of pokenode is as same as the type wich is given
    //we copy this pokemon and its pokenode into new pokedex.
    
    struct pokenode *node = pokedex->head;
    while (node != NULL) {
        
        if (compare(node, type) == TRUE 
        && node->foundstate == TRUE) {
            has_same = TRUE;
            add_in_new_pokedex(newdex, node);
        
        } 
            
        node = node->next;
    }
    //if there is no pokemon's type is same as the type which is given
    //given out a NULL;
    if (has_same != TRUE) {
        newdex = NULL;
    }
    return newdex;
}


// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    //firstly, we need creat a new pokedex.
    Pokedex newdex = new_pokedex();
    
    //then iterate the whole list to find out the pokemon
    //which has been setted as found.
    //and copy it into new pokedex.
    struct pokenode *node = pokedex->head;
    while (node != NULL) {
        
        if (node->foundstate == TRUE) {
            
            add_in_new_pokedex(newdex, node);
        }     
        node = node->next;
    }
    //then iterate the new pokedex list
    //check the pokemon one by one
    //firstly set it be found
    //then check it from the whole list to find its right order. 
    struct pokenode *ordernode = newdex->head;
    while (ordernode != NULL) {
        ordernode->foundstate = TRUE;
        order_pokenode(newdex, ordernode);
        ordernode = ordernode->next;
    }
   
    
    return newdex;
    
}


// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    //firstly create a new pokedex 
    Pokedex newdex = new_pokedex();
    

    struct pokenode *node = pokedex->head;
    while (node != NULL) {
         
        //iterate the whole list, to find out
        //the pokemon which has been found 
        //and name is as similary as the text given.
        //if yes, we copy this pokenode into the new pokedex 
        if (searchAndCompare (text, node) == TRUE 
        && node->foundstate == TRUE) {
            
            add_in_new_pokedex(newdex, node);
        
        } 
            
        node = node->next;
    }
    
    return newdex;
      
}


//////////////////////////////////////////////////////////////////////
//                         MY FUCTION                               //
//////////////////////////////////////////////////////////////////////

//////////         stage 1  fuction      ////////////

//the fuction used to check if the the pokemon we have added before.
//if have, return FALSE,
//if haven't, return TRUE.   
static int check_repeat_input(Pokemon pokemon, Pokedex pokedex) {
    int count = TRUE;
    struct pokenode *compare = pokedex->head; 
    while (compare != NULL) {
        if (pokemon_id (compare->pokemon) == pokemon_id (pokemon)) {
            count = FALSE;
        }
        compare = compare->next;
    }
    return count;
}


//the function to print out the pokemon detail 
//which have not been found.
static void pokemon_noseen_output (struct pokenode *node) {
    
    printf ("ID: %03d\n", pokemon_id(node->pokemon));
    printf("Name: ");
    star_name (pokemon_name(node->pokemon));
    printf("Height: --\n");
    printf("Weight: --\n");
    printf("Type: --\n");

}


//the fuction to print out the pokemon detail 
//which has been found
static void pokemon_seen_output (struct pokenode *pokenode) {
   
    printf ("ID: %03d\n", pokemon_id(pokenode->pokemon));
    printf("Name: %s\n", pokemon_name(pokenode->pokemon));
    printf("Height: %0.1lfm\n", pokemon_height(pokenode->pokemon));
    printf("Weight: %0.1lfkg\n", pokemon_weight(pokenode->pokemon));
    printf("Type: %s", pokemon_type_to_string
    (pokemon_first_type(pokenode->pokemon)));
    
    if (pokemon_second_type(pokenode->pokemon) != NONE_TYPE) {
        printf(" %s", pokemon_type_to_string
        (pokemon_second_type(pokenode->pokemon)));
    }
    printf("\n");
}


//the fuction to print out the star name if it has not been found.
static void star_name(const char *name) {
    int count = 0;

    while (name[count] != '\0') {
        printf("*");
        count ++;
    }
    printf("\n");
}


//the fuction used help fuction [print_pokemon], to print out
//the name of pokemon,
//if the the pokemon has been found, print out the whole name
//if not, print out the stars hided name.  
static void print_pokemon_name_vertical 
(Pokedex pokedex, struct pokenode *pokenode) {
    print_arrow (pokenode);
    
    printf("#%03d: ", pokemon_id(pokenode->pokemon));
    
    if (pokenode->foundstate == TRUE) {
        printf("%s\n", pokemon_name(pokenode->pokemon));
    } else {
        star_name (pokemon_name(pokenode->pokemon));   
    }

}


//the fuction to print the arrow before each name.
static void print_arrow (struct pokenode *pokenode) {
    if (pokenode->current_select ==TRUE) {
        printf("--> ");
            
    } else {
        printf("    ");
    }
        
}

//////////         stage 2  fuction      ////////////


static struct pokenode *search_id (Pokedex pokedex, int id) {
    struct pokenode *node = pokedex->head;
    struct pokenode *temp_node = NULL;
    while (node != NULL) {
        if (pokemon_id(node->pokemon) == id) {
            temp_node = node;
        }
        node = node->next;
    }

    return temp_node;
}
static struct pokenode *get_select(Pokedex pokedex) {
    struct pokenode *node = pokedex->head;
    struct pokenode *selectnode = NULL;
    while (node != NULL) {
        if (node->current_select == TRUE) {
            selectnode = node;
        
        }
    
        node = node->next;
    }

    return selectnode;
}

static void copy_type_into_string(int *array, struct pokenode *node) {
    int type1 = pokemon_first_type(node->pokemon);
    int temp = 0; 
    int test = TRUE;
    while (array[temp] != '\0') {
        if (type1 == array[temp]) {
            test = FALSE;
        }
        temp++;
    }
    if (test == TRUE) {
        array[temp] = type1;
    }
    int type2 = pokemon_second_type(node->pokemon);
    temp = 0; 
    test = TRUE;
    while (array[temp] != '\0') {
        if (type2 == array[temp]) {
            test = FALSE;
        }
        temp++;
    }
    if (test == TRUE) {
        array[temp] = type2;
    }
    

}

static void print_Out_TotalTYPE (int *array) {
    int temp = 0;
    while (array[temp] != '\0') {
        if (array[temp] != NONE_TYPE) {
            printf("%s\n", pokemon_type_to_string(array[temp]));
        
        }
        temp++;
    }

}
static void test_first_type (int *array, struct pokenode *node){
    
    int type1 = pokemon_first_type(node->pokemon);
    int temp = 0; 
    int test = TRUE;
    while (array[temp] != '\0') {
        if (type1 == array[temp]) {
            test = FALSE;
        }
        temp++;
    }
    if (test == TRUE) {
        node->foundstate = TRUE;
        array[temp] = type1;
    }
    int type2 = pokemon_second_type(node->pokemon);
    if (type2 != NONE_TYPE) { 
        temp = 0; 
        test = TRUE;
        while (array[temp] != '\0') {
            if (type2 == array[temp]) {
                test = FALSE;
            }
            temp++;
        }
        if (test == TRUE) {
            node->foundstate = TRUE;
            array[temp] = type2;
        }
    }



}
static void printEVO (struct pokenode *pokenode) {
    printf ("#%03d ", pokemon_id(pokenode->pokemon));
    if (pokenode->foundstate == TRUE) {
        printf("%s ", pokemon_name(pokenode->pokemon));
        printf("[%s", pokemon_type_to_string
    (pokemon_first_type(pokenode->pokemon)));
    
        if (pokemon_second_type(pokenode->pokemon) != NONE_TYPE) {
            printf(", %s", pokemon_type_to_string
            (pokemon_second_type(pokenode->pokemon)));
        }
        printf("]");
    
    } else {
        printf ("???? [????]");
    
    
    }

}
static void add_in_new_pokedex (Pokedex pokedex, struct pokenode *node) {
    struct pokenode *new = pokedex->head;
    if (new == NULL) {
        new = new_pokenode(clone_pokemon(node->pokemon));  
        pokedex->head = new;
        pokedex->head->current_select = TRUE;
        pokedex->num_pokemon++;
        pokedex->head->foundstate = TRUE;
     
    } else {
        while (new->next != NULL) {
            new = new->next;
        }
        new->next = new_pokenode(clone_pokemon(node->pokemon));
        new = new->next;
        pokedex->num_pokemon++;
        new->current_select = FALSE;
        new->foundstate = TRUE; 
    }
 

}

static int compare(struct pokenode *node, pokemon_type type) {
    int count = FALSE;
    if (pokemon_first_type(node->pokemon) == type 
    || pokemon_second_type(node->pokemon) == type) {
        count = TRUE;
    }
    return count;
}
static void order_pokenode(Pokedex pokedex, struct pokenode *node) {
    struct pokenode *compare_node = pokedex->head;
    Pokemon temp = NULL;
    while (compare_node != NULL) {
        if (pokemon_id(node->pokemon) 
        < pokemon_id(compare_node->pokemon)) {
            temp = node->pokemon;
            node->pokemon = compare_node->pokemon;
            compare_node->pokemon = temp;
            
        }
        compare_node = compare_node->next;
    }

}


//the fuction used to check if the poke mon
static int searchAndCompare (char *text, struct pokenode *node) {
    char *new_text = text;
    char *new_name = pokemon_name(node->pokemon);
    
    int test = FALSE;
    int temp = 0;
    int count = 0;
    //iterate the whole loop, if the   
    while (new_name[temp] != '\0' && test == FALSE) {
        if ((new_name[temp] == new_text[0])
        || (new_name[temp] == new_text[0] + ('a' - 'A'))
        || (new_name[temp] == new_text[0] - ('a' - 'A'))) {
            
            count = temp;
            test = if_text_in_name(new_name, count, new_text);
        }    
        temp++;
    }
    
    
    return test;
}

static int if_text_in_name (char *new_name, int count, char *new_text) {
    int i = 0;
    int test = TRUE;
    while (new_text[i] != '\0') {
        if ((new_text[i] == new_name[count])
        || (new_text[i] == new_name[count] + ('a' - 'A'))
        || (new_text[i] == new_name[count] - ('a' - 'A'))) {
        } else {   
            test = FALSE;
        }
        i++;
        count++;
    }   
    return test; 
           
}
