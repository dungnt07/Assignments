#include <stdio.h>
#include <stdlib.h>

typedef struct object{
  int weight;
  int value;
  int quantity;
  float rate;
  char name;
}object;

int main(){
  FILE* inp = fopen("BAG.INP","r");
  FILE* out = fopen("BAG.OUT","w");
  int n, totalweight;
  fscanf(inp, "%d %d", &n, &totalweight);
  object *objects = (object*) malloc(n*sizeof(object));
  for (int i = 0; i < n; i++){
        object tmp;
        fscanf(inp,"%d %d %c", &tmp.weight, &tmp.value, &tmp.name);
        tmp.rate = (float)(tmp.value) / (float)(tmp.weight); 
        objects[i] = tmp;
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (objects[i].rate < objects[j].rate){
        object tmp;
        tmp = objects[i];
        objects[i] = objects[j];
        objects[j] = tmp;
      }
    }
  }
  int currentVal = 0;
  int currentWeight = totalweight;
  for (int i = 0; i < n; i++){
    int quant = currentWeight / objects[i].weight;
    currentVal += quant * objects[i].value;
    currentWeight = currentWeight % objects[i].weight;
    objects[i].quantity = quant;
  }
  fprintf(out,"%d\n",currentVal);
  for (int i = 0; i < n; i++){
        if (objects[i].quantity == 0)
            continue;
        fprintf(out,"%c  %d\n", objects[i].name, objects[i].quantity);
  }
  fclose(inp);
  fclose(out);
  return 0;
}