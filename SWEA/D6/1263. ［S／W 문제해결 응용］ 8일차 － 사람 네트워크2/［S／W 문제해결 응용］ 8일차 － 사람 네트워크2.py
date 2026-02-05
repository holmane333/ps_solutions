from collections import deque

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # 다익스트라 알고리즘 이용 (Lazy heap 방식)
    # ///////////////////////////////////////////////////////////////////////////////////
    ary = list(map(int, input().split()))
    N = ary[0]
    mat = [ary[i:i + N] for i in range(1, len(ary), N)]
    # edge를 받아서, 각 node에서 바로 접근할 수 있도록 저장
    edges = [[] for i in range(N + 1)]
    for i in range(N):
        for j in range(i + 1, N):
            # 각 node에 연결된 node 번호와 가중치 추가
            if (mat[i][j]):
                edges[i].append(j)
                edges[j].append(i)

    res = int(1e9)
    for start in range(N):
        dq = deque()
        dq.append(start)
        v = [-1 for i in range(N)]
        v[start] = 0
        cnt = 0
        while (dq):
            x = dq.popleft()
            for node in edges[x]:
                if (v[node] != -1): continue
                v[node] = v[x] + 1
                cnt += v[node]
                dq.append(node)
        res = min(res, cnt)
                
        
    # 도착지 위치까지의 최소 거리는 info의 N번째 인덱스에 있으므로 info[N] 출력
    print(f"#{test_case} {res}")
    # ///////////////////////////////////////////////////////////////////////////////////
