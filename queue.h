#ifndef qu
#define qu
#endif
#define size 100

typedef struct {
  int qy[size];
  int f;
  int l;
  int a;
} Qu;

typedef Qu * Q;

Q create_q();
void enq(Q, int);
int unq(Q);
int first(Q);
int is_q_empty(Q);
int next(int);
