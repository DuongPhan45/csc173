#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dfa.h"

//  DFA that recognizes exactly "Turing"
void dfa_turing()
{
    DFA turing = new_DFA(6);

    DFA_set_transition_all(turing, 0, -1);
    DFA_set_transition_all(turing, 1, -1);
    DFA_set_transition_all(turing, 2, -1);
    DFA_set_transition_all(turing, 3, -1);
    DFA_set_transition_all(turing, 4, -1);
    DFA_set_transition_all(turing, 5, -1);
    DFA_set_transition_all(turing, 6, -1);

    // Set accepting state to 6
    DFA_set_accepting(turing, 6, true);

    // Set the transitions
    DFA_set_transition(turing, 0, 'T', 1);
    DFA_set_transition(turing, 1, 'u', 2);
    DFA_set_transition(turing, 2, 'r', 3);
    DFA_set_transition(turing, 3, 'i', 4);
    DFA_set_transition(turing, 4, 'n', 5);
    DFA_set_transition(turing, 5, 'g', 6);

    DFA_print(turing);
}

// DFA that recognizes any string that starts with four 4's
void dfa_four_4()
{
    DFA four_4 = new_DFA(4);

    DFA_set_transition_all(four_4, 0, -1);
    DFA_set_transition_all(four_4, 1, -1);
    DFA_set_transition_all(four_4, 2, -1);
    DFA_set_transition_all(four_4, 3, -1);
    DFA_set_transition_all(four_4, 4, 4);

    // Set accepting state 
    DFA_set_accepting(four_4, 4, true);

    // Set the transitions
    DFA_set_transition(four_4, 0, '4', 1);
    DFA_set_transition(four_4, 1, '4', 2);
    DFA_set_transition(four_4, 2, '4', 3);
    DFA_set_transition(four_4, 3, '4', 4);

    DFA_print(four_4);
}

// DFA that recognizes binary input with an odd number of 1's
void dfa_odd_1()
{
    DFA odd_1 = new_DFA(2);

    DFA_set_transition_all(odd_1, 0, -1);
    DFA_set_transition_all(odd_1, 1, -1);

    // Set accepting state
    DFA_set_accepting(odd_1, 1, true);

    // Set the transitions
    DFA_set_transition(odd_1, 0, '0', 0);
    DFA_set_transition(odd_1, 1, '1', 0);
    DFA_set_transition(odd_1, 0, '1', 1);
    DFA_set_transition(odd_1, 1, '0', 1);

    DFA_print(odd_1);
}

// DFA that recognizes binary input with an even number of 0's and an odd number of 1's
void dfa_even_odd()
{
    DFA even_odd = new_DFA(4);

    DFA_set_transition_all(even_odd, 0, -1);
    DFA_set_transition_all(even_odd, 1, -1);
    DFA_set_transition_all(even_odd, 2, -1);
    DFA_set_transition_all(even_odd, 3, -1);
    DFA_set_transition_all(even_odd, 4, 4);

    // Set accepting state 
    DFA_set_accepting(even_odd, 1, true);

    // Set the transitions
    DFA_set_transition(even_odd, 0, '1', 1);
    DFA_set_transition(even_odd, 1, '1', 0);
    DFA_set_transition(even_odd, 2, '1', 3);
    DFA_set_transition(even_odd, 3, '1', 2);
    DFA_set_transition(even_odd, 0, '0', 3);
    DFA_set_transition(even_odd, 1, '0', 2);
    DFA_set_transition(even_odd, 2, '0', 1);
    DFA_set_transition(even_odd, 3, '0', 0);

    DFA_print(even_odd);
}

// DFA that recognizes exactly "cat"
void dfa_cat()
{
    DFA cat = new_DFA(3);

    DFA_set_transition_all(cat, 0, -1);
    DFA_set_transition_all(cat, 1, -1);
    DFA_set_transition_all(cat, 2, -1);
    DFA_set_transition_all(cat, 3, -1);

    // Set accepting state to 6
    DFA_set_accepting(cat, 3, true);

    // Set the transitions
    DFA_set_transition(cat, 0, 'c', 1);
    DFA_set_transition(cat, 1, 'a', 2);
    DFA_set_transition(cat, 2, 't', 3);


    DFA_print(cat);
}

int main()
{

// Section 1

    // printf("Testing DFA that recognizes exactly \"Turing\"\n");
    // dfa_turing();

    // printf("Testing DFA that recognizes any string that starts with four 4's\n");
    // dfa_four_4();

    // printf("Testing DFA that recognizes binary input with an odd number of 1's\n");
    // dfa_odd_1();

    // printf("Testing DFA that recognizes binary input with an even number of 0's and an odd number of 1's\n");
    // dfa_even_odd();

    // printf("Testing DFA that recognizes exactly \"cat\"\n");
    // dfa_cat();
}