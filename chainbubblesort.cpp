#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

int readInt(){
	int i;
	if(scanf("%d",&i)!=1){
		fprintf(stderr,"Error while reading input\n");
		exit(1);
	}
	return i;
}
// A function to implement bubble sort

std::vector<int> count_scans(std::vector<int> A, std::vector<int> X,
                             std::vector<int> V) {
  int Q = X.size();
  std::vector<int> answer(Q);
  for(int i=0; i< Q; ++i){
    std::vector<int> B(A.size());
    for(int o=0; o<A.size(); ++o){
        B[o] = A[o];
        if(o==X[i]){
            B[o]=V[i];
            A[o]=V[i];
        }
    }
    bool tukar=false;
    int ctr = 0;
    for(int z=0; z<B.size()-1; ++z){
        tukar=false;
        for(int y=0; y<B.size()-1; ++y){
            if(B[y]>B[y+1]){
                tukar=true;
                int sementara = B[y];
                B[y] = B[y+1];
                B[y+1] = sementara;
            }
        }
        /*
        for(int it=0; it<B.size(); ++it)
            std::cout<<B[it]<<" ";
        std::cout<<"\n";
        */
        if(!tukar){
            break;
        }
        ctr+=1;
    }
    answer[i] = ctr;
  }

  return answer;
}

int main(){
	int N,Q;
	N=readInt();
	Q=readInt();

	std::vector<int> A(N);
	for(int i=0;i<N;i++)
		A[i]=readInt();

	std::vector<int> X(Q),V(Q);
	for(int j=0;j<Q;j++){
		X[j]=readInt();
		V[j]=readInt();
	}

	std::vector<int> res=count_scans(A,X,V);

	for(int j=0;j<int(res.size());j++)
		printf("%d\n",res[j]);
}
