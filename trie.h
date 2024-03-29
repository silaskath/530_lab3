/* -*- mode:c; c-file-style:"k&r"; c-basic-offset: 4; tab-width:4; indent-tabs-mode:nil; mode:auto-fill; fill-column:78; -*- */
/* vim: set ts=4 sw=4 et tw=78 fo=cqt wm=0: */

#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdint.h>
#include <assert.h>

/* A simple (reverse) trie interface */

#define MAX_KEY 64
// Uncomment this line for debug printing
//#define DEBUG 1

/* Optional init routine.  May not be required. */
void init (int numthreads);

/* Return 1 on success, 0 on failure */
int insert (const char *string, size_t strlen, int32_t ip4_address);

/* Return 1 if the key is found, 0 if not. 
 * If ip4_address is not NULL, store the IP 
 * here.  
 */
int search  (const char *string, size_t strlen, int32_t *ip4_address);


/* Return 1 if the key is found and deleted, 0 if not. */
int delete  (const char *string, size_t strlen);

/* Check the maximum node count.
 * If we have exceeded it, drop some nodes
 * to lower the count.
 */
void check_max_nodes  ();

/* Optional shut-down routine to wake up and terminate
   the delete thread.  May not be required. */
void shutdown_delete_thread ();


/* Print the structure of the tree.  Mostly useful for debugging. */
void print (); 

/* Determines whether to allow blocking until 
 * a name is available.
 */
extern int allow_squatting;


#endif /* __TRIE_H__ */ 