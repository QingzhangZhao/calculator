#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* multi(char r[],char b[],char a[],int *p){
	int len=strlen(a),len1=strlen(b),rSta=99,i=len1,j=len,temp=0,cb,ca,tSum,sCur,tt,shi,ge;
	memset(r,'0',100);
	for(i=len1-1;i>=0;i--){
		for(j=len-1;j>=0;j--){
			cb=b[i]-48;ca=a[j]-48; 
			tSum=cb*ca;
			temp=0;
			sCur=101-len1+i-len+j;
			tt=(r[sCur]-48)+tSum;
			ge=tt%10;shi=tt/10;
			r[sCur]=ge+48;
			tt=(r[sCur-1]-48)+shi;	
			rSta=sCur;
			while(tt>=10){
				r[sCur-1-temp]=tt-10+48;
				tt=r[sCur-2-temp]-48+1; 
				temp++;
			}
			if(tt<10 && tt>0){
				r[sCur-1-temp]=tt+48;	
				if(sCur-1-temp<rSta){
					rSta=sCur-1-temp;
				}
			}
		}   
	}
	*p=rSta;
	return r;
}
int main(){
	char r[100],*s1="123456789",*s2="23456";int a=0,*p=&a; 
	printf("%s",multi(r,s1,s2,p)+(*p));
	return 0;
}
