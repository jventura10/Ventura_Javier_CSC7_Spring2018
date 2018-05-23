/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneralHashFunctions.h
 * Author: Javier Ventura 
 *
 * Created on May 23, 2018, 11:26 AM
 */

#ifndef GENERALHASHFUNCTIONS_H
#define GENERALHASHFUNCTIONS_H

#include <string>

typedef unsigned int (*HashFunction)(std::string&);

unsigned int APHash  (std::string& str);



#endif /* GENERALHASHFUNCTIONS_H */

