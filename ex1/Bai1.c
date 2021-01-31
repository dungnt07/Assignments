#include <stdio.h>
#define ll long long
ll fact(ll n);
ll combination(ll n, ll k);

int main(){
  FILE *inp = fopen("TOHOP.INP","r");
  FILE *outp = fopen("TOHOP.OUT","w");
  ll n, k;
  while(fscanf(inp,"%lld %lld",&n,&k) != EOF)
    fprintf(outp,"%lld\n",combination(n,k));
  fclose(inp);
  fclose(outp);
  return 0;
}

ll fact(ll n){
  if (n == 1)
    return 1;
  else return n * fact(n-1);  
}

ll combination(ll n, ll k){
  return fact(n)/(fact(k)*fact(n-k));
}
