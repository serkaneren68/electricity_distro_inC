#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stddef.h>
#include<math.h>




typedef struct Hat Hat;
struct Hat {
		int id ;
		double x1 ;
		double y1 ;
		double x2 ;
		double y2 ;
		
		
};

typedef struct {
		int id ;
		double x1 ;
		double y1 ;
		double x2 ;
		double y2 ;
		
	
}Indirici;

typedef struct {
		int id ;
		int tip  ;
		double x1 ;
		double y1 ;
		double x2 ;
		double y2 ;
		
}Musteri;

Hat find_prev(Hat temp,Hat* hat,int k);

	
    Indirici indirici ;
	Musteri musteri[1000];
	Hat hat[1000];
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Turkish");
	FILE *dosya;
	int i=0;
	int k =0;
	
	
	
	dosya = fopen("testing.txt","r");
	
	while(!feof(dosya)){
		char temp[100] ;	
		fgets(temp,100,dosya);
		
		if(temp[0] == 'I'){
			
			fgets(temp,100,dosya);
			sscanf(temp,"%d\t%lf\t%lf\t%lf\t%lf",&indirici.id,&indirici.x1,&indirici.y1,&indirici.x2,&indirici.y2);	
			printf("%d\t%lf\t%lf\t%lf\t%lf\n",indirici.id,indirici.x1,indirici.y1,indirici.x2,indirici.y2);
			fgets(temp,100,dosya);
					
			
			if(temp[0]=='E'){
				
				fgets(temp,100,dosya);
				while(1){
					fgets(temp,100,dosya);
					
					if(temp[0]=='E'){
					
						fgets(temp,100,dosya);
							if(temp[0]=='H'){
								while(1){
									fgets(temp,100,dosya);
									if(temp[0]== 'E'){
										goto out;
								}
										sscanf(temp,"%d\t%lf\t%lf\t%lf\t%lf",&hat[k].id,&hat[k].x1,&hat[k].y1,&hat[k].x2,&hat[k].y2);
										printf("%d\t%lf\t%lf\t%lf\t%lf\n",hat[k].id,hat[k].x1,hat[k].y1,hat[k].x2,hat[k].y2);
										k++;			
								}
							}							
			}
			else{
			
			sscanf(temp,"%d\t%d\t%lf\t%lf\t%lf\t%lf",&musteri[i].id,&musteri[i].tip,&musteri[i].x1,&musteri[i].y1,&musteri[i].x2,&musteri[i].y2);
			printf(temp,"%d\t%d\t%lf\t%lf\t%lf\t%lf\n",musteri[i].id,musteri[i].tip,musteri[i].x1,musteri[i].y1,musteri[i].x2,musteri[i].y2);
			i++;}
			} 			
			}
}
}
out:
fclose(dosya);			
//son musteri i-1. müsteridir
//son hat k-1 . hattýr
printf("hat sayýsý = %d\n",k);
printf("musteri sayýsý = %d \n",i);
printf("%d \n",hat[k-1].id);
double sum = 0;
int g;
for(g=0;g<k;g++){
	sum= sum + pow((pow((hat[g].x1-hat[g].x2),2)   +  pow ((hat[g].y1-hat[g].y2),2)),0.5);
	
}
g = 0;

printf("toplam hat uzunluðun =  % lf m \n",sum);
int musteri_id ;
printf("bilgilerinizi görmek için lütfen id nizi giriniz = ");
scanf("%d",&musteri_id);

for(g=0;g<i;g++){
	if(musteri[g].id == musteri_id)
		printf("\nmusteri tipi = %d \nkordinatlar = x1,y1 = (%lf , %lf)    x2,y2 = (%lf , % lf)\n",musteri[g].tip,musteri[g].x1,musteri[g].y1,musteri[g].x2,musteri[g].y2);
	
}
g = 0;
int uzaklik_id ;	


printf("uzaklýk bulmak için id nizi girin: \t");	
scanf("%d",&uzaklik_id);
for(g=0;g<i;g++){
	if(uzaklik_id == musteri[g].id)
		printf("\n\nmusterin merkeze kus ucusu  uzaklýgý = %f \n", pow(pow((musteri[g].x1-indirici.x1),2 ) +   pow((musteri[g].y1-indirici.y1),2),0.5));
 
}
int h = 0;
int num,j,m;
Hat markez;
Hat endpoint;
printf("hat güzergahýný görmek için id giriniz : ");
scanf("%d",&num);
for(j=0; j < k; j++){
	if(indirici.x1==hat[j].x1 && indirici.y1==hat[j].y1){
		markez=hat[j];
		break;
	}
}
Musteri mus;
for(m=0; m < i ; m++){
	if(musteri[m].id==num){
		mus=musteri[m];
		break;
	}
}

		for( m=0; m < k; m++){
			if(mus.x1 == hat[m].x2 &&  mus.y1 == hat[m].y2){
				endpoint=hat[m];
				break;
			}
			
			
		}
		
