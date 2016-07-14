

/*ʼ��2016��5��15��*/


#include <stdio.h>
#include "acllib.h"
/*�������ˣ��Ҿ�Ȼ���˰�����Ӧ����.h�ļ�������.c�ļ���Ϊ�����˷���һ����Сʱ����
�̹����ģ���������������*/

#define n_plus 107
#define n_minus 109
#define n_multiply 106
#define n_divide 111

/*����Ӧ��Ӧ����ȫ�ֱ�����������
��ʱû�б�ĸ��õİ취��2016��5��30��19:59:31*/
int outcome=0;
int para1=0,para2=0; 
/*�������������������㣬������ֱ��ʹ��outcome�洢�����*/
int switch_sign=0;
//char *out="0";
/*sprintf()��֪��Ϊʲô�ò����ַ�ָ����Ϊ�յ������*/
char out[10]="0";
char para1_txt[10];
char para2_txt[10];
char *sign="";
int outcome_painted=0;	//outcome�Ƿ��Ѿ���ʾ�Ŀ���
int negative_space=0; 


void activePaint() {	/*һ��ʼ����Ϊһ����ʾ�����͹��ˣ�����������������Ѿ��������ˡ�*/
	beginPaint();
	
	/*һ���ɫ�ľ��Σ����ڸ�����һ��������̡�
	��Ȼ�ܲ����ţ����޼ƿ�ʩ��Ҳ���ܵ������õ����������ơ�
	��֪������ĳ�������ô���ġ�*/
	setBrushColor(WHITE);
	rectangle(0,55,200,150);
	
/*���ģ�����ʾ��̬�仯�����������֡�*/
	setTextFont("microsoft yahei");
//	setTextSize(30);
//	setTextColor(GRAY);
//	paintText(7,10,);
	
	setTextSize(60);
	setTextColor(BLACK);
	paintText(7,70,out);
		
	endPaint();
} 

void paintMain() {
	beginPaint();
	/*��ʾ���㲿��:*/
	setPenColor(GRAY);
	setPenStyle(PS_DASH);
	line(0,50,200,50);
		
	/*END of ��ʾ���㲿�� */
	
	/*����������һ�������������ַ����аױ�....*/
//	setBrushColor(MYGRAY);
//	rectangle(0,150,200,350);

	/*�ػ����ʱ���ð�ɫ�����ڸǡ�*/
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(0,150,200,350);
	
	/*����*/
	setPenWidth(1);
	setPenStyle(PS_SOLID);
	setPenColor(BLACK);
	line(0,150,200,150);
	line(0,200,200,200);
	line(0,250,200,250);
	line(0,300,200,300);
	/*����*/
	line(50,150,50,350);
	line(100,150,100,300);
	line(150,150,150,350);
	line(200,150,200,350);
	/*���ּ�����*/
	setTextSize(30);
	setTextFont("microsoft yahei");
	
	paintText(170,160,"/");
	paintText(170,210,"*");
	paintText(170,260,"-");
	paintText(170,310,"+");
	paintText(90,310,"��");
	paintText(15,165,"7");
	paintText(15,215,"4");
	paintText(15,265,"1");
	paintText(15,315,"0");
	paintText(65,165,"8");
	paintText(65,215,"5");
	paintText(65,265,"2");
	paintText(115,165,"9");
	paintText(115,215,"6");
	paintText(115,265,"3");
	
	
	/*��λ��ť���ػ����ʱ���ð׿��ڸǡ�*/
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(150,0,200,50);
	
	setPenColor(BLACK);
	line(150,0,150,50);
	paintText(158,7,"<-");
	
	/*�ƺ���������ͼƬ�������ǳ����ã��ʷ����ˡ�*/	
//	ACL_Image keyboard;
//	loadImage("keyboard222.jpg",&keyboard);
//	putImage(&keyboard,0,150);
//	putImageScale(&keyboard,0,150,200,200);
	
	endPaint();
} 


void timeListen(int id) {
	static cnt=0;
//	printf("		cnt=%d\n",cnt);
	cnt++;
	
	if (cnt==2) {
		paintMain();
		/*0.2sʱ��һ�������»��������棬�Ӷ��γɰ��µ�Ч����*/
		cancelTimer(0);
		cnt=0;
	}
}

void paintPressedButton(int left,int top,int right,int bottom) {
	beginPaint();
	setBrushColor(MYGRAY);
	rectangle(left,top,right,bottom);
	endPaint();
	
	startTimer(0,100);
	/*�����ǻ��ǣ��������˿��Դӱ�ĵط���ʼ��ʱ��*/
	
	/*��Ϊ���µ�Ч����һ˲��ģ����Գ���ʹ�ý����ŵ��û���������ĺ�����
	��ʵ�����Ч����*/
//	paintMain();
	/*������ʵ�ֲ��ˡ����������˲����ɵġ�*/
}

