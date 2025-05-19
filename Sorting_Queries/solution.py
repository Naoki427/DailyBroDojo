from collections import deque
import heapq

q = int(input())
raw = deque()
sorted_part = []

for _ in range(q):
    query = input().split()
    if query[0] == "1":
        raw.append(int(query[1]))
    elif query[0] == "2":
        if sorted_part:
            print(heapq.heappop(sorted_part))
        else:
            print(raw.popleft())
    else:
        while raw:
            heapq.heappush(sorted_part, raw.popleft())