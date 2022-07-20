#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#define _CRT_SECURE_NO_WARNINGS

uint32_t read_bi(char** argv_temp){
	FILE * fp;
	uint32_t temp;
	printf("바이너리 파일 읽는 중..\n");
	if (( fp = fopen(argv_temp[0], "rb")) == NULL) {
		printf("파일읽기 오류! \n");
		exit(1);
	}
	fread(&temp, sizeof(uint32_t), 1, fp);
	printf("파일 입력값 : 0x%08x\n",temp);
	fclose(fp);
	return temp;
}

uint32_t BigFromLittle(uint32_t temp){
	uint32_t swap_n1, swap_n2, swap_n3, swap_n4;
	uint32_t ret;

	swap_n1 = (0xff000000 & temp) >> 24;
	swap_n2 = (0x00ff0000 & temp) >> 8;
	swap_n3 = (0x0000ff00 & temp) << 8;
	swap_n4 = (0x000000ff & temp) << 24;

	ret = swap_n1 |
		swap_n2 |
		swap_n3 |
		swap_n4;
	return ret;

}



int main(int argc, char** argv){
	uint32_t n1;
	uint32_t n2;
	uint32_t ret;

	n1 = read_bi(&argv[1]);
	n2 = read_bi(&argv[2]);
	
	n1 = BigFromLittle(n1);
	n2 = BigFromLittle(n2);

	printf("스왑 : 0x%08x\n", n1);
	printf("스왑 : 0x%08x\n", n2);
	
	ret = n1 + n2;

	printf("덧셈 결과 : 0x%08x\n", ret);
	printf("덧셈 결과 스왑 : 0x%08x\n", BigFromLittle(ret));

	return 0;	
}
