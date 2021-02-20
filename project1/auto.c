#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"
#include "nfa.h"
#include "IntHashSet.h"

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
    DFA_free(odd_1);
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
    DFA_free(even_odd);
}

// DFA that recognizes exactly "cat"
void dfa_cat()
{
    DFA cat = new_DFA(3);

    DFA_set_transition_all(cat, 0, -1);
    DFA_set_transition_all(cat, 1, -1);
    DFA_set_transition_all(cat, 2, -1);
    DFA_set_transition_all(cat, 3, -1);

    // Set accepting state to
    DFA_set_accepting(cat, 3, true);

    // Set the transitions
    DFA_set_transition(cat, 0, 'c', 1);
    DFA_set_transition(cat, 1, 'a', 2);
    DFA_set_transition(cat, 2, 't', 3);

    DFA_print(cat);
    DFA_free(cat);
}

//  DFA that recognizes strings ending in "back"
NFA nfa_back_end()
{
    NFA back = new_NFA(4);

    // Set accepting state to
    NFA_set_accepting(back, 4, true);

    // Set the transitions
    NFA_add_transition_all(back, 0, 0);
    NFA_add_transition_str(back, 1, "bck", 0);
    NFA_add_transition_str(back, 2, "bak", 0);
    NFA_add_transition_str(back, 3, "bac", 0);

    NFA_add_transition(back, 0, 'b', 1);
    NFA_add_transition(back, 1, 'a', 2);
    NFA_add_transition(back, 2, 'c', 3);
    NFA_add_transition(back, 3, 'k', 4);

    NFA_print(back);
    NFA_free(back);
    return back;
}

//  DFA that recognizes strings containing "back"
NFA nfa_back_contain()
{
    NFA back = new_NFA(4);

    // Set accepting state
    NFA_set_accepting(back, 4, true);

    // Set the transitions
    NFA_add_transition_all(back, 0, 0);
    NFA_add_transition_all(back, 4, 4);
    NFA_add_transition_str(back, 1, "bck", 0);
    NFA_add_transition_str(back, 2, "bak", 0);
    NFA_add_transition_str(back, 3, "bac", 0);

    NFA_add_transition(back, 0, 'b', 1);
    NFA_add_transition(back, 1, 'a', 2);
    NFA_add_transition(back, 2, 'c', 3);
    NFA_add_transition(back, 3, 'k', 4);

    NFA_print(back);
    NFA_free(back);
    return back;
}

// NFA that recognize string not a partial anagram of "washington"
void nfa_washington()
{
    NFA washington = new_NFA(19);

    NFA_set_accepting(washington, 2, true);
    NFA_set_accepting(washington, 4, true);
    NFA_set_accepting(washington, 6, true);
    NFA_set_accepting(washington, 8, true);
    NFA_set_accepting(washington, 10, true);
    NFA_set_accepting(washington, 12, true);
    NFA_set_accepting(washington, 14, true);
    NFA_set_accepting(washington, 16, true);
    NFA_set_accepting(washington, 19, true);

    NFA_add_transition_all(washington, 0, 0);
    NFA_add_transition_all(washington, 1, 1);
    NFA_add_transition_all(washington, 3, 3);
    NFA_add_transition_all(washington, 5, 5);
    NFA_add_transition_all(washington, 7, 7);
    NFA_add_transition_all(washington, 9, 9);
    NFA_add_transition_all(washington, 11, 10);
    NFA_add_transition_all(washington, 13, 13);
    NFA_add_transition_all(washington, 15, 15);
    NFA_add_transition_all(washington, 17, 17);
    NFA_add_transition_all(washington, 18, 18);
    NFA_add_transition_all(washington, 2, 2);
    NFA_add_transition_all(washington, 4, 4);
    NFA_add_transition_all(washington, 6, 6);
    NFA_add_transition_all(washington, 8, 8);
    NFA_add_transition_all(washington, 10, 10);
    NFA_add_transition_all(washington, 12, 12);
    NFA_add_transition_all(washington, 14, 14);
    NFA_add_transition_all(washington, 16, 16);
    NFA_add_transition_all(washington, 19, 19);

    NFA_add_transition(washington, 1, 'a', 2);
    NFA_add_transition(washington, 3, 'g', 4);
    NFA_add_transition(washington, 5, 'h', 6);
    NFA_add_transition(washington, 7, 'i', 8);
    NFA_add_transition(washington, 9, 'o', 10);
    NFA_add_transition(washington, 11, 's', 12);
    NFA_add_transition(washington, 13, 't', 14);
    NFA_add_transition(washington, 15, 'w', 16);
    NFA_add_transition(washington, 17, 'n', 18);
    NFA_add_transition(washington, 18, 'n', 19);

    NFA_add_transition(washington, 0, 'a', 1);
    NFA_add_transition(washington, 0, 'g', 3);
    NFA_add_transition(washington, 0, 'h', 5);
    NFA_add_transition(washington, 0, 'i', 7);
    NFA_add_transition(washington, 0, 'o', 9);
    NFA_add_transition(washington, 0, 's', 11);
    NFA_add_transition(washington, 0, 't', 13);
    NFA_add_transition(washington, 0, 'w', 15);
    NFA_add_transition(washington, 0, 'n', 17);

    NFA_print(washington);
    NFA_free(washington);
}

