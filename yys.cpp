#include <stdio.h>
#include <math.h>
#include <stdlib.h>//有srand()函数
#include <string.h>
#include <unistd.h>  //含有sleep函数，秒，linux专有
//#include  <system.h> //含有usleep函数，微秒
#include <time.h>//有time(NULL)函数
using namespace std;
class Shishen{
public:
    //不变属性
	char name[10];
	char type[5];
	char sk1[10];
	char sk2[10];
	char sk3[10];
	//面板属性
	int level;
	long int jinyan;
	double gongji;
	double shengming;
	double fangyu;
	double sudu;
	double baoji;
	double baojishanghai;
	//初始属性
	double chushigongji;
	double chushishengming;
	double chushifangyu;
	double chushisudu;
	double chushibaoji;
	double chushibaojishanghai;
	//战场属性
    long int duoyujinyan;
    double zhanchangshengming;

    void fightInit(){
    zhanchangshengming=shengming;
    }
	};
/*
class Zhanchangshishen:public Shishen
{
public:
	double shengyushengming;
	double jindu;
	Zhanchangshishen():Shishen(){}
	Zhanchangshishen(Shishen s):Shishen(){
	strcpy(name,s.name);
	strcpy(type,s.type);
	level=s.level;
	xianyoujinyan=s.xianyoujinyan;
	duoyujinyan=s.duoyujinyan;
	strcpy(sk1,s.sk1);
	strcpy(sk2,s.sk2);
	strcpy(sk3,s.sk3);
	gongji=s.gongji;
	shengming=s.shengming;
	fangyu=s.fangyu;
	sudu=s.sudu;
	baoji=s.baoji;
	baojishanghai=s.baojishanghai;
}
};
*/
//function declaration
void zhandou_interface(char *);

	class Skill{
    public:
    int skillNumber;
	double gongjibili; //攻击比例
	double bilijianfang;
	Skill(){};
	Skill(int sn,double gjbl,double bljf){
	skillNumber=sn;
	gongjibili=gjbl;
	bilijianfang=bljf;
	};
	};
class Zhanchang{
public:
	//Zhanchangshishen AA;
	//Zhanchangshishen BB;
	FILE *fp;
	Shishen A;
	Shishen B;
	int jindu;
	int zhandoujieshu;
	Skill *skill;
    int w=0;//箭头计数器
Zhanchang(){}
Zhanchang(Shishen a,Shishen b,Skill *sk){
	//AA=Zhanchangshishen(a);
	//BB=Zhanchangshishen(b);
	A=a;
	A.fightInit();
	B=b;
	B.fightInit();
	jindu=0;
	zhandoujieshu=0;
	skill=sk;
}
void dayinzhanchang(){
    system("clear");
    printf("LV%2d %s      LV%2d %s\n",A.level,A.name,B.level,B.name);
    printf("%4d/%4d      %4d/%4d\n",(int)A.zhanchangshengming,(int)A.shengming,(int)B.zhanchangshengming,(int)B.shengming);}
	void dayinzhanchang(int w){
	system("clear");
	printf("LV%2d %s      LV%2d %s\n",A.level,A.name,B.level,B.name);

    if(w==0){
	printf("%4d/%4d ---> %4d/%4d\n",(int)A.zhanchangshengming,(int)A.shengming,(int)B.zhanchangshengming,(int)B.shengming);}
    else{
    printf("%4d/%4d <--- %4d/%4d\n",(int)A.zhanchangshengming,(int)A.shengming,(int)    B.zhanchangshengming,(int)B.shengming);
    }
	}
	void run(){
	while(zhandoujieshu!=1){
	sleep(1);
	if(jindu==0){
	jindu=1;
	if(beat(A,B,skill)==1){
	printf("你获得了胜利！\n");
sleep(1);
   jiesuan(A,B);
	}
	}else{
	jindu=0;
	if(beat(B,A,skill)==1){
	printf("失败！\n");
	}
	}
}
}
double atk(Shishen gong,Shishen fang,int skillNumber,Skill *sk,int &bao){
double nigong;
double shigong;
srand(time(NULL));
if(rand()%100<gong.baoji*100){
    bao=1;
}else{
bao=0;
}
nigong=gong.gongji*sk[skillNumber].gongjibili*pow(gong.baojishanghai,bao);
shigong=nigong*350/(300+fang.fangyu*(1-sk[skillNumber].bilijianfang));

return shigong;
}
	int beat(Shishen &gong,Shishen &fang,Skill *sk){
	    double  shigong=0;
	    int bao=0;
        
	    shigong=atk(gong,fang,1,sk,bao);
        fang.zhanchangshengming=fang.zhanchangshengming-shigong;
        if(fang.zhanchangshengming<=0){                    
            fang.zhanchangshengming=0;
     dayinzhanchang();
     printf("%s死亡了！\n",fang.name);
     zhandoujieshu=1;
     return 1;
        }
	dayinzhanchang(w);
    if(w==0){
        w=1;}
    else{
        w=0;}
	printf("%s对%s造成了\e[3%d;1m %d \e[0m点伤害\n",gong.name,fang.name,7-bao*4,(int)shigong);
	sleep(1);
    return 0;
	}
void  chongsuanmianban(Shishen &a){
a.gongji=a.chushigongji*pow(1.055,a.level-1);
a.shengming=a.chushishengming*pow(1.048,a.level-1);
a.fangyu=a.chushifangyu*pow(1.026,a.level-1);
printf("攻击 +%d\n",(int)(a.chushigongji*pow(1.055,a.level-1)-a.chushigongji*pow(1.055,a.level-2)));
printf("生命 +%d\n",(int)(a.chushishengming*pow(1.048,a.level-1)-a.chushishengming*pow(1.048,a.level-2)));
printf("防御 +%d\n",(int)(a.chushifangyu*pow(1.026,a.level-1)-a.chushifangyu*pow(1.026,a.level-2)));
};
    void shengji(Shishen &a){
    long int shengjijinyan=0;
    if(a.level%2==1){
        shengjijinyan=(long int)(2.5*pow(a.level,3)+25*pow(a.level,2)-12.5*a.level+165);
    }else{
        shengjijinyan=(long int)(2.5*pow(a.level,3)+22.5*pow(a.level,2)-10*a.level+150);
    }
    while(a.jinyan>=shengjijinyan){
    a.jinyan=a.jinyan-shengjijinyan;
    printf("恭喜你升到了%d级\n",++a.level);
    chongsuanmianban(a);
sleep(1);
     if(a.level%2==1){
        shengjijinyan=(long int)(2.5*pow(a.level,3)+25*pow(a.level,2)-12.5*a.level+165);
    }else{
        shengjijinyan=(long int)(2.5*pow(a.level,3)+22.5*pow(a.level,2)-10*a.level+150);
    }
    }
    }
   void jiesuan(Shishen &a,Shishen &b){
   a.jinyan=a.jinyan+b.level*30+200;
   printf("经验值 +%d\n",b.level*30+200);
   shengji(a);

 	if((fp=fopen("xianyoushishen.dat","wb"))==NULL){
		printf("read save failed!");
		exit(0);
	}
    fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
   }
	};


