#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define OG 30
#define UG 1

int main(){
	
	int mwmo[6][12]={0}, i=0, k=0, pk=0, pk1=0 , pk2=0, pk3=0, m1=0, m2=0, m3=0, w1=0, w2=0, w3=0, pges=0, mges=0, wges=0, iz=0;
	char s='x';
	
	srand(time(NULL));
	
	for(i=0;i<12;i++){
		printf("Monat%3i",i+1);
		
		pk=1;
		for(k=0;k<6;k++){
			mwmo[k][i]=rand()%(OG-UG+1)+1;

			if(k%2==0){
			printf("\t| Plegeklasse %3i\tM: %3i",pk,mwmo[k][i]);
			}
			if(k%2==1){
				printf("\t  W: %3i |",mwmo[k][i]);
				pk++;
			}
		}
		printf("\n");	
	}
	
	for(i=0;i<12;i++){
		for(k=0;k<6;k++){
			if(k%2==0){
			mges=mges+mwmo[k][i];
			}
			if(k%2==1){
			wges=mges+mwmo[k][i];
			}
		}
	}
	printf("\nM gesamt im Jahr: %3i",mges);
	printf("\nW gesamt im Jahr: %3i",wges);
	
	printf("\n\nBelegung Pruefen im Zeitraum 1-12:\n");
	i=0;
	pk=0;
	while(i<1||i>12){
		printf("Von Monat : ");
		scanf("%3i",&i);
	}
	while(iz<i||iz>12){
	printf("Bis Monat : ");
	scanf("%3i",&iz);
	}
	
	printf("\nNach Flegestufe ausgeben? y | n\n");
	while(s!='y' && s!='n'){
		scanf("%c",&s);
	}
	if(s=='y'){
		s='x';
		while(s!='y' && s!='n'){
			fflush(stdin);
			printf("\nPflegestufe I \t\t y | n\n");
			scanf("%c",&s);
			if(s=='y'){
				pk1=2;
			}
		}	
		s='x';
		while(s!='y' && s!='n'){
			fflush(stdin);
			printf("\nPflegestufe II \t\t y | n\n");
			fflush(stdin);
			scanf("%c",&s);
			if(s=='y'){
				pk2=4;
			}
		}
		s='x';
		while(s!='y' && s!='n'){
			fflush(stdin);
			printf("\nPflegestufe III \t y | n\n");
			scanf("%c",&s);
			if(s=='y'){
				pk3=6;
			}
		}	
		s='x';
	}
	
	s='x';
	printf("\nNach M || W getrennt ausgeben? y | n\n");
	while(s!='y' && s!='n'){
		scanf("%c",&s);
	}
	if(s=='y'){
		s='x';
		while(s!='m' && s!='w'){
			fflush(stdin);
			printf("\nM oder W \t\t m | w\n");
			scanf("%c",&s);
		}
	}

	printf("\n\nBelegung von Monat%3i. bis Monat%3i.\n",i,iz);
	mges=0;
	wges=0;
	
	if(s=='n'){
		for(i-=1;i<=iz-1;i++){
			for(k=0;k<6;k++){
				if(k%2==0){
				mges=mges+mwmo[k][i];
					if(pk1==2 && k==0){
						m1=m1+mwmo[k][i];
					}
					if(pk2==4 && k==2){
						m2=m2+mwmo[k][i];
					}
					if(pk3==6 && k==4){
						m3=m3+mwmo[k][i];
					}				
				}
				if(k%2==1){
				wges=wges+mwmo[k][i];
					if(pk1==2 && k==1){
						w1=w1+mwmo[k][i];
					}
					if(pk2==4 && k==3){
						w2=w2+mwmo[k][i];
					}
					if(pk3==6 && k==5){
						w3=w3+mwmo[k][i];
					}
				}
			}
		}
		printf("\nM Patienten in dem Zeitraum:\t%i",mges);
		printf("\nW Patienten in dem Zeitraum:\t%i",wges);
		if(pk1==2){
			printf("\nM der Pflegeklasse I\t%i",m1);
		}
		if(pk2==4){
			printf("\nM der Pflegeklasse II\t%i",m2);
		}
		if(pk3==6){
			printf("\nM der Pflegeklasse III\t%i",m3);
		}
		if(pk1==2){
			printf("\nW der Pflegeklasse I\t%i",w1);
		}
		if(pk2==4){
			printf("\nW der Pflegeklasse II\t%i",w2);
		}
		if(pk3==6){
			printf("\nW der Pflegeklasse III\t%i",w3);
		}	
	}	
	
	if(s=='m'){
		for(i-=1;i<=iz-1;i++){
			for(k=0;k<6;k++){
				if(k%2==0){
				mges=mges+mwmo[k][i];
					if(pk1==2 && k==0){
						m1=m1+mwmo[k][i];
					}
					if(pk2==4 && k==2){
						m2=m2+mwmo[k][i];
					}
					if(pk3==6 && k==4){
						m3=m3+mwmo[k][i];
					}
				}
			}
		}
		printf("\nM in Zeitraum:\t%i\n",mges);	
	}
	else if(s=='w'){
		for(i-=1;i<=iz-1;i++){
			for(k=0;k<6;k++){
				if(k%2==1){
				wges=wges+mwmo[k][i];
					if(pk1==2 && k==1){
						w1=w1+mwmo[k][i];
					}
					if(pk2==4 && k==3){
						w2=w2+mwmo[k][i];
					}
					if(pk3==6 && k==5){
						w3=w3+mwmo[k][i];
					}				
				}
			}
		}
		printf("\nW in Zeitraum:\t%i\n",wges);	
	}	

	if(pk1==2 && s=='m'){
		printf("\nM der Pflegeklasse I\t%i",m1);
	}
	if(pk2==4 && s=='m'){
		printf("\nM der Pflegeklasse II\t%i",m2);
	}
	if(pk3==6 && s=='m'){
		printf("\nM der Pflegeklasse III\t%i",m3);
	}
	if(pk1==2 && s=='w'){
		printf("\nW der Pflegeklasse I\t%i",w1);
	}
	if(pk2==4 && s=='w'){
		printf("\nW der Pflegeklasse II\t%i",w2);
	}
	if(pk3==6 && s=='w'){
		printf("\nW der Pflegeklasse III\t%i",w3);
	}	
	
	return 0;
}