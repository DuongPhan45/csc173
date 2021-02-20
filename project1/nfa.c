#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Set.h"
#include "nfa.h"

typedef struct NFA *NFA;

struct NFA
{
  int nstates;              // number of states
  IntHashSet **trans_table; // transition table
  int *state;               // indicate whether a state is accepting state or not
};

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFA new_NFA(int nstates)
{
  NFA this = (NFA)malloc(sizeof(struct NFA));
  if (this == NULL)
  {
    return NULL;
  }

  this->nstates = nstates;

  this->trans_table = (IntHashSet **)malloc(sizeof(IntHashSet *) * (nstates + 1));
  for (int i = 0; i <= nstates; i++)
  {
    this->trans_table[i] = (IntHashSet *)calloc(128, sizeof(IntHashSet));
  }

  this->state = (int *)calloc(nstates + 1, sizeof(int));

  return this;
};

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA nfa)
{
  // free element in transition table and accepting list
  for (int i = 0; i <= nfa->nstates; i++)
  {
    free(nfa->trans_table[i]);
  }

  // free tran_table and accepting list
  free(nfa->trans_table);
  free(nfa->state);

  // free nfa
  free(nfa);
};

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA nfa)
{
  return nfa->nstates;
};

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern Set NFA_get_transitions(NFA nfa, int state, char sym)
{

  if (nfa->trans_table[state][(int)sym] == NULL)
  {
    IntHashSet no_transition = new_IntHashSet(1);
    return no_transition; // the default value of no-transition in trans_table is an empty set
  }
  return nfa->trans_table[state][(int)sym];
};

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA nfa, int src, char sym, int dst)
{
  if (nfa->trans_table[src][(int)sym] == NULL)
  {
    nfa->trans_table[src][(int)sym] = new_IntHashSet(100);
  }
  IntHashSet_insert(nfa->trans_table[src][(int)sym], (int)dst);
};

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst)
{
  for (int i = 0; i < strlen(str); i++)
  {
    NFA_add_transition(nfa, src, str[i], dst);
  }
};

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA nfa, int src, int dst)
{
  for (int i = 0; i < 128; i++)
  {
    NFA_add_transition(nfa, src, i, dst);
  }
};

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA nfa, int state, bool value)
{
  if (value)
  {
    nfa->state[state] = 1;
  }
  else
  {
    nfa->state[state] = 0;
  }
};

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFA nfa, int state)
{
  if (nfa->state[state] == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool NFA_execute(NFA nfa, char *input)
{
  // Create inital set of possible current states {0}
  IntHashSet current = new_IntHashSet(100);
  IntHashSet_insert(current, 0);

  for (int i = 0; i < strlen(input); i++)
  {
    // A set recording all possible destinations of transition of current possible states and input
    IntHashSet temp_states = new_IntHashSet(100);

    // Loop through all current possible states
    IntHashSetIterator it = IntHashSet_iterator(current);

    while (IntHashSetIterator_hasNext(it))
    {
      int temp_src = IntHashSetIterator_next(it);
      // Get the destination set of each source (element) in current set
      IntHashSet temp_dest = NFA_get_transitions(nfa, temp_src, input[i]);
      // Union with the set of possible destinations
      IntHashSet_union(temp_states, temp_dest);
    }
    current = temp_states;
  }

  // Loop through all final possible states, return true if find an accepting states
  IntHashSetIterator it = IntHashSet_iterator(current);
  while (IntHashSetIterator_hasNext(it))
  {
    int state = IntHashSetIterator_next(it);
    // printf("state: %d value: %d", state, nfa->state[state]);
    if (nfa->state[state])
    {
      return true;
    }
  }
  return false;
};

/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA nfa)
{
  char str[256];
  do
  {
    printf("Enter an input (\"quit\" to quit):");

    fgets(str, 225, stdin);
    str[strlen(str) - 1] = '\0'; // eliminate the \n charater at the end of str

    printf("Result for input \"%s\": %s \n\n", str, NFA_execute(nfa, str) ? "true" : "false");
  } while (strcmp(str, "quit") != 0);
};