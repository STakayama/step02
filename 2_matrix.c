#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);//時刻とタイムゾーンを取得
  return tv.tv_sec + tv.tv_usec * 1e-6;//tv.tv_sec:秒, tv.tv_usec:マイクロ秒
}

int main(int argc, char** argv)
{
  //datファイル作成用
  FILE *fp;
  char str[256];
  char str_n[1000];
  double time;
  
  fp=fopen("c2_re.dat","w");

  if(fp==NULL){
    printf("failed");
    return -1;
  }

  
  if (argc != 2) {
    printf("usage: %s N\n", argv[0]);
    return -1;
  }

  int N = atoi(argv[1]);
  int n=0;
  
  for(n=2;n<N+1;n++){


  double* a = (double*)malloc(n * n * sizeof(double)); // Matrix A
  double* b = (double*)malloc(n * n * sizeof(double)); // Matrix B
  double* c = (double*)malloc(n * n * sizeof(double)); // Matrix C

  // Initialize the matrices to some values.
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i * n + j] = i * n + j; // A[i][j] 横
      b[i * n + j] = j * n + i; // B[i][j] 縦
      c[i * n + j] = 0; // C[i][j]
    }
  }

  double begin = get_time();

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      for(k=0;k<n;k++){
	c[i*n+j]+=a[i*n+k]*b[k*n+j];  //a k:列 b k:行
	}

    }
  }
  /**************************************/
  /* Write code to calculate C = A * B. */
  /**************************************/

  double end = get_time();
  time=end-begin;
  printf("time: %.6lf sec\n", time);

  // Print C for debugging. Comment out the print before measuring the execution time.
  double sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += c[i * n + j];
      //      printf("c[%d][%d]=%lf\n", i, j, c[i * n + j]);
    }
  }
  // Print out the sum of all values in C.
  // This should be 450 for N=3, 3680 for N=4, and 18250 for N=5.
  printf("sum: %.6lf\n", sum);
  
  //  ファイルに書き込み
  //sprintf(str, "%s", end-begin);
  fprintf(fp,"%d %6lf\n",n,time);//こいつ
  //  fwrite(&n,sizeof(n),1,fp);
  // fwrite(&time,sizeof(time),1,fp);

printf("a");
  
  free(a);
  free(b);
  free(c);

  //forここまで
  }

  
  fclose(fp);
  return 0;
}
