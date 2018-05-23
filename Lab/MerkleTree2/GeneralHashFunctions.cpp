

#include "GeneralHashFunctions.h"


unsigned int APHash(std::string& str){
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++){
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}
/* End Of AP Hash Function */