//*******************************************以上为类*******************************************

int main(){
	int q=0;
	char c;
	FILE *fp1,*fp2,*fp3;
	Shishen xyss;
	Shishen diren1;
	Zhanchang zc;
int tshengjijinyan;
Skill skill[10];

skill[1]=Skill(1,1,0);
if ( access("./a", F_OK)){
	if((fp1=fopen("xianyoushishen.dat","wb"))==NULL){
		printf("read save failed!");
		exit(0);
	}
	xyss=Shishen();
	strcpy(xyss.name,"首无");
	strcpy(xyss.type,"R");
	xyss.level=1;
	xyss.jinyan=0;
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
  xyss.chushigongji=124;
xyss.chushifangyu=65;
xyss.chushishengming=918;
	fwrite(&xyss,sizeof(xyss),1,fp1);
	fclose(fp1);

	diren1=Shishen();
	if((fp3=fopen("diren1.dat","wb"))==NULL){
		printf("read save failed!");
		exit(0);
	}
	strcpy(diren1.name,"白蛋");
	strcpy(diren1.type,"N");
	diren1.level=1;
	diren1.jinyan=0;
	diren1.duoyujinyan=0;
	strcpy(diren1.sk1,"无");
	strcpy(diren1.sk2,"无");
	strcpy(diren1.sk3,"无");
	diren1.gongji=114;
	diren1.shengming=960;
	diren1.fangyu=68;
	diren1.sudu=100;
	diren1.baoji=0;
	diren1.baojishanghai=1.5;
	fwrite(&diren1,sizeof(diren1),1,fp3);
	fclose(fp3);

	fopen("a","wb");
}else{
printf("存档载入中...\n");
sleep(1);
system("clear");
}
//***********************************************以上为数据准备***********************************************
	while(0==q){
	system("clear");
	printf("=========阴阳师=========\n");
	printf("    1 查看式神属性\n");
	printf("    2   开始战斗\n");
	printf("    3     退出\n");
	c=getchar();

switch(c){
	case '1':system("clear");getchar();
		printf("=========阴阳师=========\n");
		printf("        式神属性\n");
	if((fp2=fopen("xianyoushishen.dat","rb"))==NULL){
		printf("cant open file");
		exit(0);
	};
	fread(&xyss,sizeof(xyss),1,fp2);
    fclose(fp2);
        printf("昵称：%s (%s)    等级%d\n",xyss.name,xyss.type,xyss.level);
        printf("攻击：%4d    生命：%4d\n",(int)xyss.gongji,(int)xyss.shengming);
        printf("防御：%4d    速度：%4d\n",(int)xyss.fangyu,(int)xyss.sudu);
        printf("暴击：%3d%%    爆伤：%3d%%\n",(int)(xyss.baoji*100),(int)(xyss.baojishanghai*100));
if(xyss.level%2==1){
        tshengjijinyan=(long int)(2.5*pow(xyss.level,3)+25*pow(xyss.level,2)-12.5*xyss.level+165);
    }else{
        tshengjijinyan=(long int)(2.5*pow(xyss.level,3)+22.5*pow(xyss.level,2)-10*xyss.level+150);
    }
      printf("经验：%d/%d\n",(int)(xyss.jinyan),(int)(tshengjijinyan));
		printf("  1    返回\n");
		c=getchar();
		switch(c){
		case '1':system("clear");getchar();break;
		case '2':system("clear");printf(" 1 查看式神属性\n");getchar();break;
		case '3':

system("clear");printf("游戏已退出\n");q=1;break;
		};break;
	case '2':
        zhandou_interface("diren1.dat");
        getchar();getchar();break;
	case '3':system("clear");printf("游戏已退出\n");q=1;break;
};

}

return 0;
}
//loading diren and start to fight
void zhanduo_interface(char *diren_filename){
system("clear");         
if((fp2=fopen("xianyoushishen.dat","rb"))==NULL){                                       printf("cant open file");                                                               exit(0);    
};                                                                                      fread(&xyss,sizeof(xyss),1,fp2);                                                            fclose(fp2); 
if((fp2=fopen(diren_filename,"rb"))==NULL){                                               printf("cant open file");                                                               exit(0);                                                                            };                                                                                      fread(&diren1,sizeof(diren1),1,fp2);                                                    fclose(fp2);                                                                            zc=Zhanchang(xyss,diren1,skill);zc.run();
}
