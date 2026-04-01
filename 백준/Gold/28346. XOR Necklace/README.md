# [Gold IV] XOR Necklace - 28346 

[문제 링크](https://www.acmicpc.net/problem/28346) 

### 성능 요약

메모리: 2028 KB, 시간: 4 ms

### 분류

애드 혹

### 제출 일자

2026년 04월 01일 20:33:46

### 문제 설명

<p>Frograms, Inc. has been busy developing necklaces with brand-new design and feature. Every programmer working at Frograms now wears this necklace. A necklace consists of multiple beads stringed by a thread, as seen below. Each bead is given a number between $0$ to $10^9$ (inclusive).</p>

<p style="text-align: center;"><img alt="" src="" style="width: 176px; height: 201px;"></p>

<p>Most of the programmers have left for their summer vacation, and there is only a few programmers in the office today. So they decided to play a game using their own necklace to decide who will buy lunch for everyone. The rule is simple: for each pair of consecutive beads in the necklace, we take sum of their numbers. A programmer’s score is defined as the XOR(denoted as $\oplus$) of all those sums. The programmer with the lowest score loses! More formally, if there are $N$ beads and their value is denoted by $A_1$, $A_2$, $\cdots$, $A_N$ in the order they are stringed together, then the score is:</p>

<p>$$(A_1 \oplus A_2) + (A_2 \oplus A_3) + \dots + (A_{N-1} \oplus A_N) +(A_N \oplus A_1)$$</p>

<p>However, you, the most talented programmer in Frograms, Inc., is going to cheat the game by removing zero or more beads to maximize the score. What is the maximum score if you are allowed to remove some of the beads in a given necklace? Note that you cannot reorder the beads, nor leave one or less beads in a necklace.</p>

### 입력 

 <p>The input consists of $T$ test cases. The first line of the input contains $T$.</p>

<p>Each test case starts with a line containing a single integer $N$ ($2 ≤ N ≤ 500$), the number of beads on your necklace. The next line contains $N$ integers $A_1$, $A_2$, $\cdots$, $A_N$, separated by a single space.</p>

### 출력 

 <p>For each test case, print the maximum score possible you can get in a single line.</p>

