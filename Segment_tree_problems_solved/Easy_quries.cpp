#include<stdio.h>
#define MAXSIZE 131072

int N, Q;
int input[MAXSIZE];


typedef struct sNode
{
  int value;
} sNode;


sNode node[MAXSIZE*2 -1];

int iteration = 0;
//int maxTreeNode;

void buildTree(int, int, int);
///void takeInput();
int findNearestLeft(int, int, int, int);
int findNearestRight(int, int, int, int);
void updateTree(int, int, int, int);

///void answerQueries();














int main()
{
    ///takeInput();
    int i;
    scanf("%d%d", &N, &Q);
    for(i=0 ; i<N ; i++)
    {
        scanf("%d", &input[i]);
    }

    buildTree(0, N-1,0);

    ///answerQueries();
    int queryType, query;
    while(Q--)
    {
        scanf("%d%d", &queryType, &query);
        switch(queryType)
        {
        case 0:
            printf("%d ",findNearestLeft(query, 0, N-1, 0));
            printf("%d\n",findNearestRight(query, 0, N-1, 0));
            break;
        case 1:
            updateTree(query, 0, N-1, 0);
            break;
        }
    }
    return 0;
}




void buildTree(int lb, int ub,int nodeNumber)   //bulding 0 based index tree
{
    //printf("%d Building tree for %d %d index %d\n", iteration++, lb, ub, nodeNumber);
    /*	if(!(nodeNumber < maxTreeNode)) {
    		printf("Returning\n");
    		return;
    	}*/
    if(lb == ub)
    {
        node[nodeNumber].value = input[lb];
        return;
        //return node[nodeNumber].value;
    }
    int mid = (lb+ub)/2;
    buildTree(lb,	mid,	2*nodeNumber+1);
    buildTree(mid+1,ub,	2*nodeNumber+2);
    node[nodeNumber].value = node[2*nodeNumber+1].value + node[2*nodeNumber+2].value;
}

/*void takeInput() {
	int i;
	scanf("%d%d", &N, &Q);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &input[i]);
	}
	//maxTreeNode = 2*N -1;
}*/



int findNearestLeft(int query, int lb, int ub, int nodeNumber)
{
    f(node[nodeNumber].value == 0 || query <= lb)
    {
        return -1;
    }

    if(lb == ub)
    {
        return lb;
    }
    int mid = (lb+ub)/2;

    int answer;

    answer = findNearestLeft(query, mid+1, ub, 2*nodeNumber+2);

    if(answer != -1)
    {
        return answer;
    }

    answer = findNearestLeft(query, lb, mid, 2*nodeNumber+1);

    if(answer != -1)
    {
        return answer;
    }
    return -1;
}











int findNearestRight(int query, int lb, int ub, int nodeNumber)
{
    if(node[nodeNumber].value == 0 || query >= ub)
    {
        return -1;
    }
    if(lb == ub)
    {
        return lb;
    }
    int mid = (lb+ub)/2;
    int answer;
    answer = findNearestRight(query, lb, mid, 2*nodeNumber+1);
    if(answer != -1)
    {
        return answer;
    }
    answer = findNearestRight(query, mid+1, ub, 2*nodeNumber+2);
    if(answer != -1)
    {
        return answer;
    }
    return -1;
}

void updateTree(int idx, int lb, int ub, int nodeNumber)
{
    if(ub < idx || lb > idx)  // || nodeNumber >= maxTreeNode) {
    {
        return;
    }
    if(lb == ub)
    {
        input[idx] = 1;
        node[nodeNumber].value = 1;
        return;
    }
    int mid = (lb+ub)/2;
    updateTree(idx,	lb,	mid,	2*nodeNumber+1);
    updateTree(idx,	mid+1,	ub,	2*nodeNumber+2);
    node[nodeNumber].value = node[2*nodeNumber+1].value + node[2*nodeNumber+2].value;
}


/*void answerQueries() {
	int queryType, query;
	while(Q--) {
		scanf("%d%d", &queryType, &query);
		switch(queryType) {
		case 0:
			printf("%d ",findNearestLeft(query, 0, N-1, 0));
			printf("%d\n",findNearestRight(query, 0, N-1, 0));
			break;
		case 1:
			updateTree(query, 0, N-1, 0);
			break;
		}
	}
}*/
