# [Gold V] Change Making - 17600 

[문제 링크](https://www.acmicpc.net/problem/17600) 

### 성능 요약

메모리: 115456 KB, 시간: 288 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2026년 04월 01일 20:33:46

### 문제 설명

<p>The change-making problem is a classical competitive programming problem. The problem is about a currency system. In this system, there are n available denominations of coins \$c<sub>1</sub>, \$c<sub>2</sub>, . . . , \$c<sub>n</sub> where c<sub>1</sub> = 1 and c<sub>2</sub>, . . . , c<sub>n</sub> are all integers. Assume you can have unlimited supply of each denomination of coins. The change-making problem is: given a target x, make a change of \$x with minimum number of coins.</p>

<p>The change-making problem has appeared so many times in programming contest. Many contestants know how to solve this problem. However, there are also many contestants doing it wrongly. For example, many of them use greedy algorithm which does not work. This greedy algorithm repeatedly takes the coin with greatest value which does not exceed x. This algorithm actually works for some currency system but not for this case: \$1, \$3, \$4 and the target x = 6. We call such case a counterexample to this greedy algorithm, and x = 6 is a witness of the currency system \$1, \$3, \$4.</p>

<p>Please write a program to find the minimum witness for a given currency system. If there does not exist a witness or the minimum witness is greater than 10<sup>5</sup>, your program should output −1.</p>

### 입력 

 <p>The first line contains an integer n to indicate the number of denominations in the currency system. The second line contains n integers c<sub>1</sub>, . . . , c<sub>n</sub> where the currency system has \$c<sub>1</sub>, . . . , \$c<sub>n</sub>.</p>

### 출력 

 <p>Output the minimum witness x if x ≤ 10<sup>5</sup>. Otherwise output −1.</p>

