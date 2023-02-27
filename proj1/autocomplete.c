#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexi_cmp(const void *a, const void *b){
    return strcmp(((struct term*)a)->term, ((struct term*)b)->term);
}

int weight_cmp(const void *a, const void *b){
    return ((struct term*)b)->weight - ((struct term*)a)->weight;
}

void read_in_terms(struct term **terms, int *pnterms, char *filename){
    char line[200];
    FILE *fp = fopen(filename, "r");
    fgets(line, sizeof(line), fp);
    *pnterms = atoi(line);
    *terms = (struct term *)malloc((*pnterms) * sizeof(struct term));

    for(int i=0; i<*pnterms; i++){
        fgets(line, sizeof(line), fp);
        sscanf(line, "%lf %[^\n]", &((*terms)[i].weight), (*terms)[i].term);
    }

    fclose(fp);

    qsort(*terms, *pnterms, sizeof(struct term), lexi_cmp);
}

int lowest_match(struct term *terms, int nterms, char *substr){
    int low = 0, hi = nterms - 1;
    while(low<hi){
        int mid = (low + hi)/2;
        if(strncmp(terms[mid].term, substr, strlen(substr)) < 0){
            low = mid + 1;
        }else{
            hi = mid;
        }
    }
    return low;
}

int highest_match(struct term *terms, int nterms, char *substr){
    int low = 0, hi = nterms - 1;
    int ans = -1;
    while(low<hi){
        int mid = (low + hi)/2;
        if(strncmp(terms[mid].term, substr, strlen(substr)) != 0){
            if(strncmp(terms[mid].term, substr, strlen(substr)) <= 0){
                low = mid + 1;
            }else{
                hi = mid;
            }
        }else{
            if(ans < mid){
                ans = mid;
            }
            low = mid + 1;
        }
    }
    return ans;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int hi = highest_match(terms, nterms, substr);
    int low = lowest_match(terms, nterms, substr);

    if(hi == -1 || low == -1){
        *n_answer = 0;
        *answer = NULL;
        return;
    }

    *n_answer = hi - low + 1;
    *answer = (struct term *)malloc((*n_answer) * sizeof(struct term));
    
    for(int i = 0; i<*n_answer; i++)    (*answer)[i] = terms[low+i];

    qsort(*answer, *n_answer, sizeof(struct term), weight_cmp);
}

