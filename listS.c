#include "listS.h"//내가 만든 경우 ""사용, 시스템에서 정의된 경우 <>사용
int insertElement(int L[], int n, int x) {
	int i, k = 0, move = 0; //move는 자리이동 횟수 카운터
	//1. 원소의 크기를 비교하여 삽입할 위치 k 찾기
	for (i = 0; i < n; i++) {
		if (L[i] <= x && x <= L[i + 1]) {
			k = i + 1;
			break;
		}
	}
	if (i == n) // 삽입 원소가 가장 큰 원소인 경우
		k = n;

	//마지막 원소부터 k+1원소까지 뒤로 자리이동(뒤에서부터 진행, 앞에서부터 할 경우 덮어씌워질 수 있다)
	for (i = n; i > k; i--) {
		L[i] = L[i - 1];
		move++;
	}

	L[k] = x; //삽입할 위치 k 자리에 입력값 x 집어넣기
	return move;
}
int deleteElement(int L[], int n, int x) {
	int i, k = n, move = 0; //move는 자리이동 횟수 카운터
	//원소의 크기를 비교하여 삭제 위치 k 찾기
	for (i = 0; i < n; i++) {
		if (L[i] == x) {
			k = i;
			break;
		}
	}

	if (i == n) move = n;

	//k+1부터 마지막 원소까지 앞으로 자리이동(비워진 자리의 뒤부터 앞으로 한칸씩 이동하여 채우기)
	for (i = k; i < n - 1; i++) {
		L[i] = L[i + 1];
		move++;
	}

	return move;
}
