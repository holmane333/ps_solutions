# [Platinum IV] Spanning Trees - 19370 

[문제 링크](https://www.acmicpc.net/problem/19370) 

### 성능 요약

메모리: 2100 KB, 시간: 188 ms

### 분류

해 구성하기

### 제출 일자

2026년 04월 01일 20:33:46

### 문제 설명

<p>Consider a complete graph with $N$ vertices. Find $K$ spanning trees that are edge-disjoint.</p>

<p style="text-align: center;"><img alt="" src=""><img alt="" src=""><img alt="" src=""></p>

<p>The leftmost figure above shows a complete graph with four vertices. The two figures to the right are two edge-disjoint spanning trees of this graph.</p>

### 입력 

 <p>You are given two integers $N$ and $K$ on a single line ($2 \le N \le 10^4$, $1 \le K \le 100$).</p>

### 출력 

 <p>If there is no tuple of $K$ spanning trees that satisfies the conditions, print $-1$.</p>

<p>Otherwise, print $K$ spanning trees. Each spanning tree must be printed on $N - 1$ lines. The $i$-th line must contain two space-separated integers: the two endpoints of the $i$-th edge. The vertices are numbered $1$ through $N$. You may print an empty line between consecutive trees.</p>

