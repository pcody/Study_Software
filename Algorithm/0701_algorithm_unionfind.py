def Find(x):
    global parent
    if x == parent[x]:
        return x
    else :
        parent[x] = Find(parent[x])
        return parent[x]

# y부모 - x자식 관계 만들어주는 함수
def Union(x,y):
    # 루트를 찾는다.
    x = Find(x)
    y = Find(y)

    # 루트가 같다면 같은 트리이므로 합칠 필요가 없음
    if x==y:
        return

    # x의 루트를 y로 바꿈
    parent[x] = y

N = 10
parent = [0]*(N+1)

for i in range(1,N+1):
    parent[i] = i
print(parent)

Union(1,4)
print(parent)
Union(4,10)
print(parent)
Union(10,9)
print(parent)
Union(9,2)
Find(4)
print(parent)
