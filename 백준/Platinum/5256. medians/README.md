# [Platinum V] medians - 5256 

[문제 링크](https://www.acmicpc.net/problem/5256) 

### 성능 요약

메모리: 5412 KB, 시간: 80 ms

### 분류

자료 구조, 그리디 알고리즘, 애드 혹, 세그먼트 트리

### 제출 일자

2026년 4월 6일 20:37:23

### 문제 설명

<p>Let A be a permutation of 1, 2, 3 ..., 2*N - 1.</p>

<p>We define the prefix medians of A as an array B with N elements: where B[i] is the median of A[1], A[2], ..., A[2*i-1].</p>

<p>Note: The median of a list of M numbers (where M is odd) can be found by sorting the numbers and picking the middle one.</p>

<p>You are given N and the array B. You are asked to determine a permutation A whose prefix medians are precisely B.</p>

### 입력 

 <p>The input file contains 2 lines. The first line contains one integer, N. The second line describes B: N integers, separated by space.</p>

### 출력 

 <p>The output file should contain A: one line with 2*N-1 integers separated by space. If there are multiple permutations A leading to the same input array B, you may output any one. In all test data, there will always be at least one solution.</p>

