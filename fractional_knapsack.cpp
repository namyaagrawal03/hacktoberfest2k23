#include <iostream>
using namespace std;
struct ksstruct
{
  int profit;
  int weight;
  float pwratio;
};
void input(struct ksstruct ks[], int N)
{
  for(int i=0;i<N;i++)
  {
    cout<<"Enter profits of element "<<i<<": ";
    cin>>ks[i].profit;
  }
  for(int i=0;i<N;i++)
  {
    cout<<"Enter weights of element "<<i<<": ";
    cin>>ks[i].weight;
  }
}
void pbywratio(struct ksstruct ks[], int N)
{
  for(int i=0;i<N;i++)
  {
    float x=ks[i].profit/(float)(ks[i].weight);
    ks[i].pwratio=x;
  }
}
void sort(struct ksstruct ks[], int N)
{
  struct ksstruct temp;
  for(int i=0; i<N; i++)
  {
    int flag=0;
    for(int j=0; j<N; j++)
    {
      if(ks[j].pwratio<ks[j+1].pwratio)
      {
        temp=ks[j];
        ks[j]=ks[j+1];
        ks[j+1]=temp;
      }
    }
    if(flag==0)
    break;
  }
  cout<<"Sorted p/w ratio: \n";
  for(int i=0; i<N; i++)
  {
    cout<<i<<"\t";
    cout<<ks[i].pwratio<<"\t"<<"\n";
  }
}

float selection(struct ksstruct ks[], int N, float max)
{
  float max_profit=0;
  float remain=max;
  int i;
  float frac;
  for(i=0; i<N; i++)
  {
      if(remain>=ks[i].weight)
      {
        max_profit=max_profit+ks[i].profit;
        remain=remain-ks[i].weight;
      }
      else
      {
        break;
      }
  }
  float w=(float)(ks[i].weight);
  float p=(float)(ks[i].profit);
  frac = (remain/w)*p;
  max_profit=max_profit+frac;
  return max_profit;
}

int main()
{
    float max_lim;
    int N;
    float max_profit;
    cout<<"Enter number of items: ";
    cin>>N;
    struct ksstruct ks[N];
    cout<<"Enter maximum limit of bag: ";
    cin>>max_lim;
    input(ks,N);
    pbywratio(ks,N);
    sort(ks,N);
    max_profit=selection(ks,N,max_lim);
    cout<<"Maximum profit is: "<<max_profit;
}
