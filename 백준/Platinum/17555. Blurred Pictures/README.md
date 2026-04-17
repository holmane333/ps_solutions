# [Platinum V] Blurred Pictures - 17555 

[문제 링크](https://www.acmicpc.net/problem/17555) 

### 성능 요약

메모리: 5928 KB, 시간: 24 ms

### 분류

이분 탐색, 자료 구조, 매개 변수 탐색, 세그먼트 트리

### 제출 일자

2026년 4월 17일 21:37:00

### 문제 설명

<p>Damon loves to take photos of the places he visits during his travels, to put them into frames. All of his photos are in a square format of N x N pixels. He brought back beautiful pictures of the many monuments in Paris, such as the Eiffel Tower or the Louvre, but unfortunately, when he got back home, he realized that all his pictures were blurred on the edges. Looking closely, Damon realizes that he can easily distinguish the blurred pixels from the “good” (i.e., non-blurred) ones and that, luckily, all the non-blurred pixels are connected in such a way that any horizontal or vertical line drawn between two non-blurred pixels goes only through non-blurred pixels. In order to get the best from his failed pictures, he decides to cut out the biggest possible picture without any blurred pixel from each of his photos. And since his frames are all squares, for aesthetic reasons, the cut-out pictures have to be squares too. Damon does not want his pictures to be tilted so he wants the sides of the cut-outs to be parallel to the sides of the original picture.</p>

### 입력 

 <p>The input comprises several lines, each consisting of integers separated with single spaces:</p>

<ul>
	<li>The first line contains the length N, in pixels, of the input photo;</li>
	<li>Each of the next N lines contains two integers a<sub>i</sub> and b<sub>i</sub>, the indices of the first (a<sub>i</sub>) and the last (b<sub>i</sub>) non-blurred pixel on the i-th line.</li>
</ul>

### 출력 

 <p>The output should consist of a single line, whose content is an integer, the length of the largest square composed of non-blurred pixels inside the picture.</p>

