from collections import deque

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # BFS 이용
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

    # 최솟값 결과 저장 변수
    res = int(1e9)
    # 0 ~ N - 1까지 모두 순회
    for start in range(N):
        # BFS 순회를 위해 deque 선언 후 시작점 저장
        dq = deque()
        dq.append(start)
        # 방문 여부 확인 배열
        visit = [-1 for i in range(N)]
        visit[start] = 0
        # 현재 순회에 대한 결과 저장
        cnt = 0
        while (dq):
            # 현재 노드 cur 저장
            cur = dq.popleft()
            # cur와 연결된 노드 확인
            for node in edges[cur]:
                # 이미 방문한 노드일 경우 continue
                if (visit[node] != -1): continue
                # 방문했으므로 visit에 저장 및 거리 cnt에 추가, deque에 다음 노드 추가
                visit[node] = visit[cur] + 1
                cnt += visit[node]
                dq.append(node)
        # 결과 비교 후 작은 값 저장
        res = min(res, cnt)
    
    print(f"#{test_case} {res}")
    # ///////////////////////////////////////////////////////////////////////////////////