// NFA recognizes strings ending with "an" or "at"
void nfa_anat()
{
    NFA anat = new_NFA(4);

    NFA_set_accepting(anat, 2, true);
    NFA_set_accepting(anat, 4, true);

    NFA_add_transition_all(anat, 0, 0);
    NFA_add_transition(anat, 0, 'a', 1);
    NFA_add_transition(anat, 0, 'a', 3);
    NFA_add_transition(anat, 1, 'n', 2);
    NFA_add_transition(anat, 3, 't', 4);

    NFA_print(anat);
    NFA_free(anat);
}

// look for an IntHashSet in an array of IntHashSet, return the index if found, return -1 if not exist
int lookup(IntHashSet *array, int size, IntHashSet set)
{
    for (int i = 0; i <= size; i++)
    {
        if (IntHashSet_equals(set, array[i]))
            return i;
    }
    return -1;
}

DFA converter(NFA nfa)
{
    IntHashSet *possibleDfaStates = (IntHashSet *)malloc(sizeof(IntHashSet) * 100);
    int count = 1; // count the current number of states in dfa
    int **trans_table = (int **)malloc(sizeof(int *) * 100);
    int *state = (int *)calloc(100, sizeof(int)); // array showing which one is accepting state
    for (int i = 0; i < 100; i++)
    {
        trans_table[i] = (int *)calloc(128, sizeof(int));
    }

    // initialize the start state
    possibleDfaStates[0] = new_IntHashSet(1);
    IntHashSet_insert(possibleDfaStates[0], 0);

    //loop through all possible dfa states
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            IntHashSet current_state_set = possibleDfaStates[i];
            IntHashSetIterator it = IntHashSet_iterator(current_state_set);
            // create the next set of state
            IntHashSet next_state_set = new_IntHashSet(NFA_get_size(nfa));

            while (IntHashSetIterator_hasNext(it))
            {
                int current_state = IntHashSetIterator_next(it);
                // check if accepting state
                if (NFA_get_accepting(nfa, current_state))
                {
                    state[current_state] = 1;
                }
                IntHashSet_union(next_state_set, NFA_get_transitions(nfa, current_state, j));
            }

            free(it);
            
            // Push next_state_set to the array of possible state_set if it is not already in there
            int dfa_state = lookup(possibleDfaStates, count, next_state_set);
            if (dfa_state == -1)
            {
                possibleDfaStates[count] = next_state_set;
                trans_table[i][j] = count;
                count++; //increase the number of total dfa state
            }
            else
            {
                trans_table[i][j] = dfa_state;
            }
            free(next_state_set);
        }
    }
    // Create the dfa
    DFA dfa = new_DFA(count);
    for (int i = 0; i <= count; i++)
    {
        // set transitions
        for (int j = 0; j <= 128; j++)
        {
            DFA_set_transition(dfa, i, (char)j, trans_table[i][j]);
        }

        free(trans_table[i]);
        IntHashSet_free(possibleDfaStates[i]);

        // set accepting state
        if (state[i] == 1)
        {
            DFA_set_accepting(dfa, i, true);
        }
    }

    free(trans_table);
    free(possibleDfaStates);
    free(state);
  
    return dfa;
}

int main()
{

    // // Section 1

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
    // // test_iterator();

    // // Section 2

    // printf("Testing NFA that recognizes strings ending in \"back\"\n");
    // nfa_back_end();

    // printf("Testing NFA that recognizes strings containing \"back\"\n");
    // nfa_back_contain();

    // printf("Testing NFA that recognize string not a partial anagram of \"washington\" ");
    // nfa_washington();

    // printf("Testing NFA that recognizes strings ending with \"an\" or \"at\"");
    // nfa_anat();

    // Section 3

    printf("The DFA converted from an NFA that recognizes strings containing \"back\"");
    NFA backend = nfa_back_contain();
    DFA dfa = converter(backend);
    DFA_print(dfa);
    DFA_free(dfa);
    NFA_free(backend);
}