int getPlaceOfPara(int in_para) {
	int place=0;
	int temp_para=in_para;
	if (temp_para<0) {
		/*��Ȼ�����㸺�������ǵ����Ϊ����ʱ��
		����Ҫ�õ�����λ������֮��*/
		temp_para=-temp_para;
	}
	do {
		place++;
		temp_para/=10;
	} while (temp_para>0);
	/*������paraΪ0ʱ�������*/
	return place;
}

void turnParaIntoText() {
	sprintf(para1_txt,"%d",para1);
	sprintf(para2_txt,"%d",para2);
}


void paintPastProcess() {
	
	turnParaIntoText(); 
	if (negative_space!=0) {
		negative_space=10;
	}
	int place_para1=getPlaceOfPara(para1);
	int place_para2=getPlaceOfPara(para2);
	/*���»س�������ʾ����һ����������̣�
	����ʾ��������������*/
	beginPaint();
	
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(0,5,150,45);
	
	setTextFont("microsoft yahei");
	setTextSize(30);
	setTextColor(GRAY);
	paintText(7,10,para1_txt);
	paintText(7+(place_para1*15)+negative_space,10,sign);
	paintText(22+(place_para1*15)+negative_space,10,para2_txt);
	paintText(30+(place_para1*15)+(place_para2*15)+negative_space,10,"=");
	
	endPaint();
	
	negative_space=0;	//��ԭ���ſ�λ 
}

void paintProcess() {
	turnParaIntoText(); 
	int place_para1=getPlaceOfPara(para1);
	
	beginPaint();
		
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(0,55,200,150);
	
	setTextSize(60);
	setTextColor(BLACK);
	if (para1<0) {
		/*��Ȼ�������������㸺�������Ǹ�����������ʾ�ġ�
		����Ҫ���ǵ��������ʱ��һ��������ʾ�������*/
		negative_space=30;
	}
	paintText(7,70,para1_txt);
	if(switch_sign!=0){
		paintText(42+(place_para1*30+negative_space),70,para2_txt);
	}
		
	endPaint();
	
} 

void paintOutcome() {
	
	sprintf(out,"%d",outcome);
	
	beginPaint();
	
	/*һ���ɫ�ľ��Σ����ڸ�����һ��������̡�
	��Ȼ�ܲ����ţ����޼ƿ�ʩ��Ҳ���ܵ������õ����������ơ�
	��֪������ĳ�������ô���ġ�*/
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(0,55,200,150);
	
	setTextSize(60);
	setTextColor(BLACK);
	paintText(7,70,out);
	
	endPaint();
	
	outcome_painted=1; 	//�򿪽������ʾ���� 
	
	/*�����������㣬���¿�ʼ��һ�����㡣*/
	para1=0;
	para2=0; 
	switch_sign=0; 
}

void paintSign() {
	/*�����ű�ʾΪ0ʱ������ʾ���š�*/
	if (switch_sign!=0) {
		int place_para1=getPlaceOfPara(para1);
		/*Ĭ��Ϊ�գ�����ʼ��ʾ0ʱ������ʾ���š�*/
		/*��������ַ�ָ������⡣
		�ַ�ָ���൱�ڰ�һ���ַ������׵�ַ������һ��ָ�롣
		����Ҫ�ı���ֵ����Ҫ��ָ��ָ�����ַ�����ֱ��ʹ��ָ�루���� * �ŵı�������
		��ֵΪ����ִ������൱�ڸı���ָ��*/
		switch (switch_sign) {
			case 1:
				sign="+";
				break;
			case 2:
				sign="-";
				break;
			case 3:
				sign="��";
				break;
			case 4:
				sign="��";
				break;
		}
		beginPaint();
		
		setTextSize(60);
		setTextColor(BLACK);
		/*��ʾ���ķ��ŵ�λ��Ӧ�ý�����ǰ�����������Ҫ����ǰ������λ����*/
		/*λ�������ǵ�һ�����������λ������Ҫ���Ǽ�������ʱ��
		��һ����������λ����*/
		paintText((7+place_para1*30+negative_space),70,sign);
	//	printf("the sign %s has been displayed in %d place.\n",sign,(7+place*30));
		
		endPaint();
		
	}
}

void backspace() {
	
	if (switch_sign==0&&outcome_painted==1) {
		outcome=0;
		/*�ο��˼����������󣬾�����������ʱ��
		ֱ�ӽ����Ϊ0��*/
//		turnOutcomeIntoText();
		/*�۲���Է��֣�turnOutcomeIntoText()���������
		paintOutcome()�Ĺ�ϵʮ�ֽ��ܡ�
		�����Ұ�������ϵ�һ���ˡ�*/
		paintOutcome();
	} else if (switch_sign==0&&para2==0) {
		para1/=10;
		paintProcess();
	} else if (switch_sign!=0) {
		para2/=10;
		paintProcess();
	}	
	/*��10�����൱��ɾȥ�����һλ�����ǣ�*/
	
	/*������ж��Ƕ���ģ��������ǵ�0��
	���ÿ���outcome���ɸ�����*/
//	if (outcome>0) {
//		outcome /=10;
//		/*��10�����൱��ɾȥ��һλ�����ǣ�*/
//	}	else	{
//		outcome=0;
//		/*������0��*/
//	}
}

