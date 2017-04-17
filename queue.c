#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Q create_queue() {
        Q q;

        q = (Q) malloc(sizeof(Qu));

        if (q == NULL) {
                printf("Se quemó el tamal :/\n");
                exit(0);
        }

        q->f = 0;
        q->l = 0;
        q->a = 0;

        return q;
}

void enq(Q q, int e) {
        if (q->a == size) {
                printf("Se quemó el tamal :/\n");
                exit(0);
        }

        q->qy[q->l] = e;
        q->l = next(q->l);
        q->a++;
}

int unq(Q q) {
        int v;

        if (is_q_empty(q) == 1) {
                exit(0);
        }

        v = q->qy[q->f];
        q->f = next(q->f);
        q->a--;

        return v;
}

int first(Q q) {
        int v;

        if (is_q_empty(q) == 1) {
                exit(0);
        }

        v = q->qy[q->f];

        return v;
}

int is_q_empty(Q q) {
        if (q->a == 0)
                return 1;

        return 0;
}

int next(int i) {
        int ni;

        ni = (i + 1) % size;

        return ni;
}
