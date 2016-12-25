# DAG的深度优先搜索标记
[TOC "float:right"]
##有向图边到分类
	一个有向图，可以从1开始深度优先遍历对其边分成以下到四类：
1. 树边  （Tree Edge）
2. 向前边 （Forward edge） 有时也称为 向下边（Down Edge）。
3. 向后边 （Back Edge）
4. 横叉边 （Cross Edge）
如下图所示：
![边的类型](http://img.blog.csdn.net/20141208173902513?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYXRvbWljMTIz/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

##如何区分不同到边
采用深度优先遍历有向图，增加标志位pre和post记录遍历到开始时间和结束时间;
每当进行一次遍历则会将对应到时间点记录到相应到节点到pre和post中去，然后可以根据pre和post中记录的时间点来判断：
1. 如果与当前节点还未相连的节点到pre时间还是初始的时间，则这条边是树边;
2. 如果一条边是Back Edge， 那么它的post记录的时间点一定还是初始的时间点， 因为从上到下的搜索过程中，只有该顶点结束搜索才会设置相应的结束时间;
3. 如果当前节点需要遍历与其相连的pre时间点比当前节点高到节点（pre[cur] < pre[i] ), 那么说明这个节点跳过了一些节点直接到达此节点， 即这条边是Down Edge;
4. 如果当前节点开始时间比与其相连的节点到开始时间还晚，则该节点是横叉边，（比如图中从8->9如果有边的话就是横叉边）

##代码实现
```cpp
#include <stdio.h>
#include <string.h>
#define  MAXV 1000

/*
 * DAG的深度优先搜索标记
 * INIT : edge[][] 邻接矩阵； pre[], post[], tag全置成0
 * CALL ： dfstag(i, n);  
 * 		pre, post : 开始和结束时间
 *         parent 父节点
 */
 int edge[MAXV][MAXV], pre[MAXV], post[MAXV],  parent[MAXV], tag;
 void dfstag(int cur, int n)
 {
     pre[cur] = ++tag;
     for (int i = 0; i < n; ++i)
     {
         if (edge[cur][i] == 1)
         {
             if (0 == pre[i])
            {
                parent[i] = cur;
                printf("%d->%d " , cur, i);
                printf("Tree Edge!\n");
                dfstag(i, n);
            } else {
                if (0 == post[i]) {
                    printf("%d->%d ", cur, i);
                    printf("Back Edge!\n");
                }
                else if (pre[i] > pre[cur]) {
                    printf("%d->%d ", cur, i);
                    printf("Down Edge!\n");
                }
                else {
                    printf("%d->%d ", cur, i);
                    printf("Cross Edge!\n");
                }
            }
         }
     }

     post[cur] = ++tag;
 }


int main()
{
    memset(pre,0,sizeof(pre));
    memset(post,0,sizeof(post));
    memset(parent,-1,sizeof(parent));
    edge[0][1] = 1;
    edge[1][2] = 1;
    edge[1][3] = 1;
    edge[0][3] = 1;
    edge[2][4] = 1;

    //dfstag(0, 4);
    for (int i = 0; i <= 4; i++)
    {
        if (parent[i] == -1) {
            dfstag(i, 5);
        }
    }

    printf("pre: \n");
    for (int i = 0; i <= 4; i++)
    {
        printf("%d\t", pre[i]);
    }
    printf("\npost: \n");
    for (int i = 0; i <= 4; i++)
    {
        printf("%d\t", post[i]);
    }

    printf("\nparent: \n");
    for (int i = 0; i <= 4; i++)
    {
        printf("%d\t", parent[i]);
    }
    return 0;
}
```
