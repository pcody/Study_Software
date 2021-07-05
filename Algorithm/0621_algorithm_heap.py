from heapq import *

heap = []
# heappush O(logN)
heappush(heap, 1)
heappush(heap, 4)
heappush(heap, 7)
heappush(heap, 8)
heappush(heap, 2)
print(heap)
while heap:
    # heappop O(logN)
    print(heappop(heap))

heap = [5, 8, 7, 3, 2, 1, 4]
# 이미 원소가 들어있는 리스트를 힙으로 만듦 O(N)
heapify(heap)
print(heap)
while heap:
    print(heappop(heap))

nums = [5, 8, 7, 3, 2, 1, 4]
heap = []
for num in nums:
    heappush(heap, (-num, num))
print(heap)

while heap:
    print(heappop(heap)[1])


