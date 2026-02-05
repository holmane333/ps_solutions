import heapq

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # 다익스트라 알고리즘 이용 (Lazy heap 방식)
    # ///////////////////////////////////////////////////////////////////////////////////
    ary = list(map(int, input().split()))
    N = ary[0]
    mat = [ary[i:i + N] for i in range(1, len(ary), N)]
    # edge를 받아서, 각 node에서 바로 접근할 수 있도록 저장
    edges = [set() for i in range(N + 1)]
    for i in range(N):
        for j in range(i + 1, N):
            # 각 node에 연결된 node 번호와 가중치 추가
            if (mat[i][j]):
                edges[i].add(j)
                edges[j].add(i)

    res = int(1e9)
    for start in range(N):
        # heap 정의
        # hq[(cost, node)]: cost, 그 이후 node를 기준으로 최소힙 생성
        hq = [(0, start)]
        # heap에 저장할 내용, 현재 해당 node까지 가기 위해서 걸리는 최소 비용
        info = [int(1e9) for i in range(N + 1)]
        # 처음 위치 초기화
        info[start] = 0
        # 해당 node 방문 여부, info에 업데이트하는 것과 별개로 해당 node를 아직 방문하지 않았을 수 있음. 즉, heap을 통해 나온 node
        visit = [0 for i in range(N + 1)]
        cnt = 0
        used = set()
        while (hq):
            # 현재 도착한 node 위치 받기
            _, node = heapq.heappop(hq)
            # 만약 이미 도착했을 경우 다음 루프로
            # Lazy heap이기 때문에 heap 내에 같은 node 값이 존재할 수 있음
            if (visit[node]): continue
            # 방문한 적 없으므로 이제 방문한 것으로 표시
            visit[node] = 1
            used.add(node)
            cnt += info[node]
            # 해당 node와 연결된 모든 node 탐색
            for edge in edges[node].difference(used):
                # 방문 했으면 패스
                if (visit[edge]): continue
                # 다음 node까지 더 적은 비용으로 갈 수 있을 경우 업데이트하고, 이를 heap에 추가
                if (info[edge] > info[node] + 1):
                    info[edge] = info[node] + 1
                    heapq.heappush(hq, (info[node], edge))
        res = min(res, cnt)
    # 도착지 위치까지의 최소 거리는 info의 N번째 인덱스에 있으므로 info[N] 출력
    print(f"#{test_case} {res}")
    # ///////////////////////////////////////////////////////////////////////////////////
