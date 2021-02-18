#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dfa.h"

typedef struct DFA *DFA;

struct DFA
{
    int nstates;       // number of states
    int **trans_table; // transition table
    int *state;        // indicate whether a state is accepting state or not
};

/**
 * Allocate and return a new DFA containing the given number of states.
 */
DFA new_DFA(int nstates)
{
    DFA this = (DFA)malloc(sizeof(struct DFA));
    if (this == NULL)
    {
        return NULL; // Out of memory...
    }
    this->nstates = nstates;

    this->trans_table = (int **)malloc(sizeof(int *) * (nstates + 1));
    for (int i = 0; i <= nstates; i++)
    {
        this->trans_table[i] = (int *)calloc(128, sizeof(int));
    }

    this->state = (int *)calloc(nstates + 1, sizeof(int));

    return this;
};

/**
 * Free the given DFA.
 */
void DFA_free(DFA dfa)
{
    for (int i = 0; i <= dfa->nstates; i++)
    {
        free(dfa->trans_table[i]);
    }

    free(dfa->trans_table);

    free(dfa);
};

/**
 * Return the number of states in the given DFA
 */
int DFA_get_size(DFA dfa)
{
    return dfa->nstates;
};

int *DFA_get_state(DFA dfa)
{
    return dfa->state;
};
/**
 * Return the state specified by the given DFA's transition function from
 * state src on input symbol sym.
 */
int DFA_get_transition(DFA dfa, int src, char sym)
{
    return dfa->trans_table[src][(int)sym];
};

/**
 * For the given DFA, set the transition from state src on input symbol
 * sym to be the state dst->
 */
void DFA_set_transition(DFA dfa, int src, char sym, int dst)
{
    dfa->trans_table[src][(int)sym] = dst;
};

/**
 * Set the transitions of the given DFA for each symbol in the given str->
 * This is a nice shortcut when you have multiple labels on an edge between
 * two states->
 */
void DFA_set_transition_str(DFA dfa, int src, char *str, int dst)
{
    for (int i = 0; i < strlen(str); i++)
    {
        DFA_set_transition(dfa, src, str[i], dst);
    }
};

/**
 * Set the transitions of the given DFA for all input symbols
 * Another shortcut method->
 */
void DFA_set_transition_all(DFA dfa, int src, int dst)
{
    for (int i = 0; i < 128; i++)
    {
        dfa->trans_table[src][i] = dst;
    }
};

/**
 * Set whether the given DFA's state is accepting or not
 */
void DFA_set_accepting(DFA dfa, int state, bool value)
{
    if (value)
    {
        dfa->state[state] = 1;
    }
    else
    {
        dfa->state[state] = 0;
    }
};

/**
 * Return true if the given DFA's state is an accepting state
 */
bool DFA_get_accepting(DFA dfa, int state)
{
    if (dfa->state[state] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

/**
 * Run the given DFA on the given input string, and return true if it accepts
 * the input, otherwise false->
 */
bool DFA_execute(DFA dfa, char *input)
{
    int current_state = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        current_state = DFA_get_transition(dfa, current_state, input[i]);
        if (current_state == -1)
            return false; // -1 means there is no transition, don't use 0 in case 0 is also the accepting state
    }
    return DFA_get_accepting(dfa, current_state);
};

/**
 * Print the given DFA to System.out.
 */
void DFA_print(DFA dfa)
{
    char str[256];
    do
    {
        printf("Enter an input (\"quit\" to quit):");

        fgets(str, 225, stdin);
        str[strlen(str) - 1] = '\0'; // eliminate the \n charater at the end of str

        printf("Result for input \"%s\": %s \n\n", str, DFA_execute(dfa, str) ? "true" : "false");
    } while (strcmp(str, "quit") != 0);
};