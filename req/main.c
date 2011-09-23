//
//  main.c
//  req
//
//  Created by Taylor Trimble on 9/23/11.
//  Copyright 2011 Dragonfly Apps. All rights reserved.
//

#include <stdio.h>
#include <libgen.h>

int main (int argc, const char * argv[])
{
    // Check that arguments are present
    if (argc < 2) {
        printf("usage: %s r1 r2 ...\n", basename((char *)argv[0]));
        return -1;
    }
    
    // Find inverse sum of each argument
    double inverseSum = 0;
    for (int i = 1; i < argc; i++) {
        double arg;                                     // Parsed argument
        int succeeded = sscanf(argv[i], "%lf", &arg);   // succeeded = 1 if parse succeeded
        if (!succeeded) {
            printf("%s: \"%s\" is not a number\n", basename((char *)argv[0]), argv[i]);
            printf("usage: %s r1 r2 ...\n",basename((char *)argv[0]));
            return -1;
        }
        
        inverseSum += 1/arg;
    }
    
    // Find and print equivalent reistance
    double equivalentResistance = 1/inverseSum;
    printf("%.4f\n", equivalentResistance);
    
    return 0;
}