int cal(int input) {
	
	
	if (input>=96&&input<=105) {
		if (outcome_painted==1) {
			outcome_painted=0;
			/*�������ֱ������һ���Ľ������һ���Ĳ���һ��
			��ô����һ����������ʱ���ѽ���Ѿ���ʾ���عرա�
			�Է�ֹ����ķ���������ģ���ٰѽ�����ɲ���һ��*/
		} 
		if (switch_sign==0) {
			/*�����ſ��ش��ڳ�ʼ״̬����δ������ţ���ʱ�򣬵õ��Ƿ������룬
			����ʱ�����뵱����һ��������*/
			para1=para1*10+input-96;
			/*��10���ǵ���λ*/
		}
		
	//	if ((switch_sign!=0)&&(input>=96&&input<=105)) {
		if (switch_sign!=0) {
			/*�����ſ��ش����ĸ����ŵ�λ�ϵ�ʱ���Ѿ�������ţ����õ��Ƿ�������ʱ��
			����ʱ�����뵱���ڶ���������*/
			para2=para2*10+input-96; 
		}
	}
	
	if (input==n_plus||input==n_minus||
	input==n_multiply||input==n_divide) {	
	/*���������ǼӼ��˳��ĸ�����֮һ��������룬��ô�͸ı�switch_signΪ
	��Ӧ��ֵ������ʾ�÷��š�*/
		switch (input) {
			case n_plus:
				switch_sign=1;
				break;
			case n_minus:
				switch_sign=2;
				break;
			case n_multiply:
				switch_sign=3;
				break;
			case n_divide:
				switch_sign=4;
				break;
		}
		if (outcome_painted==1) {
			/*�����һ�������Ѿ���ɣ�����Ѿ���ʾ������ô���������ʱ��
			�Ͱ���һ���Ľ����������һ��*/
			para1=outcome;
			/*������ֱ������һ���Ľ������һ���Ĳ���һ��
			��ô����һ����������ʱ...����ǰ�������������ģ�顣��*/
		}
	}
	
//	if (outcome_painted==1) {
//		/*��һ���ֻ�ԭ��λ��ʮ�ֹؼ���Ӱ�쵽�˺ܶಿ�֡�*/
//		para1=0;
//		para2=0;
//		outcome_painted=0;
		/*ʵ���ǲ����ţ�
		2016��6��1��21:43:55
		2016��6��5��15:08:46����һ���ֲ���Ҫ�ˣ��Ѿ�����ԭ���ˡ�*/
//	}
	
	switch (switch_sign) {
			case 0:
				/*Ĭ��״̬�£���������ǰ����Ϊһ����λ����
				��λ��Ҫ��ʾ��*/
//				outcome=outcome*10+input;
//				place++;
				/*place�������ﲻ�ã�Ӧ��ֱ�ӷ��ڻ��ƺ����С�*/
				break;
			case 1:
				outcome=para1+para2;
				break;
			case 2:
				outcome=para1-para2;
				break;
			case 3:
				outcome=para1*para2;
				break;
			case 4:
				if (para1!=0&&para2!=0) {
					outcome=para1/para2;
					/*����Ϊ0���ʱ�������*/
				} else {
					outcome=0;
				}
				break;
		}
	
	printf("switch_sign=%d,outcome=%d\n",switch_sign,outcome);
	printf("para1=%d,para2=%d\n",para1,para2);
	return outcome;
}

