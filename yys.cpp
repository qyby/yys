#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct shishen{
	char name[10];
	char class[5];
	int level;
	long int xianyoujinyan;
	long int duoyujinyan;
	char sk1[10];
	char sk2[10];
	char sk3[10];
	double gongji;
	double shengming;
	double fangyu;
	double sudu;
	double baoji;
	double baojishanghai;
	}xyss;
struct	zhanchang{
	
}
*******************************************以上为类*******************************************

int main(){
	int q=0;
	char c;
	FILE *fp1,*fp2;
	if((fp1=fopen("xianyoushishen.dat","wb"))==NULL){
		printf("read save failed!");
		exit(0);
	}
	strcpy(xyss.name,"首无");
	strcpy(xyss.class,"R");
	xyss.level=1;
	xyss.xianyoujinyan=0;
	xyss.duoyujinyan=0;
	strcpy(xyss.sk1,"重击");
	strcpy(xyss.sk2,"冥火");
	strcpy(xyss.sk3,"虚无");
	xyss.gongji=124;
	xyss.shengming=918;
	xyss.fangyu=65;
	xyss.sudu=100;
	xyss.baoji=0.1;
	xyss.baojishanghai=1.5;
	fwrite(&xyss,sizeof(xyss),1,fp1);	
	fclose(fp1);

	struct shishen diren1; 
	if((fp1=fopen("diren1.dat","wb"))==NULL){
		printf("read save failed!");
		exit(0);
	}
	strcpy(diren1.name,"白蛋");
	strcpy(diren1.class,"N");
	diren1.level=1;
	diren1.xianyoujinyan=0;
	diren1.duoyujinyan=0;
	strcpy(diren1.sk1,NULL);
	strcpy(diren1.sk2,NULL);
	strcpy(diren1.sk3,NULL);
	diren1.gongji=114;
	diren1.shengming=960;
	diren1.fangyu=68;
	diren1.sudu=100;
	diren1.baoji=0;
	diren1.baojishanghai=1.5;
	fwrite(&diren1,sizeof(diren1),1,fp1);	
	fclose(fp1);
***********************************************以上为数据准备***********************************************
	while(0==q){
	system("clear");
	printf("======阴阳师======\n");
	printf(" 1 查看式神属性\n");
	printf(" 2   开始战斗\n");
	printf(" 3     退出\n");
	c=getchar();
	
switch(c){
	case '1':system("clear");getchar();
		printf("======阴阳师======\n");
		printf("     式神属性\n");
	if((fp2=fopen("xianyoushishen.dat","rb"))==NULL){
		printf("cant open file");
		exit(0);
	}
	fread(&xyss,sizeof(xyss),1,fp2);
	printf("昵称：%s (%s)    等级%d\n",xyss.name,xyss.class,xyss.level);
	printf("攻击：%4d    生命：%4d\n",(int)xyss.gongji,(int)xyss.shengming);
   printf("防御：%4d    速度：%4d\n",(int)xyss.fangyu,(int)xyss.sudu);
  printf("暴击：%3d%%    爆伤：%3d%%\n",(int)(xyss.baoji*100),(int)(xyss.baojishanghai*100));
		printf("  1    返回\n");	
		c=getchar();
		switch(c){
		case '1':system("clear");getchar();break;
		case '2':system("clear");printf(" 1 查看式神属性\n");getchar();break;
		case '3':system("clear");printf("游戏已退出\n");q=1;break;
		};break;
	case '2':system("clear");printf(" 1 查看式神属性\n");getchar();break;
	case '3':system("clear");printf("游戏已退出\n");q=1;break;
}

}
return 0;
}
