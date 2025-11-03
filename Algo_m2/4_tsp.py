from itertools import permutations

cost=[
     [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

n=len(cost)
cities=[i for i in range(1,n)]  #skip start city 0
mincost=100000
best_path=[]

for perm in permutations(cities):
    total=0
    k=0
    
    for j in perm:
        total=total+cost[k][j]
        k=j
    total=total+cost[k][j]
    
    if total<mincost:
        mincost=total
        best_path=(0,)+perm+(0,)
        
print("Minimum cost =",mincost)
print("Best path= ",best_path)