void keyboardBack(int key,int event) {
//	printf("key=%d\n",key);
	if (event==0)
	printf("key=%d,event=%d\n",key,event);
	
	if (key>=96&&key<=111&&event==0) {	//when press down
		cal(key);
		paintProcess();
		paintSign();
		/*���ŷ������ֺ��ӡ�����ⱻ���ǡ�*/
	}
	
//	turnOutcomeIntoText();
	
	if (key==8&&event==0) {
		/*����,ע��ֻ���ǰ��£�����ֻ��key=8��������Σ�
		backspace������ֵ8�������һλ��*/
		backspace();
		/*��λ�������ʾ�أ�
		��ʱ�ֱ��Ĵ���Ϊ������Ӧ�Ļ��ƺ�������backspace()�ڵ������
		�������ʾ��*/
		paintSign();
		/*����һ���ı��������ʾһ�Σ����˼·����������
		2016��6��2��21:38:57��
		2016��6��5��15:51:17���ҽ����о�����Ҫ�����ڸ�ˮƽ�Ļ����ϣ�
		��������������ʵ�ֶ������ѵģ�ʲô���Ű���Ч�ʰ�����������*/
	}
//		activePaint();

	if (key==13&&event==0) {
		/*����,ע��ֻ���ǰ���(&&event==0)������ֻ��key=13��������Σ�
		backspace������ֵ8�������һλ��*/
		/*����ʾ��һ���Ĳ��衣*/
		paintPastProcess();
		/*���»س�����ʾ�����*/
		paintOutcome();
		/*���ҽ����������ͷ��ſ��ع��㡣
		�ڴ˴�����������ֵ���㣬Ϊ�λ�ı���ʾ����أ�
		�������ڹ���ǰ���Ѿ���ʾ������
		����˵Ӧ�ò�����Ϊֵ�ĸı������ٴ���ʾ����
		
		�ҵ�ԭ���ˣ�����ֻ���ǰ���(&&event==0)�ˡ�*/
		para1=0;
		para2=0; 
		switch_sign=0; 
	} 

}

void mouseBack(int x,int y,int button,int event) {
//	printf("x=%d,y=%d,b=%d,e=%d\n",x,y,button,event);
	/*˼·�ǣ���xy���껮�ֳ�������������һ�����Ͱ���Ӧ�ġ���ֵ����
	Ҳ�������input����cal()������ */
	/*�����button=1��������event=0��������event=0��*/
	
	if (event==0) {
		if (x>=0&&x<=50&&y>=150&&y<=200) {
			paintPressedButton(0,150,50,200);
			cal(103);//7
		}
		if (x>=0&&x<=50&&y>=201&&y<=250) {
			paintPressedButton(0,200,50,250);
			cal(100);//4
		}
		if (x>=0&&x<=50&&y>=250&&y<=300) {
			paintPressedButton(0,250,50,300);
			cal(97);//1
		}
		if (x>=0&&x<=50&&y>=300&&y<=350) {
			paintPressedButton(0,300,50,350);
			cal(96);//0
		}
		if (x>=50&&x<=100&&y>=150&&y<=200) {
			paintPressedButton(50,150,100,200);
			cal(104);//8
		}
		if (x>=50&&x<=100&&y>=201&&y<=250) {
			paintPressedButton(50,200,100,250);
			cal(101);//5
		}
		if (x>=50&&x<=100&&y>=251&&y<=300) {
			paintPressedButton(50,250,100,300);
			cal(98);//2
		}
		if (x>=100&&x<=150&&y>=150&&y<=200) {
			paintPressedButton(100,150,150,200);
			cal(105);//9
		}
		if (x>=100&&x<=150&&y>=201&&y<=250) {
			paintPressedButton(100,200,150,250);
			cal(102);//6
		}
		if (x>=100&&x<=150&&y>=251&&y<=300) {
			paintPressedButton(100,250,150,300);
			cal(99);//3
		}
		
		if (x>=151&&x<=200&&y>=150&&y<=350){
			if (y>=150&&y<=200){
				cal(111);//�� 
				paintPressedButton(150,150,200,200);
			}
			if (y>=200&&y<=250){
				cal(106);//�� 
				paintPressedButton(150,200,200,250);
			}
			if (y>=250&&y<=300){
				cal(109);//�� 
				paintPressedButton(150,250,200,300);
			}
			if (y>=300&&y<=350){
				cal(107);//�� 
				paintPressedButton(150,300,200,350);
			}
		} 
		
		if (x>=150&&x<=200&&y>=0&&y<=50) {
			cal(8);//��λ��
			backspace();
			paintPressedButton(150,0,200,50);
		}
		
		/*ֻ�а���ʱ�Ŵ�ӡ��*/
		paintProcess();
		paintSign();
		if (x>=50&&x<=150&&y>=301&&y<=350) {
			paintPressedButton(50,300,150,350);
			cal(13);//���ں�,�س��� 
			paintPastProcess();
			paintOutcome();
		} 
	}
}


int Setup() {
//	initConsole();
	initWindow("My Caculator",DEFAULT,DEFAULT,200,350);
	
	registerKeyboardEvent(keyboardBack);
	registerMouseEvent(mouseBack);
	registerTimerEvent(timeListen);
	
	beginPaint();
	/*��ʼ��0,����㲻���ظ���γ��֣����Դ�paintMain�ж��������ˡ�*/
	setTextFont("microsoft yahei");
	setTextSize(60);
	setTextColor(BLACK);
	paintText(7,70,out);
	endPaint();
	
	/*�������ֲ����������,�պ��ǵ���һЩ��Ч�Ļ���
	���ܻ������һ�������������ػ���档*/
	paintMain();
	
	return 0;
}
