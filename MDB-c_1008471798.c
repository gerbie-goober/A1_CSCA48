/*
 *  CSC A48 - Winter 2022 - Assignment 1 starter
 * 
 *  (c) 2020-22 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Wu, Matthew):
 * Student Number: 10008471798
 * UTORid: wumatth8
 * Your instructor's name is: Marcelo Ponce Castro
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Matthew Wu
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
    char name[MAX_STR_LEN];
    float salary;
    struct castList_struct *next;
} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList *cast;
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;
    
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  cast = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node = NULL;
    new_node = (ReviewNode *)calloc(1, sizeof(ReviewNode));
    if(new_node == NULL){
        return NULL;
    }
    strcpy(new_node->review.movie_title, "");
    strcpy(new_node->review.movie_studio, "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->review.cast = NULL;
    new_node->next = NULL;
    return new_node;    
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *ptr = head;
    while(ptr != NULL){
        if(!(strcmp(ptr->review.movie_title, title)) && !(strcmp(ptr->review.movie_studio, studio)) && ptr->review.year == year){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;  
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data needs to fill-in the review,
     * as well as a pointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *new_node = NULL;
    if (findMovieReview(title, studio, year, head) == NULL){
        new_node = newMovieReviewNode();
        if(new_node != NULL){
            strcpy(new_node->review.movie_title, title);
            strcpy(new_node->review.movie_studio, studio);
            new_node->review.year = year;
            new_node->review.BO_total = BO_total;
            new_node->review.score = score;
            new_node->next = head;
            return new_node;
        }
    }
    printf("The movie is already in the database.");
    return head;
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    ReviewNode *p = head;
    int length = 0;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = findMovieReview(title, studio, year, head);
    if(p != NULL){
        p->review.BO_total = BO_total;
        p->review.score = score;
    }
    else{
        printf("Sorry, no such movie exists in the database.");
    }
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = findMovieReview(title, studio, year, head);
    ReviewNode *ptr = head;
    if(p != NULL && head != NULL){
        while((ptr->next) != NULL){
            if((ptr->next) == p){
                ptr->next = (ptr->next)->next;
                free(ptr->next);
                return head;
            }
            ptr = ptr->next;
        }
    }
    if(head == p){
        if(head->next == NULL){
            free(head);
            return NULL;
        }
        ReviewNode *temp = head->next;
        free(head);
        return temp;
    }
    return head;
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p = head;
    float movie_BO_sum = 0.0;
    while(p != NULL){
        printf("%s\n", p->review.movie_title);
        printf("%s\n", p->review.movie_studio);
        printf("%d\n", p->review.year);
        printf("%f\n", p->review.BO_total);
        printf("%d\n", p->review.score);
        printf("*******************\n");
        movie_BO_sum += p->review.BO_total;
        p = p->next;
    }    
    return movie_BO_sum;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    ReviewNode *p = head;
    float movie_BO_sum = 0.0;
    while(p != NULL){
        if(strcmp(p->review.movie_studio, studio) == 0){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");
            movie_BO_sum += p->review.BO_total;
        }
        p = p->next;
    }    
    return movie_BO_sum;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    ReviewNode *p = head;
    float movie_BO_sum = 0.0;
    while(p != NULL){
        if(p->review.score >= min_score){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n"); 
            movie_BO_sum += p->review.BO_total;
        }
        p = p->next;
    }    
    return movie_BO_sum;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    
    ReviewNode *p = NULL;
    ReviewNode *q = NULL;
    p = head;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
    return NULL;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

const char *find_smallest(ReviewNode *head, char smallest[MAX_STR_LEN]){
    ReviewNode *p = head;
    if(head != NULL){
        while(p != NULL){
            if(strcmp(smallest, p->review.movie_title) >= 0){
                strcpy(smallest, p->review.movie_title);
            }
            p = p->next;
        }
        return smallest;
    }
    return NULL;
}

ReviewNode *add_smallest(char smallest[MAX_STR_LEN], ReviewNode *new_head, ReviewNode *head){
    ReviewNode *new_node = new_head;
    ReviewNode *node = head;
    while(node != NULL){
        if(strcmp(node->review.movie_title, smallest) == 0){
            while(new_node != NULL){
                new_node = new_node->next;
            }
            new_node = (ReviewNode *)calloc(1, sizeof(ReviewNode));
            if(new_node != NULL){
                new_node = node;
                new_node->next = NULL;
                return deleteMovieReview(node->review.movie_title, node->review.movie_studio, node->review.year, head);
            }
        }
        node = node->next;
    }
    return NULL;
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    char smallest[MAX_STR_LEN] = "z";
    ReviewNode *new_head = NULL;
    while(head != NULL){
        strcpy(smallest, find_smallest(head, smallest));
        head = add_smallest(smallest, new_head, head);
    }
    return new_head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    ReviewNode *movie = findMovieReview(title, studio, year, head);
    if(movie != NULL){
        //temp = movie->review.cast;
        if(movie->review.cast != NULL){
            while(movie->review.cast != NULL){
                if(movie->review.cast->next != NULL && movie->review.cast->salary < salary && movie->review.cast->next->salary > salary){
                    CastList *temp = movie->review.cast->next;
                    movie->review.cast->next = (CastList *)calloc(1, sizeof(CastList));
                    if(movie->review.cast != NULL){
                        strcpy(movie->review.cast->next->name, name);
                        movie->review.cast->next->salary = salary;
                        movie->review.cast->next->next = temp;
                    }
                }
                else{
                    if(movie->review.cast->salary > salary){
                        movie->review.cast->next = (CastList *)calloc(1, sizeof(CastList));
                        if(movie->review.cast != NULL){
                            strcpy(movie->review.cast->next->name, name);
                            movie->review.cast->next->salary = salary;
                        }
                        break;
                    }
                    else{
                        movie->review.cast->next = movie->review.cast;
                        movie->review.cast = (CastList *)calloc(1, sizeof(CastList));
                        if(movie->review.cast != NULL){
                            strcpy(movie->review.cast->name, name);
                            movie->review.cast->salary = salary;
                        }
                        break;
                    }
                }
                movie->review.cast = movie->review.cast->next;
            }
        }
        movie->review.cast = (CastList *)calloc(1, sizeof(CastList));
        if(movie->review.cast != NULL){
            strcpy(movie->review.cast->name, name);
            movie->review.cast->salary = salary;
        }
    }
}

typedef struct starInMoviesList_struct
{    
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;  
    float earnings;
    struct starInMoviesList_struct *next;
} StarInMoviesList;

typedef struct earningsList_struct
{    
    char name[MAX_STR_LEN];
    StarInMoviesList *movies;
    float avg_earnings;
    struct earningsList_struct *next;
} EarningsList;

EarningsList *newEarningsListNode(char name[MAX_STR_LEN])
{
    EarningsList *new_node = NULL;
    new_node = (EarningsList *)calloc(1, sizeof(EarningsList));
    if(new_node == NULL){
        return NULL;
    }
    strcpy(new_node->name, name);
    new_node->movies = NULL;
    new_node->avg_earnings = 0.0;
    new_node->next = NULL;
    return new_node;    
}

StarInMoviesList *add_movie(StarInMoviesList *movies, char movie_title[MAX_STR_LEN], char movie_studio[MAX_STR_LEN], int year){
    StarInMoviesList *temp = movies;
    while(temp != NULL){
        temp = temp->next;
    }
    strcpy(temp->movie_title, movie_title);
    strcpy(temp->movie_studio, movie_studio);
    temp->year = year;
    return movies;
}

EarningsList *find_actor(EarningsList *actors, char name[MAX_STR_LEN]){
    EarningsList *p = actors;
    //printf("%s", p->name);
    while(p != NULL){
        if(strcmp(p->name, name) == 0){
            printf("1");
            return actors;
        }
        p = p->next;
    } 
    return NULL;
}

EarningsList *add_actor(EarningsList *actors, char name[MAX_STR_LEN], char movie_title[MAX_STR_LEN], char movie_studio[MAX_STR_LEN], int year){
    EarningsList *p = actors;
    printf("start");
    if(p == NULL){
        printf("0");
        return newEarningsListNode(name);
    }
    if(find_actor(actors, name) == NULL){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newEarningsListNode(name);
    }
    printf("1");
    find_actor(actors, name)->movies = add_movie(find_actor(actors, name)->movies, movie_title, movie_studio, year);
    //printf("%s", find_actor(actors,name)->name);
    return actors;
}

EarningsList *add_actor_info(EarningsList *actors, ReviewNode *node){
    ReviewNode *p = node;
    while(p != NULL){
        CastList *temp = (p->review.cast);
        while(temp != NULL){
            actors = add_actor(actors, temp->name, p->review.movie_title, p->review.movie_studio, p->review.year);
            printf("1");
            printf("%s", temp->name);
            temp = temp->next;
        }
        
        p = p->next;
    }
    return actors;
}

EarningsList *calculate_earnings(EarningsList *actor, ReviewNode *node){
    EarningsList *p = actor;
    while(p != NULL){
        StarInMoviesList *temp1 = actor->movies;
        while(temp1 != NULL){
            ReviewNode *node = findMovieReview(temp1->movie_title, temp1->movie_studio, temp1->year, node);
            //printf("1");
            temp1->earnings = node->review.BO_total;
            CastList *temp2 = node->review.cast;
            while(temp2 != NULL){
                temp1->earnings = temp1->earnings - temp2->salary;
                temp2 = temp2 -> next;
            }
            temp1 = temp1->next;
        }
        p = p->next;
    }
    return actor;
}

EarningsList *calculate_avg(EarningsList *head){
    EarningsList *p = head;
    float avg;
    int counter;
    while(p != NULL){
        avg = 0.0;
        counter = 0;
        StarInMoviesList *temp = p->movies;
        while(temp != NULL){
            avg += temp->earnings;
            counter++;
            temp = temp->next;
        }
        p->avg_earnings = avg / counter;
        p = p->next;
    }
    return head;
}

EarningsList *find_highest(EarningsList *head){
    EarningsList *p = head;
    EarningsList *winner = NULL;
    float highest = 0.0;
    while(p != NULL){
        if(p->avg_earnings > highest){
            highest = p->avg_earnings;
            winner = p;
        }
        printf("%s", p->name);
        p = p->next;
    }
    return winner;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    EarningsList *earnings = NULL;
    EarningsList *winner = NULL;
    //printf("1");
    earnings = add_actor_info(earnings, head);
    //printf("1");
    earnings = calculate_earnings(earnings, head);
    printf("hit earnings");
    earnings = calculate_avg(earnings);
    printf("hit calc");
    winner = find_highest(earnings);
    printf("hit highest");
    printf("%s\n", winner->name);
    printf("%f\n", winner->avg_earnings);
            
}

void printNames(ReviewNode *movie){
    CastList *p;
    if(movie == NULL || movie->review.cast == NULL) return;
    p = movie->review.cast;
    printf("The cast for this movie are:\n");
    while(p != NULL){
        printf("Cast member: %s, Salary: %f\n", p->name, p->salary);
        p = p->next;
    }
}