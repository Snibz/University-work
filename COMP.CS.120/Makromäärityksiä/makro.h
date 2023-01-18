#ifndef OTE_DEBUG
#else
    #include <stdio.h>
#endif

#define MJapu(s) #s

#define MJ(s) MJapu(s)

#define PII 3.141592653589793

#ifndef DESIMAALIT
    #define DESIMAALIT 3
#endif

#ifndef TYYPPI
    #define TYYPPI unsigned char
#endif

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )

#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

#define MIN3(a ,b, c) ( MIN(a,b) < (c) ? MIN(a,b) : c )

#define MAX3(a, b, c) ( MAX(a,b) > (c) ? MAX(a,b) : c )

#define MIN4(a, b, c, d) ( MIN3(a, b, c) < d ? MIN3(a, b, c) : d )

#define MAX4(a, b, c, d) ( MAX3(a, b, c) > d ? MAX3(a, b, c) : d )

#ifndef  OTE_DEBUG
    #define debug(msg)
#else
    #define debug(msg) ( fprintf(stderr, msg) )
#endif
