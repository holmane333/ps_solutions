# [Platinum V] Dad’s Card Trick - 11171 

[문제 링크](https://www.acmicpc.net/problem/11171) 

### 성능 요약

메모리: 32412 KB, 시간: 32 ms

### 분류

애드 혹, 많은 조건 분기

### 제출 일자

2026년 04월 01일 20:33:46

### 문제 설명

<p>You are always doing impressive card tricks, and it’s driving everyone mad. To put a stop to this, your dad decides to challenge you to do a trick he thinks is impossible.</p>

<p>He starts by blindfolding you, and gives you a deck of N cards. He tells you that K of the cards are face up. Your task is to find a sequence of operations to perform, with the following goal: The deck should be separated into two decks at the end of the sequence, such that each of the two decks have the same number of face up cards (not necessarily K), no matter which order the cards were in initially. The other deck is initially empty. You are allowed to do the following two operations in any order, any number of times:</p>

<ol>
	<li>Move a card from one deck to the other.</li>
	<li>Flip over any one card in any of the two decks. If it was face up, it will now be face down and vice versa.</li>
</ol>

<p>In order to impress your dad, you have decided not only to accept the challenge, but to find the shortest sequence of operations possible. Being a prominent programmer, you realize that you can cheat by writing a program that generates this for you.</p>

### 입력 

 <p>The first line of the input consists of a single integer, T, the number of test cases. Each of the following T test cases consists of a single line with two integers, N and K, separated by a space.</p>

<ul>
	<li>1 ≤ T ≤ 20</li>
	<li>1 ≤ K ≤ N ≤ 1000</li>
</ul>

### 출력 

 <p>For each test case, output the minimum number of operations needed to achieve the goal. If it is not possible, output -1 instead.</p>