double sayac_musteri = 0.0;	
		
printf("\nHAT: %d\n",endpoint.id);
sayac_musteri = sayac_musteri + pow(pow((endpoint.x2-endpoint.x1),2 ) +   pow((endpoint.y2-endpoint.y1),2),0.5);
Hat temp=find_prev(endpoint,hat,k);
if(temp.id != -1)
	printf("HAT: %d\n",temp.id);
	sayac_musteri = sayac_musteri + pow(pow((temp.x2-temp.x1),2 ) +   pow((temp.y2-temp.y1),2),0.5);
while(temp.id!=markez.id){
	Hat new_hat=find_prev(temp,hat,k);
	if(new_hat.id == -1){
		printf(" ----- hat kesik------- \n");
		break;	
	}
	printf("HAT : %d\n",new_hat.id);
	sayac_musteri = sayac_musteri + pow(pow((new_hat.x2-new_hat.x1),2 ) +   pow((new_hat.y2-new_hat.y1),2),0.5);
	
	
	if(new_hat.id == markez.id){
		printf("Ýndirici Merkez\n");
		
	}	
	temp=new_hat;
	
}

printf("musteriye baðlý toplam  hat uzunlugu =  %lf \n\n",sayac_musteri);

double x,y;


printf("dosyalar oluþturuldu!!!  kesikler.txt ve  uzaklýklar.txt dosyalarýný kontrol edin  \n");
FILE *dosya_yaz ;
FILE *kesikler_yaz ;
kesikler_yaz = fopen("kesikler.txt","w");
dosya_yaz = fopen("uzaklýklar.txt","w");
fprintf(dosya_yaz,"id\that		kusucusu\n");
int z;
for(z=0;z<i;z++){

for(j=0; j < k; j++){
	if(indirici.x1==hat[j].x1 && indirici.y1==hat[j].y1){
		markez=hat[j];
		break;
	}
}
Musteri mus;
for(m=0; m < i ; m++){
	if(musteri[m].id==musteri[z].id){
		mus=musteri[m];
		break;
	}
}

		for( m=0; m < k; m++){
			if(mus.x1 == hat[m].x2 &&  mus.y1 == hat[m].y2){
				endpoint=hat[m];
				break;
			}
			
			
		}
		
double sayac_musteri = 0.0;	
fprintf(dosya_yaz,"%d\t",musteri[z].id)		;

sayac_musteri = sayac_musteri + pow(pow((endpoint.x2-endpoint.x1),2 ) +   pow((endpoint.y2-endpoint.y1),2),0.5);
Hat temp=find_prev(endpoint,hat,k);
if(temp.id != -1)
	
	sayac_musteri = sayac_musteri + pow(pow((temp.x2-temp.x1),2 ) +   pow((temp.y2-temp.y1),2),0.5);
while(temp.id!=markez.id){
	Hat new_hat=find_prev(temp,hat,k);
	if(new_hat.id == -1){
		if(temp.id !=-1)fprintf(kesikler_yaz,"hat %d kesiktir \n",temp.id);
		
		break;	
	}
	
	sayac_musteri = sayac_musteri + pow(pow((new_hat.x2-new_hat.x1),2 ) +   pow((new_hat.y2-new_hat.y1),2),0.5);
	
	
	if(new_hat.id == markez.id){
		
		
	}	
	temp=new_hat;
	
}

fprintf(dosya_yaz,"%lf\t",sayac_musteri);
fprintf(dosya_yaz,"%lf\n", pow(pow((musteri[z].x1-indirici.x1),2 ) +   pow((musteri[z].y1-indirici.y1),2),0.5));
}
fclose(kesikler_yaz);
fclose(dosya_yaz);
	
	return 0;
}

Hat find_prev(Hat temp,Hat* hat,int k){
	int i; 
	Hat hats = {-1,-1,-1,-1,-1};
	for( i=0; i < k ; i++){
		if(temp.x1== hat[i].x2){
			if(temp.y1 == hat[i].y2){
				return hat[i];
			}
		}
	}
	return hats;	
}
