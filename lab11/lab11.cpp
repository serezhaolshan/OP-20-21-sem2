#include <iostream>
#include <ctime>
#include <clocale>
#include <cstdio>
#include <string.h>

using namespace std;

char y;
int sz;
struct space {
  char sc[5];
	float apprWeight;
  float percent;
	unsigned long long int numberOfStars;	
}ms[10];
space x;

void Print(int size) {
  printf("--------------------------------------------------------------------------\n");
	cout << "|Приблизительное количество звезд разных спектральных классов в Галактике|"<<endl;
	cout <<"|------------------------------------------------------------------------|"<<endl;
	cout <<"| Спектральный класс | Приблизительная масса | Часть  |    Численность   |"<<endl;
	cout <<"|--------------------|-----------------------|--------|------------------|"<<endl;
  for(int i=0;i<size;++i){
  printf("| %-18c | %-21f | %-6llu| %-16f |\n", ms[i].sc,ms[i].apprWeight,ms[i].numberOfStars,ms[i].percent);
	printf("|--------------------|-----------------------|--------|------------------|\n");
  //printf("|Примечание: не показаны данные для классов: B, A, G, K                  |\n");
  //printf("-------------------------------------------------------------------------");
  }
  //cout << char(rand()%26+0x61) << "  "
}

void	Random() {
  srand(time(0));
  for(int i=0;i<5;++i){
    int r=rand()%26+1;
    r+=64;
    ms[i].sc[0]=(char)r;
  }
}

void SortStruct(int n, int m) {
	for (int i=0; i<n-1; i++) {
    m = i;
    for ( int j=i+1; j<n; j++)
      if (ms[m].sc > ms[j].sc) m=j;
    if (m>i) {
      x=ms[i];
      ms[m]=x;    
      }
    }
}

/*
int size = 0;
	for (int i = 0; i < 10; ++i) {
		printf("%d. Введите: спектральный класс, Приблизительную массу , Часть , Численность > ", 
      n+1);

		cin >> ms[i].sc;
		if (!strcmp(ms[i].sc, "***")) break;
1		cin >> ms[i].num >> el[i].temperature >> el[i].viscosity;
		size++;
	}
	sz = size;
*/

void InputStruct() {
  int sqx;
  for (int n=0; n<10; n++){
    printf("%d. Введите: спектральный класс, Приблизительную массу , Часть , Численность > ", 
      n+1);
    scanf("%c",&ms[n].sc);
    if (!strcmp(ms[n].sc,"*")) {break;}
    scanf("%f",&ms[n].apprWeight);
    scanf("%f",&ms[n].percent);
    scanf("%llu",&ms[n].numberOfStars);
    cin>>y;
    /* Внимание! Мы обходим ошибку в системе программирования */
    scanf("%f",&sqx); ms[n].numberOfStars=sqx;
    }
}

int main() {
  int size;
  int m; // minimal element
  int checker;
  while(true){
  scanf("%d",&checker);
  while(checker > 6 || checker < 0){
    printf("You've entered incorrect number. Try again: ");
    scanf("%d",&checker);
  }
  switch(checker) {
    case (1): {
      InputStruct();  
      break;
    } 
    case(2): {
      Random();
      break;
    }
    case(3): {
      SortStruct(size,m);
      break;
    }
    case (4): {
      Print(size);
      break;
    }
    case (5): {
      return 0;
    }
  }
  }
}
