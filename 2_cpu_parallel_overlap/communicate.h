/*******************************************************
 * File: communicate.h
 * Description: 
 *   Header file declaring the communicate_gradients() function.
 *   This function simulates gradient communication (AllReduce) 
 *   using sleep delays for each layer.
 *
 * Part of: Phase 2 - OpenMP Overlap Project
 *******************************************************/

#ifndef COMMUNICATE_H
#define COMMUNICATE_H

void communicate_gradients();

#endif
